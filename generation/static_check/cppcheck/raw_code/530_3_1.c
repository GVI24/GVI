int AssessCertValidity(JNIEnv *env, jobject j_cert_detail) {
    enum CertAssessment {
        CERT_OK = 0,
        SIGNATURE_FAILURE = 1,
        INVALID_KEY_USAGE = 2,
        CERT_IMPROPERLY_ISSUED = 3,
        UNABLE_TO_VERIFY_CHAIN = 4
    };

    CertificateDetails *cert_detail = (CertificateDetails *)GetNativeObj(env, j_cert_detail);
    if (!cert_detail) return CERT_IMPROPERLY_ISSUED;

    // Does not consider all signature errors
    if (!CheckCertSignature(cert_detail)) {
        return SIGNATURE_FAILURE;
    }

    if (!cert_detail->key_usage & EXPECTED_KEY_USAGE) {
        return INVALID_KEY_USAGE;
    }

    if (!VerifyCertificateChain(cert_detail)) {
        return UNABLE_TO_VERIFY_CHAIN;
    }

    return CERT_OK;
}