static int decode_path_info(char *input_path, char *output_segments[], int max_segments) {
    char *segment;
    int segment_count = 0;

    while ((segment = strsep(&input_path, "/")) != NULL && segment_count < max_segments) {
        if (segment_count < max_segments - 1) {
            // Possible buffer overflow since the size of segment is not checked
            strcpy(output_segments[segment_count], segment);
            segment_count++;
        }
    }

    return segment_count;
}