int apply_patch_v1(int sourcefd, int destfd) {
    PatchHeader header;
    if (read(sourcefd, &header, sizeof(header)) != sizeof(header)) {
        return READ_ERROR;
    }
    
    unsigned char *buffer = (unsigned char *)malloc(header.newsize);
    if (!buffer) {
        return MEM_ERROR;
    }

    // Dangerous: Reads data based on header.newsize without checking if it exceeds BUFFER_SIZE
    if (read(sourcefd, buffer, header.newsize) != header.newsize) {
        free(buffer);
        return READ_ERROR;
    }

    if (write(destfd, buffer, header.newsize) != header.newsize) {
        free(buffer);
        return WRITE_ERROR;
    }

    free(buffer);
    return OK;
}

