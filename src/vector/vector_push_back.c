#include "vector.h"

#include <string.h>
#include <assert.h>

void	*resize_no_free(void **vec, const uint64_t new_size);

inline bool	vector_push_back(void **vec, const void *data, const uint64_t elem_count)
{
	assert(elem_count != 0);
	struct header	*header = (struct header *)(*(char **)vec - HEADER_SIZE);
	if (header->Elem_max - header->Elem_count < elem_count)
	{
		// Realloc, too small.
		void	*old_vec = resize_no_free(vec, (header->Elem_count + (elem_count - 1)) * 2); // We cannot use vector_resize, bc data could be the vector itself, and vector_resize free the old data.
		if (old_vec == NULL)
			return (false);
		header = (struct header *)(*(char **)vec - HEADER_SIZE);
		char	*new_pos = *(char **)vec + (header->Elem_size * header->Elem_count);
		memcpy(new_pos, data, (elem_count * header->Elem_size));
		header->Elem_count += elem_count;
		vector_free(old_vec);
		return (true);
	}
	header = (struct header *)(*(char **)vec - HEADER_SIZE);
	char	*new_pos = *(char **)vec + (header->Elem_size * header->Elem_count);
	memcpy(new_pos, data, (elem_count * header->Elem_size));
	header->Elem_count += elem_count;
	return (true);
}
