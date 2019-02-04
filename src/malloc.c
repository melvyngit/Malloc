#include "malloc.h"

void		*malloc(size_t size)
{
  chunkstruct_t	*chunk;
  void		*ptr;

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
