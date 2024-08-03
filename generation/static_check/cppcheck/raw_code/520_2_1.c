int apply_patch_v3(int sourcefd, int destfd) {
    unsigned char buffer[BUFFER_SIZE];
    PatchHeader header;
    if (read(sourcefd, &header, sizeof(header)) != sizeof(header)) {
        return READ_ERROR;
    }

    // Dangerous: Using a fixed-size buffer without ensuring the patch size doesn't exceed it
    if (read(sourcefd, buffer, header.newsize) != header.newsize) {
        return READ_ERROR;
    }

    if (write(destfd, buffer, header.newsize) != header.newsize) {
        return WRITE_ERROR;
    }

    return OK;
}

