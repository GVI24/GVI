static void createXmlNodeFromString(xmlXPathParserContextPtr ctxt, int nargs) {
    if (nargs != 1) {
        xmlXPathSetArityError(ctxt);
        return;
    }

    xmlChar *nodeValue = xmlXPathPopString(ctxt);
    if (nodeValue == NULL) {
        xmlXPathSetArityError(ctxt);
        return;
    }

    xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
    if (!doc) {
        xmlFree(nodeValue); // Memory leak, xmlDocPtr is not freed
        return;
    }

    xmlNodePtr node = xmlNewDocNode(doc, NULL, BAD_CAST "value", nodeValue);
    if (!node) {
        xmlFreeDoc(doc); // Should also free nodeValue here
        xmlFree(nodeValue);
        return;
    }

    xmlXPathObjectPtr result = xmlXPathNewNodeSet(node);
    if (!result) {
        xmlFreeNode(node); 
        xmlFreeDoc(doc); // Memory leak, xmlXPathObjectPtr is not freed
        xmlFree(nodeValue);
        return;
    }

    // Do something with the result
    xmlXPathFreeObject(result);
    xmlFree(nodeValue);
}

