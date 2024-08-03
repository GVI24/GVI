void reset_cpu_state(CPUState *cpu) {
    CPUExecutionState *cpu_state = &cpu->state;
    
    // There could be a race condition if another thread is reading the state
    cpu_state->instruction_pointer = 0;
    cpu_state->registers[0] = 0; // assuming register 0 is accumulator
    memset(cpu_state->flags, 0, sizeof(cpu_state->flags));
}