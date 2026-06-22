#include "vector.h"

bool	vector_shrink(void **vec)
{
	struct header	*header = (struct header *)(*(char **)vec - HEADER_SIZE);
	return (vector_resize(vec, header->Elem_count));
}
