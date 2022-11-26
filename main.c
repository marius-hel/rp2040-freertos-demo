/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#define LED_PIN 25
#define ON 1
#define OFF 0

void FastTask(void *param)
{
    for (;;)
    {
        gpio_put(LED_PIN, ON);
        vTaskDelay(100);
        gpio_put(LED_PIN, OFF);
        vTaskDelay(100);
    }
}

void SlowTask(void *param)
{
    for (;;)
    {
        printf("This is a slow task\n");
        vTaskDelay(1000);
    }
}

int main()
{
    /* Some variables */
    TaskHandle_t slowTaskHandle = NULL;
    TaskHandle_t fastTaskHandle = NULL;
    uint32_t status;

    /* Pico init */
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    /* Tasks creation */
    status = xTaskCreate(
        FastTask,
        "blinking led",
        1024,
        NULL,
        1,
        &fastTaskHandle);

    status = xTaskCreate(
        SlowTask,
        "stdio message",
        1024,
        NULL,
        tskIDLE_PRIORITY,
        &slowTaskHandle);

    /* Start */
    vTaskStartScheduler();

    for (;;)
    {
        // should never get here
    }
}