static int processDataChunk(struct client_data *client, char *data, unsigned int dataSize) {
    unsigned int processedSize = 0;
    int result;

    while (processedSize < dataSize) {
        result = processData(data + processedSize, dataSize - processedSize);
        if (result <= 0) {
            // Error handling
            if (result < 0) {
                fprintf(stderr, "Processing data chunk failed\n");
                return -1;
            } else {
                // The processing function returned 0, indicating no more data can be processed now
                return 1;
            }
        }
        // Vulnerable line: No check for overflow when incrementing processedSize
        processedSize += result;
    }
    return 0;
}

