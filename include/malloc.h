/*
** malloc.h for Malloc in /root/Malloc/include
** 
** Made by Melvyn Covindarassou
** Login   <covind_m@etna-alternance.net>
** 
** Started on  Thu Feb  7 11:20:19 2019 Melvyn Covindarassou
** Last update Thu Feb  7 11:20:32 2019 Melvyn Covindarassou
*/

#ifndef			__MALLOC_H__
#define			__MALLOC_H__

#include		<unistd.h>
#include		<stdlib.h>
#include		<stddef.h>
#include		<pthread.h>

typedef struct		s_chunkstruct
{
  size_t		size;
  char			free;
  struct s_chunkstruct	*next;
}			t_chunkstruct;

t_chunkstruct		*first;
t_chunkstruct		*last;

void			mutual_exclusion_unlock(void);
void			mutual_exclusion_lock(void);
size_t			size_alignment(size_t size);
t_chunkstruct		*chunk_initialisation(size_t size, void *ptr, t_chunkstruct *chunk);
t_chunkstruct		*getting_free_chunk(size_t size);
void			*malloc(size_t size);
void			setting_last(void);
void			free(void *chunk);

#endif
