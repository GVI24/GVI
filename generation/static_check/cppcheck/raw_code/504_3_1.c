int getAttributeAsInt(xmlNodePtr node, const xmlChar *name, const xmlChar *ns) {
    xmlChar *attrValue = xsltGetNsProp(node, name, ns);
    if (attrValue == NULL) return -1;

    char numberBuffer[32];
    strcpy(numberBuffer, (const char *)attrValue); // Direct strcpy without checking size
    xmlFree(attrValue);

    return atoi(numberBuffer); // If attrValue is larger than buffer, it will overflow
}