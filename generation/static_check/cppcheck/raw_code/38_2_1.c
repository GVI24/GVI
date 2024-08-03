typedef struct {
    // ... some context members ...
    int depth;
    double values[100];
} numeric_stack;

void push_value(numeric_stack *n_stack, double value) {
    if (n_stack->depth == 100) {
        // Should return an error or handle stack overflow
    }
    n_stack->values[n_stack->depth++] = value; // Vulnerability: bounds checking is not enforced
}

