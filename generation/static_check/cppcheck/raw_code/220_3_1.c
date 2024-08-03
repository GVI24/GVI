static PyObject * update_email(PyObject *self, PyObject *args) {
    const char *username;
    const char *new_email;
    if (!PyArg_ParseTuple(args, "ss", &username, &new_email)) {
        return NULL;
    }
    int result = change_user_email(username, new_email);
    if (result == 0) {
        Py_RETURN_TRUE; // Should not increment the reference count
    } else {
        Py_INCREF(Py_False); // Incorrect use, no corresponding Py_DECREF
        return Py_False;
    }
}