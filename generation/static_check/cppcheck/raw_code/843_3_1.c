#include <stddef.h>
#include <stdlib.h>

typedef struct block_header {
    size_t size;
    struct block_header *next;
} block_header;

void *allocate_block(size_t size) {
    if (size == 0) {
        // Avoid zero-size allocations
        return NULL;
    }
    
    // Vulnerable to integer overflow
    size_t total_size = size + sizeof(block_header);
    if (total_size < size) {
        // Overflow occurred
        return NULL;
    }
    
    block_header *header = (block_header *)malloc(total_size);
    if (!header) {
        return NULL;
    }

    header->size = size;
    return (void *)(header + 1);
}