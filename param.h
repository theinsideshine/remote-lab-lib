/**
 * File:   Clase que da soporte al acceso a los parametros por el usuario
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
#ifndef PARAM_H
#define PARAM_H

#include "Arduino.h"

/*
 * DEBE CORRESPONDER CON LOS NOMBRES EN MemoryName.js, proyecto del frontEnd remote-lab-react
 */

// Inputs.

#define FUERZA   1
#define PESO     2
#define ENERGIA  3
#define TENSION  4
#define POTENCIA 5

// Outputs. 

#define ACELERACION    10
#define MILIMETROS     20
#define AMPER          30
#define NEWTON         40
#define ANGULO         50


//  Configuracion 


#define INPUT0_ADD    11
#define INPUT1_ADD    22
#define INPUT2_ADD    33
#define INPUT3_ADD    44
#define INPUT4_ADD    55
#define INPUT0_MUL    66
#define INPUT1_MUL    77
#define INPUT2_MUL    88
#define INPUT3_MUL    99
#define INPUT4_MUL    100




#endif // PARAM_H
