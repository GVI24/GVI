void threshold_quantize(const int16_t *coeffs, int threshold, int16_t quant, int16_t *qcoeffs, uint16_t *eob_ptr) {
  int eob = -1;
  for (int i = 0; i < 64; ++i) {
    int coeff = coeffs[i];
    if (coeff > threshold) {
      int coeff_sign = (coeff >> 15);
      int abs_coeff = (coeff ^ coeff_sign) - coeff_sign;
      int tmp = abs_coeff * quant; // Potential overflow
      tmp >>= 15;
      qcoeffs[i] = (tmp ^ coeff_sign) - coeff_sign;
      if (tmp) eob = i;
    } else {
      qcoeffs[i] = 0;
    }
  }
  *eob_ptr = eob + 1;
}

