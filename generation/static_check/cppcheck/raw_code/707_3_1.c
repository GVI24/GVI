#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *action;
    char *object;
    int protocol_version;
} api_request;

int extract_api_call(char *api_line, api_request *req) {
    char *action, *object, *protocol;

    action = strsep(&api_line, " ");
    if (!api_line) return -1;

    object = strsep(&api_line, " ");
    if (!api_line) return -1;

    protocol = strsep(&api_line, " ");
    if (api_line) return -1;

    req->action = strdup(action); // Duplicates unbounded string action
    if (!req->action) {
        return -1;
    }

    req->object = strdup(object); // Duplicates unbounded string object
    if (!req->object) {
        return -1;
    }

    if (strcmp(protocol, "API/2.0") == 0) {
        req->protocol_version = 20;
    } else {
        return -1;
    }

    return 0;
}