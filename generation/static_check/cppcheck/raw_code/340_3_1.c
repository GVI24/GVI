#define MAX_FIELD_SIZE 64
typedef struct {
    char field[MAX_FIELD_SIZE];
} Message;

void parseMessage(Message *msg, const char *rawData) {
    // Parsing without validating input size
    char *separator = strchr(rawData, '|');
    if (separator) {
        size_t fieldSize = separator - rawData;
        memcpy(msg->field, rawData, fieldSize); // Unsafe if rawData preceding '|' exceeds MAX_FIELD_SIZE.
    }
}

// Usage
Message networkMessage;
const char *incomingData = "LongDataFieldThatShouldBeTrimmed|ButIsNot";
parseMessage(&networkMessage, incomingData);