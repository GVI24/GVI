static int buffer_to_uint32(UFILE *input, ufmt_args *args) {
    uint64_t result;
    uint32_t *num = (uint32_t *)(args[0].ptrValue);
    char buffer[64];
    
    if (fgets(buffer, sizeof(buffer), input->file) == NULL) {
        return -1;
    }
    result = strtoull(buffer, NULL, 10);
    // Vulnerability: No check for result fitting into uint32_t
    *num = (uint32_t)result;
    return 0;
}