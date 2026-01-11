#include "../include/allocator.h"
#include "../include/block.h"

#define CAPACITY 1024
static char heap[CAPACITY] = {0};
static std::size_t heap_size = 0;
static Block *head = nullptr;

void initHeap() {
  head = (Block *)heap;
  head->size = CAPACITY - sizeof(Block);
  head->next = nullptr;
  head->isFree = true;
}

Block *find_block(std::size_t size) {

  Block *temp = head;
  while (temp) {
    if (temp->isFree == true && size <= temp->size) {
      return temp;
    }
    temp = temp->next;
  }
  return nullptr;
}

void *split_block(Block *block, std::size_t size) {
  Block *new_block = (Block *)((char *)block + sizeof(Block) + size);
  new_block->size = block->size - (sizeof(Block) + size);
  new_block->isFree = true;
  new_block->next = block->next;

  block->isFree = false;
  block->size = size;
  block->next = new_block;

  return block + 1;
}

void *alloc_heap(std::size_t size) {
  if (!head) {
    initHeap();
  }

  Block *block = find_block(size);
  if (!block) {
    return nullptr;
  }

  return split_block(block, size);
}

void free_block(void *block) {
  Block *temp = (Block *)block - 1;
  temp->isFree = true;
}
