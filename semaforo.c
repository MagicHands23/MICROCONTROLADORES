#include <16F877a.h>
#device ADC=10
#use delay(crystal=20Mhz)
#FUSES NOWDT, NOBROWNOUT, NOLVP

#USE STANDARD_IO(B)
#USE STANDARD_IO(C)

int8 num[3] = {      //estados de los bits
0b00000000,
0b00000001,
0b00000010
};
               
int GREEN = 0;
int RED = 0;

Void main(){

port_b_pullups(true);

   while (true){
   
      for(int GREEN = 0; GREEN < 40 ; GREEN++){
         output_b(num[1]);    //configurar los pines
         delay_ms(100);
            if(input(PIN_C0)==1){   //si se presiona el boton, el led verde sale del for y se va a amarillo
            GREEN = 40;
            }
          }
          
          For (int YELLOW = 0; YELLOW < 4; YELLOW++){    //genera 4 pulsos, uno cada 350ms
           output_b(num[2]); 
             delay_ms(350);
            output_low(PIN_B1);     //no hay instruccion de boton, por lo tanto no sucede nada
            delay_ms(350);
          }
          
          for(int RED = 0; RED < 110; RED++){
             output_high(PIN_B2); 
             delay_ms(50);
               if(input(PIN_C0)==1){   //si se presiona el boton la cuenta se regresa a 0
                RED=0;
                }
               }
              }
  }
