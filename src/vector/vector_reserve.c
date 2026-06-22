#include "vector.h"

bool	vector_reserve(void **vec, const uint64_t reserve_size)
{
	struct header	*header = (struct header *)(*(char **)vec - HEADER_SIZE);
	if (reserve_size <= header->Elem_max)
		return (true);
	return (vector_resize(vec, reserve_size));
}
