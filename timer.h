/**
 * File:   Clase de timers por software basados en la funcion millis()
 *         de arduino que al estar basada en un timer de la cpu por irq,
           no bloquea la ejecucion. 
 *
 * - Compiler:           Arduino 1.8.15
 * - Supported devices:  Mega
 *
 * \author               LC: leandro.cintioli@alumnos.udemm.edu.ar
 *                       PT: pablo.tavolaro@alumnos.udemm.edu.ar
 *
 * Date:  1-05-2021
 *
 *      Universidad de la Marina Mercante.
 */
 
#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"

class CTimer
{
  public:
    CTimer();
    void start();
    bool expired(uint32_t);

  private:
      uint32_t timer;
};

#endif // TIMER_H
