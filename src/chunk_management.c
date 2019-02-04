#include "malloc.h"

chunkstruct_t	*chunk_initialisation(size_t size, void *ptr, chunkstruct_t *chunk)
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

chunkstruct_t	*getting_free_chunk(size_t size)
{
  chunkstruct_t	*temporary;

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
