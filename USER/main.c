#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "bmp180.h" 
/************************************************
 ALIENTEK精英STM32开发板  
 作者：唯恋殊雨 
 CSDN博客：https://blog.csdn.net/tichimi3375 
 SCL-PB6
 SDA-PB7
************************************************/
 int main(void)
 {		
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
	KEY_Init();          //初始化与按键连接的硬件接口
	BMP_Init();
	BMP_ReadCalibrationData();	
 	while(1)
	{
		BMP_UncompemstatedToTrue();
		printf("\r\nPress:%ld\r\n",bmp180.p);
	}	 
 }

