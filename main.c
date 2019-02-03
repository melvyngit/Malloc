#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <pthread.h>

typedef struct chunkstruct_s {
		size_t size;
		char free;
		struct chunkstruct_s *next;
	} chunkstruct_t;

	chunkstruct_t *first;
	chunkstruct_t *last;

pthread_mutex_t mutual_exclusion = PTHREAD_MUTEX_INITIALIZER;

void mutual_exclusion_unlock(void)
{
	if (pthread_mutex_unlock(&mutual_exclusion) != 0)
		abort();
}

void mutual_exclusion_lock(void)
{
	if (pthread_mutex_lock(&mutual_exclusion) != 0)
		abort();
}

size_t size_alignment(size_t size)
{
	size = (0xf + size) & ~0xf;
	return (size);
}

chunkstruct_t *chunk_initialisation(size_t size, void *ptr, chunkstruct_t *chunk)
{
	chunk = ptr;
	chunk->free = 0;
	chunk->next = NULL;
	chunk->size = size;
	if (first == NULL)
		first = chunk;
	if (last != NULL)
		last->next = chunk;
	last = chunk;
	return (chunk);
}

chunkstruct_t *getting_free_chunk(size_t size)
{
	chunkstruct_t *temporary;

	temporary = first;
	while (temporary != NULL)
	 {
		if (temporary->size >= size && temporary->free == 1)
		 {
			temporary->free = 0;
			mutual_exclusion_unlock();
			return ((void *)(1 + temporary));
		 }
		temporary = temporary->next;
	 }
 return (NULL);
}

void *malloc(size_t size)
{
	chunkstruct_t *chunk;
	void *ptr;

	if (size == 0)
		return (NULL);
	size = size_alignment(size);
	mutual_exclusion_lock();
	chunk = getting_free_chunk(size);
	if (chunk != NULL)
		return (chunk);
	ptr = sbrk(size + sizeof(chunkstruct_t));
	if (ptr == ((void *)-1))
	{
		mutual_exclusion_unlock();
		return (NULL);
	}
	chunk = chunk_initialisation(size, ptr, chunk);
	mutual_exclusion_unlock();
	return ((void *)(1 + chunk));
}

void setting_last(void)
{
	chunkstruct_t *temporary;

	temporary = first;
	if (last != first)
 		{
	 		while (temporary != NULL)
	 			{
		 			if (temporary->next == last)
		 				{
			 				temporary->next = NULL;
			 				last = temporary;
		 				}
		 			temporary = temporary->next;
	 			}
 		}
	else
		{
			last = NULL;
			first = NULL;
		}
}

void free(void *chunk)
{
	chunkstruct_t *new_chunk;
	void *limit;

	if (chunk == NULL)
		return;
	mutual_exclusion_lock();
	new_chunk = -1 + (chunkstruct_t *)chunk;
	limit = sbrk(0);
	if ((char *)chunk + new_chunk->size == limit)
	{
		setting_last();
		sbrk(-sizeof(chunkstruct_t) - new_chunk->size);
		mutual_exclusion_unlock();
		return;
	}
	new_chunk->free = 1;
	mutual_exclusion_unlock();
}
