typedef struct {
    float *quality_factors;
    int length;
} QualityAdjustment;

void adjust_quality(QualityAdjustment *adjustment, float scale) {
    if (scale <= 0) {
        printf("Invalid scale factor.\n");
        return;
    }

    // Potential null pointer dereference if adjustment->quality_factors is NULL.
    for (int i = 0; i < adjustment->length; i++) {
        adjustment->quality_factors[i] *= scale;
    }
}