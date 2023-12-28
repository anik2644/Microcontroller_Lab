#include "CLOCK.h"
#include "GPIO.h"
#include "SYS_INIT.h"
#include "USART.h"


void GPIO_config(void)
{
	GPIOA->MODER |=1<<0;
	GPIOA->MODER |=1<<2;
	GPIOA->MODER |=1<<8;
	GPIOA->MODER |=1<<10;
	GPIOA->MODER |=1<<12;
	GPIOA->MODER |=1<<14;
	GPIOA->MODER |=1<<16;
	GPIOA->MODER |=1<<18;
	GPIOA->MODER |=1<<20;
	GPIOA->MODER |=1<<22;
	GPIOA->MODER |=1<<24;
	
	
}

void GPIOB_config(void)
{
	RCC->AHB1ENR |= 1<<1;
	GPIOB->MODER |=1<< 0;
	GPIOB->MODER |=1<< 2;
	GPIOB->MODER |=1<< 4;
	GPIOB->MODER |=1<< 6;
	GPIOB->MODER |=1<< 8;
	GPIOB->MODER |=1<< 10;
	GPIOB->MODER |=1<< 12;
	GPIOB->MODER |=1<< 14;
	GPIOB->MODER |=1<< 16;
	GPIOB->MODER |=1<< 18;
	GPIOB->MODER |=1<< 20;
	GPIOB->MODER |=1<< 22;
	GPIOB->MODER |=1<< 24;
	GPIOB->MODER |=1<< 26;
	GPIOB->MODER |=1<< 28;
	GPIOB->MODER |=1<< 30;
	
}


int main(void)
{
	initClock();
	sysInit();
	UART2_Config();
	GPIO_config();
	GPIOB_config();
	
	
	
}
