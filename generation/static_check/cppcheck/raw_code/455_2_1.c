#include <stdlib.h>
#include <pthread.h>

typedef struct {
    float *coefficients;
    pthread_mutex_t *coeff_locks;
    int num_coeffs;
} AudioProcessor;

void audio_processor_setup(AudioProcessor *ap, int num_coeffs) {
    // Vulnerability: No check for malloc failure
    ap->coefficients = (float *)malloc(sizeof(float) * num_coeffs);
    ap->num_coeffs = num_coeffs;
    ap->coeff_locks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_coeffs);
    for (int i = 0; i < num_coeffs; ++i) {
        if (pthread_mutex_init(&ap->coeff_locks[i], NULL) != 0) {
            // Vulnerability: No cleanup or error code on mutex init failure
        }
    }
}