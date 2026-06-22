#include "vector.h"

#include <stdint.h>

struct header	*get_header(const void *vec);

uint64_t	vector_size(const void *vec)
{
	struct header	*header = get_header(vec);
	return (header->Elem_count);
}
