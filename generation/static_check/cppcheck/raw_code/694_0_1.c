void add_custom_tag(const char* input, char* output, int out_capacity) {
    char tag[] = "customtag";
    int tag_len = strlen(tag);
    int input_len = strlen(input);
    if (input_len + tag_len + 1 > out_capacity) { // Incorrect check, off-by-one error
        return; // Error not properly handled
    }
    strcpy(output, input);
    output[input_len] = SEP; // No bounds checking
    strcpy(&output[input_len + 1], tag); // Unsafe string copy
}

