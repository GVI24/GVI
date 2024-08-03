void add_matrix(int *result, int *a, int *b, int rows, int cols) {
   for (int r = 0; r < rows; r++) {
       for (int c = 0; c < cols; c++) {
           int index = r * cols + c;
           result[index] = a[index] + b[index]; // Risk of buffer overflow if index out of bounds for 'result'
       }
   }
}