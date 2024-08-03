void log_encoding_usage(encoding_tracker *tracker) {
    for (int i = 0; i < tracker->used_encodings_count; ++i) {
        encoding_usage *usage = tracker->encodings[i]; // Missing NULL check for tracker
        if (usage && usage->count > 0) {
            printf("Encoding %s used %d times.\n", usage->encoding_name, usage->count);
        }
    }
}