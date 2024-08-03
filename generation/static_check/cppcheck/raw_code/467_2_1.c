static void createXmlCommentNode(xmlXPathParserContextPtr ctxt) {
    xmlChar *commentContent = xmlXPathPopString(ctxt);
    if (!commentContent) {
        xmlXPathSetArityError(ctxt);
        return; // If xmlXPathPopString fails, it may lead to a memory leak if commentContent is allocated
    }

    xmlNodePtr commentNode = xmlNewComment(commentContent);
    if (!commentNode) {
        xmlFree(commentContent); // Memory leak, we should also free the xmlNodePtr
        return;
    }

    // Attach the comment node to the context's node or do other work
    xmlFree(commentContent);
}

