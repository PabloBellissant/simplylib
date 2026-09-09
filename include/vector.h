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
*		...Data[0] <-- Pointer position
*	}
*/

#include <stdint.h>
#include <stdbool.h>

struct header
{
	uint64_t Elem_count;
	uint64_t Elem_max;
};

# define ELEM_COUNT_SPACE 8
# define ELEM_MAX_SPACE 8
# define HEADER_SIZE (ELEM_COUNT_SPACE + ELEM_MAX_SPACE)

void		*vector_init(const uint32_t elem_size, const uint64_t base_size);
void		*vector_at(const void *vec, const uint64_t index, const uint64_t elem_size);
void		*vector_front(void *vec);
void		*vector_back(const void *vec, const uint64_t elem_size);
void		vector_free(void *vec);
bool		vector_empty(const void *vec);
uint64_t	vector_size(const void *vec);
uint64_t	vector_capacity(const void *vec);
bool		vector_reserve(void **vec, const uint64_t reserve_size, const uint64_t elem_size);
bool		vector_shrink(void **vec, const uint64_t elem_size);
void		vector_clear(void *vec);
bool		vector_resize(void **vec, const uint64_t new_size, const uint64_t elem_size);
bool		vector_push_back(void **vec, const void *data, const uint64_t elem_count, const uint64_t elem_size);
void		vector_pop_back(void *vec);
bool		vector_insert(void **vec, const void *data, const uint64_t elem_count, const uint64_t pos, const uint64_t elem_size);
void		vector_erase(void *vec, const uint64_t index, const uint64_t elem_count, const uint64_t elem_size);

uint64_t	vector_begin(const void *vec);
uint64_t	vector_end(const void *vec);

int			vector_iterate(void *vec, int(*f)(void *), const uint64_t elem_size);
void		vector_swap_elem(void *vec, const uint64_t index_a, const uint64_t index_b, const uint64_t elem_size);
void		vector_swap_and_pop(void *vec, const uint64_t index, const uint64_t count, const uint64_t elem_size);

//
// DEFINES
//

# define VECTOR_INIT(type, base_size) vector_init(sizeof(type), base_size)
# define VECTOR_AT(vec, index) vector_at(vec, index, sizeof(*(vec)))
# define VECTOR_FRONT(vec) vector_front(vec)
# define VECTOR_BACK(vec) vector_back(vec, sizeof(*(vec)))
# define VECTOR_FREE(vec) vector_free(vec)
# define VECTOR_EMPTY(vec) vector_empty(vec)
# define VECTOR_SIZE(vec) vector_size(vec)
# define VECTOR_CAPACITY(vec) vector_capacity(vec)
# define VECTOR_RESERVE(vec, reserve_size) vector_reserve((void **)&vec, reserve_size, sizeof(*vec))
# define VECTOR_SHRINK(vec) vector_shrink((void **)&vec, sizeof(*vec))
# define VECTOR_CLEAR(vec) vector_clear(vec)
# define VECTOR_RESIZE(vec, new_size) vector_resize((void **)&vec, new_size, sizeof(*vec))
# define VECTOR_PUSH_BACK(vec, data, elem_count) vector_push_back((void **)&vec, data, elem_count, sizeof(*vec))
# define VECTOR_POP_BACK(vec) vector_pop_back(vec)
# define VECTOR_INSERT(vec, data, elem_count, pos) vector_insert((void **)&vec, data, elem_count, pos, sizeof(*vec))
# define VECTOR_ERASE(vec, index, elem_count) vector_erase(vec, index, elem_count, sizeof(*vec))
# define VECTOR_BEGIN(vec) vector_begin(vec)
# define VECTOR_END(vec) vector_end(vec)
# define VECTOR_ITERATE(vec, func) vector_iterate(vec, func, sizeof(*vec))
# define VECTOR_SWAP_ELEM(vec, index_a, index_b) vector_swap_elem(vec, index_a, index_b, sizeof(*vec))
# define VECTOR_SWAP_AND_POP(vec, index, count) vector_swap_and_pop(vec, index, count, sizeof(*vec));
