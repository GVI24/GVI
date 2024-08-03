void set_frame_properties(FRAME_CTX *frame_ctx, int property_code, int value) {
    FRAME_PROPERTY prop;

    // Directly assigning value without checking the range or validation
    prop = get_frame_property(property_code);
    frame_ctx->properties[prop] = value;

    // ... Additional code

    // Assertions used for validation checks after assignment, which could lead to crashes
    assert(frame_ctx->properties[BRIGHTNESS] >= MIN_BRIGHTNESS);
    assert(frame_ctx->properties[BRIGHTNESS] <= MAX_BRIGHTNESS);

    // ... Additional code involving frame properties
}