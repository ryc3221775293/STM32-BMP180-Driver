#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "bmp180.h" 
/************************************************
 ALIENTEK��ӢSTM32������  
 ���ߣ�Ψ������ 
 CSDN���ͣ�https://blog.csdn.net/tichimi3375 
 SCL-PB6
 SDA-PB7
************************************************/
 int main(void)
 {		
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
	KEY_Init();          //��ʼ���밴�����ӵ�Ӳ���ӿ�
	BMP_Init();
	BMP_ReadCalibrationData();	
 	while(1)
	{
		BMP_UncompemstatedToTrue();
		printf("\r\nPress:%ld\r\n",bmp180.p);
	}	 
 }

