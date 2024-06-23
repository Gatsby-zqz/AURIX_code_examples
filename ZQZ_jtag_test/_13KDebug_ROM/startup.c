//****************************************************************************************
//*
//* File Name: startup.c
//* Project Name: _13KDebug_ROM
//* Version: v1.0
//* Date: 2024-06-03 19:03:42
//* Author: gaojianzheng
//* 
//****************************************************************************************/

//#################     auto value variable from tool 	 #############//
extern unsigned int __text_end__;
extern unsigned int __bss_start__;
extern unsigned int __bss_end__;
extern unsigned int __data_start__;
extern unsigned int __data_end__;


//####################################################################//
int main(void);
int startup(void);
//####################################################################//
int startup(void)
{
	unsigned int *s;
	unsigned int *begin;
	unsigned int *end;

	s = (unsigned int*)&__text_end__;		
	begin = (unsigned int*)&__data_start__;
	end = (unsigned int*)&__data_end__;
	while( begin <  end) {	// cppcheck-suppress comparePointers
		*begin = *s;
		begin++;s++;
	}


	begin = (unsigned int*)&__bss_start__;
	end = (unsigned int*)&__bss_end__;
	while( begin < end ){	// cppcheck-suppress comparePointers
		*begin = 0;begin++;
	}

//############# begin to run main function	#############//		
	main();
	while(1);
}
//####################################################################//
