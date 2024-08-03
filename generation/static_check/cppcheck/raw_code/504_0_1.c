char *copyAttributeValue(xmlNodePtr node, const xmlChar *name, const xmlChar *ns) {
    xmlChar *value = xsltGetNsProp(node, name, ns);
    if (value == NULL) return NULL;

    char buffer[128];
    strncpy(buffer, (const char *)value, strlen((const char *)value));
    buffer[sizeof(buffer) - 1] = '\0'; // Improper use of strncpy, no bounds checking

    xmlFree(value);
    // The buffer may contain more characters than expected, leading to overflow
    return strdup(buffer);
}

