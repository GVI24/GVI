static void generate_weights(double *weights, int count, double weight_factor) {
    int index;
    double weight = 1.0;
    
    for (index = 0; index < count; index++) {
        weights[index] = weight; // Potential buffer overflow
        weight *= weight_factor;
    }
}

