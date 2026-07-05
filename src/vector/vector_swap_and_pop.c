#include "vector.h"

void	vector_swap_and_pop(void *vec, const uint64_t index, const uint64_t count)
{
	for (uint64_t i = 0; i < count; i++)
	{
		vector_swap_elem(vec, index, vector_end(vec) - 1);
		vector_pop_back(vec);
	}
}
