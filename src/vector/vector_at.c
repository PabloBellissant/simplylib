#include "vector.h"

#include <stddef.h>
#include <assert.h>

struct header	*get_header(const void *vec);

void	*vector_at(const void *vec, const uint64_t index, const uint64_t elem_size)
{
	struct header *header = get_header(vec);
	assert(index < header->Elem_count);
	return (((char *) vec) + (elem_size * index));
}
