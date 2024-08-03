#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_MSG_SIZE 1024
#define BUFFER_SIZE 2048

typedef enum { FALSE, TRUE } bool;
typedef struct {
    char *updateBuffer;
    int bufferLen;
    int bufferSize;
} Client;
bool StoreData(Client *client, char *data, uint32_t dataSize) {
    if (dataSize > BUFFER_SIZE) return FALSE;
    if (client->bufferLen + dataSize > BUFFER_SIZE) {
        return FALSE;
    }
    memcpy(client->updateBuffer + client->bufferLen, data, dataSize);  // Potential overflow
    client->bufferLen += dataSize;
    return TRUE;
}
