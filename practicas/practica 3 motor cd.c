#include <16F877a.h>
#device ADC = 10
#use delay(crystal = 20000000)
#FUSES NOWDT, NOBROWNOUT, NOLVP, HS

#include <lcd_c.c>
#include <kbd4x4_d.c>
#include <getNum16.c>

#use STANDARD_IO(B)


#define M1 PIN_B0
#define M2 PIN_B1
#define boton_paro PIN_B2

int1 delay_paro(int16 segundos); // Declaramos función pero no la definimos

// Mover motor
void girarHorario(){
   output_high(M1);
   output_low(M2);
}

// Mover motor
void girarAntihorario(){
   output_high(M2);
   output_low(M1);
}

// Detener motor
void paro(){
   output_low(M1);
   output_low(M2);
}

void rutina_105(){                     // Rutina 105
      printf(lcd_putc,"\fRutina 105...");
      for(int16 i = 0; i < 3; i++){
      girarHorario();
      if(delay_paro(5) == 1)break;
      paro();
      delay_paro(1);
      girarAntihorario();  
      if(delay_paro(5)==1)break;
      paro();
      if(delay_paro(1)==1)break;
      i++;
   }
   
}

void rutina_210(){    //Rutina 210
      printf(lcd_putc,"\fRutina 210...");
      for(int8 i = 0;i<4;i++){
      girarHorario();
      if(delay_paro(3)==1)break;
      paro();
      if(delay_paro(1)==1)break;
   }
}

void rutina_315(){                        //Rutina 315
   printf(lcd_putc,"\fTiempo 1-120:");
   int16 seg = get_num_lcd(1,2);
   if(seg<120){
   for(int16 i = 0;i<3;i++){
      printf(lcd_putc,"\fRutina 315...");
      girarHorario();
      if(delay_paro(seg)==1)break;
      paro();
      if(delay_paro(1)==1)break;
      girarAntihorario();
      if(delay_paro(seg)==1)break;
      paro();
      if(delay_paro(1)==1)break;
   }
   }
   else
   {
        printf(lcd_putc,"\fError");
        delay_ms(1000);
   }
   
}

void rutina_420(){                           //Rutina 420
   printf(lcd_putc,"\fTiempo 1-120");
   int16 seg = get_num_lcd(1,2);
   if(seg<120){
   printf(lcd_putc,"\fIteraciones 1-50");
   int16 iteraciones = get_num_lcd(1,2);
   if(iteraciones<50){
   for (int16 i = 1; i<iteraciones; i++){
      printf(lcd_putc,"\fIteracion: %Lu",i);
      girarHorario();
      if(delay_paro(seg)==1)break;
      paro();
      if(delay_paro(1)==1)break;
      girarAntihorario();
      if(delay_paro(seg)==1)break;
      paro();
      if(delay_paro(1)==1)break;
   }
   }
   else     //de iteraciones
   {
        printf(lcd_putc,"\fError");
        delay_ms(1000);
   }
   }
   else     //de tiempo
   {
        printf(lcd_putc,"\fError");
        delay_ms(1000);
   }
   
}

void paro_emergencia(){
   paro(); // Detener motores
   printf(lcd_putc,"\fPARO DE EMERG"); // Mostrar mensaje
   while(input(boton_paro) == 1){} // Esperar a que el usuario suelte el botón de paro
   printf(lcd_putc,"\fPRESIONAR TECLA"); // Mostrar mensaje
   char c = read_key(); // Esperar a que el usuario presione una tecla
}

int1 delay_paro(int16 segundos){
   // Iterar hasta alcanzar el tiempo equivalente en intervalos
   // de 10 ms
   for(int16 i = 0; i < segundos * 100; i++){
      delay_ms(10);
      if(input(boton_paro)){
         paro_emergencia();
         return 1; // 1 porque salió mal
      }
   }
   return 0;
}


//Directiva para utilizar puerto USART
//#use rs232(BAUD=9600, XMIT = PIN_C6, RCV=PIN_C7)


void main()
{
   // setup_uart(9600); //Configurar baudios
   // Inicializar pines
   lcd_init();
   kbd_init();
   
   int16 bandera;
   
   paro(); // Apagar el motor
   input(boton_paro);
   while (TRUE)
    {
        printf(lcd_putc,"\f105-210-315-420");
        bandera = get_num_lcd(1,2);
        switch(bandera)
        {
            case 105:
               rutina_105();
               break;
               
            case 210:
               rutina_210();
               break;
               
            case 315:
               rutina_315();
               break;
               
            case 420:
               rutina_420();
               break;
               
            default:
            printf(lcd_putc,"\fError");
            delay_ms(1000);
            break;
            
        }
    }
}
