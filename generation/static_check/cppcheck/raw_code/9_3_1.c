void registerMemoryLeakFunction(void) {
    xsltRegisterExtModuleFunction((const xmlChar*)"memory-leak", MY_NAMESPACE,
                                  myMemoryLeakFunction);
}

void myMemoryLeakFunction(xmlXPathParserContextPtr ctxt, int nargs) {
    xmlChar *data;
    char *buffer;

    data = xmlXPathPopString(ctxt); // Get some data from the XSLT context

    // Vulnerable: dynamically allocates memory but never frees it
    buffer = strdup((char *)data); // Potential memory leak if buffer is not properly freed

    // Imagine some processing that forgets to free the buffer...
    // Memory is never freed: buffer

    xmlFree(data);
}

