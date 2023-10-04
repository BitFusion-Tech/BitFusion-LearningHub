#define F_CPU 8000000UL  // Replace with your actual clock frequency
#include <avr/io.h>
#include <util/delay.h>
#include "MCAL/pwm.h"
#include "MCAL/timers.h"
#include "MCAL/adc.h"
#include "MCAL/icu.h"
#include "MCAL/ext_Interrupts.h"
#include "ECUAL/motor.h"
#include "ECUAL/lcd.h"
#include "ECUAL/stepper_motor.h"
#include "ECUAL/led.h"
#include "ECUAL/Lm35_sensor.h"

uint8_t data = 'A';


void Uart_Init(void){
	UBRRL = 51;
	CLEAR_BIT(UCSRA,U2X);
	
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	SET_BIT(UCSRB,TXEN);
	//SET_BIT(UCSRB,RXEN);
}

void Uart_Send(uint8_t data){
	
	while(!READ_BIT(UCSRA,UDRE));
	UDR = data;
}


int main(void)
{
	SET_BIT(DDRD,1);
	Uart_Init();
	while(1)
	{
		Uart_Send(data);	
	}
	
	
}

