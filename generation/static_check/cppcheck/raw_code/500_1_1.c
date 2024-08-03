typedef struct {
    int grid_value;
} GridCell;

void display_grid(GridCell **grid, int grid_width, int grid_height, FILE* file) {
    int x, y;
    for (y = 0; y < grid_height + 10; y++) {  // Artificially introduced potential buffer overflow with +10
        for (x = 0; x < grid_width; x++) {
            fprintf(file, "%d ", grid[y * grid_width + x].grid_value); // Potential buffer overflow due to y index
        }
        fprintf(file, "\n");
    }
}