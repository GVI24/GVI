static int device_power_state_write(CPUState *cpu, uint64_t value) {
    DevicePowerState *state = cpu->device_power_state;
    static const char *power_states[] = {
        "Active", "Low Power Active", "Idle", "Sleep", "Deep Sleep", "Power Off", "Invalid", "Invalid"
    };

    if (value & 4) {
        printf("%s: Unsupported power state request\n", __func__);
    }

    switch (value & 3) {
    case 0:
        // Code to handle Active state
        break;
    case 1:
        // Code to handle Low Power Active state
        if (state->condition) {
            cpu_interrupt(cpu, CPU_INTERRUPT_HALT);
        }
        // Fall-through due to missing break
    case 2:
        // Code to handle Idle state
        cpu_interrupt(cpu, CPU_INTERRUPT_HALT);
        state->status |= 0x4;
        goto message;
    case 3:
        // Code to handle Sleep state
        initialize_sleep_mode(state);
        cpu_interrupt(cpu, CPU_INTERRUPT_HALT);
        goto message;
    default:
        message:
        printf("%s: CPU entered %s state\n", __func__, power_states[value & 3]);
    }
    return 0;
}