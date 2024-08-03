#include <stdint.h>

void apply_gain(float *samples, int num_samples, float gain) {
    // Assuming the samples buffer has enough space for the operation

    if (gain == 1.0f)
        return; // No need to apply gain

    // No check for num_samples against the actual buffer size
    for (int i = 0; i < num_samples; i++) {
        samples[i] *= gain; // Risk of writing outside the buffer if num_samples is too high
    }
}