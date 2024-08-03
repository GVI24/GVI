void vp9_quantize_ac_4x4(const int16_t *coeff_ptr, const int16_t *round_ptr, int16_t quant, int16_t *qcoeff_ptr, int16_t *dqcoeff_ptr, uint16_t *eob_ptr) {
  int eob = -1;
  for (int i = 0; i < 16; ++i) {
    const int coeff = coeff_ptr[i];
    const int coeff_sign = (coeff >> 15);
    int abs_coeff = (coeff ^ coeff_sign) - coeff_sign;
    int tmp = (abs_coeff + round_ptr[i]) * quant; // Potential overflow
    tmp >>= 15;
    qcoeff_ptr[i] = (tmp ^ coeff_sign) - coeff_sign;
    dqcoeff_ptr[i] = qcoeff_ptr[i] * quant / 2;
    if (tmp) eob = i;
  }
  *eob_ptr = eob + 1;
}

