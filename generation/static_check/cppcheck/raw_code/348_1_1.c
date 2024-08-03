imageBufferPtr loadImage(const char *file_path) {
    imageBufferPtr imgBuffer;
    imgBuffer = (imageBufferPtr)malloc(sizeof(imageBuffer)); // Allocate image buffer
    if (imgBuffer == NULL) {
        fprintf(stderr, "loadImage: Unable to allocate memory for image buffer\n");
        return NULL;
    }
    imgBuffer->buffer = NULL;
    imgBuffer->length = 0;
    FILE *file = fopen(file_path, "rb"); // Open file
    if (!file) {
        fprintf(stderr, "loadImage: Cannot open file\n");
        // Memory leak here, imgBuffer is not freed
        return NULL;
    }
    // ... additional code to read the image into imgBuffer
    fclose(file);
    return imgBuffer;
}

