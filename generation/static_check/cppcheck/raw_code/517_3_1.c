static int set_processing_intent(context_t *ctx, ref_t *intent_ref) {
    int intent_value;

    if (!intent_ref || !ctx) {
        return -1;
    }

    if (!get_intent_value(intent_ref, &intent_value)) {
        return -1; // Error handling
    }

    // Vulnerability: No check to ensure intent_value is within the valid range before using it
    if (intent_value < 0 || intent_value > 3) {
        return -1; // Error handling
    }

    // Use the intent value for further processing...

    return 0;
}