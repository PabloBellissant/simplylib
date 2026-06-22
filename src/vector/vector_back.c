#include "vector.h"

struct header	*get_header(const void *vec);

void	*vector_back(const void *vec)
{
	struct header *header = get_header(vec);
	return ((char *)vec + ((header->Elem_count - 1) * header->Elem_size));
}
