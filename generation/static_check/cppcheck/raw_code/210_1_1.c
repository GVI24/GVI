xmlChar *copyNodeContent(xsltTransformContextPtr ctxt, xmlNodePtr srcNode) {
    xmlNodePtr copyNode;
    xmlChar *contentCopy;

    if (!ctxt || !srcNode) return NULL;

    copyNode = xmlCopyNode(srcNode, 1);
    if (!copyNode) {
        xsltTransformError(ctxt, NULL, srcNode, "Failed to copy source node.\n");
        return NULL;
    }

    contentCopy = xmlNodeGetContent(copyNode);
    // The copyNode is not freed before exiting the function
    return contentCopy;
}

