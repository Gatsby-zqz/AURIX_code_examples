# 1 "../vector.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 353 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "../vector.c" 2
void startup();

 __attribute__((section(".text")))

void _start()
{

  __asm("mov R0,#0xD0010000");
  __asm("mov sp,r0");

  __asm("mov R4,r0");
  __asm("mov R5,r0");
  __asm("mov R11,r0");
  __asm("mov R12,r0");

  __asm("ljmp startup");
};
