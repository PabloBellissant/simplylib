#include "vector.h"

bool	vector_shrink(void **vec, const uint64_t elem_size)
{
	struct header	*header = (struct header *)(*(char **)vec - HEADER_SIZE);
	return (vector_resize(vec, header->Elem_count, elem_size));
}
