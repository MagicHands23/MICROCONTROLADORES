#include <16F877A.h>
#fuses XT, NOWDT
#use delay (clock = 20 MHz)

#use standard_io(b)

#include <lcd_c.c>
#include <kbd4x4_b.c>
#include <getNum16.c>

char getKey()
{
   char c;
   do
   {
   c=kbd_getc();
   }
   while(c=='\0');
   return c;
}
void main()
{
   lcd_init();              
   kbd_init();
   port_b_pullups(true);
   int16 a,b;
      
   while (true)
   {
      printf(lcd_putc,"\fIngresa el numero a");
      a=get_num_lcd(1,2);  
      printf(lcd_putc,"\fIngresa el numero b");
      b=get_num_lcd(1,2);  
      
      if(a>b)
      {
               printf(lcd_putc,"\fa es mayor que b");
               delay_ms(1000);
      }
      else
      {
               printf(lcd_putc,"\fb es mayor que a");
               delay_ms(1000);
      }
   }
}
