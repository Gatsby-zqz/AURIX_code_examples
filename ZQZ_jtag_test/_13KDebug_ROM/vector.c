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
