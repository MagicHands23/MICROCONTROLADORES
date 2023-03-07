#include <16F877A.h>
#fuses XT, NOWDT
#use delay (clock = 20 MHz)
#FUSES NOWDT, NOBROWNOUT, NOLVP, HS

#use standard_io(b)
#use standard_io(d)

void main()
{
   int1 boton_previo=input(boton);
   output_low(led);
   int1 encendido=0;
   
   while (true)
   {
      if(boton_previo == 0 && input(boton) == 1)
      {
         if(encendido){
         output_low(led);
         encendido=0;}
         else{
         output_high(led)=1;}
      }
      boton_previo=input(boton);
      delay_ms(100);
   }
}
