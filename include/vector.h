#pragma once

/*
*	Vector Lib
*
*
*
*	Memory :
*	struct mem
*	{
*		// Header
*			uint64_t Elem_count; <-- Malloc Position
*			uint64_t Elem_max;
*			uint32_t Elem_size;
*		...Data[0] <-- Pointer position
*	}
*/

#include <stdint.h>
#include <stdbool.h>

struct header
{
	uint64_t Elem_count;
	uint64_t Elem_max;
	uint32_t Elem_size;
};

# define ELEM_COUNT_SPACE 8
# define ELEM_MAX_SPACE 8
# define ELEM_SIZE_SPACE 4
# define HEADER_SIZE (ELEM_COUNT_SPACE + ELEM_MAX_SPACE + ELEM_SIZE_SPACE)

void		*vector_init(const uint32_t elem_size, const uint64_t base_size);
void		*vector_at(const void *vec, const uint64_t index);
void		*vector_front(void *vec);
void		*vector_back(const void *vec);
void		vector_free(void *vec);
bool		vector_empty(const void *vec);
uint64_t	vector_size(const void *vec);
uint64_t	vector_capacity(const void *vec);
bool		vector_reserve(void **vec, const uint64_t reserve_size);
bool		vector_shrink(void **vec);
void		vector_clear(void *vec);
bool		vector_resize(void **vec, const uint64_t new_size);
bool		vector_push_back(void **vec, const void *data, const uint64_t elem_count);
void		vector_pop_back(void *vec);
bool		vector_insert(void **vec, const void *data, const uint64_t elem_count, const uint64_t pos);
void		vector_erase(void *vec, const uint64_t index, const uint64_t elem_count);

uint64_t	vector_begin(const void *vec);
uint64_t	vector_end(const void *vec);
