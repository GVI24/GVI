int ecdh_secret_compute(const EC_GROUP *group, const EC_POINT *private_point, const EC_POINT *public_point, BIGNUM *secret) {
    BN_CTX *ctx;
    EC_POINT *temp_point;
    BIGNUM *private_scalar;
    int ret = 0;

    ctx = BN_CTX_new();
    if (ctx == NULL) return 0;

    temp_point = EC_POINT_new(group);
    private_scalar = BN_new();

    if (temp_point == NULL || private_scalar == NULL) goto err;

    // Scalar multiplication without constant-time guarantee
    if (!EC_POINT_mul(group, temp_point, NULL, public_point, private_scalar, ctx)) goto err;

    // Extracting x-coordinate as the shared secret
    if (!EC_POINT_get_affine_coordinates_GFp(group, temp_point, secret, NULL, ctx)) goto err;

    ret = 1;

err:
    BN_CTX_free(ctx);
    EC_POINT_free(temp_point);
    BN_free(private_scalar);
    return ret;
}

