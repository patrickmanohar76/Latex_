#include <avr/io.h>
#include <util/delay.h>
int A,B,W,X,Y,Z,R,S;
int main (void)
{
	DDRD &= (1<<PD2);
	DDRD &= (1<<PD3);
	DDRD &= (1<<PD4);
	DDRD &= (1<<PD5);
	DDRB &= (1<<PB0);
	DDRB &= (1<<PB1);
	DDRB |= (1<<PB5);
	while(1){
		W = (PIND&(1<<PD2)) == (1<<PIND2);
		X = (PIND&(1<<PD3)) == (1<<PIND3);
		Y = (PIND&(1<<PD4)) == (1<<PIND4);
		Z = (PIND&(1<<PD5)) == (1<<PIND5);
		R = (PINB&(1<<PB0)) == (1<<PINB0);
		S = (PINB&(1<<PB1)) == (1<<PINB1);
		A=(!R&&!S&&W)||(!R&&S&&X)||
			(R&&!S&&Y)||(R&&S&&Z);
		B=((!R&&S)||(R&&!S));
		if(A==B)
		{
			PORTB = (1<<5);
		}
		else{
			PORTB = (0<<5);
		}
	}
	return 0;
}
