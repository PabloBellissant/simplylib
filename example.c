#define SIMPLY_VECTOR_IMPLEMENTATION // <-- Need to define implementation ONE time, in only one file. Usualy the main.c
#include "vector.h"

#include <stdio.h>

int	main(void)
{
	// Simple usage for int
	{
		int	*arr = VECTOR_INIT(int, 16); // <-- Initialize a vector of type int, with 16 base elements.

		for (int i = 0; i < 50; i++) // <-- The vector will realloc itself, to handle more elements.
		{
			int	val = i * i;
			VECTOR_PUSH_BACK(arr, &val, 1); // <-- Push back to vector 'arr', the element val.
		}

		printf("Vector size : %zu\n", VECTOR_SIZE(arr));
		printf("Vector capacity : %zu\n", VECTOR_CAPACITY(arr));

		for (int i = 0; i < 50; i++)
		{
			printf("elem %d : %d\n", i, arr[i]); // <-- To access elements you only need to use [], like a usual array.
		}
		VECTOR_FREE(arr); // <-- free the vector, elements and internal header.
	}

	// Usage with a struct
	{
		struct player
		{
			char	*name;
			int		hp;
			int		strength;
		};

		struct player *players = VECTOR_INIT(struct player, 10);

		struct player p1 = (struct player) {.name = "Steve", .hp = 20, .strength = 1};
		VECTOR_PUSH_BACK(players, &p1, 1);

		struct player p2 = (struct player) {.name = "Alex", .hp = 15, .strength = 2};
		VECTOR_PUSH_BACK(players, &p2, 1);

		for (int i = 0; i < 2; i++)
		{
			printf("Name : %s, hp : %d, strength : %d\n", players[i].name, players[i].hp, players[i].strength);
		}
		VECTOR_FREE(players);
	}

	// More complex usage
	{
		int	*arr = VECTOR_INIT(int, 2000);

		for (int i = 0; i < 8; i++)
		{
			VECTOR_PUSH_BACK(arr, &i, 1);
		}

		VECTOR_PUSH_BACK(arr, arr, 8); // <-- Pushing the vector itself 
		
		for (int i = 0; i < 16; i++)
		{
			printf("%d\n", arr[i]);
		}

		printf("%zu, %zu\n", VECTOR_CAPACITY(arr), VECTOR_SIZE(arr));
		VECTOR_SHRINK(arr);
		printf("%zu, %zu\n", VECTOR_CAPACITY(arr), VECTOR_SIZE(arr));

		size_t i = 0;

		while (i < VECTOR_SIZE(arr))
		{
			VECTOR_SWAP_AND_POP(arr, 0, 1);
		}

		VECTOR_FREE(arr);
	}
}
