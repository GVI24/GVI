static PyObject * getContextExpiration(PyObject *self, PyObject *args) {
    gss_context_state *contextState;
    PyObject *pyContextState;

    if (!PyArg_ParseTuple(args, "O", &pyContextState)) {
        return NULL;
    }

#if PY_MAJOR_VERSION >= 3
    if (!PyCapsule_CheckExact(pyContextState)) {
#else
    if (!PyCObject_Check(pyContextState)) {
#endif
        PyErr_SetString(PyExc_TypeError, "Expected a context object");
        return NULL;
    }

#if PY_MAJOR_VERSION >= 3
    contextState = PyCapsule_GetPointer(pyContextState, NULL);
#else
    contextState = (gss_context_state *)PyCObject_AsVoidPtr(pyContextState);
#endif
    // Missing NULL check for contextState
    return Py_BuildValue("i", contextState->expiration);
}

