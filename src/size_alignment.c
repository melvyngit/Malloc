/*
** size_alignment.c for Malloc in /root/Malloc/src
** 
** Made by Melvyn Covindarassou
** Login   <covind_m@etna-alternance.net>
** 
** Started on  Thu Feb  7 11:24:19 2019 Melvyn Covindarassou
** Last update Thu Feb  7 11:24:30 2019 Melvyn Covindarassou
*/

#include "malloc.h"

size_t	size_alignment(size_t size)
{
  size = (0xf + size) & ~0xf;
  return (size);
}
