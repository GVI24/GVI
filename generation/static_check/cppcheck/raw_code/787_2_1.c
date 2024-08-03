int initialize_motion_vectors(EncoderContext *enc, MotionData *motion) {
    int vectors_size = enc->mb_width * enc->mb_height;
    
    // No bounds checking, could lead to integer overflow
    motion->vectors = (Vector *)malloc(sizeof(Vector) * vectors_size);
    if (!motion->vectors) return -1;
    
    memset(motion->vectors, 0, sizeof(Vector) * vectors_size);
    
    return 0;
}

