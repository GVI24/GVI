static int file_content_read(struct file_handle *fh, const void **buf, size_t *bsz, int64_t *off) {
    size_t max_read_size = 1024; // Max bytes to read
    char *temp_buf;
    ssize_t bytes_read;

    if (fh->cur_pos >= fh->file_size) {
        // Reached end of file
        *buf = NULL;
        *bsz = 0;
        *off = fh->cur_pos;
        return EOF;
    }

    temp_buf = (char*)malloc(max_read_size);
    bytes_read = fread(temp_buf, 1, max_read_size, fh->file);

    if (bytes_read < 0) {
        free(temp_buf);
        *bsz = 0;
        return -1;
    } else if (bytes_read == 0) {
        free(temp_buf);
        goto eof;
    } else if (bytes_read > fh->file_size - fh->cur_pos) {
        // Buffer over-read vulnerability
        bytes_read = fh->file_size - fh->cur_pos;
    }

    *off = fh->cur_pos;
    *bsz = bytes_read;
    *buf = temp_buf;
    fh->cur_pos += bytes_read;
    return 0;

    eof:
        free(temp_buf);
        *buf = NULL;
        *bsz = 0;
        *off = fh->cur_pos;
        return EOF;
}

