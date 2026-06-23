#include "vector.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

void	*resize_no_free(void **vec, const uint64_t new_size)
{
	assert(new_size != 0);
	struct header	*header = (struct header *)(*(char **)vec - HEADER_SIZE);
	struct header	*new_header = malloc(header->Elem_size * new_size + HEADER_SIZE);
	if (!new_header)
		return (NULL);
	new_header->Elem_max = new_size;
	if (new_size < header->Elem_count)
		header->Elem_count = new_size;
	new_header->Elem_count = header->Elem_count;
	new_header->Elem_size = header->Elem_size;
	memcpy((char *)new_header + HEADER_SIZE, *vec, header->Elem_size * header->Elem_count);
	void	*ret = *vec;
	*vec = (char *)new_header + HEADER_SIZE;
	return (ret);
}
