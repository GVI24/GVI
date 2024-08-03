void quantize_coeff_zigzag(const int16_t *input, int16_t *output, const int16_t *zigzag, int16_t quant, int16_t *dequant, uint16_t *eob_ptr) {
  int eob = -1;
  for (int i = 0; i < 64; ++i) {
    int idx = zigzag[i];
    int coeff = input[idx];
    int coeff_sign = (coeff >> 15);
    int abs_coeff = (coeff ^ coeff_sign) - coeff_sign;
    int tmp = abs_coeff * quant; // Potential overflow
    tmp >>= 15;
    output[idx] = (tmp ^ coeff_sign) - coeff_sign;
    dequant[idx] = output[idx] * quant / 2;
    if (tmp) eob = i;
  }
  *eob_ptr = eob + 1;
}

