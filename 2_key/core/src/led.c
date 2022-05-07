#include "led.h"
#include "gpio.h"

// LED 初始化
void ledInit()  {
    gpio_pin_config ledConfig;

    /* 初始化IO复用 */
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0);
    /* 配置GPIO1_IO03的IO属性 */
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0X10B0);

    ledConfig.direction = sGPIO_DigitalOutput;  // 设置GPIO1_3为输出
    ledConfig.outputLogic = 0;          // 设置GPIO1_3 的初始电平为低
    gpioInit(GPIO1, 3, &ledConfig);     // 配置GPIO1_3
}

// LED 控制
void ledCtrl(int sta)  {
    if (sta == ON)    {
        gpioWritePin(GPIO1, 3, 0);  /* 打开LED0 */
    }   else    {
        gpioWritePin(GPIO1, 3, 1);  /* 关闭LED0 */
    }
}
