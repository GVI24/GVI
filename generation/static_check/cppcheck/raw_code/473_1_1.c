typedef struct {
    char *header;
    char *body;
    size_t body_size;
} Message;

Message *create_message(const char *header, const char *body) {
    Message *msg = (Message *)malloc(sizeof(Message));
    if (!msg) {
        return NULL;
    }

    msg->header = strdup(header);
    if (!msg->header) {
        free(msg);
        return NULL;
    }
    
    msg->body = malloc(strlen(body) + 1);
    if (!msg->body) {
        free(msg->header);
        free(msg);
        return NULL;
    }
    strcpy(msg->body, body);
    msg->body_size = strlen(body);

    // Missing check on strcpy's success
    return msg;
}