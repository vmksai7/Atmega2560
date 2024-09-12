/***************************************************************
C program to diaply number 11,22,33,44,55,66,77,88,99 in two
seven segment displays
***************************************************************/
void setup() {
  // put your setup code here, to run once:
  volatile char *fdir,*kdir;
  fdir = 0x30;
  *fdir = 0xFF;

  kdir = 0x107;
  *kdir = 0xFF;
}


void loop() {
  // put your main code here, to run repeatedly:
  volatile char *fout,*kout;
  volatile long i;
  fout = 0x31;
  kout = 0x108;

  *fout = 0x06;
  *kout = 0x06;
  for(i=0;i<1000000;i++);

  *fout = 0x5B;
  *kout = 0x5B;
  for(i=0;i<1000000;i++);

  *fout = 0x4F;
  *kout = 0x4F;
  for(i=0;i<1000000;i++);

  *fout = 0x66;
  *kout = 0x66;
  for(i=0;i<1000000;i++);

  *fout = 0x6D;
  *kout = 0x6D;
  for(i=0;i<1000000;i++);

  *fout = 0x7D;
  *kout = 0x7D;
  for(i=0;i<1000000;i++);

  *fout = 0x07;
  *kout = 0x07;
  for(i=0;i<1000000;i++);

  *fout = 0x7F;
  *kout = 0x7F;
  for(i=0;i<1000000;i++);

  *fout = 0x6F;
  *kout = 0x6F;
  for(i=0;i<1000000;i++);
}
