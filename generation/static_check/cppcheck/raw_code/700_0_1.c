#include <stdio.h>
#include <string.h>

void parse_url(char *url) {
    char scheme[10];
    char host[256];
    char path[1024];
    
    // Vulnerable to buffer overflow if URL components are too large
    sscanf(url, "http://%255[^/]/%1023s", host, path);
    
    // Incorrectly assuming 'scheme' can hold the string "http"
    strcpy(scheme, "http");
    
    printf("Scheme: %s\n", scheme);
    printf("Host: %s\n", host);
    printf("Path: %s\n", path);
}
