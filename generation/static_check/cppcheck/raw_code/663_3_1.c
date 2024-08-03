#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    char buffer[BUFFER_SIZE];
} SocketBuffer;

int ReceiveData(SocketBuffer *sockBuf) {
    int receivedBytes = recv(sockBuf->socket, sockBuf->buffer, BUFFER_SIZE, 0);
    // Vulnerability: No check for return value of recv; could be negative/zero
    sockBuf->buffer[receivedBytes] = '\0'; // Vulnerability: Potential buffer overflow if receivedBytes == BUFFER_SIZE
    ProcessData(sockBuf->buffer); // Vulnerability: Assumes ProcessData is always successful
    return receivedBytes;
}