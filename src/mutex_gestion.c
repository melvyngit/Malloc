/*
** mutex_gestion.c for Malloc in /root/Malloc/src
** 
** Made by Melvyn Covindarassou
** Login   <covind_m@etna-alternance.net>
** 
** Started on  Thu Feb  7 11:23:56 2019 Melvyn Covindarassou
** Last update Thu Feb  7 11:24:07 2019 Melvyn Covindarassou
*/

#include "malloc.h"

pthread_mutex_t mutual_exclusion = PTHREAD_MUTEX_INITIALIZER;

void	mutual_exclusion_unlock(void)
{
  if (pthread_mutex_unlock(&mutual_exclusion) != 0)
    abort();
}

void	mutual_exclusion_lock(void)
{
  if (pthread_mutex_lock(&mutual_exclusion) != 0)
    abort();
}
