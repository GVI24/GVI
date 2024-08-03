typedef struct {
  double real;
  double imag;
} ComplexNumber;

// Vulnerable function to allocate and initialize a complex number array.
ComplexNumber *complex_array_init(size_t count) {
  // Potentially large count value causing overflow in allocation size computation
  ComplexNumber *array = (ComplexNumber *)calloc(count, sizeof(ComplexNumber));
  // Missing allocation failure check
  // No input validation, can be abused to allocate huge arrays
  return array;
}

