/* =============================================================================
   HelloWorld.c
   v2.0 (5/02/2018)
   Description:
    Test SDCC ROM CRT
============================================================================= */

#include "../include/newTypes.h"
#include "../include/msxSystemVars.h"
#include "../include/msxBIOS.h"



char INKEY();
void SCREEN1();
void COLOR(char ink, char background, char border);
void LOCATE(char x, char y);
void PRINT(char* text);
void bchput(char value);





      
void main(void) 
{
  
  COLOR(15,4,4);      
  SCREEN1();
  
  LOCATE(9,12);
  PRINT("Hello World!");
  
  LOCATE(1,23);
  INKEY();

}



char INKEY()
{
__asm   
   call CHGET
   ld   L,A
__endasm;
}



void SCREEN1()
{
__asm
  call INIT32
__endasm;
}




void COLOR(char ink, char background, char border)
{
ink;background,border;
__asm
  push IX
  ld   IX,#0
  add  IX,SP
  
  ld   IY,#FORCLR
  ld   A,4(IX)
  ld   (IY),A

  ld   A,5(IX)
  ld   1(IY),A
  
  ld   A,6(IX)
  ld   2(IY),A 
  
  call CHGCLR
  
  pop  IX
__endasm;
}


/* =============================================================================
   Set a position the cursor in to the specified location
   Posiciona el cursor hasta la ubicacion especificada
   x(byte) - column (1 to 32 or 40) 
   y(byte) - line   (1 to 24)
============================================================================= */
void LOCATE(char x, char y)
{
x;y;
__asm
  push IX
  ld   IX,#0
  add  IX,SP
  
  ld   A,4(IX) ;x
  ld   H,A
  ld   A,5(IX) ;y
  ld   L,A   
  call POSIT
  
  pop  IX
__endasm;

}



void PRINT(char* text)
{
  while(*(text)) bchput(*(text++));
}



//  Displays one character
void bchput(char value)
{
value;
__asm
  push IX
  ld   IX,#0
  add  IX,SP
  
  ld   A,4(IX)   
  call CHPUT
  
  pop  IX
__endasm;
}



