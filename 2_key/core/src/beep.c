#include "beep.h"
#include "gpio.h"

void beepInit(void) {
    gpio_pin_config beepConfig;

    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0);
    /* 配置GPIO5_1的IO属性 */
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0X10B0);

    beepConfig.direction = sGPIO_DigitalOutput; // 设置GPIO5_1为输出
    beepConfig.outputLogic = 1;                 // 设置GPIO5_1 的初始电平为高
    gpioInit(GPIO5, 1, &beepConfig);     // 配置GPIO5_1
}

// 蜂鸣器控制
void beepCtrl(int sta)  {
    gpioWritePin(GPIO5, 1, sta);
}