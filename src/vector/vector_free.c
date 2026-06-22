#include "vector.h"

#include <stdlib.h>

struct header	*get_header(const void *vec);

void	vector_free(void *vec)
{
	free(get_header(vec));
}
