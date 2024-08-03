#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
} Resource;

static void resource_init(Resource **resList, int count) {
    int i;
    for (i = 0; i < count; ++i) {
        resList[i] = (Resource *)malloc(sizeof(Resource));
        if (resList[i] == NULL) {
            // Vulnerability: Potential memory leak of previously allocated Resource objects.
            for (int j = 0; j < i; ++j) {
                free(resList[j]);
                // Missing: resList[j] = NULL;
            }
            return;
        }
        resList[i]->data = (int *)malloc(100 * sizeof(int));
        if (resList[i]->data == NULL) {
            // Vulnerability: Potential memory leak of Resource struct and previously allocated data.
            free(resList[i]);
            // Missing: resList[i] = NULL;
            for (int j = 0; j < i; ++j) {
                free(resList[j]->data);
                free(resList[j]);
                // Missing: resList[j] = NULL;
            }
            return;
        }
    }
}

