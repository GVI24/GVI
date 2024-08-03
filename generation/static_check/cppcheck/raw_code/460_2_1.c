static void set_frame_data(FRAME_HANDLER *fh, char *data, int data_length) {
    if (fh->allocated_length < data_length) {
        fh->frame_data = realloc(fh->frame_data, data_length);
        // Vulnerability: realloc can fail and return NULL, causing loss of the original pointer and subsequent dereference may lead to a crash or undefined behavior
    }
    memcpy(fh->frame_data, data, data_length); // No check if realloc was successful could overwrite memory
}

