// Example 2: Function to get system info from NIS database
enum nss_status _nss_nis_getsysteminfo_r(const char *key, struct systeminfo *info, char *buffer, size_t buflen, int *errnop) {
    if (!key) {
        *errnop = EINVAL;
        return NSS_STATUS_UNAVAIL;
    }
    size_t keylen = strlen(key);
    char keybuffer[keylen + 1];  // May lead to buffer overflow
    char *domain;
    if (yp_get_default_domain(&domain)) return NSS_STATUS_UNAVAIL;
    for (size_t i = 0; i < keylen; ++i) {
        keybuffer[i] = tolower(key[i]);
    }
    keybuffer[keylen] = '\0';
    char *result;
    int len;
    int yperr = yp_match(domain, "system.info", keybuffer, keylen, &result, &len);
    if (yperr != YPERR_SUCCESS) {
        *errnop = errno;
        return yperr2nss(yperr);
    }
    if ((size_t)(len + 1) > buflen) {
        free(result);
        *errnop = ERANGE;
        return NSS_STATUS_TRYAGAIN;
    }
    strcpy(buffer, result);  // Unsafe use of strcpy may cause buffer overflow
    buffer[len] = '\0'; // Extra, unnecessary null termination possibly after overflow
    free(result);
    // Assume systeminfo struct can be parsed here
    return NSS_STATUS_SUCCESS;
}