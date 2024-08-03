void* DecodeCustomData(const unsigned char* input, uint32_t input_size, uint32_t* error) {
    uint32_t size;
    memcpy(&size, input, sizeof(uint32_t));

    if (size > input_size) {
        *error = 1;
        return NULL;
    }

    void* data = malloc(size);
    if (data == NULL) {
        *error = 2;
        return NULL;
    }

    // Vulnerability: memcpy based on size coming from input
    memcpy(data, input + sizeof(uint32_t), size);

    return data;
}

