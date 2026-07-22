#include "vector.h"

#include <assert.h>

struct header	*get_header(const void *vec);

void	vector_swap_elem(void *vec, const uint64_t index_a, const uint64_t index_b, const uint64_t elem_size)
{
	struct header	*header = get_header(vec);
	assert(header->Elem_count != 0);
	assert(index_a < header->Elem_count);
	assert(index_b < header->Elem_count);
	char	temp;
	for (uint32_t i = 0; i < elem_size; i++)
	{
		temp = *((char *)vec + (elem_size * index_a) + i);
		*((char *)vec + (elem_size * index_a) + i) = *((char *)vec + (elem_size * index_b) + i);
		*((char *)vec + (elem_size * index_b) + i) = temp;
	}
}
