#include "malloc.h"

size_t	size_alignment(size_t size)
{
  size = (0xf + size) & ~0xf;
  return (size);
}
