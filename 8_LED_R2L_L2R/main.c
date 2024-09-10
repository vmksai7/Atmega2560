/********************************************************************************
C program to blink 8 LED's from right to left and left to right with 
100000 sec delay
********************************************************************************/
#include"prog.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  char x;
  volatile long i;
  for(x=0;x<8;x++)
  {  
    output(1<<x);
    for(i=0;i<100000;i++);
  }
  for(x=7;x>=0;x--)
  {  
    output(1<<x);
    for(i=0;i<100000;i++);
  }
}
