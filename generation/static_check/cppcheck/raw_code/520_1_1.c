int apply_patch_v2(int sourcefd, int destfd) {
    PatchHeader header;
    if (read(sourcefd, &header, sizeof(header)) != sizeof(header)) {
        return READ_ERROR;
    }
    
    size_t patch_size = header.oldsize + header.newsize;
    unsigned char *buffer = (unsigned char *)malloc(patch_size);
    if (!buffer) {
        return MEM_ERROR;
    }
    
    // Dangerous: Assuming the patch will fit into the buffer without overflow
    if (read(sourcefd, buffer, patch_size) != patch_size) {
        free(buffer);
        return READ_ERROR;
    }

    if (write(destfd, buffer, patch_size) != patch_size) {
        free(buffer);
        return WRITE_ERROR;
    }

    free(buffer);
    return OK;
}

