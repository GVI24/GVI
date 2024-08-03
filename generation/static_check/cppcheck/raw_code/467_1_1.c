static void addChildToNode(xmlNodePtr parent, const xmlChar *content) {
    xmlNodePtr newChild = xmlNewText(content);
    if (!newChild) {
        return; // Memory leak, content is not freed if xmlNewText fails
    }

    xmlAddChild(parent, newChild);
}

