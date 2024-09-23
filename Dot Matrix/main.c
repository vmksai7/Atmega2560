void setup() {
  // put your setup code here, to run once:
  volatile char *dirf, *dirk;
  dirf = 0x30;
  dirk = 0x107;
  *dirf = 0x03;
  *dirk = 0x03;
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *outf, *outk;
  volatile long i;
  outf = 0x31;
  outk = 0x108;
  
  *outf = 0x02;
  *outk = 0x01;
  for(i=0;i<500000;i++);
  *outf = 0x01;
  *outk = 0x01;
  for(i=0;i<500000;i++);
  *outf = 0x02;
  *outk = 0x02;
  for(i=0;i<500000;i++);
  *outf = 0x01;
  *outk = 0x02;
  for(i=0;i<500000;i++);
  *outf = 0x03;
  *outk = 0x00;
  for(i=0;i<500000;i++);
}
