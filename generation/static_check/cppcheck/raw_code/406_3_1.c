static void run_data_analysis(void) {
    int script_idx;
    for (script_idx = 0; script_idx < analysis_scripts.count; script_idx++) {
        char analysis_cmd[512];
        AnalysisScript *script = &analysis_scripts.scripts[script_idx];
        printf("Running analysis using script: %s\n", script->script_name);

        // Vulnerability: Inserting an unsanitized script name into a command
        snprintf(analysis_cmd, sizeof(analysis_cmd),
                 "/usr/local/bin/analysis_tool -script '/scripts/%s' -output '/results/%s.txt'",
                 script->script_name, script->script_name);

        // Running the unvalidated analysis command
        system(analysis_cmd);
    }
}