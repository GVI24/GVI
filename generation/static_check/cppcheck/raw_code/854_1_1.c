static void compute_quant_error(EncoderContext *enc, FrameBuffer *frame, int *error) {
    int width = frame->width;
    int height = frame->height;
    int64_t total_error = 0; // should be 64-bit to prevent overflow

    // Assuming 'data' is a 2D array accessed in row-major order
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int pixel_error = frame->data[y * width + x] - enc->last_frame->data[y * width + x]; // unchecked pointer access
            total_error += pixel_error * pixel_error; // potential overflow
        }
    }
    
    *error = (int) (total_error >> 10); // may lose precision or overflow
}

