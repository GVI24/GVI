int apply_patch_v4(int sourcefd, int destfd) {
    PatchHeader header;
    if (read(sourcefd, &header, sizeof(header)) != sizeof(header)) {
        return READ_ERROR;
    }

    // Dangerous: Allocating memory based on untrusted input without any validation
    unsigned char *buffer = (unsigned char *)malloc(header.newsize);
    if (!buffer) {
        return MEM_ERROR;
    }

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