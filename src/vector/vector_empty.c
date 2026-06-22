#include "vector.h"

#include <stdbool.h>

struct header	*get_header(const void *vec);

bool	vector_empty(const void *vec)
{
	struct header	*header = get_header(vec);
	if (header->Elem_count == 0)
		return (true);
	return (false);
}
