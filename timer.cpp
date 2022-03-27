/**
 * File:   Clase de timers por software basados en la funcion millis().
 *
 * - Compiler:           Arduino 1.8.15
 * - Supported devices:  Mega
 *
 * \author               LC: leandro.cintioli@alumnos.udemm.edu.ar
 *                       PT: pablo.tavolaro@alumnos.udemm.edu.ar
 *
 * Date:  12-05-2022
 *
 *      Universidad de la Marina Mercante.
 */


 /* La funcion millis y micros usan el timer 0
  *  
  */
  
#include "timer.h"

CTimer::CTimer()
{
    start();
}

void CTimer::start( void )
{
    timer = millis();
}

bool CTimer::expired( uint32_t ms )
{
    return ((millis() - timer) > ms);
}
