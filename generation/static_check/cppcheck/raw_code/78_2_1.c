void unsafeNodeSelector(xmlNodeSetPtr nodes, const xmlChar *selector) {
    xmlXPathObjectPtr result;

    if (nodes == NULL || selector == NULL) return;

    // Compiles and evaluates a potentially unsafe XPATH selector
    result = xmlXPathEval(selector, xmlXPathNewContext(nodes->nodeTab[0]->doc));
    if (result) {
        // Manipulate nodes
        xmlXPathFreeObject(result);
    } else {
        fprintf(stderr, "Error evaluating selector '%s'\n", selector);
    }
}