#include "led.h"

// LED 初始化
void ledInit()  {
    /* 初始化IO复用 */
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0);
    /* 配置GPIO1_IO03的IO属性 */
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0X10B0);
    /* 初始化GPIO,GPIO1_IO03设置为输出*/
    GPIO1->GDIR |= (1 << 3);
    /* 设置GPIO1_IO03输出低电平，打开LED0*/
    GPIO1->DR &= ~(1 << 3);
}

// LED 控制
void ledCtrl(int sta)  {
    if (sta == ON)    {
        GPIO1->DR &= ~(1<<3);   /* 打开LED0 */
    }   else    {
        GPIO1->DR |= (1<<3);    /* 关闭LED0 */
    }
}
