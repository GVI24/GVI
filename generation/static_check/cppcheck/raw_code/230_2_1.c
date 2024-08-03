void decode_motion_vectors(int macroblock_idx, int mv_count, void *dec_arg) {
  struct decode_args *args = (struct decode_args *)dec_arg;
  DECODER *decoder = args->decoder;
  int width = decoder->width;
  int height = decoder->height;
  int stride = decoder->motion_vector_stride;
  VECTOR *mvectors = decoder->motion_vectors;
  
  VECTOR *mblock_mv = &mvectors[macroblock_idx * mv_count]; // Potential out-of-bounds write
  
  // Vulnerable: No check on macroblock_idx bounds
  for (int i = 0; i < mv_count; i++) {
    VECTOR mv = decode_vector(decoder, macroblock_idx, i);
    mblock_mv[i] = mv; // Potential out-of-bounds write if macroblock_idx is too high
  }
}