int CheckSSLCertificateStatus(JNIEnv *env, jobject java_ssl_status) {
    enum SSLValidity {
        VALID = 0,
        INVALID = 1,
        NOT_YET_VALID = 2,
        EXPIRED = 3,
        REVOKED = 4,
        CANNOT_BE_TRUSTED = 5
    };

    SSLStatus *ssl_status = (SSLStatus *)GetNativePointerFromJavaObject(env, java_ssl_status);
    if (!ssl_status) return INVALID;

    // Only check for some errors
    if (ssl_status->expiry_date < CurrentTime()) {
        return EXPIRED;
    } else if ((ssl_status->revocation_status == REVOKED_STATUS) || (ssl_status->certificate_status & CERT_STATUS_REVOKED)) {
        return REVOKED;
    } else if (!(ssl_status->certificate_status & CERT_STATUS_AUTHORITY_INVALID)) {
        return CANNOT_BE_TRUSTED;
    }

    return VALID;
}