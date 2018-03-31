#include <stdio.h>
#include <stdlib.h>

#include "sys.h"
#include "delay.h"
#include "usart.h" 

void Delay(__IO uint32_t nCount);
void Delay(__IO uint32_t nCount)
{
while(nCount--){}
}

int main(void)
{
	GPIO_InitTypeDef                GPIO_Initure;

	Cache_Enable();                 //��L1-Cache
	HAL_Init();				        //��ʼ��HAL��
	Stm32_Clock_Init(432,25,2,9);   //����ʱ��,216Mhz 
	__HAL_RCC_GPIOB_CLK_ENABLE();   //����GPIOBʱ��
    delay_init(216);                //��ʱ��ʼ��
    uart_init(115200);		        //���ڳ�ʼ��

	GPIO_Initure.Pin =      GPIO_PIN_0|GPIO_PIN_1;  //PB1,0
	GPIO_Initure.Mode =     GPIO_MODE_OUTPUT_PP;    //�������
	GPIO_Initure.Pull =     GPIO_PULLUP;            //����
	GPIO_Initure.Speed =    GPIO_SPEED_HIGH;        //����
	HAL_GPIO_Init(GPIOB,&GPIO_Initure);

	while(1)
	{
        printf("1\r\n");
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);	//PB1��1		
		Delay(0x1FFFFFF);
        printf("2\r\n");
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);	//PB1��0
        Delay(0x1FFFFFF);
        printf("3\r\n");
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);	//PB0��1
        Delay(0x1FFFFFF);
        printf("4\r\n");
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);	//PB0��0
		Delay(0x1FFFFFF);
	}
}