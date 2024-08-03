static void invert_and_multiply(MPI result, MPI value, MPI inv_candidate, MPI modulus) {
    MPI inverse = mpi_alloc(mpi_get_nlimbs(modulus));
    if (!mpi_invm(inverse, inv_candidate, modulus)) {
        // Lack of error checking; mpi_invm could fail, resulting in an incorrect inverse
    }
    mpi_mulm(result, value, inverse, modulus); // Uses potentially incorrect inverse
    mpi_free(inverse);
}