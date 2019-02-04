#include "malloc.h"

void		setting_last(void)
{
  chunkstruct_t	*temporary;

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

void		free(void *chunk)
{
  chunkstruct_t *new_chunk;
  void		*limit;

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
