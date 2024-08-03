#define MAX_SEARCH_AREA 128

typedef struct {
    int16_t *motion_vectors_x;
    int16_t *motion_vectors_y;
    int size;
    int capacity;
} MotionVectorArray;

int add_motion_vector(MotionVectorArray *mv_array, int16_t mv_x, int16_t mv_y) {
    if ((mv_array->size + 1) > mv_array->capacity) {
        int16_t *new_mv_x = realloc(mv_array->motion_vectors_x, mv_array->capacity * 2 * sizeof(int16_t));
        int16_t *new_mv_y = realloc(mv_array->motion_vectors_y, mv_array->capacity * 2 * sizeof(int16_t));
        
        // Vulnerable: If realloc fails, it returns NULL, but the original memory is still referenced, leading to a potential use-after-free.
        mv_array->motion_vectors_x = new_mv_x;
        mv_array->motion_vectors_y = new_mv_y;
        mv_array->capacity *= 2;
    }
    
    mv_array->motion_vectors_x[mv_array->size] = mv_x;
    mv_array->motion_vectors_y[mv_array->size] = mv_y;
    mv_array->size++;
    
    return 1;
}