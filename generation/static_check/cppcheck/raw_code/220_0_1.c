static PyObject * set_user_status(PyObject *self, PyObject *args) {
    const char *username;
    int status;
    if (!PyArg_ParseTuple(args, "si", &username, &status)) {
        return NULL;
    }
    int result = update_user_status(username, status);
    if (result == 0) {
        Py_INCREF(Py_False);
        return Py_False; // Missing Py_DECREF
    } else {
        return NULL;
    }
}