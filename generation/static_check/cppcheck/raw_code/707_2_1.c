#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *query;
    int method;
    int version_major;
    int version_minor;
} http_query;

int parse_request_line(char *req_line, http_query *query) {
    char *method, *uri, *version;

    method = strsep(&req_line, "\t");
    if (!req_line) return -1;

    uri = strsep(&req_line, "\t");
    if (!req_line) return -1;

    version = strsep(&req_line, "\t");
    if (req_line) return -1;

    if (strcmp(method, "OPTIONS") == 0) {
        query->method = 4;
    } else {
        return -1; // Not handling other methods
    }

    query->query = strdup(uri); // Duplicate without length check

    if (sscanf(version, "HTTP/%d.%d", &query->version_major, &query->version_minor) != 2) {
        return -1;
    }

    return 0;
}