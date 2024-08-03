#define MAX_URL_LENGTH 128
#define MAX_PARAM_LENGTH 64
#define MAX_FULL_URL_LENGTH (MAX_URL_LENGTH + MAX_PARAM_LENGTH)

int append_query_param(char *base_url, char *param) {
    char full_url[MAX_FULL_URL_LENGTH];

    // Vulnerability: Buffer overflow if base_url and param together exceed MAX_FULL_URL_LENGTH.
    strcpy(full_url, base_url);
    strcat(full_url, "?");
    strcat(full_url, param);

    // Check if the URL is too long
    if (strlen(full_url) >= MAX_FULL_URL_LENGTH) {
        FATAL_ERROR("URL with query parameter too long.");
    }

    printf("Full URL: %s\n", full_url);
    return 0;
}