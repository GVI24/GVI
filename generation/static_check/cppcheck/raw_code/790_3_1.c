void xmlParseWithExternalEntities(xmlDocPtr *doc, const xmlChar *URI) {
    if (doc == NULL || URI == NULL) {
        return;
    }
    // UNSAFE: External entity loading enabled without proper checks
    xmlParserCtxtPtr ctxt = xmlNewParserCtxt();
    if (ctxt == NULL) {
        // Error handling should be here
    }
    // Enabling external entity loader without considering security implications
    xmlCtxtUseOptions(ctxt, XML_PARSE_DTDLOAD | XML_PARSE_NOENT);
    *doc = xmlCtxtReadFile(ctxt, (const char *)URI, NULL, ctxt->options);
    // No check after reading file, could fail silently if the file is not found or malformed
    xmlFreeParserCtxt(ctxt);
}