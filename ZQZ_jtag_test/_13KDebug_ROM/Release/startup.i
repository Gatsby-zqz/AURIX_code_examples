# 1 "../startup.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 353 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "../startup.c" 2
# 12 "../startup.c"
extern unsigned int __text_end__;
extern unsigned int __bss_start__;
extern unsigned int __bss_end__;
extern unsigned int __data_start__;
extern unsigned int __data_end__;



int main(void);
int startup(void);

int startup(void)
{
 unsigned int *s;
 unsigned int *begin;
 unsigned int *end;

 s = (unsigned int*)&__text_end__;
 begin = (unsigned int*)&__data_start__;
 end = (unsigned int*)&__data_end__;
 while( begin < end) {
  *begin = *s;
  begin++;s++;
 }


 begin = (unsigned int*)&__bss_start__;
 end = (unsigned int*)&__bss_end__;
 while( begin < end ){
  *begin = 0;begin++;
 }


 main();
 while(1);
}
