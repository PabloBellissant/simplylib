#ifndef VECTOR_H
# define VECTOR_H

/*
*	Vector Lib
*
*
*
*	Memory :
*	struct mem
*	{
*		// Header :
*			uint64_t Elem_count; <-- Malloc Position
*			uint64_t Elem_max;
*		...Data[0] <-- Pointer position
*	};
*/

// PUBLIC API

#include <stdint.h>
#include <stdbool.h>

void		*_vector_init(const uint32_t elem_size, const uint64_t base_size);
void		*_vector_at(const void *vec, const uint64_t index, const uint64_t elem_size);
void		*_vector_front(void *vec);
void		*_vector_back(const void *vec, const uint64_t elem_size);
void		_vector_free(void *vec);
bool		_vector_empty(const void *vec);
uint64_t	_vector_size(const void *vec);
uint64_t	_vector_capacity(const void *vec);
bool		_vector_reserve(void **vec, const uint64_t reserve_size, const uint64_t elem_size);
bool		_vector_shrink(void **vec, const uint64_t elem_size);
void		_vector_clear(void *vec);
bool		_vector_resize(void **vec, const uint64_t new_size, const uint64_t elem_size);
bool		_vector_push_back(void **vec, const void *data, const uint64_t elem_count, const uint64_t elem_size);
void		_vector_pop_back(void *vec);
bool		_vector_insert(void **vec, const void *data, const uint64_t elem_count, const uint64_t pos, const uint64_t elem_size);

void		_vector_erase(void *vec, const uint64_t index, const uint64_t elem_count, const uint64_t elem_size);
// Slow, consider using vector_swap_and_pop() if index does not count.

uint64_t	_vector_begin(const void *vec);
uint64_t	_vector_end(const void *vec);

int			_vector_iterate(void *vec, int(*f)(void *), const uint64_t elem_size);
void		_vector_swap_elem(void *vec, const uint64_t index_a, const uint64_t index_b, const uint64_t elem_size);
void		_vector_swap_and_pop(void *vec, const uint64_t index, const uint64_t count, const uint64_t elem_size);

# define VECTOR_INIT(type, base_size) _vector_init(sizeof(type), base_size) 
# define VECTOR_AT(vec, index) _vector_at(vec, index, sizeof(*(vec))) 
# define VECTOR_FRONT(vec) _vector_front(vec) 
# define VECTOR_BACK(vec) _vector_back(vec, sizeof(*(vec))) 
# define VECTOR_FREE(vec) _vector_free(vec) 
# define VECTOR_EMPTY(vec) _vector_empty(vec) 
# define VECTOR_SIZE(vec) _vector_size(vec) 
# define VECTOR_CAPACITY(vec) _vector_capacity(vec) 
# define VECTOR_RESERVE(vec, reserve_size) _vector_reserve((void **)&vec, reserve_size, sizeof(*vec)) 
# define VECTOR_SHRINK(vec) _vector_shrink((void **)&vec, sizeof(*vec)) 
# define VECTOR_CLEAR(vec) _vector_clear(vec) 
# define VECTOR_RESIZE(vec, new_size) _vector_resize((void **)&vec, new_size, sizeof(*vec)) 
# define VECTOR_PUSH_BACK(vec, data, elem_count) _vector_push_back((void **)&vec, data, elem_count, sizeof(*vec)) 
# define VECTOR_POP_BACK(vec) _vector_pop_back(vec) 
# define VECTOR_INSERT(vec, data, elem_count, pos) _vector_insert((void **)&vec, data, elem_count, pos, sizeof(*vec)) 
# define VECTOR_ERASE(vec, index, elem_count) _vector_erase(vec, index, elem_count, sizeof(*vec)) 
# define VECTOR_BEGIN(vec) _vector_begin(vec) 
# define VECTOR_END(vec) _vector_end(vec) 
# define VECTOR_ITERATE(vec, func) _vector_iterate(vec, func, sizeof(*vec)) 
# define VECTOR_SWAP_ELEM(vec, index_a, index_b) _vector_swap_elem(vec, index_a, index_b, sizeof(*vec)) 
# define VECTOR_SWAP_AND_POP(vec, index, count) _vector_swap_and_pop(vec, index, count, sizeof(*vec)); 

// #define SIMPLY_VECTOR_IMPLEMENTATION
#ifdef SIMPLY_VECTOR_IMPLEMENTATION

#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct simply_vector_header
{
	uint64_t Elem_count;
	uint64_t Elem_max;
};

# define ELEM_COUNT_SPACE 8
# define ELEM_MAX_SPACE 8
# define HEADER_SIZE (ELEM_COUNT_SPACE + ELEM_MAX_SPACE)

void		*_vector_init(const uint32_t elem_size, const uint64_t base_size)
{
	assert(base_size != 0);
	assert(elem_size != 0);
	struct simply_vector_header *memory = (struct simply_vector_header *)malloc(HEADER_SIZE + elem_size * base_size);
	if (!memory)
		return (NULL);
	memory->Elem_count = 0;
	memory->Elem_max = base_size;
	return ((char *)memory + HEADER_SIZE);
}

struct simply_vector_header	*_get_header(const void *vec);

struct simply_vector_header	*_get_header(const void *vec)
{
	struct simply_vector_header *header = (struct simply_vector_header *)((char *)vec - HEADER_SIZE);
	return (header);
}

void	*_vector_at(const void *vec, const uint64_t index, const uint64_t elem_size)
{
	return (((char *) vec) + (elem_size * index));
}

void	*_vector_front(void *vec)
{
	return (vec);
}

void	*_vector_back(const void *vec, const uint64_t elem_size)
{
	struct simply_vector_header *header = _get_header(vec);
	assert(header->Elem_count > 0);
	return ((char *)vec + ((header->Elem_count - 1) * elem_size));
}

void	_vector_free(void *vec)
{
	free(_get_header(vec));
}

bool	_vector_empty(const void *vec)
{
	struct simply_vector_header	*header = _get_header(vec);
	return (header->Elem_count == 0);
}

uint64_t	_vector_size(const void *vec)
{
	struct simply_vector_header	*header = _get_header(vec);
	return (header->Elem_count);
}

uint64_t	_vector_capacity(const void *vec)
{
	struct simply_vector_header	*header = _get_header(vec);
	return (header->Elem_max);
}

bool	_vector_reserve(void **vec, const uint64_t reserve_size, const uint64_t elem_size)
{
	struct simply_vector_header	*header = (struct simply_vector_header *)(*(char **)vec - HEADER_SIZE);
	if (reserve_size <= header->Elem_max)
		return (true);
	return (_vector_resize(vec, reserve_size, elem_size));
}

bool	_vector_shrink(void **vec, const uint64_t elem_size)
{
	struct simply_vector_header	*header = (struct simply_vector_header *)(*(char **)vec - HEADER_SIZE);
	return (_vector_resize(vec, header->Elem_count, elem_size));
}

void	_vector_clear(void *vec)
{
	struct simply_vector_header	*header = _get_header(vec);
	header->Elem_count = 0;
}

bool	_vector_resize(void **vec, const uint64_t new_size, const uint64_t elem_size) {
	assert(new_size != 0);
	struct simply_vector_header	*header = (struct simply_vector_header *)(*(char **)vec - HEADER_SIZE);
	struct simply_vector_header	*new_header = malloc(elem_size * new_size + HEADER_SIZE);
	if (!new_header)
		return (false);
	new_header->Elem_max = new_size;
	if (new_size < header->Elem_count)
		header->Elem_count = new_size;
	new_header->Elem_count = header->Elem_count;
	memcpy((char *)new_header + HEADER_SIZE, *vec, elem_size * header->Elem_count);
	_vector_free(*vec);
	*vec = (char *)new_header + HEADER_SIZE;
	return (true);
}

void	*_resize_no_free(void **vec, const uint64_t new_size, const uint64_t elem_size)
{
	assert(new_size != 0);
	struct simply_vector_header	*header = (struct simply_vector_header *)(*(char **)vec - HEADER_SIZE);
	struct simply_vector_header	*new_header = malloc(elem_size * new_size + HEADER_SIZE);
	if (!new_header)
		return (NULL);
	new_header->Elem_max = new_size;
	if (new_size < header->Elem_count)
		header->Elem_count = new_size;
	new_header->Elem_count = header->Elem_count;
	memcpy((char *)new_header + HEADER_SIZE, *vec, elem_size * header->Elem_count);
	void	*ret = *vec;
	*vec = (char *)new_header + HEADER_SIZE;
	return (ret);
}

bool	_vector_push_back(void **vec, const void *data, const uint64_t elem_count, const uint64_t elem_size)
{
	assert(elem_count != 0);
	struct simply_vector_header	*header = (struct simply_vector_header *)(*(char **)vec - HEADER_SIZE);
	if (header->Elem_max - header->Elem_count < elem_count)
	{
		// Realloc, too small.
		void	*old_vec = _resize_no_free(vec, (header->Elem_count + (elem_count - 1)) * 2, elem_size); // We cannot use vector_resize, bc data could be the vector itself, and vector_resize free the old data.
		if (old_vec == NULL)
			return (false);
		header = (struct simply_vector_header *)(*(char **)vec - HEADER_SIZE);
		char	*new_pos = *(char **)vec + (elem_size * header->Elem_count);
		memcpy(new_pos, data, (elem_count * elem_size));
		header->Elem_count += elem_count;
		_vector_free(old_vec);
		return (true);
	}
	header = (struct simply_vector_header *)(*(char **)vec - HEADER_SIZE);
	char	*new_pos = *(char **)vec + (elem_size * header->Elem_count);
	memcpy(new_pos, data, (elem_count * elem_size));
	header->Elem_count += elem_count;
	return (true);
}

void	_vector_pop_back(void *vec)
{
	struct simply_vector_header	*header = _get_header(vec);
	header->Elem_count -= 1;
}

bool	_vector_insert(void **vec, const void *data, const uint64_t elem_count, const uint64_t pos, const uint64_t elem_size)
{
	assert(elem_count != 0);
	struct simply_vector_header	*header = (struct simply_vector_header *)(*(char **)vec - HEADER_SIZE);
	assert(pos <= header->Elem_count);
	if (header->Elem_max - header->Elem_count < elem_count)
	{
		// realloc
		void	*old_vec = _resize_no_free(vec, (header->Elem_count + (elem_count - 1)) * 2, elem_size); // We cannot use vector_resize, bc data could be the vector itself, and vector_resize free the old data.
		if (!old_vec)
			return (false);
		header = (struct simply_vector_header *)(*(char **)vec - HEADER_SIZE);
		char	*new_pos = *(char **)vec + (elem_size * pos);
		memmove(new_pos + (elem_count * elem_size), new_pos, header->Elem_count * elem_size);
		memcpy(new_pos, data, elem_count * elem_size);
		header->Elem_count += elem_count;
		_vector_free(old_vec);
		return (true);
	}
	header = (struct simply_vector_header *)(*(char **)vec - HEADER_SIZE);
	char	*new_pos = *(char **)vec + (elem_size * pos);
	memmove(new_pos + (elem_count * elem_size), new_pos, header->Elem_count * elem_size);
	memcpy(new_pos, data, elem_count * elem_size);
	header->Elem_count += elem_count;
	return (true);
}

void	_vector_erase(void *vec, const uint64_t index, const uint64_t elem_count, const uint64_t elem_size)
{
	struct simply_vector_header	*header = _get_header(vec);
	assert((index + elem_count) <= header->Elem_count);
	char	*pos = (char *)vec + (elem_size * index);
	memmove(pos, pos + (elem_size * elem_count), (header->Elem_count - index - elem_count) * elem_size);
	header->Elem_count -= elem_count;
}

uint64_t	_vector_end(const void *vec)
{
	struct simply_vector_header	*header = _get_header(vec);
	return (header->Elem_count);
}

uint64_t	_vector_begin(const void *vec)
{
	(void) vec;
	return (0);
}

int	_vector_iterate(void *vec, int(*f)(void *), const uint64_t elem_size)
{
	struct simply_vector_header *header = _get_header(vec);

	for (size_t i = 0; i < header->Elem_count; i++)
	{
		int	ret_value = f(_vector_at(vec, i, elem_size));
		if (ret_value != 0)
			return ret_value;
	}
	return (0);
}

void	_vector_swap_elem(void *vec, const uint64_t index_a, const uint64_t index_b, const uint64_t elem_size)
{
	struct simply_vector_header *header = _get_header(vec);
	assert(header->Elem_count != 0);
	assert(index_a < header->Elem_count);
	assert(index_b < header->Elem_count);
	char	temp;
	for (uint32_t i = 0; i < elem_size; i++)
	{
		temp = *((char *)vec + (elem_size * index_a) + i);
		*((char *)vec + (elem_size * index_a) + i) = *((char *)vec + (elem_size * index_b) + i);
		*((char *)vec + (elem_size * index_b) + i) = temp;
	}
}

void	_vector_swap_and_pop(void *vec, const uint64_t index, const uint64_t count, const uint64_t elem_size)
{
	for (uint64_t i = 0; i < count; i++)
	{
		_vector_swap_elem(vec, index, _vector_end(vec) - 1, elem_size);
		_vector_pop_back(vec);
	}
}

#endif // SIMPLY_VECTOR_IMPLEMENTATION

#endif
