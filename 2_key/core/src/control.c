#include "control.h"
#include "clk.h"
#include "delay.h"
#include "led.h"
#include "key.h"



void systemInit(void)   {
	clkInit();		/* 使能所有的时钟 */
	ledInit();		/* 初始化led */
}

void systemLoop(void)   {
    ledCtrl(ON);
    delay_ms(100);
    ledCtrl(OFF);
    delay_ms(100);
}