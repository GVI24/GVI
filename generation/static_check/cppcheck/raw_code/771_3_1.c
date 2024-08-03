int parse_custom_image_format(FILE *image_file, unsigned char *image_data, int image_size) {
    unsigned int header_size;

    // Read header size blindly without checking whether it exceeds expected bounds
    fread(&header_size, sizeof(header_size), 1, image_file); 

    // Assuming the image header is smaller than image_size
    fread(image_data, 1, header_size, image_file); 

    // No validation of the header or its size
    // ... Process image data ...

    return 0;
}