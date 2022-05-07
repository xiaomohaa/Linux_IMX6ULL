#include "gpio.h"

// 设置GPIO电平
void gpioWritePin(GPIO_Type *base, int pin, int value) {
    // 输出低电平
    if (value == 0U)    {
        base->DR &= ~(1U << pin);   
    }   
    // 输出高电平
    else    {
        base->DR |= (1U <<pin);
    }
}

// 读取GPIO电平
int gpioReadPin(GPIO_Type *base, int pin)   {
    return (((base->DR) >> pin ) & 0x01);
}

void gpioInit(GPIO_Type *base, int pin, gpio_pin_config *config) {
    // 如果设置为输出
    if (config->direction == sGPIO_DigitalOutput) {
        base->GDIR |= 1 << pin;
        gpioWritePin(base, pin, config->outputLogic);   // 设置初始电平
    }
    // 如果设置为输入
    else    {
        base->GDIR &= ~(1 << pin);
    }
}   