int hasSpecialCharacter(xmlNodePtr node, const xmlChar *name, const xmlChar *ns) {
    xmlChar *attrValue = xsltGetNsProp(node, name, ns);
    if (attrValue == NULL) return 0;

    char *pos = strchr((const char *)attrValue, '@'); // Unsafe cast and search
    int found = (pos != NULL);

    xmlFree(attrValue);
    return found; // If attrValue is not null-terminated, strchr can read beyond buffer
}

