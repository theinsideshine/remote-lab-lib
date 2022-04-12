/**
 * File:   Clase que da soporte a los leds de debug
 *
 * - Compiler:           Arduino 1.8.15
 * - Supported devices:  Mega
 *
 * \author               LC: leandro.cintioli@alumnos.udemm.edu.ar
 *                       PT: pablo.tavolaro@alumnos.udemm.edu.ar
 *
 * Date:  01-05-2022
 *
 *      Universidad de la Marina Mercante.
 */

/*
 * El led se conecta con el catodo a gnd y el anodo atraves de una resistencia al pin6
 */
 
#include "led.h"

CLed::CLed()
{

}

void CLed::init(void){
  pinMode(PIN_LED_DEBUG, OUTPUT);
  pinMode(PIN_LED_DEBUG, HIGH); //Apaga led
}

void CLed::off(void){

   digitalWrite(PIN_LED_DEBUG, LOW); 
 
}

void CLed::on(void){

   digitalWrite(PIN_LED_DEBUG, HIGH);  
}
/*
 * n_blink numero de blinkeos
 * t_blink tiempo de blinkeos en ms
 */
 
void CLed::n_blink(uint8_t n_blink,uint16_t t_blink){

  for (uint8_t i=0; i<n_blink; i++){    
    digitalWrite(PIN_LED_DEBUG, HIGH); 
   delay(t_blink);
   digitalWrite(PIN_LED_DEBUG, LOW); 
   delay(t_blink);
    
  }
}
