/*
 * File:   Clase para controlar la confirguracion en la EEPROM.
 *
 * - Compiler:           Arduino 1.8.15
 * - Supported devices:  Mega
 *
 * \author               LC: leandro.cintioli@alumnos.udemm.edu.ar
 *                       PT: pablo.tavolaro@alumnos.udemm.edu.ar
 *
 * Date:  17-04-2022
 *
 *      Universidad de la Marina Mercante.
 */
 
#ifndef memory_H
#define memory_H

#include "Arduino.h"
#include "precompilation.h"
#include <ArduinoJson.h>

#define FIRMWARE_VERSION                "0.0.00"
                                               
                                                  
//#define EEPROM_ADDRESS_memory         4       // Direccion en la epprom donde se almacena la memoryuracion.
#define MAGIC_NUMBER                    54    // Numero magico para detectar memoria sin inicializar.


#define UINT8_0_DEFAULT               0 
#define UINT8_1_DEFAULT               1             
#define UINT8_2_DEFAULT               2  
#define UINT8_3_DEFAULT               3  
#define UINT8_4_DEFAULT               4  
#define UINT8_5_DEFAULT               5 
#define UINT8_6_DEFAULT               6             
#define UINT8_7_DEFAULT               7  
#define UINT8_8_DEFAULT               8  
#define UINT8_9_DEFAULT               9                                                                                       

#define ST_TEST_DEFAULT                 0              //  Estado del test pòr defecto.
#define ST_MODE_DEFAULT                 ST_MODE_TEST   //  Modo de operacion del sistema. 

#define UINT16_0_DEFAULT               65500 
#define UINT16_1_DEFAULT               65501             
#define UINT16_2_DEFAULT               65502  
#define UINT16_3_DEFAULT               65503  
#define UINT16_4_DEFAULT               65504  
#define UINT16_5_DEFAULT               65505 
#define UINT16_6_DEFAULT               65506          
#define UINT16_7_DEFAULT               65507
#define UINT16_8_DEFAULT               65508
#define UINT16_9_DEFAULT               65509


#define INT32_0_DEFAULT               70000
#define INT32_1_DEFAULT               70001
#define INT32_2_DEFAULT               70002 
#define INT32_3_DEFAULT               70003   
#define INT32_4_DEFAULT               70004
#define INT32_5_DEFAULT               70005  
#define INT32_6_DEFAULT               70006
#define INT32_7_DEFAULT               70007  
#define INT32_8_DEFAULT               70008 
#define INT32_9_DEFAULT               70009 



// Mapa de direcciones de los campos de memoryuracion en la EEPROM.
#define EEPROM_ADDRESS_MAGIC_NUMBER     0

// Unsigned 8 bits

#define EEPROM_ADDRESS_UINT8_0      (EEPROM_ADDRESS_MAGIC_NUMBER + sizeof(uint8_t))
#define EEPROM_ADDRESS_UINT8_1      (EEPROM_ADDRESS_UINT8_0  + sizeof(uint8_t))
#define EEPROM_ADDRESS_UINT8_2      (EEPROM_ADDRESS_UINT8_1  + sizeof(uint8_t))
#define EEPROM_ADDRESS_UINT8_3      (EEPROM_ADDRESS_UINT8_2  + sizeof(uint8_t))
#define EEPROM_ADDRESS_UINT8_4      (EEPROM_ADDRESS_UINT8_3  + sizeof(uint8_t))
#define EEPROM_ADDRESS_UINT8_5      (EEPROM_ADDRESS_UINT8_4  + sizeof(uint8_t))
#define EEPROM_ADDRESS_UINT8_6      (EEPROM_ADDRESS_UINT8_5  + sizeof(uint8_t))
#define EEPROM_ADDRESS_UINT8_7      (EEPROM_ADDRESS_UINT8_6  + sizeof(uint8_t))
#define EEPROM_ADDRESS_UINT8_8      (EEPROM_ADDRESS_UINT8_7  + sizeof(uint8_t))
#define EEPROM_ADDRESS_UINT8_9      (EEPROM_ADDRESS_UINT8_8  + sizeof(uint8_t))
// Para remote-lab-lib
#define EEPROM_ADDRESS_ST_TEST          (EEPROM_ADDRESS_UINT8_9 + sizeof(uint8_t))  
#define EEPROM_ADDRESS_ST_MODE          (EEPROM_ADDRESS_ST_TEST     + sizeof(uint8_t))  
#define EEPROM_ADDRESS_SERIAL_LEVEL     (EEPROM_ADDRESS_ST_MODE     + sizeof(uint8_t))


#define EEPROM_ADDRESS_UINT16_0      (EEPROM_ADDRESS_SERIAL_LEVEL + sizeof(uint8_t))
#define EEPROM_ADDRESS_UINT16_1      (EEPROM_ADDRESS_UINT16_0  + sizeof(uint16_t))
#define EEPROM_ADDRESS_UINT16_2      (EEPROM_ADDRESS_UINT16_1  + sizeof(uint16_t))
#define EEPROM_ADDRESS_UINT16_3      (EEPROM_ADDRESS_UINT16_2  + sizeof(uint16_t))
#define EEPROM_ADDRESS_UINT16_4      (EEPROM_ADDRESS_UINT16_3  + sizeof(uint16_t))
#define EEPROM_ADDRESS_UINT16_5      (EEPROM_ADDRESS_UINT16_4  + sizeof(uint16_t))
#define EEPROM_ADDRESS_UINT16_6      (EEPROM_ADDRESS_UINT16_5  + sizeof(uint16_t))
#define EEPROM_ADDRESS_UINT16_7      (EEPROM_ADDRESS_UINT16_6  + sizeof(uint16_t))
#define EEPROM_ADDRESS_UINT16_8      (EEPROM_ADDRESS_UINT16_7  + sizeof(uint16_t))
#define EEPROM_ADDRESS_UINT16_9      (EEPROM_ADDRESS_UINT16_8  + sizeof(uint16_t))

#define EEPROM_ADDRESS_INT32_0      (EEPROM_ADDRESS_UINT16_9  + sizeof(uint16_t))
#define EEPROM_ADDRESS_INT32_1      (EEPROM_ADDRESS_INT32_0  + sizeof(int32_t))
#define EEPROM_ADDRESS_INT32_2      (EEPROM_ADDRESS_INT32_1  + sizeof(int32_t))
#define EEPROM_ADDRESS_INT32_3      (EEPROM_ADDRESS_INT32_2  + sizeof(int32_t))
#define EEPROM_ADDRESS_INT32_4      (EEPROM_ADDRESS_INT32_3  + sizeof(int32_t))
#define EEPROM_ADDRESS_INT32_5      (EEPROM_ADDRESS_INT32_4  + sizeof(int32_t))
#define EEPROM_ADDRESS_INT32_6      (EEPROM_ADDRESS_INT32_5  + sizeof(int32_t))
#define EEPROM_ADDRESS_INT32_7      (EEPROM_ADDRESS_INT32_6  + sizeof(int32_t))
#define EEPROM_ADDRESS_INT32_8      (EEPROM_ADDRESS_INT32_7  + sizeof(int32_t))
#define EEPROM_ADDRESS_INT32_9      (EEPROM_ADDRESS_INT32_8  + sizeof(int32_t))





/*
 *  Para poder leer los dispositivo y ejecutar accciones se pone un modo de operacion .
 *  
 */


#define ST_MODE_TEST                    0               // Modo de operacion normal, ensayo activado.
#define ST_MODE_HOME_M2                 1               // Va al home del motor 2.
#define ST_MODE_CELL                    2               // Muestra el valor de las celdas.


class Cmemory
{
  public:
    Cmemory();

    uint8_t get_uint8_0( void );
    void    set_uint8_0( uint8_t parameter );

    uint8_t get_uint8_1( void );
    void   set_uint8_1( uint8_t parameter );

    uint8_t get_uint8_2( void );
    void   set_uint8_2( uint8_t parameter );

    uint8_t get_uint8_3( void );
    void   set_uint8_3( uint8_t parameter );

    uint8_t get_uint8_4( void );
    void   set_uint8_4( uint8_t parameter );

    uint8_t get_uint8_5( void );
    void   set_uint8_5( uint8_t parameter );

    uint8_t get_uint8_6( void );
    void   set_uint8_6( uint8_t parameter );

    uint8_t get_uint8_7( void );
    void   set_uint8_7( uint8_t parameter );

    uint8_t get_uint8_8( void );
    void set_uint8_8( uint8_t parameter );

    uint8_t get_uint8_9( void );
    void set_uint8_9( uint8_t parameter );
    

    uint8_t get_serial_level( void );
    void set_serial_level( uint8_t enable );

    uint8_t get_st_test( void );
    void set_st_test( uint8_t enable );

    uint8_t get_st_mode( void );
    void set_st_mode( uint8_t mode ); 

    

    uint16_t get_uint16_0( void );
    void    set_uint16_0( uint16_t parameter );

    uint16_t get_uint16_1( void );
    void   set_uint16_1( uint16_t parameter );

    uint16_t get_uint16_2( void );
    void   set_uint16_2( uint16_t parameter );

    uint16_t get_uint16_3( void );
    void   set_uint16_3( uint16_t parameter );

    uint16_t get_uint16_4( void );
    void   set_uint16_4( uint16_t parameter );

    uint16_t get_uint16_5( void );
    void   set_uint16_5( uint16_t parameter );

    uint16_t get_uint16_6( void );
    void   set_uint16_6( uint16_t parameter );

    uint16_t get_uint16_7( void );
    void   set_uint16_7( uint16_t parameter );

    uint16_t get_uint16_8( void );
    void set_uint16_8( uint16_t parameter );

    uint16_t get_uint16_9( void );
    void set_uint16_9( uint16_t parameter );

    int32_t get_int32_0( void );
    void    set_int32_0( int32_t parameter );

    int32_t get_int32_1( void );
    void    set_int32_1( int32_t parameter );

    int32_t get_int32_2( void );
    void    set_int32_2( int32_t parameter );

    int32_t get_int32_3( void );
    void    set_int32_3( int32_t parameter );

    int32_t get_int32_4( void );
    void    set_int32_4( int32_t parameter );
    
    int32_t get_int32_5( void );
    void    set_int32_5( int32_t parameter );

    int32_t get_int32_6( void );
    void    set_int32_6( int32_t parameter );

    int32_t get_int32_7( void );
    void    set_int32_7( int32_t parameter );

    int32_t get_int32_8( void );
    void    set_int32_8( int32_t parameter );

    int32_t get_int32_9( void );
    void    set_int32_9( int32_t parameter );  

    void host_cmd( void );
    void send_test_finish(void);

  private:
    uint8_t serial_level;         // 0 = serial de informacion de control desactivada.
    uint8_t st_test;            // Estado del ensayo 
    uint8_t st_mode;            // Modo del ensayo


    uint8_t uint8_0; 
    uint8_t uint8_1; 
    uint8_t uint8_2; 
    uint8_t uint8_3; 
    uint8_t uint8_4; 
    uint8_t uint8_5; 
    uint8_t uint8_6; 
    uint8_t uint8_7; 
    uint8_t uint8_8; 
    uint8_t uint8_9; 

    uint16_t uint16_0; 
    uint16_t uint16_1; 
    uint16_t uint16_2; 
    uint16_t uint16_3; 
    uint16_t uint16_4; 
    uint16_t uint16_5; 
    uint16_t uint16_6; 
    uint16_t uint16_7; 
    uint16_t uint16_8;
    uint16_t uint16_9;


    int32_t int32_0;
    int32_t int32_1;
    int32_t int32_2;
    int32_t int32_3;
    int32_t int32_4;
    int32_t int32_5;
    int32_t int32_6;
    int32_t int32_7;
    int32_t int32_8;
    int32_t int32_9;  
   
    
    void send_all_parameters( JsonDocument& );
    void send_all_uint8( JsonDocument& doc );
    void send_all_uint16( JsonDocument& doc );
    void send_all_int32( JsonDocument& doc );
    void send_all_cfg( JsonDocument& doc );
    void send_version( JsonDocument& );
    void send_ok( JsonDocument& );
    void send_ack( JsonDocument& );
    void send_status( JsonDocument& doc );    
    void send_serial_level( JsonDocument& doc );
    void send_st_mode( JsonDocument& doc );

    void send_uint8_0(JsonDocument& doc);
    void send_uint8_1(JsonDocument& doc);
    void send_uint8_2(JsonDocument& doc);
    void send_uint8_3(JsonDocument& doc);
    void send_uint8_4(JsonDocument& doc);
    void send_uint8_5(JsonDocument& doc);
    void send_uint8_6(JsonDocument& doc);
    void send_uint8_7(JsonDocument& doc);
    void send_uint8_8(JsonDocument& doc);
    void send_uint8_9(JsonDocument& doc);  

    void send_uint16_0(JsonDocument& doc);
    void send_uint16_1(JsonDocument& doc);
    void send_uint16_2(JsonDocument& doc);
    void send_uint16_3(JsonDocument& doc);
    void send_uint16_4(JsonDocument& doc);
    void send_uint16_5(JsonDocument& doc);
    void send_uint16_6(JsonDocument& doc);
    void send_uint16_7(JsonDocument& doc);
    void send_uint16_8(JsonDocument& doc);
    void send_uint16_9(JsonDocument& doc);

    void send_int32_0(JsonDocument& doc);
    void send_int32_1(JsonDocument& doc);
    void send_int32_2(JsonDocument& doc);
    void send_int32_3(JsonDocument& doc);
    void send_int32_4(JsonDocument& doc);
    void send_int32_5(JsonDocument& doc);
    void send_int32_6(JsonDocument& doc);
    void send_int32_7(JsonDocument& doc);
    void send_int32_8(JsonDocument& doc);
    void send_int32_9(JsonDocument& doc);
       
};

#endif // memory_H
