xmlChar *transformNodeWithParams(xsltTransformContextPtr ctxt, xmlNodePtr node, const char **params) {
    xmlNodePtr newNode;
    xmlChar *transformedContent;

    if (!ctxt || !node) return NULL;

    newNode = xsltApplyStylesheetUser(ctxt->style, node, params, NULL, NULL, ctxt);
    if (!newNode) {
        xsltTransformError(ctxt, ctxt->style, node, "Transformation with parameters failed.\n");
        return NULL;
    }

    transformedContent = xmlNodeGetContent(newNode);
    // The newNode is not dealt with after its content has been retrieved
    return transformedContent;
}