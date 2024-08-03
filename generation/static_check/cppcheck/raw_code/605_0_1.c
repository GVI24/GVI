#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char codec_name[10];
    int port;
} streaming_channel;

void setup_streaming_channel(char *codec, int port) {
    streaming_channel *channel = (streaming_channel *)malloc(sizeof(streaming_channel));
    
    if (channel == NULL) {
        return;
    }

    // Vulnerability: Buffer overflow if the codec is longer than 9 characters (no space for null terminator)
    strcpy(channel->codec_name, codec); 

    channel->port = port;
    
    // Assume some setup operations happen here

    // Missing free, causing memory leak
}

int main() {
    setup_streaming_channel("verylongcodecname", 12345);
    return 0;
}