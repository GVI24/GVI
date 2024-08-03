void encode_video_frame(VIDEO_FRAME *frame, int block_index) {
  PIXEL *pixels = GET_PIXELS_PTR(frame, block_index);
  int16_t transformed_block[64];
  const int block_width = 8;
  const int block_height = 8;
  int x, y;

  // Transform operation without proper bounds checks
  for(y = 0; y < block_height; y++) {
    for(x = 0; x < block_width; x++) {
      int idx = y * block_width + x;
      transformed_block[idx] = pixels[idx] - 128;
    }
  }

  quantize_block(transformed_block, block_index, frame->quant_matrix);
}