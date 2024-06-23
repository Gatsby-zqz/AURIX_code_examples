# 1 "../main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 353 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "../main.c" 2
# 10 "../main.c"
volatile unsigned int a=3;

int main(void)
{

 a=4;

 while(1)
 {
  a=5;
  a+=6;

  a=10;

 }
}
