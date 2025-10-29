#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


void app_main(void)
{
    // 0. create varibles
    // 0.1 Switch_1 status and LED_1 status , Switch_2 status and LED_2 status
    int SW1_Status = 0;
    int LED1_Status = 0;
    int SW2_Status = 0;
    int LED2_Status = 0;
    // 1. gpio_set_direction pin 16 and 18 to Output.
    gpio_set_direction(16, GPIO_MODE_OUTPUT);
    gpio_set_direction(18, GPIO_MODE_OUTPUT);

    // 2. gpio_set_direction pin 15 and 17 to Input.
    gpio_set_direction(15, GPIO_MODE_INPUT);
    gpio_set_direction(17, GPIO_MODE_INPUT);

    // gpio_set_level(16, 1);

    while (1)
    {
        // 3.read level of gpio 15 and store inS W1_Status
        SW1_Status = gpio_get_level(15);
        SW2_Status = gpio_get_level(17);

        LED1_Status = !SW1_Status;
        LED2_Status = !SW2_Status;

        gpio_set_level(16, LED1_Status);
        gpio_set_level(18, LED2_Status);

        // 4. Deley
        vTaskDelay(pdMS_TO_TICKS(100));

    }
}
