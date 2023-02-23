#include <16F877a.h>
#device ADC = 10
#use delay(crystal = 20000000)
#FUSES NOWDT, NOBROWNOUT, NOLVP

//Directiva para utilizar puerto USART
#use rs232(BAUD=9600, XMIT = PIN_C6, RCV=PIN_C7)

int8 sumar(int8 a, int8 b)
{
   int8 resultado = a + b;
   return resultado;
}

void main()
{
   setup_uart(9600); //Configurar baudios
   
   printf("Ejercico suma\n\r");
   
   int8 num1 = 2;
   int8 num2 = 3;
   int8 res;
   
   //res = sumar(num1,num2);
   res=(num1+num2);
   
   printf("%u + %u: %u\n\r",num1,num2,res);
   while (1)
    {
    
    }
}
