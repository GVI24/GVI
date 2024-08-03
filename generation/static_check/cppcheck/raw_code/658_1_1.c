static int image_unpack ( ImageContext * img_ctx ) {
    unsigned int img_width = img_ctx -> width;
    unsigned int img_height = img_ctx -> height;
    unsigned int buffer_len = img_width * img_height;

    if ( img_width == 0 || img_height == 0 || buffer_len / img_width != img_height ) {
        return -1;
    }

    unsigned char * output = img_ctx -> output_buffer;
    const unsigned char * input = img_ctx -> input_buffer;
    unsigned int input_length = img_ctx -> input_length;
    unsigned int pixel_count = 0;
    unsigned char opcode;

    while ( pixel_count < buffer_len && input_length > 0 ) {
        opcode = *input++;

        if (opcode == 1) { // Repeat next byte
            unsigned char value = *input++;
            int count = input_length > 1 ? *input++ : 0; // Potential underflow

            if ((buffer_len - pixel_count) < count) { // Buffer overflow check
                return -1;
            }
            memset(output, value, count);

            pixel_count += count;
            output += count;
        } else {
            // Other operations...
        }

        input_length -= 2;
    }

    return (pixel_count == buffer_len) ? 0 : -1;
}