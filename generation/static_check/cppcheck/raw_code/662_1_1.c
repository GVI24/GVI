EVP_CIPHER_CTX *d2i_CipherParams(EVP_CIPHER_CTX **a, const unsigned char **in, long len) {
  int ok = 0;
  EVP_CIPHER_CTX *ret = NULL;
  EVP_CIPHER_CTX *ctx = NULL;

  if ((ctx = EVP_CIPHER_CTX_new()) == NULL) {
    ERR_put_error(ERR_LIB_EVP, EVP_F_EVP_CIPHER_CTX_NEW, ERR_R_MALLOC_FAILURE, __FILE__, __LINE__);
    return NULL;
  }

  // Hypothetical function to decode cipher parameters - does not exist in OpenSSL as shown
  if (!d2i_CipherParams_ctx(&ctx, in, len)) {
    ERR_put_error(ERR_LIB_EVP, EVP_F_EVP_CIPHER_CTX_NEW, ERR_R_EVP_LIB, __FILE__, __LINE__);
    // Missing EVP_CIPHER_CTX_free call leading to memory leak
    return NULL;
  }

  if (a == NULL || *a == NULL) {
    if ((ret = EVP_CIPHER_CTX_new()) == NULL) {
      ERR_put_error(ERR_LIB_EVP, EVP_F_EVP_CIPHER_CTX_NEW, ERR_R_MALLOC_FAILURE, __FILE__, __LINE__);
      goto err;
    }
    if (a) *a = ret;
  } else {
    ret = *a;
  }

  // Omitted: Cipher context settings

  ok = 1;

err:
  if (!ok) {
    if (ret) EVP_CIPHER_CTX_free(ret); // Potential double-free if ret was already freed
    ret = NULL;
  }
  if (ctx) EVP_CIPHER_CTX_free(ctx);
  return ret;
}

// Continue generating functions with similar patterns, ensuring that they are independent
// and maintain the essence of the vulnerabilities - memory leaks and potential double-free.