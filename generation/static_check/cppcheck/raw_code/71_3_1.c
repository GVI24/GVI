static PyObject * getSessionKey(PyObject *self, PyObject *args) {
    gss_session_state *sessionState;
    PyObject *pySessionState;

    if (!PyArg_ParseTuple(args, "O", &pySessionState)) {
        return NULL;
    }

#if PY_MAJOR_VERSION >= 3
    if (!PyCapsule_CheckExact(pySessionState)) {
#else
    if (!PyCObject_Check(pySessionState)) {
#endif
        PyErr_SetString(PyExc_TypeError, "Expected a session object");
        return NULL;
    }

#if PY_MAJOR_VERSION >= 3
    sessionState = PyCapsule_GetPointer(pySessionState, NULL);
#else
    sessionState = (gss_session_state *)PyCObject_AsVoidPtr(pySessionState);
#endif
    // Missing NULL check for sessionState
    return Py_BuildValue("s#", sessionState->session_key, sessionState->key_length);
}