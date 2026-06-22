#include "vector.h"

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

void	*vector_init(const uint32_t elem_size, const uint64_t base_size)
{
	assert(base_size != 0);
	struct header *memory = (struct header *)malloc(HEADER_SIZE + elem_size * base_size);
	if (!memory)
		return (NULL);
	memory->Elem_count = 0;
	memory->Elem_max = base_size;
	memory->Elem_size = elem_size;
	return ((char *)memory + HEADER_SIZE);
}
