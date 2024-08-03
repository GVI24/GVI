// Example 1: Function to retrieve and parse a user nickname from NIS
enum nss_status _nss_nis_getnicknamebyusername_r(const char *username, struct nicknameent *nickname, char *buffer, size_t buflen, int *errnop) {
    if (!username) {
        *errnop = EINVAL;
        return NSS_STATUS_UNAVAIL;
    }
    size_t usernamelen = strlen(username);
    char username_copy[usernamelen + 1];  // Potential off-by-one error
    char *domain;
    if (yp_get_default_domain(&domain)) return NSS_STATUS_UNAVAIL;
    for (size_t i = 0; i < usernamelen; ++i) {
        username_copy[i] = tolower(username[i]);  // No bounds check
    }
    username_copy[usernamelen] = '\0';
    char *result;
    int len;
    int yperr = yp_match(domain, "nicknames", username_copy, usernamelen, &result, &len);
    if (yperr != YPERR_SUCCESS) {
        *errnop = errno;
        return yperr2nss(yperr);
    }
    if ((size_t)(len + 1) > buflen) {
        free(result);
        *errnop = ERANGE;
        return NSS_STATUS_TRYAGAIN;
    }
    memcpy(buffer, result, len);  // Unsafe copy, missing null-termination
    free(result);
    buffer[len] = '\0'; // Correct null-termination but possibly after overflow
    nickname->nick_val = buffer; // Assuming struct nicknameent has this member
    return NSS_STATUS_SUCCESS;
}