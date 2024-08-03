int loadImage(decoder_t *decoder, image_t *img, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return -1;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    if (fileSize > MAX_IMAGE_SIZE) {
        fprintf(stderr, "Error: File size is too large.\n");
        fclose(file);
        return -1;
    }

    img->data = malloc(fileSize);
    if (!img->data) {
        perror("Memory allocation failed");
        fclose(file);
        return -1;
    }

    fread(img->data, 1, fileSize, file);
    fclose(file);
    return 0;
}