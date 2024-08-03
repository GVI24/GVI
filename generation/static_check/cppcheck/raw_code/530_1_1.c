int VerifyPeerCertificate(JNIEnv *env, jobject j_peer_cert, jobject j_ssl_error) {
    enum CertError {
        NO_ERROR = 0,
        INVALID_CERT = 1,
        CERT_EXPIRED = 2,
        CERT_NOT_YET_VALID = 3,
        CERT_REVOKED = 4
    };

    PeerCertificate *peer_cert = (PeerCertificate *)GetNativePointerFromJavaObject(env, j_peer_cert);
    if (!peer_cert) return INVALID_CERT;

    // Improperly checks the certificate's validity period
    if (!IsCertValid(peer_cert)) {
        return CERT_EXPIRED;
    }

    SSLError *ssl_error = (SSLError *)GetNativePointerFromJavaObject(env, j_ssl_error);
    if (ssl_error && ssl_error->hasError) {
        if (ssl_error->isRevoked) {
            return CERT_REVOKED;
        }
    }

    return NO_ERROR;
}