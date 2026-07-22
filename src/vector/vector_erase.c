#include "vector.h"

#include <string.h>
#include <assert.h>

struct header	*get_header(const void *vec);

// Slow, consider using vector_swap_and_pop() if index does not count.
void	vector_erase(void *vec, const uint64_t index, const uint64_t elem_count, const uint64_t elem_size)
{
	struct header	*header = get_header(vec);
	assert((index + elem_count) <= header->Elem_count);
	char	*pos = (char *)vec + (elem_size * index);
	memmove(pos, pos + (elem_size * elem_count), (header->Elem_count - index - elem_count) * elem_size);
	header->Elem_count -= elem_count;
}
