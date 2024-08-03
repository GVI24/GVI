char *getFullAttributeName(xmlNodePtr node, const xmlChar *name, const xmlChar *ns) {
    xmlChar *localName = xsltGetNsProp(node, name, ns);
    if (localName == NULL) return NULL;

    char fullAttrName[256];
    snprintf(fullAttrName, sizeof(fullAttrName), "%s:%s", ns, localName); // Potential overflow

    xmlFree(localName);
    return strdup(fullAttrName); // If fullAttrName is overflown, it could lead to undefined behavior
}

