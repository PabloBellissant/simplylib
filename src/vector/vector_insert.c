#include "vector.h"

#include <string.h>
#include <assert.h>

bool	vector_insert(void **vec, const void *data, const uint64_t elem_count, const uint64_t pos)
{
	assert(elem_count != 0);
	struct header	*header = (struct header *)(*(char **)vec - HEADER_SIZE);
	assert(pos <= header->Elem_count);
	if (header->Elem_max - header->Elem_count < elem_count)
	{
		if (!vector_resize(vec, (header->Elem_count + (elem_count - 1)) * 2))
			return (false);
	}
	header = (struct header *)(*(char **)vec - HEADER_SIZE);
	char	*new_pos = *(char **)vec + (header->Elem_size * pos);
	memmove(new_pos + (elem_count * header->Elem_size), new_pos, header->Elem_count * header->Elem_size);
	memcpy(new_pos, data, elem_count * header->Elem_size);
	header->Elem_count += elem_count;
	return (true);
}
