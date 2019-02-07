/*
** chunk_management.c for Malloc in /root/Malloc/src
** 
** Made by Melvyn Covindarassou
** Login   <covind_m@etna-alternance.net>
** 
** Started on  Thu Feb  7 11:22:38 2019 Melvyn Covindarassou
** Last update Thu Feb  7 11:22:58 2019 Melvyn Covindarassou
*/

#include "malloc.h"

t_chunkstruct	*chunk_initialisation(size_t size, void *ptr, 
		t_chunkstruct *chunk)
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

t_chunkstruct	*getting_free_chunk(size_t size)
{
  t_chunkstruct	*temporary;

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
