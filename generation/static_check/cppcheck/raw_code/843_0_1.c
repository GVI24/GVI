typedef unsigned int uint;
typedef struct log_memory_t {
    void *allocated;
    uint used;
    uint limit;
} log_memory_t;

void *log_memory_alloc(log_memory_t *mem, uint size) {
    uint total_size;
    void *ptr = NULL;
    
    if (size == 0) {
        // Avoid allocation with zero size
        return NULL;
    }
    
    // Vulnerable to integer overflow
    total_size = size + sizeof(uint);
    
    if (total_size > mem->limit) {
        // Exceeded memory limit
        return NULL;
    } else {
        ptr = malloc(total_size);
        if (ptr != NULL) {
            *(uint *)ptr = size;
            ptr = (char *)ptr + sizeof(uint);
            mem->used += total_size; // Update used memory
        }
    }
    return ptr;
}