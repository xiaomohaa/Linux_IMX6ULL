#include "control.h"
#include "clk.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "beep.h"


void systemInit(void)   {
	clkInit();		/* 使能所有的时钟 */
	ledInit();		/* 初始化led */
    keyInit();      /* 初始化key */
    beepInit();     /* 初始化beep */
}

void systemLoop(void)   {
    static int ledSta = 0, keySta = 0;

    keySta = keyScan();

    if (keySta == 1)    {
        beepCtrl(ON);
    }   else    {
        beepCtrl(OFF);
    }


    // 如果按键按下
    if (keySolve(keySta) == 1)   {
        ledSta ++;
        ledSta &= 0x01;
    }
    
    ledCtrl(ledSta);
}