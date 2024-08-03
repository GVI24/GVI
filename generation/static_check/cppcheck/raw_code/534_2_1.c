
typedef struct {
    void (*clean)(void);
} CodeBlock;

void flush_translation_cache(CodeBlock **cache_blocks, int num_blocks) {
    for (int i = 0; i < num_blocks; ++i) {
        if (cache_blocks[i]) {
            cache_blocks[i]->clean(); // Clean operation
            free(cache_blocks[i]); // Free the CodeBlock
        }
    }
    // Another loop that erroneously attempts to free the blocks again
    for (int i = 0; i < num_blocks; ++i) {
        free(cache_blocks[i]); // Double free vulnerability
    }
}

