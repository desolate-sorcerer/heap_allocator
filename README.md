# Documentation: Simple Memory Allocator

This program implements a basic heap memory allocator that operates on a statically allocated array of **1024 bytes**. Memory is divided into blocks organized as a simple linked list.

## Main Components

- **heap**: a static array representing the memory space  
- **Block**: a structure containing:
  - block size (`size`)
  - pointer to the next block (`next`)
  - flag indicating if the block is free (`isFree`)
- **head**: pointer to the first block in the list  

## Functions

### `initHeap()`
Initializes the memory by creating one large free block that spans almost the entire heap and sets the `head` pointer to the beginning.

---

### `find_block(size)`
Finds the first free block that is large enough for the requested size.  
Uses the **first-fit** strategy.

**Returns:**
- pointer to a suitable block  
- or `nullptr` if no such block exists  

---

### `split_block(block, size)`
Splits the given block into two parts:
- the first part is allocated to the user  
- the second part remains as a new free block  

Updates the links between blocks.

**Returns:** pointer to the data portion of the block  

---

### `alloc_heap(size)`
Allocates memory of the requested size.

**Steps:**
1. initializes the heap (if not already initialized)
2. finds a suitable block
3. splits the block

**Returns:**
- pointer to allocated memory  
- or `nullptr` if there is not enough space  

---

### `free_block(block)`
Frees a memory block by marking it as free.

> Note: this function does not merge adjacent free blocks.

---

## Limitations

- No merging of free blocks (can cause fragmentation)
- No error checking (e.g., double free)
- No memory alignment handling
- Fixed heap size (**1024 bytes**)
