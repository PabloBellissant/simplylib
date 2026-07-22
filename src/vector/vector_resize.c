#include "vector.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

bool	vector_resize(void **vec, const uint64_t new_size, const uint64_t elem_size)
{
	assert(new_size != 0);
	struct header	*header = (struct header *)(*(char **)vec - HEADER_SIZE);
	struct header	*new_header = malloc(elem_size * new_size + HEADER_SIZE);
	if (!new_header)
		return (false);
	new_header->Elem_max = new_size;
	if (new_size < header->Elem_count)
		header->Elem_count = new_size;
	new_header->Elem_count = header->Elem_count;
	memcpy((char *)new_header + HEADER_SIZE, *vec, elem_size * header->Elem_count);
	vector_free(*vec);
	*vec = (char *)new_header + HEADER_SIZE;
	return (true);
}
