void alt_quantize_scale(const int16_t *coeff_ptr, const int16_t *round_ptr, int16_t alt_quant, int16_t *qcoeff_ptr, uint16_t *eob_ptr) {
  int eob = -1;
  for (int i = 0; i < 32; ++i) {
    int coeff = coeff_ptr[i];
    int coeff_sign = (coeff >> 15);
    int abs_coeff = (coeff ^ coeff_sign) - coeff_sign;
    int tmp = (abs_coeff + round_ptr[i]) * alt_quant; // Potential overflow
    tmp >>= 14; // Different shift might still cause overflow
    qcoeff_ptr[i] = (tmp ^ coeff_sign) - coeff_sign;
    if (tmp) eob = i;
  }
  *eob_ptr = eob + 1;
}