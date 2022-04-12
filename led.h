/**
 * File:   Clase que da soporte a los leds de debug
 *
 * - Compiler:           Arduino 1.8.15
 * - Supported devices:  Mega
 *
 * \author              
 *                       LC: leandro.cintioli@alumnos.udemm.edu.ar
 *                       PT: pablo.tavolaro@alumnos.udemm.edu.ar
 *
 * Date:  01-05-2022
 *
 *      Universidad de la Marina Mercante.
 */
#ifndef LED_H
#define LED_H

#include "Arduino.h"


#define PIN_LED_DEBUG                 6
#define N_BLINK_MIN                   1
#define N_BLINK_MAX                   10
#define T_BLINK_MIN                   100         // 100 ms.
#define T_BLINK_MAX                   1000        // 1   s.


class CLed
{
  public:
    CLed();
    void init( void );
    void on(void);
    void off(void);
    void n_blink(uint8_t n_blink,uint16_t t_blink);
        
  private:
      
};

#endif // LED_H
