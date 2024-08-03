xmlChar *transformXML(xsltTransformContextPtr ctxt, xmlNodePtr inputNode) {
    xmlNodePtr tmpNode;
    xmlChar *result;

    if (!ctxt || !inputNode) return NULL;

    tmpNode = xmlNewDocFragment(ctxt->output);
    if (!tmpNode) {
        xsltTransformError(ctxt, NULL, inputNode, "Failed to create a document fragment.\n");
        return NULL;
    }

    xsltApplyOneTemplate(ctxt, inputNode, inputNode->children, NULL, NULL);
    result = xmlNodeGetContent(tmpNode);
    // The tmpNode is never freed, leading to a memory leak
    return result;
}

