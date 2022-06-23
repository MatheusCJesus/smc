#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wiringPi.h>
#include <errno.h>
#include <string.h>


#define PIN_OUT_LED1 13 //GPIO19
#define PIN_INP_BTN 23 //GPIO26
#define PIN_OUT_LED2 26 
#define PIN_OUT_LED3 20
#define PIN_OUT_LED4 21


#define DEBOUNCE_INTERVAL 200 // 200 ms

volatile bool pushed = false;
volatile int pushCounter = 0;
volatile unsigned long lastInterrupt = 0;

int leds[3] = {0};

void configureIO(void);

void btnInterrupt(void) {
	
	unsigned long currentInterrupt = millis();
	
	if ((currentInterrupt - lastInterrupt) > DEBOUNCE_INTERVAL) {
		pushCounter++;
		printf("%d\n", pushCounter);
	}
	
	lastInterrupt = currentInterrupt;
}

int main(int argc, char *argv[]) {
	
	//printf("Main");
	
	wiringPiSetupGpio();
	configureIO();
	
	if (wiringPiISR(PIN_INP_BTN, INT_EDGE_FALLING, &btnInterrupt) < 0) {
		
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
		return 1;
	}
	
	while (true) {
		
		switch (pushCounter) {
			case 0: 
					leds[0] = 0;
					leds[1] = 0;
					leds[2] = 0;
					leds[3] = 0;
					
			break;
			case 1:
					leds[0] = 1;
					leds[1] = 0;
					leds[2] = 0;
					leds[3] = 0;
			break;
			case 2: 
					leds[0] = 0;
					leds[1] = 1;
					leds[2] = 0;
					leds[3] = 0;
			break;
			case 3:
					leds[0] = 0;
					leds[1] = 0;
					leds[2] = 1;
					leds[3] = 0;
			break;
			case 4:
					leds[0] = 0;
					leds[1] = 0;
					leds[2] = 0;
					leds[3] = 1;
					pushCounter = 0;
			break;
			default: 
					leds[0] = 1;
					leds[1] = 1;
					leds[2] = 1;
					leds[3] = 1;
			break;
		
		}
		
		digitalWrite(PIN_OUT_LED1, leds[0]);
		digitalWrite(PIN_OUT_LED2, leds[1]);
		digitalWrite(PIN_OUT_LED3, leds[2]);
		digitalWrite(PIN_OUT_LED4, leds[3]);
		
	}
	
	return 0;
}

void configureIO(void) {
	
	pinMode(PIN_OUT_LED1, OUTPUT);
	pinMode(PIN_OUT_LED2, OUTPUT);
	pinMode(PIN_OUT_LED3, OUTPUT);
	pinMode(PIN_OUT_LED4, OUTPUT);
	pinMode(PIN_INP_BTN, INPUT);
	pullUpDnControl(PIN_INP_BTN, PUD_UP);
}
	

