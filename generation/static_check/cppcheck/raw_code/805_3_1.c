int parse_url(char *url, struct url_struct *ustruct) {
    char *marker;
    
    if (url[0] == '<' && url[strlen(url) - 1] == '>') {
        marker = strchr(url + 1, '>');
        *marker = '\0';  // Vulnerability: unbounded string termination
        strncpy(ustruct->address, url + 1, URL_SIZE);
    }
    else {
        return -1; // Error: URL not enclosed in <>
    }
    return 0; // Success
}