#include "vector.h"

struct header	*get_header(const void *vec)
{
	struct header *header = (struct header *)((char *)vec - HEADER_SIZE);
	return (header);
}
