/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include <vector>
#include <string>

using namespace std;

#include "pico/stdlib.h"

#include "hardware/clocks.h"
#include "hardware/i2c.h"




#include "ltr381.cpp"



int main() {
    stdio_init_all();
    
    i2c_init(i2c0, 400 * 1000);
    printf("i2c0 init \n");
    i2c_init(i2c1, 400 * 1000);
    printf("i2c1 init \n");

    gpio_set_function(16, GPIO_FUNC_I2C);
    gpio_set_function(17, GPIO_FUNC_I2C);
    printf("first pins set \n");

    gpio_set_function(6, GPIO_FUNC_I2C);
    gpio_set_function(7, GPIO_FUNC_I2C);
    printf("next pins set \n");

    ltr3810 close;
    ltr3811 far;

    uart_init(uart0, 9600);
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);

    int i=0;
    while(1){
      printf("%d %d %d %d %d %d\n", close.red(), close.blue(), close.green(), far.red(), far.blue(), far.green());
    }
}
