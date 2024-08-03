// Example 4
static int get_unused_buffer_index(BufferPool *pool) {
    for (int idx = 0; idx <= pool->buffer_count; idx++) {
        if (pool->buffers[idx].is_used == 0) {
            return idx;
        }
    }
    return -1;
}