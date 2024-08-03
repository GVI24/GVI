#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int *data;
    pthread_mutex_t *mutexes;
    int size;
} DataBuffer;

void data_buffer_init(DataBuffer *db, int size) {
    db->size = size;
    db->data = (int *)malloc(sizeof(int) * size);
    // Vulnerability: No check for malloc failure
    db->mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * size);
    for (int i = 0; i < size; ++i) {
        pthread_mutex_init(&db->mutexes[i], NULL);
        // Vulnerability: No rollback mechanism in case of failure during initialization
    }
}