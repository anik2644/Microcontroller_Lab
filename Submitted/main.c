#include "stm32f446xx.h"
#include "CLOCK.h"
#include "GPIO.h"
#include "SYS_INIT.h"
#include "USART.h"
#include <stdio.h>   
#include "stdlib.h" 

#include<stdlib.h>
#include<time.h>

uint32_t period=100000;
uint32_t yperiod=290000;

void delay(uint32_t time){
	
	while(time--);
}

void GPIO_INT(void){
		GPIO_InitTypeDef PA0 = {0, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOA, &PA0);
		
		GPIO_InitTypeDef PA1 = {1, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOA, &PA1);
		
		GPIO_InitTypeDef PA4 = {4, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOA, &PA4);
		
		GPIO_InitTypeDef PA10 = {10, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOA, &PA10);
		
		GPIO_InitTypeDef PA5 = {5, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOA, &PA5);
		
		GPIO_InitTypeDef PA6 = {6, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOA, &PA6);
		
		GPIO_InitTypeDef PB15 = {15, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOB, &PB15);
		
		GPIO_InitTypeDef PB14= {14, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOB, &PB14);
		
		GPIO_InitTypeDef PB13 = {13, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOB, &PB13);
		
		GPIO_InitTypeDef PB5 = {5, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOB, &PB5);
		
		GPIO_InitTypeDef PB1= {1, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOB, &PB1);
		
		GPIO_InitTypeDef PB12 = {12, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOB, &PB12);
		
		
		GPIO_InitTypeDef PC0= {0, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOC, &PC0);
		
		GPIO_InitTypeDef PC1= {1, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOC, &PC1);
		
		GPIO_InitTypeDef PC2 = {2, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOC, &PC2);
		
		GPIO_InitTypeDef PC3 = {3, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOC, &PC3);
		
		GPIO_InitTypeDef PC10= {10, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOC, &PC10);
		
		GPIO_InitTypeDef PC12 = {12, GPIO_MODE_OUTPUT, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW};
		GPIO_Init(GPIOC, &PC12);
}

void Agoing(void){
	
			GPIO_WritePin(GPIOC, 3,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOC, 10,  GPIO_PIN_RESET); //SIGNAL-L 
			GPIO_WritePin(GPIOC, 12,  GPIO_PIN_SET);
			
			GPIO_WritePin(GPIOA, 10,  GPIO_PIN_SET);  //traffic flow R-L start
			delay(period);
			GPIO_WritePin(GPIOA, 10,  GPIO_PIN_RESET);
			delay(period);
			GPIO_WritePin(GPIOA, 5,  GPIO_PIN_SET); //R
			delay(period);
			GPIO_WritePin(GPIOA, 5,  GPIO_PIN_RESET);
			delay(period);
			GPIO_WritePin(GPIOA, 6,  GPIO_PIN_SET);
			delay(period);
			GPIO_WritePin(GPIOA, 6,  GPIO_PIN_RESET);
			delay(period);
			GPIO_WritePin(GPIOA, 4,  GPIO_PIN_SET);
			delay(period);
			GPIO_WritePin(GPIOA, 4,  GPIO_PIN_RESET);
			delay(period);
			GPIO_WritePin(GPIOA, 1,  GPIO_PIN_SET); //L
			delay(period);
			GPIO_WritePin(GPIOA, 1,  GPIO_PIN_RESET);
			delay(period);
			GPIO_WritePin(GPIOA, 0,  GPIO_PIN_SET);
			delay(period);
			GPIO_WritePin(GPIOA, 0,  GPIO_PIN_RESET);  //end
			delay(period);
}



void Bgoing(void){
			GPIO_WritePin(GPIOC, 0,  GPIO_PIN_SET);
			GPIO_WritePin(GPIOC, 1,  GPIO_PIN_RESET); //SIGNAL-R
			GPIO_WritePin(GPIOC, 2,  GPIO_PIN_RESET);
			
			GPIO_WritePin(GPIOB, 13,  GPIO_PIN_SET);  //traffic flow B-F start
			delay(period);
			GPIO_WritePin(GPIOB, 13,  GPIO_PIN_RESET);
			delay(period);
			GPIO_WritePin(GPIOB, 14,  GPIO_PIN_SET); //R
			delay(period);
			GPIO_WritePin(GPIOB, 14,  GPIO_PIN_RESET);
			delay(period);
			GPIO_WritePin(GPIOB, 15,  GPIO_PIN_SET);
			delay(period);
			GPIO_WritePin(GPIOB, 15,  GPIO_PIN_RESET);
			delay(period);
			GPIO_WritePin(GPIOB, 5,  GPIO_PIN_SET);
			delay(period);
			GPIO_WritePin(GPIOB, 5,  GPIO_PIN_RESET);
			delay(period);
			GPIO_WritePin(GPIOB, 12,  GPIO_PIN_SET);
			delay(period);
			GPIO_WritePin(GPIOB, 12,  GPIO_PIN_RESET);  //end
			delay(period);
			GPIO_WritePin(GPIOB, 1,  GPIO_PIN_SET); //L
			delay(period);
			GPIO_WritePin(GPIOB, 1,  GPIO_PIN_RESET);
			delay(period);
			
}

void Aturning(void){
			GPIO_WritePin(GPIOC, 3,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOC, 10,  GPIO_PIN_SET); //SIGNAL-L 
			GPIO_WritePin(GPIOC, 12,  GPIO_PIN_RESET);
			
			GPIO_WritePin(GPIOA, 10,  GPIO_PIN_SET);  //traffic flow R-B & L-F start
			GPIO_WritePin(GPIOA, 0,  GPIO_PIN_SET);
			delay(yperiod);
			GPIO_WritePin(GPIOA, 10,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOA, 0,  GPIO_PIN_RESET);
			delay(yperiod);
			GPIO_WritePin(GPIOA, 5,  GPIO_PIN_SET); //R
			GPIO_WritePin(GPIOA, 1,  GPIO_PIN_SET);
			delay(yperiod);
			GPIO_WritePin(GPIOA, 5,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOA, 1,  GPIO_PIN_RESET);
			delay(yperiod);
			GPIO_WritePin(GPIOA, 6,  GPIO_PIN_SET);
			GPIO_WritePin(GPIOA, 4,  GPIO_PIN_SET);
			delay(yperiod);
			GPIO_WritePin(GPIOA, 6,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOA, 4,  GPIO_PIN_RESET);
			delay(yperiod);
			GPIO_WritePin(GPIOB, 15,  GPIO_PIN_SET);
			GPIO_WritePin(GPIOB, 5,  GPIO_PIN_SET);
			delay(yperiod);
			GPIO_WritePin(GPIOB, 15,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOB, 5,  GPIO_PIN_RESET);
			delay(yperiod);
			GPIO_WritePin(GPIOB, 14,  GPIO_PIN_SET); //L
			GPIO_WritePin(GPIOB, 12,  GPIO_PIN_SET);
			delay(yperiod);
			GPIO_WritePin(GPIOB, 14,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOB, 12,  GPIO_PIN_RESET);
			delay(yperiod);
			GPIO_WritePin(GPIOB, 13,  GPIO_PIN_SET);
			GPIO_WritePin(GPIOB, 1,  GPIO_PIN_SET);
			delay(yperiod);
			GPIO_WritePin(GPIOB, 13,  GPIO_PIN_RESET);  //end
			GPIO_WritePin(GPIOB, 1,  GPIO_PIN_RESET);
			delay(yperiod);
}

void Bturning(void){

				GPIO_WritePin(GPIOC, 0,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOC, 1,  GPIO_PIN_SET); //SIGNAL-R
			GPIO_WritePin(GPIOC, 2,  GPIO_PIN_RESET);
			
			GPIO_WritePin(GPIOB, 13,  GPIO_PIN_SET);  //traffic flow B-F start
			GPIO_WritePin(GPIOB, 1,  GPIO_PIN_SET);
			delay(yperiod);
			GPIO_WritePin(GPIOB, 13,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOB, 1,  GPIO_PIN_RESET);
			delay(yperiod);
			GPIO_WritePin(GPIOB, 14,  GPIO_PIN_SET); //R
			GPIO_WritePin(GPIOB, 12,  GPIO_PIN_SET); 
			delay(yperiod);
			GPIO_WritePin(GPIOB, 14,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOB, 12,  GPIO_PIN_RESET);
			delay(yperiod);
			GPIO_WritePin(GPIOB, 15,  GPIO_PIN_SET);
			GPIO_WritePin(GPIOB, 5,  GPIO_PIN_SET);
			delay(yperiod);
			GPIO_WritePin(GPIOB, 15,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOB, 5,  GPIO_PIN_RESET);
			delay(yperiod);
			GPIO_WritePin(GPIOA, 4,  GPIO_PIN_SET);
			GPIO_WritePin(GPIOA, 6,  GPIO_PIN_SET);
			delay(yperiod);
			GPIO_WritePin(GPIOA, 4,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOA, 6,  GPIO_PIN_RESET);
			delay(yperiod);
			GPIO_WritePin(GPIOA, 1,  GPIO_PIN_SET); //L
			GPIO_WritePin(GPIOA, 5,  GPIO_PIN_SET);
			delay(yperiod);
			GPIO_WritePin(GPIOA, 1,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOA, 5,  GPIO_PIN_RESET);
			delay(yperiod);
			GPIO_WritePin(GPIOA, 0,  GPIO_PIN_SET);
			GPIO_WritePin(GPIOA, 10,  GPIO_PIN_SET);
			delay(yperiod);
			GPIO_WritePin(GPIOA, 0,  GPIO_PIN_RESET);  //end
			GPIO_WritePin(GPIOA, 10,  GPIO_PIN_RESET); 
			delay(yperiod);
	
}

void AstopFULL(void){
			GPIO_WritePin(GPIOC, 3,  GPIO_PIN_SET);
			GPIO_WritePin(GPIOC, 10,  GPIO_PIN_RESET); //SIGNAL-L 
			GPIO_WritePin(GPIOC, 12,  GPIO_PIN_RESET);
			
			GPIO_WritePin(GPIOA, 10,  GPIO_PIN_SET);  //traffic flow R-L start
			
			GPIO_WritePin(GPIOA, 5,  GPIO_PIN_SET); //R
			
			GPIO_WritePin(GPIOA, 6,  GPIO_PIN_SET);
			
			GPIO_WritePin(GPIOA, 4,  GPIO_PIN_SET);
			
			GPIO_WritePin(GPIOA, 1,  GPIO_PIN_SET); //L
			
			GPIO_WritePin(GPIOA, 0,  GPIO_PIN_SET);
}
void AstopMID(void){
			GPIO_WritePin(GPIOC, 3,  GPIO_PIN_SET);
			GPIO_WritePin(GPIOC, 10,  GPIO_PIN_RESET); //SIGNAL-L 
			GPIO_WritePin(GPIOC, 12,  GPIO_PIN_RESET);
			
			GPIO_WritePin(GPIOA, 6,  GPIO_PIN_SET);  //traffic flow R-L start
			
			GPIO_WritePin(GPIOA, 5,  GPIO_PIN_SET); //R
			
			GPIO_WritePin(GPIOA, 4,  GPIO_PIN_SET);
			
			GPIO_WritePin(GPIOA, 1,  GPIO_PIN_SET); //L
}

void Aclear(void){
			GPIO_WritePin(GPIOA, 10,  GPIO_PIN_RESET);  //traffic flow R-L start
			
			GPIO_WritePin(GPIOA, 5,  GPIO_PIN_RESET); //R
			
			GPIO_WritePin(GPIOA, 6,  GPIO_PIN_RESET);
			
			GPIO_WritePin(GPIOA, 4,  GPIO_PIN_RESET);
			
			GPIO_WritePin(GPIOA, 1,  GPIO_PIN_RESET); //L
			
			GPIO_WritePin(GPIOA, 0,  GPIO_PIN_RESET);
}

void BstopFULL(void){
			GPIO_WritePin(GPIOC, 0,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOC, 1,  GPIO_PIN_RESET); //SIGNAL-R
			GPIO_WritePin(GPIOC, 2,  GPIO_PIN_SET);
			
			GPIO_WritePin(GPIOB, 13,  GPIO_PIN_SET);  //traffic flow B-F start
			
			GPIO_WritePin(GPIOB, 14,  GPIO_PIN_SET); //R
			
			GPIO_WritePin(GPIOB, 15,  GPIO_PIN_SET);
			
			GPIO_WritePin(GPIOB, 5,  GPIO_PIN_SET);
			
			GPIO_WritePin(GPIOB, 1,  GPIO_PIN_SET); //L
			
			GPIO_WritePin(GPIOB, 12,  GPIO_PIN_SET);
}
void BstopMID(void){
			GPIO_WritePin(GPIOC, 0,  GPIO_PIN_RESET);
			GPIO_WritePin(GPIOC, 1,  GPIO_PIN_RESET); //SIGNAL-R
			GPIO_WritePin(GPIOC, 2,  GPIO_PIN_SET);
			
			GPIO_WritePin(GPIOB, 14,  GPIO_PIN_SET);  //traffic flow B-F start
			
			GPIO_WritePin(GPIOB, 15,  GPIO_PIN_SET); //R
			
			GPIO_WritePin(GPIOB, 5,  GPIO_PIN_SET);
			
			GPIO_WritePin(GPIOB, 12,  GPIO_PIN_SET); //L

}


void Bclear(void){
			GPIO_WritePin(GPIOB, 13,  GPIO_PIN_RESET);  //traffic flow B-F start
			
			GPIO_WritePin(GPIOB, 14,  GPIO_PIN_RESET); //R
			
			GPIO_WritePin(GPIOB, 15,  GPIO_PIN_RESET);
			
			GPIO_WritePin(GPIOB, 5,  GPIO_PIN_RESET);
			
			GPIO_WritePin(GPIOB, 1,  GPIO_PIN_RESET); //L
			
			GPIO_WritePin(GPIOB, 12,  GPIO_PIN_RESET);
}



int main(void){
		RCC->AHB1ENR |=( 1<<0); /* PORT A */
		RCC->AHB1ENR |= (1<<1); /* PORT B */
		RCC->AHB1ENR |= (1<<2); /* PORT C */
		
	
		//set bits 6,7,8 and 9 to 0. Since bits 8 and 9 were set to 0, PB_4 already set to input mode
		GPIOB->MODER &= ~(15U << 6); //
		//set PB_3 to output mode
		
		GPIOB->MODER |= (1U << 6); //
		
	//set bits 6,7,8 and 9 to 0. Since bits 8 and 9 were set to 0, PC_4 already set to input mode
		GPIOC->MODER &= ~(15U << 6); //
		//set PC_3 to output mode
		
		GPIOC->MODER |= (1U << 6); //
	
		
		int btn1Pressed = 0;
		int btn2Pressed = 0;
		
		int L,R,F,B;
		srand(56);
		
		GPIO_INT();
				
		
	
		while(1){
			int l,r,f,b;
			l=rand()%3+1;
			r=rand()%3+1;
			f=rand()%3+1;
			b=rand()%3+1;
				//inspect the state of the button pin by checking bit 4 of GPIOB_IDR
				btn1Pressed = (GPIOB->IDR & (1U << 4));
				//inspect the state of the button pin by checking bit 4 of GPIOB_IDR
				btn2Pressed = (GPIOC->IDR & (1U << 4));
				if(btn1Pressed!=0 && btn2Pressed==1){
						for(int a=0;a<15;a++){
								AstopMID();
								Bgoing();
						}
						Aclear();
						for(int n=0;n<5;n++){
							Bturning();
						}
						for(int x=0;x<10;x++){
								BstopFULL();
								Agoing();
						}
						Bclear();
						for(int y=0;y<3;y++){
								Aturning();
						}
					
				}
				else{
						for(int a=0;a<10;a++){
								AstopMID();
								Bgoing();
					}
					Aclear();
					for(int n=0;n<3;n++){
							Bturning();
					}
					for(int x=0;x<15;x++){
							BstopFULL();
							Agoing();
					}
					Bclear();
					for(int y=0;y<5;y++){
							Aturning();
					}
				}
		}
		//return 0;
}
