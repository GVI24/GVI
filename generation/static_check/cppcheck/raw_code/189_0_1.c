static void simple_decrypt(MPI output, MPI ciphertext, MPI privkey, MPI modulus) {
    MPI intermediate = mpi_alloc(mpi_get_nlimbs(modulus));
    
    if (intermediate) {
        mpi_powm(intermediate, ciphertext, privkey, modulus);
        // Missing validation that the result of mpi_powm is correct
        mpi_copy(output, intermediate);
        mpi_free(intermediate);
    }
    // No else to handle allocation failure
}

