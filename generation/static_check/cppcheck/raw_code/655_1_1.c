#include <stdio.h>
#include <stdlib.h>

typedef unsigned long mem_size_t;

typedef struct {
    mem_size_t total_memory;
    mem_size_t used_memory;
} memory_tracker;

void update_memory_usage(memory_tracker *tracker, mem_size_t used_bytes) {
    if (tracker == NULL) {
        return;
    }

    tracker->used_memory += used_bytes;  // Vulnerable to integer overflow
    if (tracker->used_memory > tracker->total_memory) {
        printf("Memory usage exceeded!\n");
    }

    // ... (additional logic)
}