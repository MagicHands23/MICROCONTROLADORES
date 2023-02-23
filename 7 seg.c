#include <16F877a.h>
#device ADC = 10
#use delay(crystal = 20000000)
#FUSES NOWDT, NOBROWNOUT, NOLVP, HS

//Directiva para utilizar puerto USART
#use rs232(BAUD=9600, XMIT = PIN_C6, RCV=PIN_C7)

#use standard_io(B)
#use standard_io(A)

int8 numeros[16]=
{
   0b00111111, //0
   0b00000110, //1
   0b01011011, //2
   0b01001111, //3
   0b01100110, //4
   0b01101101, //5
   0b11111101, //6
   0b00000111, //7
   0b11111111, //8
   0b01101111, //9
   0b01110111, //A
   0b01111111, //B
   0b00111001, //C
   0b00111111, //D
   0b11111001, //E
   0b01110001  //F
};

void main ()
{
   setup_uart(9600); //Configurar baudios
   // Inicializar pines
   output_b(0);
   
   while(1)
   {
      for(int8 i = 0; i < sizeof(numeros); i++)
      {
         output_b(numeros[]);
         delay_ms(500);
      }
       if(input(pin_A0) ==1)
       {
         output_b(numeros[+1]);
       }
       if(input(pin_A2) ==1)
       {
         output_b(numeros[-1]);
       }
      
   }
}
