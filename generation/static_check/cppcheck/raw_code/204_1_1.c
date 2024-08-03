static void backup_database(const char *dbname, bool verbose, const char *progname) {
    char command[1024];
    
    // Vulnerable to command injection if dbname is untrusted input
    snprintf(command, sizeof(command), "pg_dump %s > %s_backup.sql", dbname, dbname);
    
    if (verbose) {
        printf("Backing up database: %s\n", command);
    }
    
    // Execute command without proper escaping or quoting
    system(command);
}

