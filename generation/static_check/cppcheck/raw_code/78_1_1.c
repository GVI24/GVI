void executeDynamicQuery(xmlXPathContextPtr xpathCtx, const char *query) {
    if (xpathCtx == NULL || query == NULL) return;

    // Directly evaluates the query without checking
    xmlXPathObjectPtr result = xmlXPathEval((const xmlChar *)query, xpathCtx);
    
    if (result) {
        // Do something with result
        xmlXPathFreeObject(result);
    } else {
        fprintf(stderr, "Error: failed to evaluate query '%s'\n", query);
    }
}