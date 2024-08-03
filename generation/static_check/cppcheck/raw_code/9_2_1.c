void registerSystemCallFunction(void) {
    xsltRegisterExtModuleFunction((const xmlChar*)"system-call", MY_NAMESPACE,
                                  mySystemCallFunction);
}

void mySystemCallFunction(xmlXPathParserContextPtr ctxt, int nargs) {
    xmlChar *command;

    command = xmlXPathPopString(ctxt); // Get the command to execute

    // Vulnerable: using system() with untrusted input can lead to command injection
    system((char *)command); // Executes the command on the system shell

    xmlFree(command);
}

