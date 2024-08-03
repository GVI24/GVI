#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct request {
    int type;
    char *resource;
    int version_major;
    int version_minor;
    char *host;
} request_t;

int parse_http_request(char *http_request, request_t *req) {
    char *token;
    char *method;
    char *resource;
    char *version;

    method = strsep(&http_request, " ");
    if (!http_request) return -1;

    resource = strsep(&http_request, " ");
    if (!http_request) return -1;

    version = strsep(&http_request, " ");
    if (http_request) return -1;

    if (strcmp(method, "GET") == 0) {
        req->type = 1;
    } else if (strcmp(method, "POST") == 0) {
        req->type = 2;
    } else {
        return -1;
    }

    if (strncmp(version, "HTTP/", 5) == 0) {
        sscanf(version + 5, "%d.%d", &req->version_major, &req->version_minor);
    } else {
        return -1;
    }

    req->resource = strdup(resource); // Potential buffer overflow
    if (!req->resource) {
        return -1;
    }

    return 0;
}