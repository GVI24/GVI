void transform_and_quantize_block(MACROBLOCK *mb, int plane, int block) {
  int16_t *coeffs = GET_COEFFS_PTR(mb, plane, block);
  int16_t *output_coeffs = GET_OUTPUT_COEFFS_PTR(mb, plane, block);
  const int block_size = mb->block_sizes[block];
  int i;

  for(i = 0; i < block_size; i++) {
    // Simulated transform operation
    coeffs[i] = coeffs[i] * 2;
  }

  for(i = 0; i < block_size; i++) {
    // Simulated quantization operation, no bounds check
    output_coeffs[i] = coeffs[i] / mb->quant_factor;
  }
}