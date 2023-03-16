.include "/sdcard/arduino/report2/m328Pdef/m328Pdef.inc"

.def q=r18
.def q1=r19
.def q2=r20
.def d=r21

setup:

ldi r17,0b10111100
out DDRD,r16
ldi r16,0b11111111

loop:

ldi r22,0b00000000
and r22,r17
out PORTD,r22

call delay

ldi r22,0b00000100
and r22,r17
out PORTD,r22

in r17,PIND
ldi r23,0b00001000
and r23,r17
mov q1,r23

in r17,PIND
ldi r24,0b00010000
and r24,r17
mov q2,r24

ldi r25,0b00000000
mov r26,q1
com r26
cp r26,r25
brne equal

ldi r24,0b00001000
and r24,r17
mov r24,q1
out PORTD,r24

ldi r24,0b00010000
and r24,r17
mov r24,q2
out PORTD,r24

in r16,PIND
ldi r24,0b01000000
and r24,r16
mov q,r24

mov r24,q
mov r27,q1
lsr r24
lsl r27
lsl r27
eor r27,r24
mov d,r27

ldi r24,0b00100000
and r24,r16
mov r24,d
out PORTD,r24

ldi r24,0b10000000
and r24,r16
mov r24,q
lsl r24
out PORTD,r24

rjmp loop

start:
rjmp start

equal:
com q2

delay:
ldi r23,100
loop1:
ldi r24,100
loop2:
ldi r29,100
loop3:
dec r29
brne loop2
dec r24
brne loop1
dec r23
brne delay
ret
