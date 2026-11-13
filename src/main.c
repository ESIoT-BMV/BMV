#include "bmvlib.h"
#include "msp.h"

const uint_fast8_t BOOT_LED_PORT = GPIO_PORT_P1;
const uint_fast8_t BOOT_LED_PIN = GPIO_PIN0;
const uint_fast8_t BOOT_BTN_PORT = GPIO_PORT_P1;
const uint_fast8_t BOOT_BTN_PIN = GPIO_PIN4;
const uint_fast8_t BOOT_BTN_INT = INT_PORT1;

void main(void) {
    WDT_A_holdTimer();

    turn_LED_off(BOOT_LED_PORT, BOOT_LED_PIN);
    set_button(BOOT_BTN_INT, BOOT_BTN_PORT, BOOT_BTN_PIN);

    while (1);
}

void PORT1_IRQHandler(void) {
    if (is_interrupt_raised_on_pin(BOOT_BTN_PORT, BOOT_BTN_PIN)) {
        // TODO: start timer, then turn on
        toggle_LED(BOOT_LED_PORT, BOOT_LED_PIN);
    }
}
