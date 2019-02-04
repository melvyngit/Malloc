#ifndef			MALLOC_H
#define			MALLOC_H

#include		<unistd.h>
#include		<stdlib.h>
#include		<stddef.h>
#include		<pthread.h>

typedef struct		chunkstruct_s
{
  size_t		size;
  char			free;
  struct chunkstruct_s	*next;
}chunkstruct_t;

chunkstruct_t		*first;
chunkstruct_t		*last;

void			mutual_exclusion_unlock(void);
void			mutual_exclusion_lock(void);
size_t			size_alignment(size_t size);
chunkstruct_t		*chunk_initialisation(size_t size, void *ptr, chunkstruct_t *chunk);
chunkstruct_t		*getting_free_chunk(size_t size);
void			*malloc(size_t size);
void			setting_last(void);
void			free(void *chunk);

#endif
