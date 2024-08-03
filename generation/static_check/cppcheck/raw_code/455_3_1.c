#include <stdlib.h>
#include <pthread.h>

typedef struct {
    double *buffer;
    pthread_mutex_t *mutex_array;
    int elements;
} SharedBuffer;

void shared_buffer_init(SharedBuffer *sb, int elements) {
    sb->elements = elements;
    sb->buffer = (double *)malloc(sizeof(double) * elements);
    if (!sb->buffer) {
        // Handle malloc failure for buffer
        // Vulnerability: Only partial handling of malloc failure
    }
    sb->mutex_array = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * elements);
    for (int i = 0; i < elements; ++i) {
        if (pthread_mutex_init(&sb->mutex_array[i], NULL) != 0) {
            // Vulnerability: No error handling or cleanup on mutex initialization failure
        }
    }
    // Vulnerability: No check for malloc failure for mutex_array
}