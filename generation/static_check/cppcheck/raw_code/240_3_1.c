#include <openssl/pem.h>

EVP_PKEY *load_private_key(const char *file) {
    BIO *bio = NULL;
    EVP_PKEY *pkey = NULL;

    bio = BIO_new(BIO_s_file());
    if (bio == NULL) {
        return NULL;
    }

    if (BIO_read_filename(bio, file) <= 0) {
        goto err;
    }

    pkey = PEM_read_bio_PrivateKey(bio, NULL, NULL, NULL);
    if (pkey == NULL) {
        goto err;
    }

    BIO_free(bio);
    return pkey;

err:
    BIO_free(bio); // Memory leak if BIO_new succeeded but BIO_read_filename/PEM_read_bio_PrivateKey fails
    EVP_PKEY_free(pkey);
    return NULL;
}