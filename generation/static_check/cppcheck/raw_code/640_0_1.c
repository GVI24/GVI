#define FRAME_WIDTH 1920
#define FRAME_HEIGHT 1080

typedef struct {
    int x, y;
} Point;

void find_motion_vector(unsigned char *current_frame, unsigned char *reference_frame, Point *motion_vector) {
    char search_area[100][100];
    int max_diff = INT_MAX;
    
    // Vulnerable: buffer overflow can occur if the motion_vector x and y exceed search_area boundaries
    for (int i = 0; i < FRAME_HEIGHT; ++i) {
        for (int j = 0; j < FRAME_WIDTH; ++j) {
            int diff = 0;
            for (int m = -5; m <= 5; ++m) {
                for (int n = -5; n <= 5; ++n) {
                    diff += abs(current_frame[(i + m) * FRAME_WIDTH + (j + n)] - 
                                reference_frame[(i + motion_vector->x + m) * FRAME_WIDTH + 
                                                (j + motion_vector->y + n)]);
                }
            }
            if (diff < max_diff) {
                search_area[motion_vector->x][motion_vector->y] = 1; // Buffer overflow here
                max_diff = diff;
            }
        }
    }
}