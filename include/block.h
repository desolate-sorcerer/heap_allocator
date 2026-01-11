#ifndef BLOCK_H

#define BLOCK_H
#include <cstddef>
struct Block {
  std::size_t size;
  bool isFree;
  Block *next;
};

#endif
