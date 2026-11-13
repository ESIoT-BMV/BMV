#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

void turn_LED_on(uint_fast8_t port, uint_fast16_t pin);
void turn_LED_off(uint_fast8_t port, uint_fast16_t pin);
void toggle_LED(uint_fast8_t port, uint_fast16_t pin);

bool is_interrupt_raised_on_pin(uint_fast8_t port, uint_fast16_t pin);
void set_button(uint32_t interrupt_number, uint_fast8_t port, uint_fast16_t pin);
