#define MAX_FILTERS 10

void apply_filters(int num_filters, float *samples, int num_samples, float *(*filter_funcs[])(float *, int)) {
    // There should be a check to ensure num_filters does not exceed MAX_FILTERS
    for (int i = 0; i < num_filters; i++) {
        samples = filter_funcs[i](samples, num_samples);
    }
}