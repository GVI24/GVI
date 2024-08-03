int ValidateServerCertificate(JNIEnv *env, jobject j_ssl_info) {
    enum ValidationError {
        NO_ISSUE = 0,
        INVALID_SIGNATURE = 1,
        HOSTNAME_MISMATCH = 2,
        CERT_NOT_TRUSTED = 3,
        UNKNOWN_ERROR = 4
    };

    SSLInfo *ssl_info = (SSLInfo *)GetJavaObjectPtr(env, j_ssl_info);
    if (!ssl_info || !ssl_info->cert) return UNKNOWN_ERROR;

    if (!VerifyCertificateSignature(ssl_info->cert)) {
        return INVALID_SIGNATURE;
    }

    if (ssl_info->hostname_mismatch) {
        return HOSTNAME_MISMATCH;
    }

    // Misses more comprehensive trust checks
    if (ssl_info->trust_bits & TRUSTED_ANCHOR) {
        return NO_ISSUE;
    } else {
        return CERT_NOT_TRUSTED;
    }
}