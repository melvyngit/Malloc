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
