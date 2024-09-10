/********************************************************************************
It's a .h file containd initialization and function definations
********************************************************************************/
void init(void);
void output(char);
char input(void);

void init(void)
{
  char *dir_reg = (char*)0x30;
  *dir_reg = 0xFF;
}

void output(char out_data)
{
  volatile char *out = (char*)0x31;
  *out = out_data;
}
