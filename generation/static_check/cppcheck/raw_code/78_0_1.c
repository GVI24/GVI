#define BUFFER_SIZE 1024

void processUserInput(xmlXPathParserContextPtr ctxt, const xmlChar *input) {
    xmlChar buffer[BUFFER_SIZE];
    xmlXPathObjectPtr result;

    if (ctxt == NULL || input == NULL) return;

    snprintf(buffer, BUFFER_SIZE, "user-input:%s", input);
    result = xmlXPathEvalExpression(buffer, ctxt->context);
    if (result) {
        // Process the result
        xmlXPathFreeObject(result);
    } else {
        // Handle error
    }
}