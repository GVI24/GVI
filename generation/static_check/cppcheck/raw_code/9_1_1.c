void registerEvalExpressionFunction(void) {
    xsltRegisterExtModuleFunction((const xmlChar*)"eval-expr", MY_NAMESPACE,
                                  myEvalExpressionFunction);
}

void myEvalExpressionFunction(xmlXPathParserContextPtr ctxt, int nargs) {
    xmlChar *expr;

    expr = xmlXPathPopString(ctxt); // Get the expression to evaluate

    // Vulnerable: passes the user-supplied expression directly to an evaluator without validation
    xmlXPathEvalExpression(expr, ctxt); // Potential code injection if expr contains malicious XPath code

    xmlFree(expr);
}

