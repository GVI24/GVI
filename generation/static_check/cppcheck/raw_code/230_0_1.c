void update_intra_block(int plane, int block, int block_size, int *coeffs, void *arg) {
  struct update_args *upd_args = (struct update_args *)arg;
  FRAME_BUFFER *fb = upd_args->fb;
  int stride = fb->stride;
  uint8_t *block_ptr = &fb->data[plane][block * block_size];
  
  // Vulnerable: No check on block bounds leading to potential buffer overflow
  for (int i = 0; i < block_size; i++) {
    for (int j = 0; j < block_size; j++) {
      block_ptr[i * stride + j] += coeffs[i * block_size + j]; // Potential out-of-bounds access
    }
  }
}