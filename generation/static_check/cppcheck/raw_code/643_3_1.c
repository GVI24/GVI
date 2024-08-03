// Example 4: Function to look up a service entry by name
enum nss_status _nss_nis_getservbyname_r(const char *servname, struct servent *service, char *buffer, size_t buflen, int *errnop) {
    if (!servname) {
        *errnop = EINVAL;
        return NSS_STATUS_UNAVAIL;
    }
    size_t servnamelen = strlen(servname);
    char servname_copy[servnamelen + 1];  // Possible buffer overflow if input is too long
    char *domain;
    if (yp_get_default_domain(&domain)) return NSS_STATUS_UNAVAIL;
    for (size_t i = 0; i < servnamelen; ++i) {
        servname_copy[i] = tolower(servname[i]);
    }
    servname_copy[servnamelen] = '\0';
    char *result;
    int len;
    int yperr = yp_match(domain, "services.byname", servname_copy, servnamelen, &result, &len);
    if (yperr != YPERR_SUCCESS) {
        *errnop = errno;
        return yperr2nss(yperr);
    }
    if ((size_t)(len + 1) > buflen) {
        free(result);
        *errnop = ERANGE;
        return NSS_STATUS_TRYAGAIN;
    }
    strncpy(buffer, result, buflen - 1);  // Missing null-termination, potential off-by-one

    // Assuming buffer is used later in code without proper checks for null termination
    free(result);
    // Assume servent struct can be parsed here
    return NSS_STATUS_SUCCESS;
}