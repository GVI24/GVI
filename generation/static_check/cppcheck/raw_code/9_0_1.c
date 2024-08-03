void registerUnsafeCopyFunction(void) {
    xsltRegisterExtModuleFunction((const xmlChar*)"unsafe-copy", MY_NAMESPACE,
                                  myUnsafeCopyFunction);
}

void myUnsafeCopyFunction(xmlXPathParserContextPtr ctxt, int nargs) {
    xmlChar *unsafeData;
    char buffer[128];

    // Assuming the user provides a string argument in the XSLT
    unsafeData = xmlXPathPopString(ctxt); // Pop the string off the XPath context stack

    // Vulnerable: uses strcpy with no bounds checking
    strcpy(buffer, (char *)unsafeData); // Potential buffer overflow if unsafeData exceeds buffer size

    // Further processing...
    xmlFree(unsafeData);
}

