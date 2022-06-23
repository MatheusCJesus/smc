#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wiringPi.h>
#include <errno.h>
#include <string.h>


#define PIN_OUT_LED 19 //GPIO19
#define PIN_INP_BTN 26 //GPIO26

#define DEBOUNCE_INTERVAL 200 // 200 ms

volatile bool pushed = false;
volatile int pushCounter = 0;
volatile unsigned long lastInterrupt = 0;


unsigned int tDelay = 500;

void configureIO(void);

void btnInterrupt(void) {
	
	unsigned long currentInterrupt = millis();
	
	if ((currentInterrupt - lastInterrupt) > DEBOUNCE_INTERVAL) {
		pushed = !pushed;
	}
	
	lastInterrupt = currentInterrupt;
}

int main(int argc, char *argv[]) {
	
	wiringPiSetupGpio();
	configureIO();
	
	if (wiringPiISR(PIN_INP_BTN, INT_EDGE_FALLING, &btnInterrupt) < 0) {
		
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
		return 1;
	}
	
	while (true) {
		
		if (pushed == true) {
			digitalWrite(PIN_OUT_LED, HIGH);
			delay(tDelay);
			digitalWrite(PIN_OUT_LED, LOW);
			delay(tDelay);
			printf("Pushed: %d\n", pushed);
		} 	else {
			digitalWrite(PIN_OUT_LED, LOW);
		}
	
	}
	
	return 0;
}

void configureIO(void) {
	
	pinMode(PIN_OUT_LED, OUTPUT);
	pinMode(PIN_INP_BTN, INPUT);
	pullUpDnControl(PIN_INP_BTN, PUD_UP);
}
	

