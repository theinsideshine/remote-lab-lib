/*
 * File:   Clase para serialuear mensajes formateados en arduino.
 *
 * - Compiler:           Arduino 1.8.15
 * - Supported devices:  Mega
 *
 * \author               LC: leandro.cintioli@alumnos.udemm.edu.ar
 *                       PT: pablo.tavolaro@alumnos.udemm.edu.ar
 *
 * Date:  17-05-2022
 *
 *      Universidad de la Marina Mercante.
 */
 
#ifndef LOG_H
#define LOG_H

#include "Arduino.h"

#define LOG_SERIAL_SPEED                115200

#define  LOG_DISABLED                    0           // serial desactivado.
#define  LOG_MSG                         1           // serialea mensajes
#define  LOG_CTRL_JSON                   2           // serial habilitado en formato json.
#define  LOG_CTRL_ARDUINO_PLOTTER        3           // serial habilitado en formato arduino serial plotter.

class CLog
{
  public:
    CLog();
    void init( uint8_t );
    void msg( const __FlashStringHelper *fmt, ... );
    void ctrl( uint16_t raw, uint16_t filtered, uint8_t state, uint16_t danger_point );
    void set_level(uint8_t);

  private:
    void msg_ctrl( const __FlashStringHelper *fmt, ... );

    uint8_t level;            // Nivel de serial (0 = desactivado).
};

#endif // LOG_H
