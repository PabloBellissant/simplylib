#include "vector.h"

#include <assert.h>

struct header	*get_header(const void *vec);

void	*vector_back(const void *vec, const uint64_t elem_size)
{
	struct header *header = get_header(vec);
	assert(header->Elem_count > 0);
	return ((char *)vec + ((header->Elem_count - 1) * elem_size));
}
