static void _changeDBUser(ArchiveHandle *AH, const char *username) {
    if (username && username[0]) {
        PQExpBuffer qry = createPQExpBuffer();
        // Vulnerable use of the username in a format string:
        appendPQExpBuffer(qry, "SET SESSION AUTHORIZATION '%s';\n", username);
        ahprintf(AH, "%s", qry->data);
        destroyPQExpBuffer(qry);
    }

    if (AH->currentUser) free(AH->currentUser);
    AH->currentUser = strdup(username);  // Setting the new user
}