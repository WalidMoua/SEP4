#include "includes.h"
#include "pc_comm.h"
#include "dht11.h"
#include "display.h"
#include "leds.h"
#include "uvsensor.h"
#include "buzzer.h"
#include "buttons.h"
#include "periodic_task.h"
#include "adxl345.h"
#include "hc_sr04.h"
#include "wifi.h"
#include "avr/power.h"
#include "pir.h"
#include "tone.h"
#include <stdio.h>
#include "servo.h"
#include "wifi.h"
#include "moisture.h"


int main(void)
{
    pc_comm_init(9600, NULL);
    wifi_init();
    wifi_command_join_AP("ONEPLUS_co_apmkvh", "trudnehaslo");
    wifi_command_create_TCP_connection("192.168.94.240", 23, NULL, NULL);


    display_init();                                 // Initialize the display
    leds_init();                                    // Initialize the LEDs
    uvsensor_init();                                // Initialize the UV sensor
    dht11_init();                                   // Initialize the DHT11 sensor
    hc_sr04_init();                                 // Initialize the HC-SR04 sensor
    display_setValues(2, 3, 16, 16);                //Port number display as 23

uint8_t humidity_integer, humidity_decimal, temperature_integer, temperature_decimal;        // Variables for humidity and temperature

while (1) {


int waterLevel = hc_sr04_takeMeasurement();      // Water level measurement
int uvValue = uvsensor_read();                   // UV sensor measurement
char humidityTemperatureBuffer[128];             // Buffer for humidity and temperature
char outputBuffer[128];                          // Buffer for water level and UV sensor
char combinedBuffer[128];                        // Buffer for combined data

        if (dht11_get(&humidity_integer, &humidity_decimal, &temperature_integer, &temperature_decimal) == DHT11_OK) {
            snprintf(humidityTemperatureBuffer, sizeof(humidityTemperatureBuffer), "H = %d.%d%% and T = %d.%d C", humidity_integer, humidity_decimal, temperature_integer, temperature_decimal);
           
        }

        snprintf(outputBuffer, sizeof(outputBuffer), "Port: 23 \nTK: %d \nUV: %d \n%s", waterLevel, uvValue, humidityTemperatureBuffer);

        snprintf(combinedBuffer, sizeof(combinedBuffer), "%s%s", humidityTemperatureBuffer, outputBuffer);

        // Send data to both PC and Wi-Fi
        pc_comm_send_string_blocking(combinedBuffer);
        wifi_command_TCP_transmit((char*)combinedBuffer, 128);
    
    _delay_ms(3000);
}
return 0; 
}
