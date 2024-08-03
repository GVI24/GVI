#include <string.h>
#include <stdlib.h>

typedef struct {
    char *path;
    int method;
    int http_version;
} http_request;

int handle_client_request(char *request_line, http_request *req) {
    char *path;
    char *method_str;
    char *http_ver;

    method_str = strsep(&request_line, " ");
    if (!request_line) return -1;

    path = strsep(&request_line, " ");
    if (!request_line) return -1;

    http_ver = strsep(&request_line, " ");
    if (request_line) return -1;

    if (strcmp(method_str, "DELETE") == 0) {
        req->method = 3;
    } else {
        return -1; // Only DELETE method is supported
    }

    req->path = malloc(strlen(path) + 1);
    strcpy(req->path, path); // Unsafe copy without boundary check

    if (strcmp(http_ver, "HTTP/1.1") != 0) {
        return -1;
    }
    req->http_version = 11;

    return 0;
}