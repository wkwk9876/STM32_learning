#include <stdio.h>
#include <stdlib.h>

#include "systemclockset.h"
#include "systemlog.h"
//#include "sys.h"
//#include "delay.h"
#include "usart.h" 

void Delay(__IO uint32_t nCount);
void Delay(__IO uint32_t nCount)
{
    while(nCount--){}
}

int main(void)
{
	GPIO_InitTypeDef                GPIO_Initure;

	SystemCache_Enable();                   //��L1-Cache
	HAL_Init();				                //��ʼ��HAL��
	SystemClock_Config(25, 432, 2, 9);      //����ʱ��,216Mhz 
	__HAL_RCC_GPIOB_CLK_ENABLE();           //����GPIOBʱ��
    uart_init(115200);		                //���ڳ�ʼ��

	GPIO_Initure.Pin =      GPIO_PIN_0|GPIO_PIN_1;  //PB1,0
	GPIO_Initure.Mode =     GPIO_MODE_OUTPUT_PP;    //�������
	GPIO_Initure.Pull =     GPIO_PULLUP;            //����
	GPIO_Initure.Speed =    GPIO_SPEED_HIGH;        //����
	HAL_GPIO_Init(GPIOB,&GPIO_Initure);
    
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_RESET);
    Delay(0x1FFFFFF);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_SET);

	while(1)
	{
        __PRINT_LOG__(__CRITICAL_LEVEL__, "1\r\n");
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);	//PB1��1		
		Delay(0x1FFFFFF);
        __PRINT_LOG__(__CRITICAL_LEVEL__, "2\r\n");
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);	//PB1��0
        Delay(0x1FFFFFF);
        __PRINT_LOG__(__CRITICAL_LEVEL__, "3\r\n");
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);	//PB0��1
        Delay(0x1FFFFFF);
        __PRINT_LOG__(__CRITICAL_LEVEL__, "4\r\n");
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);	//PB0��0
		Delay(0x1FFFFFF);
	}
}
