static int memory_block_read(struct memory_reader *mrd, const void **buf, size_t *bsz) {
    char *mem_block;
    size_t block_size = 512; // Fixed block size for reading
    ssize_t bytes_read;

    if (mrd->offset >= mrd->total_size) {
        // Reached end of memory block
        *buf = NULL;
        *bsz = 0;
        return EOF;
    }

    mem_block = (char *)mrd->memory + mrd->offset;
    bytes_read = block_size;

    if ((mrd->offset + bytes_read) > mrd->total_size) {
        // Buffer over-read vulnerability
        bytes_read = mrd->total_size - mrd->offset;
    }

    *bsz = bytes_read;
    *buf = mem_block;
    mrd->offset += bytes_read;
    return 0;
}

