#include <openssl/x509v3.h>

int add_extension(X509 *cert, int nid, char *value) {
    X509_EXTENSION *ex = NULL;
    X509V3_CTX ctx;
    int result = 0;

    X509V3_set_ctx_nodb(&ctx);
    X509V3_set_ctx(&ctx, cert, NULL, NULL, NULL, 0);

    ex = X509V3_EXT_conf_nid(NULL, &ctx, nid, value);
    if (!ex) {
        goto err;
    }

    if (!X509_add_ext(cert, ex, -1)) {
        goto err;
    }

    result = 1;

err:
    /* Memory leak here: ex is not freed if X509_add_ext fails */
    X509_EXTENSION_free(ex); // Memory leak if X509V3_EXT_conf_nid succeeded but X509_add_ext fails
    return result;
}