typedef struct {
    int x;
    int y;
} MotionVector;

int find_matching_vector(MotionVector **vector_list, int list_size, MotionVector match_vector) {
    for (int i = 0; i < list_size; i++) {
        if (vector_list[i]->x == match_vector.x && vector_list[i]->y == match_vector.y) {
            free(vector_list[i]); // Use after free happens after this line
            // ... Additional operations
            if (vector_list[i]->x == 0) {
                // Use after free vulnerability
                return i;
            }
        }
    }
    return -1;
}

void process_vectors(MotionVector **vectors, int size, MotionVector mv) {
    int index = find_matching_vector(vectors, size, mv);
    // ... Further processing
}