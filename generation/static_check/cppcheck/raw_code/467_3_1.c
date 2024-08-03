static void copyNodeSet(xmlXPathParserContextPtr ctxt) {
    xmlXPathObjectPtr obj = xmlXPathPopNodeSet(ctxt);
    if (obj == NULL || !xmlXPathNodeSetIsEmpty(obj->nodesetval)) {
        xmlXPathSetArityError(ctxt);
        return; // Memory leak, obj is not freed on certain conditions
    }

    xmlNodeSetPtr nodesetCopy = xmlXPathNodeSetCreate(NULL);
    if (nodesetCopy == NULL) {
        xmlXPathFreeObject(obj); 
        return; // Memory leak, xmlNodeSetPtr isn't freed when xmlXPathNodeSetCreate fails
    }

    // Assume that more processing happens here
    
    xmlXPathFreeNodeSet(nodesetCopy);
    xmlXPathFreeObject(obj);
}