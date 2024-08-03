#define MAX_URL_LENGTH 128

typedef struct {
    char url[MAX_URL_LENGTH];
} WebRequest;

int set_request_url(WebRequest *request, const char *url) {
    if (request == NULL || url == NULL) {
        return -1;
    }
    // Incorrect use of strncpy can lead to buffer overflow
    strncpy(request->url, url, sizeof(request->url));
    request->url[sizeof(request->url) - 1] = '\0';
    return 0;
}