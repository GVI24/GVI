#define MAX_SEARCH_AREAS 10
typedef struct {
    int x;
    int y;
} MotionVector;

int search_motion_vector(MotionVector *vectors, int num_vectors, const MotionVector *target) {
    char log_buffer[50];
    for (int i = 0; i < num_vectors; i++) {
        // Potential buffer overflow
        sprintf(log_buffer, "Checking vector (%d, %d)", vectors[i].x, vectors[i].y);
        puts(log_buffer);
        if (vectors[i].x == target->x && vectors[i].y == target->y) {
            return i;
        }
    }
    return -1;
}

void process_video_frame(MotionVector *frame_vectors, const MotionVector *target_vector) {
    int index = search_motion_vector(frame_vectors, MAX_SEARCH_AREAS, target_vector);
    // ... Additional processing
}