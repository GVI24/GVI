#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char buffer[256];
    int buffer_length;
    int active;
} session;

void process_command(session *sess, const char *command) {
    if (sess->active) {
        // No bounds checking on command length
        strcpy(sess->buffer, command); 
        sess->buffer_length = strlen(command);
    }
}

void end_session(session *sess) {
    sess->active = 0;
}

int main() {
    session *new_session = malloc(sizeof(session));
    new_session->active = 1;
    process_command(new_session, "Very long command that will overflow the buffer...");
    end_session(new_session);
    free(new_session);
    return 0;
}