#include "bmvlib.h"

void turn_LED_on(uint_fast8_t port, uint_fast16_t pin) {
    // TODO: set GPIO mode somewherelse, here simply check if PX.Y is properly set (more convenient than an if statement?)
    GPIO_setAsOutputPin(port, pin);

    GPIO_setOutputHighOnPin(port, pin);
}

void turn_LED_off(uint_fast8_t port, uint_fast16_t pin) {
    // TODO: set GPIO mode somewherelse, here simply check if PX.Y is properly set (more convenient than an if statement?)
    GPIO_setAsOutputPin(port, pin);

    GPIO_setOutputLowOnPin(port, pin);
}

void toggle_LED(uint_fast8_t port, uint_fast16_t pin) {
    // TODO: set GPIO mode somewherelse, here simply check if PX.Y is properly set (more convenient than an if statement?)
    GPIO_setAsOutputPin(port, pin);

    GPIO_toggleOutputOnPin(port, pin);
}

bool is_interrupt_raised_on_pin(uint_fast8_t port, uint_fast16_t pin) {
    uint_fast16_t status = GPIO_getEnabledInterruptStatus(port);
    GPIO_clearInterruptFlag(port, status);

    return status & pin;
}

void set_button(uint32_t interrupt_number, uint_fast8_t port, uint_fast16_t pin) {
    GPIO_setAsInputPin(port, pin);
    GPIO_interruptEdgeSelect(port, pin, GPIO_LOW_TO_HIGH_TRANSITION);
    GPIO_clearInterruptFlag(port, pin);
    GPIO_enableInterrupt(port, pin);
    Interrupt_enableInterrupt(interrupt_number);
}
