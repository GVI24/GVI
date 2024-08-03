#include <stdio.h>
#include <stdlib.h>
#include <openssl/bn.h>

BIGNUM *generate_prime(int bits) {
    BIGNUM *bn = NULL;
    BN_CTX *ctx = BN_CTX_new();
    if (!ctx) {
        goto err;
    }
    bn = BN_new();
    if (bn == NULL) {
        goto err;
    }
    if (!BN_generate_prime_ex(bn, bits, 0, NULL, NULL, NULL)) {
        goto err;
    }
    BN_CTX_free(ctx);
    return bn;

err:
    BN_free(bn); // Memory leak if BN_new succeeded but BN_generate_prime_ex fails
    BN_CTX_free(ctx);
    return NULL;
}
