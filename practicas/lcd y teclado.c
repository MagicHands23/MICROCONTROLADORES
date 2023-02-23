#include <16F877A.h>
#fuses XT, NOWDT
#use delay (clock = 20 MHz)

#use standard_io(b)
#use standard_io(d)

#include <lcd_c.c>
#include <kbd4x4_b.c>
#include <getNum16.c>

char getKey()
{
   char c;
   do
   {
   c=kbd_getc();     //c será variable tipo caracter
   }
   while(c=='\0');
   return c;
}

void main()
{
   lcd_init();                //inicialisamos lcd y teclado y declaramos lo necesario
   kbd_init();
   int LED,parpadeo,x=0;
   int16 tiempo;
   port_b_pullups(true);
   
   while (true)
   {
      if(x==1)
      {
         printf(lcd_putc, "\f PARO \n PRESS ANY KEY");
         delay_ms(1000);
         getKey();      //retorna la tecla presionada
      }
      x=0;     //estado
      if(x==0)
      {
         do
         {
            printf(lcd_putc,"\fLED 1-2-3:");
            LED=get_num_lcd(1,2);                  //Ingresar y mostrar valor en lcd
            if(LED !=1 && LED !=2 && LED !=3)      //si no tienen el mismo valor LED dara error
            {
               printf(lcd_putc,"\fERROR");
               delay_ms(1000);
            }
         }
      while(LED !=1 && LED !=2 && LED !=3);
         do
         {
            printf(lcd_putc,"\fTiempo (s):  ");
            tiempo=get_num_lcd(1,2);                  //Ingresar y mostrar valor en lcd
               if(tiempo>120)
               {
                  printf(lcd_putc,"\fERROR");
                  delay_ms(1000);
               }
         }
         while(tiempo>120);
      }
      if(LED==1)
      {
         for(int16 i=1; i<=(tiempo*10); i++)    //se encendera el tiempo establecido
         {
            output_high(pin_d0);
            delay_ms(100);
               if(input(pin_d3)==1){x=1; i=tiempo+1;break;}    //al terminar el tiempo se regresa al inicio
         }
         output_low(pin_d0);
      }
      if(LED==2)
      {
         output_high(pin_d1);                              //se encenderá un cuarto de tiempo, al finalizar:
         for(int16 a=0; a<=(tiempo*25);a++)
         {
            delay_ms(10);
            if(input(pin_d3)==1){x=1;break;}
         }
         output_low(pin_d1);                             //se apagará un cuarto de tiempo, al finalizar:
         for(int16 b=0; b<=(tiempo*25);b++)
         {
            delay_ms(10);
            if(input(pin_d3)==1){x=1;break;}
         }
         output_high(pin_d1);                         //se encenderá un cuarto de tiempo, al finalizar:
         for(int16 m=0; m<=(tiempo*25);m++)
         {
            delay_ms(10);
            if(input(pin_d3)==1){x=1;break;}
         }
         output_low(pin_d1);                       //se apagará un cuarto de tiempo, al finalizar:
         for(int16 n=0; n<=(tiempo*25);n++)
         {
            delay_ms(10);
            if(input(pin_d3)==1){x=1;break;}
         }                                         //Al finalizar se regresa al incio
      }
      if(LED==3)
      {
         if(tiempo %2==0){tiempo=tiempo;}          //se encenderá 1s y se apagará 1s hasta llegar al tiempo ingresado
         else{tiempo=tiempo+1;}
         parpadeo=tiempo/2;
            
            for(int l=1;l<=parpadeo;l++)
            {
               output_high(pin_d2);
               for(int c=0; c<=10; c++)
               {
                  delay_ms(100);
                  if(input(pin_d3)==1){x=8;break;}    //si se presiona PARO se regresa al inicio
               }
               output_low(pin_d2);
               for(int d=0; d<=10; d++)
               {
                  delay_ms(100);
                  if(input(pin_d3)==1){x=8;break;}    //si se presiona PARO se regresa al inicio
               }
               output_low(pin_d2);
               if(x==8){x=1; break;}
            }
      }
   }
   

}
