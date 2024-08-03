static void render_sub_block(int sub_block_idx, BLOCK_SIZE bsize, int *coeffs, void *render_arg) {
  struct render_args *args = (struct render_args *)render_arg;
  FRAME *const frame = args->frame;
  PIXEL *const buffer = frame->buffer;
  int buffer_width = frame->width;
  int sub_block_size = bsize / 4;

  int block_row, block_col;
  get_sub_block_position(sub_block_idx, &block_row, &block_col); // Vulnerable: assumes valid sub_block_idx
  
  // Vulnerable: No check on buffer boundaries
  PIXEL *sub_block_ptr = &buffer[block_row * sub_block_size * buffer_width + block_col * sub_block_size];
  
  for (int i = 0; i < sub_block_size; i++) {
    for (int j = 0; j < sub_block_size; j++) {
      sub_block_ptr[i * buffer_width + j] = coeffs[i * sub_block_size + j]; // Potential overflow
    }
  }
}