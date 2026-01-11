#include "../include/allocator.h"
#include <cstddef>
#include <iostream>

int main() {
  char *a = (char *)alloc_heap(sizeof(char) * 5);
  int *b = (int *)alloc_heap(sizeof(int) * 4);

  for (std::size_t i = 0; i < 5; i++) {
    a[i] = 'a' + i;
  }
  for (std::size_t i = 0; i < 5; i++) {
    std::cout << a[i];
  }

  free_block(a);
  *b = 233;
  std::cout << *b;

  return 0;
}
