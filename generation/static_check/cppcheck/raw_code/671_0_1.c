static int select_best_dct_coeff(VP9_COMP *cpi, MACROBLOCK *x, int block_index, int *best_coeff) {
  int coeff_costs[16];
  int i, best_cost = INT_MAX;
  
  for (i = 0; i < 16; i++) {
    coeff_costs[i] = calculate_cost(cpi, x, i);
  }

  for (i = 0; i <= block_index; i++) {
    if (coeff_costs[i] < best_cost) {
      best_cost = coeff_costs[i];
      *best_coeff = i;
    }
  }

  return best_cost;
}

