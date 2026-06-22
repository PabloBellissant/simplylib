#include "vector.h"

#include <stddef.h>
#include <assert.h>

struct header	*get_header(const void *vec);

void	*vector_at(const void *vec, const uint64_t index)
{
	struct header *header = get_header(vec);
	assert(index < header->Elem_count);
	return (((char *) vec) + (header->Elem_size * index));
}
