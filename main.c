/*******************************************************************************
*                   : TUSUR
* File              : main.c
* Compiler          : IAR for ARM 
* Version           : 6.30.1.3142
* Last modified     : 07.06.2019
* 
* Author            : Dykhova Anna
* Support mail      : dyhovaanna@gmail.com
* 
* Description       : Work with stack
*
********************************************************************************

/*
CODE_SELECTION:
0 - Perepolnenie komandoy PUSH
1 - Zapis const v R13
2 - Summirovanie R13 è R1
3 - Perepolnenie s recursiey
4 - Peredacha parametrov function 
5 - Perecluchenie na alternativny stack
*/
#define CODE_SELECTION 5 

int recursion(void){
  return recursion();
}

int send_params(int a, int b, int c, int d, int e, int f){
  return (a+b+c+d+e+f);    
}

void main()
{

#if CODE_SELECTION == 0 
    while(1) //(Warning)
    {
      __asm(
            "PUSH {R1}" 
            );
    }

#elif CODE_SELECTION == 1
    __asm( "MOV R13, #10"); // R13 = 10 (ERROR)

#elif CODE_SELECTION == 2
    __asm( "MOV R1, #8888\n" "ADD R13, R1"); // R1 = 8888, R13=(R1+R13) (WARNING)

#elif CODE_SELECTION == 3
    recursion();

#elif CODE_SELECTION == 4
    int sum = send_params(0x1,0x2,0x3,0x4,0x5,0x6); // Stack params

#elif CODE_SELECTION == 5
    __asm( "MOV R0, #0x2\n" "MSR CONTROL, R0"); // CONTROL
#endif

  return;
}