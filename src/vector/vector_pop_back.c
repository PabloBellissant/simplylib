#include "vector.h"

struct header	*get_header(const void *vec);

void	vector_pop_back(void *vec)
{
	struct header	*header = get_header(vec);
	header->Elem_count -= 1;
}
