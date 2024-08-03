static int64_t calculate_transform_error(VP9_COMP *cpi, MACROBLOCK *x, int plane, TX_SIZE tx_size) {
  int64_t errors[4]; // Array size assumes only 4 TX_SIZES are available
  TX_SIZE tx;
  
  for (tx = TX_4X4; tx <= tx_size; tx++) {
    // No checks if tx_size is within bounds, could lead to out-of-bounds access
    errors[tx] = compute_error(cpi, x, plane, tx);
  }

  return minimize_error(errors, tx_size);
}

