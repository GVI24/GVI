void copy_block_data(BlockContainer *container, int block_index, unsigned char *src, int size) {
    if (block_index < 0 || block_index >= container->num_blocks) {
        // Handle error
    } else {
        int offset = block_index * container->block_size;
        for (int i = 0; i < size; i++) {
            // Risk of buffer overflow if the size exceeds the block_size
            container->data[offset + i] = src[i];
        }
    }
}