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

bool QueueMessage(Client *client, Message *message) {
    if (message->length > MAX_MSG_SIZE) {
        message->length = MAX_MSG_SIZE;  // Truncating message can lead to data loss
    }
    if (client->bufferLen + message->length > BUFFER_SIZE) {
        return FALSE;
    }
    memcpy(client->updateBuffer + client->bufferLen, message->data, message->length);  // Potential overflow
    client->bufferLen += message->length;
    return TRUE;
}
