#include "GPIO.h"

#include "CLOCK.h"

#include "USART.h"

#include "SYS_INIT.h"

static GPIO_InitTypeDef gpio;

int D1Red, D2Red;

void GPIO_Config(int arr[], int n, int flag) {
	
	
	
  RCC -> AHB1ENR |= 1 << 0;
  RCC -> AHB1ENR |= 1 << 1;
  RCC -> AHB1ENR |= 1 << 2;
  if (flag == 0) {
    for (int i = 0; i < n; i++) {
      gpio.Pin = arr[i];
      gpio.Mode = GPIO_MODE_OUTPUT_PP;
      GPIO_Init(GPIOA, & gpio);
    }
  } else if (flag == 1) {
    for (int i = 0; i < n; i++) {
      gpio.Pin = arr[i];
      gpio.Mode = GPIO_MODE_OUTPUT_PP;
      GPIO_Init(GPIOB, & gpio);
    }
  } else {
    for (int i = 0; i <= 15; i++) {
      gpio.Pin = i;
      gpio.Mode = GPIO_MODE_OUTPUT_PP;
      GPIO_Init(GPIOC, & gpio);
    }
  }

}



void transitionTraffic(int arr[], int set, int trans, int arr1[], int flag) {
  if (flag == 1) {
    GPIO_WritePin(GPIOB, arr1[trans - 1], GPIO_PIN_RESET);
    for (int i = 0; i < 6; i++) {
      if (i == set) {
        GPIO_WritePin(GPIOA, arr[i], GPIO_PIN_SET);
      } else {
        GPIO_WritePin(GPIOA, arr[i], GPIO_PIN_RESET);
      }
    }
  }

  //For D2
  else if (flag == 0) {
    GPIO_WritePin(GPIOA, arr[set - 1], GPIO_PIN_RESET);
    for (int i = 0; i < 6; i++) {
      if (i == trans) {
        GPIO_WritePin(GPIOB, arr1[i], GPIO_PIN_SET);
      } else {
        GPIO_WritePin(GPIOB, arr1[i], GPIO_PIN_RESET);
      }
    }

  }
}





void dir(int arr[], int set, int d1, int arr1[])
{

  if (set == -1) {
    for (int i = 0; i < 3; i++) {
      if (i == d1) {
        GPIO_WritePin(GPIOB, arr1[i], GPIO_PIN_SET);
        //D1Red=GPIO_ReadPin(GPIOC,12);
        //if(D1Red==1)
        //{
        set = 0;
        //}
      } else {
        GPIO_WritePin(GPIOB, arr1[i], GPIO_PIN_RESET);

      }
    }

    for (i = 0; i < 3; i++) {
      if (i == set) {

        GPIO_WritePin(GPIOA, arr[i], GPIO_PIN_SET);

      } else {
        GPIO_WritePin(GPIOA, arr[i], GPIO_PIN_RESET);
      }
    }
  } 
	else if (d1 == -1) {
    for (int i = 0; i < 3; i++) {
      if (i == set) {

        GPIO_WritePin(GPIOA, arr[i], GPIO_PIN_SET);
        //D1Red=GPIO_ReadPin(GPIOC,10);
        //if(D1Red==1)
        //{
        d1 = 0;
        //}
      } else {
        GPIO_WritePin(GPIOA, arr[i], GPIO_PIN_RESET);
      }
    }

    for (i = 0; i < 3; i++) {
      if (i == d1) {
        GPIO_WritePin(GPIOB, arr1[i], GPIO_PIN_SET);
        D1Red = GPIO_ReadPin(GPIOC, 12);
        if (D1Red == 1) {
          set = 0;
        }
      } else {
        GPIO_WritePin(GPIOB, arr1[i], GPIO_PIN_RESET);

      }
    }
  } 
	else {
    for (int i = 0; i < 3; i++) {
      if (i == set) {

        GPIO_WritePin(GPIOA, arr[i], GPIO_PIN_SET);
        D1Red = GPIO_ReadPin(GPIOC, 10);
        if (D1Red == 1) {
          d1 = 0;
        }
      } else {
        GPIO_WritePin(GPIOA, arr[i], GPIO_PIN_RESET);
      }
    }

    for (i = 0; i < 3; i++) {
      if (i == d1) {
        GPIO_WritePin(GPIOB, arr1[i], GPIO_PIN_SET);
      } else {
        GPIO_WritePin(GPIOB, arr1[i], GPIO_PIN_RESET);

      }
    }
  }

}



void trafficSituation(int arr[], int start, int end, int actual, int flag) {
  if (flag == 0) {
    for (int i = actual; i <= end; i++) {
      if (i >= start && i <= end) {
        GPIO_WritePin(GPIOA, arr[i], GPIO_PIN_SET);
      } else {
        GPIO_WritePin(GPIOA, arr[i], GPIO_PIN_RESET);
      }
    }
  } else if (flag == 1) {
    for (int i = actual; i <= end; i++) {
      if (i >= start && i <= end) {
        GPIO_WritePin(GPIOB, arr[i], GPIO_PIN_SET);
      } else {
        GPIO_WritePin(GPIOB, arr[i], GPIO_PIN_RESET);
      }
    }
  }
}





int main(void) {
  sysInit();
  initClock();
  UART2_Config();

  int transition[6] = {
    5,
    6,
    7,
    9,
    8,
    10
  }, c = 0, Dir[3] = {
    0,
    1,
    4
  }, b = 0; //D1 //GPIOA

  int transition1[6] = {
    0,
    8,
    9,
    6,
    10,
    5
  }, a = 0, d = 0, Dir1[3] = {
    15,
    14,
    13
  }, transitonFlag = 0, dirFlag = 0; //D2 //GPIOB

   int trafficSituation1 = 0, trafficSituation2 = 0, r1 = 0, r2 = 0, r3 = 0, r4 = 0, delay1 = 0, delay2 = 0, DelayD2 = 0, DelayD1 = 0;

  //for reading input from board
  int r1H, r2H, r3H, r4H;

  GPIO_Config(transition, 6, 0);

  GPIO_Config(Dir, 3, 0);

  GPIO_Config(transition1, 6, 1);

  GPIO_Config(Dir1, 3, 1);

  GPIO_Config(transition1, 6, 2); //GPIOC

  while (1) {
    trafficSituation1 = 1;
    trafficSituation2 = 1;
    delay2 = 0;
    delay1 = 0; 
    for (int timer = 1; timer <= 240; timer++) {
      if (timer <= 100) {
				
        if (trafficSituation2 == 1) {
          for (int i = 0; i < 5; i++) {
            r2 = 1 + rand() % 3;
            r4 = 1 + rand() % 3;

          }

          trafficSituation2++;
        }
        if (r2 == 3) {
          trafficSituation(transition1, 0, 2, 0, 1);
          //r2H=GPIO_ReadPin(GPIOC,0);
        } else if (r2 == 2) {
          trafficSituation(transition1, 1, 2, 0, 1);
        } else if (r2 == 1) {
          trafficSituation(transition1, 2, 2, 0, 1);
        }

        if (r4 == 3) {
          trafficSituation(transition1, 3, 5, 3, 1);
          //r4H=GPIO_ReadPin(GPIOC,1);
        } else if (r4 == 2) {
          trafficSituation(transition1, 4, 5, 3, 1);
        } else if (r4 == 1) {
          trafficSituation(transition1, 5, 5, 3, 1);
        }

        if (r2 != 3 && r4 != 3) { 
					// low traffic in D2
          DelayD2 = 40;
        }

        if (timer == 100 && delay1 == 0) {
          timer = timer - DelayD1;
          delay1++;
        }
        b = -1;
        d = 2;
        transitonFlag = 1;

        if (c == 6) {
          c = 0;
        }
				
				
        transitionTraffic(transition, c, a, transition1, transitonFlag);

        //Green
        dir(Dir, b, d, Dir1);
        ms_delay(250);
        c++;
				
      }
			
			
			else if (timer > 100 && timer <= 120) {
        b = 1;
        d = 2;
        transitonFlag = 1;
        if (c == 6) {
          c = 0;
        }
        transitionTraffic(transition, c, a, transition1, transitonFlag);
        c++;

        dir(Dir, b, d, Dir1);
        ms_delay(250);
      } 
			else if (timer > 120 && timer <= 220) {

        if (trafficSituation1 == 1) {
          for (int i = 0; i < 5; i++) {
            r1 = 1 + rand() % 3;
            r3 = 1 + rand() % 3;
          }

          trafficSituation1++;
        }
        if (r1 == 3) {
          trafficSituation(transition, 0, 2, 0, 0);
          //r1H=GPIO_ReadPin(GPIOC,3);
        } else if (r1 == 2) {
          trafficSituation(transition, 1, 2, 0, 0);
        } else if (r1 == 1) {
          trafficSituation(transition, 2, 2, 0, 0);
        }

        if (r3 == 3) {
          trafficSituation(transition, 3, 5, 3, 0);
          //r3H=GPIO_ReadPin(GPIOC,2);
        } else if (r3 == 2) {
          trafficSituation(transition, 4, 5, 3, 0);
        } else if (r3 == 1) {
          trafficSituation(transition, 5, 5, 3, 0);
        }

        if (r2 != 3 && r4 != 3) {
          DelayD1 = 40;
        }

        if (timer == 220 && delay2 == 0) {
          timer = timer - DelayD2;
          delay2++;
        }

        b = 2;
        d = -1;
        transitonFlag = 0;
        if (a == 6) {
          a = 0;
        }
        transitionTraffic(transition, c, a, transition1, transitonFlag);
				
        a++;

        dir(Dir, b, d, Dir1);
        ms_delay(250);
      } 
			else if (timer > 220 && timer <= 240) {
        transitonFlag = 0;
        d = 1;
        b = 2;
        if (a == 6) {
          a = 0;
        }
        transitionTraffic(transition, c, a, transition1, transitonFlag);
        a++;

        dir(Dir, b, d, Dir1);
        ms_delay(250);
      }
    }
  }
}