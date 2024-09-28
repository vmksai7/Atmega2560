void init_port(void);
void outdata(char);
void outcontrol(char);
void delay1(int);
void lcd_control_write(void);
void init_lcd(void);
void write_data(char);
void write_string(char *ptr);

void setup() {
  // put your setup code here, to run once:
  init_port();
  init_lcd();
  write_string("Embedded Systems");
}

void write_string(char *ptr)
{
  while(*ptr!=0)
  {
    write_data(*ptr);
    ptr++;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

void init_port(void)
{
  volatile char *portf_dir = (volatile char *)0x30;
  volatile char *portk_dir = (volatile char *)0x107;
  *portf_dir = 0xFF;
  *portk_dir = 0x03;
}

void lcd_control_write(void)
{
  outcontrol(0x01);
  delay1(1);
  outcontrol(0x00);
  delay1(1);
}

void outdata(char out_data)
{
  volatile char *portf_data = (volatile char *)0x31;
  *portf_data = out_data;
}

void outcontrol(char out_data)
{
  volatile char *portk_data = (volatile char *)0x108;
  *portk_data = out_data;
}

void init_lcd(void)
{
  outdata(0x3C); //8 bit 2 line
  lcd_control_write();
  outdata(0x0F); //Display on cursor blinking
  lcd_control_write();
  outdata(0x01); //Clear Display
  lcd_control_write();
  outdata(0x06); //Auto increment
  lcd_control_write();
}

void delay1(int count)
{
  volatile long i;
  for(i=0;i<50000;i++);
}

void write_data(char wr_data)
{
  outdata(wr_data);
  outcontrol(0x02);
  delay1(1);
  outcontrol(0x03);
  delay1(1);
  outcontrol(0x02);
  delay1(1);
}
