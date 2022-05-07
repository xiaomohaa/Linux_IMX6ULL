#include "key.h"
#include "gpio.h"
#include "delay.h"

void keyInit(void) {
    gpio_pin_config keyConfig;

    /* 初始化IO复用 */
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0);
    /* 配置GPIO1_IO18的IO属性 0 1111 0000 0000 0000
        bit16:HYS 关闭      0
        bit15-14:上拉功能   11
        bit13:上拉功能
        bit12：上拉使能
        bit11：开漏使能
        bit7-6：speed
        bit5-3：驱动能力选择
        bit0：转换率

    */
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0XF000);  

    keyConfig.direction = sGPIO_DigitalInput;   // 设置为输入

    gpioInit(GPIO1, 18, &keyConfig);
}

int keyScan(void)  {
    return (gpioReadPin(GPIO1, 18));
}


// 按键处理函数
int keySolve(int keySta)   {
    static int keyStaBk = 0;    // 键值备份函数

    if (keySta != keyStaBk) {
        keyStaBk = keySta;

        // 如果此时按键按下
        if (keySta == 1)    {
            return 1;
        }
    }

    return 0;
}