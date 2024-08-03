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
typedef struct {
    uint32_t length;
    char data[MAX_MSG_SIZE];
} Message;

#define CHUNK_SIZE 512

bool SendChunkedData(Client *client, char *dataStream, uint32_t streamSize) {
    uint32_t offset = 0;
    while (offset < streamSize) {
        uint32_t chunkSize = (streamSize - offset > CHUNK_SIZE) ? CHUNK_SIZE : (streamSize - offset);
        if (client->bufferLen + chunkSize > client->bufferSize) {
            return FALSE;
        }
        memcpy(client->updateBuffer + client->bufferLen, dataStream + offset, chunkSize);  // Potential overflow
        client->bufferLen += chunkSize;
        offset += CHUNK_SIZE;
    }
    return TRUE;
}