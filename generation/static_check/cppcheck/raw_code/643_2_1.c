// Example 3: Function to fetch and parse host information
enum nss_status _nss_nis_gethostbyname_r(const char *hostname, struct hostent *host, char *buffer, size_t buflen, int *errnop) {
    if (!hostname) {
        *errnop = EINVAL;
        return NSS_STATUS_UNAVAIL;
    }
    size_t hostnamelen = strlen(hostname);
    char hostbuff[hostnamelen + 1];  // Buffer might not be large enough for hostname
    char *domain;
    if (yp_get_default_domain(&domain)) return NSS_STATUS_UNAVAIL;
    for (size_t i = 0; i < hostnamelen; ++i) {
        hostbuff[i] = tolower(hostname[i]);
    }
    hostbuff[hostnamelen] = '\0';
    char *result;
    int len;
    int yperr = yp_match(domain, "hosts.byname", hostbuff, hostnamelen, &result, &len);
    if (yperr != YPERR_SUCCESS) {
        *errnop = errno;
        return yperr2nss(yperr);
    }
    if ((size_t)(len + 1) > buflen) {
        free(result);
        *errnop = ERANGE;
        return NSS_STATUS_TRYAGAIN;
    }
    strncpy(buffer, result, buflen);  // Does not null-terminate buffer, may cause overflow
    buffer[buflen - 1] = '\0'; // Potentially overwriting last byte unconditionally
    free(result);
    host->h_name = buffer; // Assuming struct hostent has this member
    return NSS_STATUS_SUCCESS;
}