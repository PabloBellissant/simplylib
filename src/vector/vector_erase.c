#include "vector.h"

#include <string.h>
#include <assert.h>

struct header	*get_header(const void *vec);

void	vector_erase(void *vec, const uint64_t index, const uint64_t elem_count)
{
	struct header	*header = get_header(vec);
	assert((index + elem_count) <= header->Elem_count);
	char	*pos = (char *)vec + (header->Elem_size * index);
	memmove(pos, pos + (header->Elem_size * elem_count), (header->Elem_count - index - elem_count) * header->Elem_size);
	header->Elem_count -= elem_count;
}
