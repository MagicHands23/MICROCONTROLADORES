/*
#include <16F877a.h>
#device ADC=10
#use delay(crystal=20000000)
#FUSES NOWDT, NOBROWNOUT, NOLVP, XT
#include <lcd_c.c>
#include <KBD_D 4X4.c>
#include <Lee_Num16b.c>

void main(){
   lcd_init();
   kbd_init();
   
   int16 num1,num2,res;
   char operation;
   while(TRUE){
         lcd_putc("\fNUM1");
         num1 = kbd_getc(1,2);
         
         do{
            lcd_putc("\fOperation");
            operation = read_key();
         }while(!(operation == '+' || operation == '*'));
         
         lcd_putc("\fNUM2");
         num2 =kbd_getc(1,2);
         
         if(operation == '+'){
            res = num1 + num2;
         }else{
            res = num1 * num2;
         } 
         printf(lcd_putc,"\f%lu %c %lu = %lu",num1,operation,num2,res);
         
         delay_ms(2000);

   } // while
} // main
*/

#include <16F877a.h>
#device ADC=10
#use delay(crystal=20000000)
#FUSES NOWDT, NOBROWNOUT, NOLVP, XT

#include <kbd4x4_d.c>
#include <lcd_c.c>
#include <getNum16.c>

void main(){
   lcd_init();
   kbd_init();
   
   int16 num1,num2,res;
   char operation;
   while(TRUE){
         lcd_putc("\fNUM1");
         num1 = get_num_lcd(1,2);
            
         do{
            lcd_putc("\fOperation");
            operation = read_key();
         }while(!(operation == '+' || operation == '*'));
         
         lcd_putc("\fNUM2");
         num2 = get_num_lcd(1,2);
         
         if(operation == '+'){
            res = num1 + num2;
         }else{
            res = num1 * num2;
         } 
         printf(lcd_putc,"\f%lu %c %lu = %lu",num1,operation,num2,res);
         
         delay_ms(2000);

   } // while
} // main
