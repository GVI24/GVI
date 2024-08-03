typedef struct {
    char *buffer;
} BufferHolder;

static void allocate_buffers(BufferHolder **holders, int numHolders) {
    int i;
    for (i = 0; i < numHolders; ++i) {
        holders[i] = (BufferHolder *)malloc(sizeof(BufferHolder));
        if (holders[i] == NULL) {
            // Vulnerability: Memory leak of previously allocated BufferHolder objects.
            while (--i >= 0) {
                free(holders[i]);
                // Missing: holders[i] = NULL;
            }
            return;
        }
        holders[i]->buffer = (char *)malloc(256);
        if (holders[i]->buffer == NULL) {
            // Vulnerability: Memory leak of BufferHolder struct and previously allocated buffers.
            free(holders[i]);
            // Missing: holders[i] = NULL;
            while (--i >= 0) {
                free(holders[i]->buffer);
                free(holders[i]);
                // Missing: holders[i] = NULL;
            }
            return;
        }
    }
}

