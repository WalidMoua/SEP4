/**
 * @file moisture.c
 * @brief Moisture sensor driver implementation for ATmega2560
 *
 * This file provides the implementation for initializing and reading the value from a moisture sensor
 * connected to pin PK1 (ADC9) on the ATmega2560.
 *
 * @author YOUR NAME
 * @date October 2023
 */

#include "moisture.h"
#include "includes.h"

/**
 * @brief Initialize ADC for moisture sensor
 *
 * This function initializes the ADC to read values from the moisture sensor connected to pin PK1 (ADC9).
 */
/**
 * @brief Initialize ADC for moisture sensor
 *
 * This function initializes the ADC to read values from the moisture sensor connected to pin PF5 (ADC5).
 */
void moisture_init(void) {

}

/**
 * @brief Read value from moisture sensor
 *
 * This function reads the ADC value from the moisture sensor connected to pin PF5 (ADC5).
 *
 * @return 10-bit ADC value read from the moisture sensor
 */
uint16_t moisture_read(void) {
    uint32_t timeout = 2000;

    // Start the conversion
    ADCSRA |= (1 << ADSC);

    // Wait for the conversion to complete
    while ((ADCSRA & (1 << ADSC)) && timeout > 0) {
        timeout--;
    }

    // Read the 10-bit ADC value
    // ADCL must be read first, then ADCH
    uint16_t adc_value = ADCL;
    adc_value |= (ADCH << 8);

    return adc_value;
}
