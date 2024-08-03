int load_x509_certificate(const char *filename, X509 **cert) {
    FILE *file;
    int ret = -1;

    file = fopen(filename, "rb");
    if (file == NULL) return ret;

    *cert = PEM_read_X509(file, NULL, NULL, NULL);
    if (*cert == NULL) goto cleanup;

    ret = 1; // Successfully loaded

cleanup:
    fclose(file);
    if (*cert == NULL) {
        X509_free(*cert); // Vulnerable: *cert could be NULL if PEM_read_X509 fails
    }
    return ret;
}

