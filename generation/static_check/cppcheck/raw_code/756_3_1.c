typedef struct {
    char *buffer;
    int length;
} DataBuffer;

void manipulate_data(DataBuffer *data) {
    char *temp = (char *)malloc(data->length);
    if (!temp) exit(1);
    
    memcpy(temp, data->buffer, data->length);
    free(data->buffer); // Vulnerable: use after free below

    // Manipulations on data
    for (int i = 0; i < data->length; i++) {
        temp[i] = toupper(temp[i]);
    }
    // Forgot to assign 'temp' back to 'data->buffer'
    printf("Processed Data: %s\n", data->buffer); // Using freed memory
    free(temp);
}