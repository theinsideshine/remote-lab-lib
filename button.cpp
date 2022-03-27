/**
 * File:   Soporte para botones
 *          
 *         
 *
 * - Compiler:           Arduino 1.8.15
 * - Supported devices:  Mega
 *
 * \author               LC: leandro.cintioli@alumnos.udemm.edu.ar
 *                       PT: pablo.tavolaro@alumnos.udemm.edu.ar
 *
 * Date:  01-04-2022
 *
 *      Universidad de la Marina Mercante.
 */
 
#include "button.h"

CButton::CButton()
{

}

void CButton::init( void )
{
    pinMode( PIN_LIMIT_M1, INPUT_PULLUP );
    pinMode( PIN_LIMIT_M2, INPUT_PULLUP );   
    
}


// Devuelve el valor del true si el  del boton 2 esta en LOW

bool CButton::is_button_m2_low ( void ){

 return (digitalRead( PIN_LIMIT_M2 ) == LOW) ;
  
}

// Devuelve el valor del true si el  del boton 1 esta en LOW

bool CButton::is_button_m1_low ( void ){

  return (digitalRead( PIN_LIMIT_M1 ) == LOW) ;
  
}
