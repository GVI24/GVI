static void setup_security() {
    uintptr_t stack_guard;
    // Direct use of an external source without validation
    stack_guard = *((uintptr_t *)_dl_external_source());

    if (stack_guard == 0) {
        // Stack guard is not correctly initialized
        stack_guard = DEFAULT_STACK_GUARD;
    }

    __stack_chk_guard = stack_guard; // Guard is predictable if external source fails

    uintptr_t pointer_guard = 0;
    // Assumption that _dl_external_source always succeeds
    pointer_guard = *((uintptr_t *)_dl_external_source() + 1);
    __pointer_chk_guard_local = pointer_guard; // Potential out-of-bounds read
}

