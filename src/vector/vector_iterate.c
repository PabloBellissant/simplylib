#include "vector.h"

#include <stddef.h>

struct header	*get_header(const void *vec);

int	vector_iterate(void *vec, int(*f)(void *))
{
	struct header *header = get_header(vec);

	for (size_t i = 0; i < header->Elem_count; i++)
	{
		int	ret_value = f(vector_at(vec, i));
		if (ret_value != 0)
			return ret_value;
	}
	return (0);
}
