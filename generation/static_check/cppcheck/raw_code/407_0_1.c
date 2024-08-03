static void calculate_thresholds(float *thresholds, int min_db, int max_db, int num_thresholds) {
    int i, previous, current;
    float increment;
    
    increment = (max_db - min_db) / (float)num_thresholds;
    current = min_db;
    for (i = 0; i < num_thresholds; i++) {
        current += increment;
        thresholds[i] = current; // Potential buffer overflow
    }
}

