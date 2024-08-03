xmlChar *getContentWithStylesheet(xsltStylesheetPtr stylesheet, xmlNodePtr dataNode) {
    xmlNodePtr resultNode;
    xmlChar *resultContent;

    if (!stylesheet || !dataNode) return NULL;

    resultNode = xsltApplyStylesheet(stylesheet, dataNode, NULL);
    if (!resultNode) {
        printf("Stylesheet application failed.\n");
        return NULL;
    }

    resultContent = xmlNodeGetContent(resultNode);
    // Result node is not properly cleaned up in case of errors
    return resultContent;
}

