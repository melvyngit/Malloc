/*
** free.c for Malloc in /root/Malloc/src
** 
** Made by Melvyn Covindarassou
** Login   <covind_m@etna-alternance.net>
** 
** Started on  Thu Feb  7 11:23:10 2019 Melvyn Covindarassou
** Last update Thu Feb  7 11:23:27 2019 Melvyn Covindarassou
*/

#include "malloc.h"

void		setting_last(void)
{
  t_chunkstruct	*temporary;

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
  t_chunkstruct *new_chunk;
  void		*limit;

  if (chunk == NULL)
    return;
  mutual_exclusion_lock();
  new_chunk = -1 + (t_chunkstruct *)chunk;
  limit = sbrk(0);
  if ((char *)chunk + new_chunk->size == limit)
    {
      setting_last();
      sbrk(-sizeof(t_chunkstruct) - new_chunk->size);
      mutual_exclusion_unlock();
      return;
    }
  new_chunk->free = 1;
  mutual_exclusion_unlock();
}
