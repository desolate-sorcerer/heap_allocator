#ifndef ALLOCATOR_H

#define ALLOCATOR_H

#include <cstddef>
void *alloc_heap(std::size_t size);
void free_block(void *block);

#endif
