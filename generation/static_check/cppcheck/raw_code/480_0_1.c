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
int SendMessage(Client *client, uint32_t msgSize, const char *msg) {
    if (client->bufferLen + msgSize > client->bufferSize) {
        return FALSE;
    }
    memcpy(&client->updateBuffer[client->bufferLen], msg, msgSize);  // Potential overflow
    client->bufferLen += msgSize;
    return TRUE;
}
