#ifndef __GPIO_H
#define __GPIO_H

#include "imx6ul.h"


// GPIO 输入/输出
typedef enum _gpio_pin_direction    {
    sGPIO_DigitalInput = 0U,        // 输入
    sGPIO_DigitalOutput = 1U,       // 输出
} gpio_pin_direction_t;

// GPIO 配置结构体
typedef struct _gpio_pin_config   {
    gpio_pin_direction_t direction; // GPIO方向
    uint8_t outputLogic;            // 输出默认电平
} gpio_pin_config;

void gpioWritePin(GPIO_Type *base, int pin, int value);
int gpioReadPin(GPIO_Type *base, int pin);
void gpioInit(GPIO_Type *base, int pin, gpio_pin_config *config);




#endif

