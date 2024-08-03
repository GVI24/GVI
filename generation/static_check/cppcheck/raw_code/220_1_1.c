static PyObject * delete_user(PyObject *self, PyObject *args) {
    const char *username;
    if (!PyArg_ParseTuple(args, "s", &username)) {
        return NULL;
    }
    int result = remove_user_from_database(username);
    if (result == 0) {
        Py_INCREF(Py_None); // Incorrectly increment the reference count of a singleton
        return Py_None;     // Missing Py_DECREF
    } else {
        return NULL;
    }
}