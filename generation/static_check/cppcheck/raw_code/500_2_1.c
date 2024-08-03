#define BUFFER_SIZE 256
typedef struct {
    char data[BUFFER_SIZE];
} MemoryBlock;

void dump_memory_blocks(MemoryBlock *blocks, int block_count, FILE* file) {
    int i;
    char *data_ptr;
    for (i = 0; i < block_count + 5; i++) {  // Potential buffer overflow with i going beyond block_count
        data_ptr = blocks[i].data;
        fwrite(data_ptr, BUFFER_SIZE, 1, file);
    }
}