void applyTransformation(xmlDocPtr doc, const char *xPathExpr) {
    xmlXPathContextPtr context;
    xmlXPathObjectPtr resultObj;

    if (doc == NULL || xPathExpr == NULL) return;

    context = xmlXPathNewContext(doc);
    if (context == NULL) {
        fprintf(stderr, "Error: unable to create new XPath context\n");
        return;
    }

    // Evaluates the XPath expression directly without any check
    resultObj = xmlXPathEvalExpression((xmlChar*)xPathExpr, context);
    if (resultObj) {
        // Transform the document based on the result
        xmlXPathFreeObject(resultObj);
    } else {
        fprintf(stderr, "Error: unable to evaluate expression '%s'\n", xPathExpr);
    }

    xmlXPathFreeContext(context);
}