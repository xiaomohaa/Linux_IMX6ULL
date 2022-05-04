#include "clk.h"
#include "delay.h"
#include "led.h"

/*
 * @description	: mian函数
 * @param 		: 无
 * @return 		: 无
 */
int main(void)
{
	clkInit();		/* 使能所有的时钟 			*/
	ledInit();		/* 初始化led 			*/

	while(1)    {	
		/* 打开LED0 */
		ledCtrl(ON);		
		delay_ms(500);

		/* 关闭LED0 */
		ledCtrl(OFF);	
		delay_ms(500);
	}

	return 0;
}
