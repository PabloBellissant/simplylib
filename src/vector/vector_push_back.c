#include "vector.h"

#include <string.h>
#include <assert.h>

bool	vector_push_back(void **vec, const void *data, const uint64_t elem_count)
{
	assert(elem_count != 0);
	struct header	*header = (struct header *)(*(char **)vec - HEADER_SIZE);
	if (header->Elem_max - header->Elem_count < elem_count)
	{
		if (!vector_resize(vec, (header->Elem_count + (elem_count - 1)) * 2))
		{
			return (false);
		}
	}
	header = (struct header *)(*(char **)vec - HEADER_SIZE);
	memcpy(*(char **)vec + (header->Elem_size * header->Elem_count), data, (elem_count * header->Elem_size));
	header->Elem_count += elem_count;
	return (true);
}
