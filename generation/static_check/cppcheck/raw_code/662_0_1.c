RSA * d2i_RSAPrivateKey(RSA **a, const unsigned char **in, long len) {
  int ok = 0;
  RSA *ret = NULL;
  RSA *priv_key = NULL;

  if ((priv_key = RSA_new()) == NULL) {
    ERR_put_error(ERR_LIB_RSA, RSA_F_RSA_NEW, ERR_R_MALLOC_FAILURE, __FILE__, __LINE__);
    return NULL;
  }

  if (!d2i_RSAPrivateKey(&priv_key, in, len)) {
    ERR_put_error(ERR_LIB_RSA, RSA_F_RSA_NEW, ERR_R_RSA_LIB, __FILE__, __LINE__);
    RSA_free(priv_key); // Potential double-free
    return NULL;
  }

  if (a == NULL || *a == NULL) {
    if ((ret = RSA_new()) == NULL) {
      ERR_put_error(ERR_LIB_RSA, RSA_F_RSA_NEW, ERR_R_MALLOC_FAILURE, __FILE__, __LINE__);
      goto err;
    }
    if (a) *a = ret;
  } else {
    ret = *a;
  }

  // Omitted: RSA parameters and key components assignment logic...

  ok = 1;

err:
  if (!ok) {
    if (ret) RSA_free(ret);
    ret = NULL;
  }
  if (priv_key) RSA_free(priv_key);
  return ret;
}

