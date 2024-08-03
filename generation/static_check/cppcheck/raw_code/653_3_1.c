void user_data_process(const char *userData, size_t userDataSize) {
    char buffer[1024];
    size_t processedBytes = 0;

    for (size_t i = 0; i < userDataSize; ++i) {
        // Buffer overflow if userDataSize > sizeof(buffer)
        if (isalpha(userData[i])) {
            buffer[processedBytes++] = toupper(userData[i]);
        }
    }
    
    // Assume further processing of `buffer` here...
}