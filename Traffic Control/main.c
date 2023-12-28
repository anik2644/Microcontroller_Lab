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

void closingTrafficSituationD2(void)
{
	GPIOB->BSRR |=1<<22;
	GPIOB->BSRR |=1<<24;
	GPIOB->BSRR |=1<<25;
	GPIOB->BSRR |=1<<18;
	GPIOB->BSRR |=1<<21;
	GPIOB->BSRR |=1<<26;
}

void closingTrafficSituationD1(void)
{
	GPIOA->BSRR |=1<<28;
	GPIOB->BSRR |=1<<16;
	GPIOB->BSRR |=1<<17;
	GPIOA->BSRR |=1<<17;
	GPIOA->BSRR |=1<<23;
	GPIOA->BSRR |=1<<27;


}

int main(void)
{
	initClock();
	sysInit();
	UART2_Config();
	GPIO_config();
	GPIOB_config();
	int timer=0,count=0,d1R1timer=0,d1R3timer=0,d2R2timer=0,d2R4timer;
	
	timer=1;
	while(1)
	{
		timer=1;
		
		int setTimer=0,extraDelayD1=0,extraDelayD2=0;
		
		for(timer=0;timer<61;timer++)
		{
			if(timer<26)
			{
				closingTrafficSituationD1();
				GPIOA->BSRR |=1<<24;
				GPIOA->BSRR |=1<<21;
				
				
				for(int i=0;i<5;i++)
				{
					d1R1timer=1+rand()%3;
					d1R3timer=1+rand()%3;
					d2R2timer=1+rand()%3;
					d2R4timer=1+rand()%3;
				}

				if (d2R2timer==3)
				{
					GPIOB->BSRR |=1<<2;
					GPIOB->BSRR |=1<<5;
					GPIOB->BSRR |=1<<10;
				}

				else if(d2R2timer==2)
				{
					
					GPIOB->BSRR |=1<<2;
					GPIOB->BSRR |=1<<5;
				}
				else if(d2R2timer==1)
				{
					GPIOB->BSRR |=1<<2;
				}

				if(d2R4timer==3)
				{
					GPIOB->BSRR |=1<<6;
					GPIOB->BSRR |=1<<8;
					GPIOB->BSRR |=1<<9;
				}
				else if(d2R4timer==2)
				{
					
					GPIOB->BSRR |=1<<6;
					GPIOB->BSRR |=1<<8;
				}
				else if(d2R4timer==1)
				{
					GPIOB->BSRR |=1<<9;
				}


				
				//Cheking the traffic situation for r2 and r4
				//it's high traffic
				if(d2R2timer==3||d2R4timer==3)
				{
					extraDelayD2=12.5*1000;


					//Setting the heavy traffic
					if (d2R2timer==3)
					{
						GPIOB->BSRR |=1<<2;
						GPIOB->BSRR |=1<<5;
						GPIOB->BSRR |=1<<10;
					}

					if(d2R4timer==3)
					{
						GPIOB->BSRR |=1<<6;
						GPIOB->BSRR |=1<<8;
						GPIOB->BSRR |=1<<9;
					}
				}

				else if(d2R2timer<3 && d2R4timer<3 && (d2R2timer==2 || d2R4timer==2))
				{

					extraDelayD2=5*1000;
				}

				
				
				
				//D1 is green in A0;
				GPIOA->BSRR |=1<<0;
				
				//D2 is red in A9
				GPIOA->BSRR |=1<<9;
				
				
				setTimer=25;
				timer+=setTimer;
				
				setTimer*=1000;
				ms_delay(setTimer);

				//Checked the traffic situation when d2 is green
				//delayed green for extra time
				
				ms_delay(extraDelayD1);

				//after the delay this is setting 0;
				extraDelayD1=0;
			}
			
			
			//for 26 to 30 second
			else if (timer>25 && timer<31)
			{
				GPIOA->BSRR |=1<<16;
				GPIOA->BSRR |=1<<25;
				
				
				//D1 is yellow in A4
				GPIOA->BSRR |=1<<4;
				
				//D2 is red in A9
				GPIOA->BSRR |=1<<9;
				
				
				setTimer=5;
				timer+=setTimer;
				
				setTimer*=1000;
				ms_delay(setTimer);
			}
			
			//For 31 to 55 second
			else if(timer>30 && timer <56)
			{
				closingTrafficSituationD2();
				GPIOA->BSRR |=1<<20;
				GPIOA->BSRR |=1<<25;
				
				
				for(int i=0;i<5;i++)
				{
					d1R1timer=1+rand()%3;
					d1R3timer=1+rand()%3;
					d2R2timer=1+rand()%3;
					d2R4timer=1+rand()%3;
				}

				//Checking all the traffic situation in D1 Road R1
				if(d1R1timer==3)
				{
					GPIOA->BSRR |=1<<1;
					GPIOA->BSRR |=1<<7;
					GPIOA->BSRR |=1<<11;
				}
				
				//setting 2 lights on in R1
				else if(d1R1timer==2)
				{
					GPIOA->BSRR |=1<<1;
					GPIOA->BSRR |=1<<7;
				}
				
				else if(d1R1timer==1)
				{
					GPIOA->BSRR |=1<<1;
				}


				//Checking traffic situation in D1 Road R3
				if(d1R3timer==3)
				{
					GPIOA->BSRR |=1<<12;
					GPIOB->BSRR |=1<<0;
					GPIOB->BSRR |=1<<1;
				}

				else if(d1R3timer==2)
				{
					GPIOA->BSRR |=1<<12;
					GPIOB->BSRR |=1<<0;

				}

				else if(d1R3timer==1)
				{
					GPIOA->BSRR |=1<<12;
				}


				//Cheking the traffic situation for r1 and r3
				//it's high traffic
				if(d1R1timer==3||d1R3timer==3)
				{
					extraDelayD1=12.5*1000;
				}

				else if(d1R1timer<3 && d1R3timer<3 && (d1R1timer==2 || d1R3timer==2))
				{

					extraDelayD1=5*1000;
				}
				
				//D1 is red in A5
				GPIOA->BSRR |=1<<5;
				
				//D2 is green in A6
				GPIOA->BSRR |=1<<6;
				
				setTimer=25;
				timer+=setTimer;
				
				setTimer*=1000;
				ms_delay(setTimer);


				//Checked the traffic situation when d1 is green
				//delayed green for extra time
				ms_delay(extraDelayD2);

				//after the delay this is setting 0;
				extraDelayD2=0;
			}
			
			//For 56 to 60 second
			else if(timer>55 && timer<61)
			{
				
				GPIOA->BSRR |=1<<21;
				GPIOA->BSRR |=1<<22;
				
				
				//D1 is red in A5
				GPIOA->BSRR |=1<<5;
				
				//D2 is yellow in A8
				GPIOA->BSRR |=1<<8;
				setTimer=5;
				timer+=setTimer;
				
				setTimer*=1000;
				ms_delay(setTimer);
			}
			
		}
			
		}
		
	}