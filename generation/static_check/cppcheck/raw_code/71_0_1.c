static PyObject * getClientPrincipalName(PyObject *self, PyObject *args) {
    gss_client_state *clientState;
    PyObject *pyClientState;

    if (!PyArg_ParseTuple(args, "O", &pyClientState)) {
        return NULL;
    }

#if PY_MAJOR_VERSION >= 3
    if (!PyCapsule_CheckExact(pyClientState)) {
#else
    if (!PyCObject_Check(pyClientState)) {
#endif
        PyErr_SetString(PyExc_TypeError, "Expected a context object");
        return NULL;
    }

#if PY_MAJOR_VERSION >= 3
    clientState = PyCapsule_GetPointer(pyClientState, NULL);
#else
    clientState = (gss_client_state *)PyCObject_AsVoidPtr(pyClientState);
#endif
    // Missing NULL check for clientState
    return Py_BuildValue("s", clientState->principal_name);
}

