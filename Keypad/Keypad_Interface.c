/********************************************************************************
C Program to blink 4 LED's in binary format of 1 to 9 using keypad with Arduino
Mega 2560 Microcontroller
*******************************************************************************/
void setup() {
  // put your setup code here, to run once:
  volatile long i,j;
  volatile char *dirf,*dirk,*dira,x;
  volatile char *outf,*ink,*outa;

  dirf = 0x30;
  dirk = 0x107;
  dira = 0x21;

  outf = 0x31;
  ink = 0x106;
  outa = 0x22;

  *dirf = 0x0F;
  *dirk = 0x00;
  *dira = 0x0F;

  while(1)
  {
    for(i=0;i<4;i++)
    {
      *outf = 1<<i;
      char inp = *ink & 0x0F;
      if(*ink!=0)
      {
        char num = getnumber(i,inp);
        *outa = num;

        for(j=0;j<200000;j++);
        *outa = 0;
      }
    }
  }
}

char getnumber(int row,char col)
{
    if(row == 0)
    {
      if(col == 0x01)
        return 1;
      if(col == 0x02)
        return 2;
      if(col == 0x04)
        return 3;
    }
    if(row == 1)
    {
      if(col == 0x01)
        return 4;
      if(col == 0x02)
        return 5;
      if(col == 0x04)
        return 6;
    }
    if(row == 2)
    {
      if(col == 0x01)
        return 7;
      if(col == 0x02)
        return 8;
      if(col == 0x04)
        return 9;
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
