# A simple C library, that recreate c++ std::vector

# Example : 
```c
#define SIMPLY_VECTOR_IMPLEMENTATION // Need one and only one implementation, next file will only need to include svector.h
#include "svector.h"

int main(void)
{
  int *arr = VECTOR_INIT(int, 64); // 64 int pre_allocated

  for (int i = 0; i < 64; i++)
  {
    int value = i * 2
    VECTOR_PUSH_BACK(arr, &value, 1);
  }

  for (uint64_t i = 0; i < VECTOR_SIZE(arr); i++)
  {
    printf("%d\n", arr[i]); // can access it directly like a regular array.
  }
  VECTOR_FREE(arr); // Need to free to avoid memory leaks
}
```

See ([Examples](/example.c)) for other examples.

# Usage :
- To use the library, you only have to add the header file svector.h in your includes, and define SIMPLY_VECTOR_IMPLEMENTATION one time in one file.



# All macro/functions exposed by the api :

|Macro name|description|return_type|parameters|can fail|
|-|-|-|-|-|
|VECTOR_INIT|Initialize the vector|void *|type, init size|Yes (malloc)|
|VECTOR_AT|Get the index value|void *|vec, index|No|
|VECTOR_FRONT|Return the first element|void *|vec|No|
|VECTOR_BACK|Return the last element|void *|vec|No|
|VECTOR_FREE|Free the vector|void|vec|No|
|VECTOR_EMPTY|Check if the vector is empty|bool|vec|No|
|VECTOR_SIZE|Return the size|uint64|vec|No|
|VECTOR_CAPACITY|Return the actual capacity|uint64|vec|No|
|VECTOR_RESERVE|Pre allocate to a size|bool|vec, reserve size|Yes (malloc)|
|VECTOR_SHRINK|Reduce the capacity to the actual size|bool|vec|Yes (malloc)|
|VECTOR_CLEAR|Set the size to 0|void|vec|No
|VECTOR_RESIZE|Resize the vector|bool|vec, new size|Yes (malloc)|
|VECTOR_PUSH_BACK|Push count element at the end|bool|vec, &data, count|Yes (malloc)|
|VECTOR_POP_BACK|Remove the last element|void|vec|No|
|VECTOR_INSERT|Insert count element at index pos|bool|vec, &data, count, pos|Yes (malloc)|
|VECTOR_ERASE|Erase count element at index|void|vec, index, count|No|
|VECTOR_BEGIN|Return the first index (0)|void|vec|No|
|VECTOR_ITERATE|Iterate the function func over the vector|int|vec, func|No|
|VECTOR_SWAP_ELEM|Swap two element from a vec|void|vec, index_a, index_b|No|
|VECTOR_SWAP_AND_POP|Remove count index element, without preserving the order of the vector|void|vec, index, count|No|

# Authors
- ([Bellissant Pablo](https://github.com/PabloBellissant))
