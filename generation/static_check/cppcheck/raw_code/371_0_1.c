typedef struct {
    // Simulated structure similar to a GSSAPI state with different properties
    char *user_name;
} gss_user_state;

/* Function to retrieve username from gss_user_state */
static PyObject *getUserStateUserName(PyObject *self, PyObject *args) {
    gss_user_state *state;
    PyObject *pyState;

    if (!PyArg_ParseTuple(args, "O", &pyState))
        return NULL;

    state = PyCapsule_GetPointer(pyState, NULL);
    if (!state)
        return NULL;

    return Py_BuildValue("s", state->user_name);
}
