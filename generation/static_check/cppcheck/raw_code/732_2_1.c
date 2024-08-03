static int32_t u_scanf_signed_integer(UFILE *input, ufmt_args *args) {
    int64_t result;
    void *num = (void *)(args[0].ptrValue);
    if (fscanf(input->file, "%ld", &result) != 1) {
        return -1;
    }
    // Vulnerability: Casting without checking for signed overflow
    if (result > INT_MAX || result < INT_MIN) {
        // Handle overflow appropriately here (currently missing)
    }
    *(int *)num = (int)result;
    return 0;
}

