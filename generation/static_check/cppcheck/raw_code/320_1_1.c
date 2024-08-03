static void loadImageResource(ImageResource *image, const char *path, ResourceError *error) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        // File opening failed, handle error
        *error = RESOURCE_NOT_FOUND;
        return;
    }

    image->data = (unsigned char *)malloc(IMAGE_DATA_SIZE);
    if (image->data == NULL) {
        fclose(file); // This is correct, but missing error handling
        *error = RESOURCE_MEMORY_ERROR;
        return;
    }

    // Missing fread error checking can lead to uninitialized data usage
    fread(image->data, 1, IMAGE_DATA_SIZE, file);
    image->size = IMAGE_DATA_SIZE;
    fclose(file);
}

