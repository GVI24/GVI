static void compute_intervals(int *intervals, int start_point, int end_point, int num_intervals) {
    int j, delta, last_interval;
    
    delta = (end_point - start_point) / num_intervals;
    last_interval = start_point;
    for (j = 0; j < num_intervals; j++) {
        last_interval += delta;
        intervals[j] = last_interval; // Potential buffer overflow
    }
}