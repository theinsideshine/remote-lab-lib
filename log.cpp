/*
 * File:   Clase para serializar mensajes formateados en arduino.
 *
 * - Compiler:           Arduino 1.8.15
 * - Supported devices:  Mega
 *
 * \author               LC: leandro.cintioli@alumnos.udemm.edu.ar
 *                       PT: pablo.tavolaro@alumnos.udemm.edu.ar
 *
 * Date:  27-04-2022
 *
 *      Universidad de la Marina Mercante.
 */
#include "log.h"

CLog::CLog()
{
    level = LOG_CTRL_JSON;
}

void CLog::init( uint8_t level )
{
    Serial.begin( LOG_SERIAL_SPEED );
    set_level( level );    
}

void CLog::set_level( uint8_t level )
{
    this->level = level;
}

// Muestra informacion de serialueo por el puerto serie, precedidos
// por los milisegundos desde el reset.
// Implementa un wrapper de la funcion print de C para usar string
// formateados, ejemplo: ("distancia %d", var)
// NOTA: para ahorrar memoria RAM usa la version vsnprintf_P para que los
//       string se almacenen en la flash. Hay que anteponer el modificador
//       F(), ejemplo: serial_msg( F("valor = %d"), var );
void CLog::msg( const __FlashStringHelper *fmt, ... )
{
    if( level ==  LOG_MSG  ){
        char buf[ 128 ];
        va_list args;

        va_start(args, fmt);
        vsnprintf_P( buf, sizeof(buf), (const char *)fmt, args); // progmem for AVR
        va_end(args);

        Serial.print( millis() );
        Serial.print( " " );
        Serial.println( buf );
    }
}

// Muestra informacion de serialueo por el puerto serie, precedidos
// por los milisegundos desde el reset.
// Implementa un wrapper de la funcion print de C para usar string
// formateados, ejemplo: ("distancia %d", var)
// NOTA: para ahorrar memoria RAM usa la version vsnprintf_P para que los
//       string se almacenen en la flash. Hay que anteponer el modificador
//       F(), ejemplo: serial_msg( F("valor = %d"), var );
void CLog::msg_ctrl( const __FlashStringHelper *fmt, ... )
{
char buf[ 256 ];
va_list args;

    va_start(args, fmt);
    vsnprintf_P( buf, sizeof(buf), (const char *)fmt, args); // progmem for AVR
    va_end(args);

    Serial.println( buf );
}

// serialuea la informacion de control. Hay dos opciones, la primera es para serialeos
// para pos-procesar con excel. Y la segunda es para procesarla en tiempo real con
// la utilidad plotter de arduino.
void CLog::ctrl( uint16_t raw, uint16_t filtered, uint8_t state, uint16_t danger_point )
{
    if( level == LOG_CTRL_JSON ){
      msg_ctrl( F("{\"info\":\"serial\",\"time\":%lu,\"raw\":%d,\"filtered\":%d,\"state\":%d}"),
                 millis() , raw, filtered, state, danger_point );
    }else if( level == LOG_CTRL_ARDUINO_PLOTTER ) {
        // Escala el estado para mejorar la visualizacion.
        uint16_t scale = map( state, 0, 3, 0, 5000 );

        msg_ctrl( F("Min:0, raw:%d, filtered:%d, state:%d, danger:%d, Max:8190"),
                  raw, filtered, scale, danger_point );
    }
}
