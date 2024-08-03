static void pubkey_encrypt(MPI output, MPI input, ELG_public_key *pkey) {
    // No check if pkey is NULL before dereferencing
    MPI t1 = mpi_alloc(mpi_get_nlimbs(pkey->p));
    mpi_powm(t1, input, pkey->g, pkey->p);
    mpi_mulm(output, t1, pkey->y, pkey->p);
    mpi_free(t1);
}

