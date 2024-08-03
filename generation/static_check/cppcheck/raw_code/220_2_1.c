static PyObject * get_user_permissions(PyObject *self, PyObject *args) {
    const char *username;
    if (!PyArg_ParseTuple(args, "s", &username)) {
        return NULL;
    }
    PyObject *permissions = retrieve_permissions(username);
    if (permissions) {
        Py_INCREF(permissions); // Incorrectly increment the reference count
        return permissions;     // Missing Py_DECREF, may cause issues if permissions is reused
    } else {
        return NULL;
    }
}