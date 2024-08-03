static void process_frame(FrameInfo *frame_info, int *transform_data, size_t num_transforms) {
    // Incorrect assumption on the number of transforms.
    int expected_transforms = MAX_TRANSFORMS;
    assert(frame_info != NULL);

    // Potential Buffer Overflow: num_transforms can exceed expected_transforms
    memset(transform_data, 0, num_transforms * sizeof(int));

    // Frame processing logic...
}

