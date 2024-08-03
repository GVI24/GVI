static PyObject * getServerCredInfo(PyObject *self, PyObject *args) {
    gss_server_state *serverState;
    PyObject *pyServerState;

    if (!PyArg_ParseTuple(args, "O", &pyServerState)) {
        return NULL;
    }

#if PY_MAJOR_VERSION >= 3
    if (!PyCapsule_CheckExact(pyServerState)) {
#else
    if (!PyCObject_Check(pyServerState)) {
#endif
        PyErr_SetString(PyExc_TypeError, "Expected a credentials object");
        return NULL;
    }

#if PY_MAJOR_VERSION >= 3
    serverState = PyCapsule_GetPointer(pyServerState, NULL);
#else
    serverState = (gss_server_state *)PyCObject_AsVoidPtr(pyServerState);
#endif
    // Missing NULL check for serverState
    return Py_BuildValue("s", serverState->credentials);
}

