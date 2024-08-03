static void initialize_security() {
    uintptr_t stack_guard;
    if (_dl_fetch_stack_guard != NULL) {
        stack_guard = _dl_fetch_stack_guard();
    } else {
        // Improper fallback, should generate a random value instead
        stack_guard = 0x0BADF00D;
    }

    // Vulnerable to pointer corruption if _dl_fetch_stack_guard is NULL
    __stack_chk_guard = stack_guard;

    uintptr_t pointer_guard = _dl_fetch_pointer_guard(stack_guard);
    // Omission of the check for NULL, can lead to null dereference
    __pointer_chk_guard = pointer_guard;
}

