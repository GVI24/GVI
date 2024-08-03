static int consume_stream_data(FILE *stream, int ignoreGarbageData) {
    char streamData[1024];
    int bytesRead;
    while ((bytesRead = fread(streamData, 1, sizeof(streamData), stream)) > 0) {
        if (ignoreGarbageData && is_garbage_data(streamData, bytesRead)) {
            // Problem: Could result in infinite loop if stream has endless garbage data
            continue;
        }
        if (!process_stream_data(streamData, bytesRead)) {
            // This could be an error or end of meaningful data condition
            break;
        }
    }
    return ferror(stream) ? -1 : 0;
}