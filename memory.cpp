/*
 * File:   Clase para controlar la confirguracion en la EEPROM.
 *
 * - Compiler:           Arduino 1.8.15
 * - Supported devices:  Mega
 *
 * \author               LC: leandro.cintioli@alumnos.udemm.edu.ar
 *                       PT: pablo.tavolaro@alumnos.udemm.edu.ar
 *
 * Date:  05-05-2022
 *
 *      Universidad de la Marina Mercante.
 */
 
#include "memory.h"
#include "serial.h"


#include <EEPROM.h>



Cmemory::Cmemory()
{
uint8_t magic_number;

    EEPROM.get( EEPROM_ADDRESS_MAGIC_NUMBER, magic_number );

    if( magic_number != MAGIC_NUMBER ){
        magic_number = MAGIC_NUMBER;
        EEPROM.put( EEPROM_ADDRESS_MAGIC_NUMBER, magic_number );

        set_uint8_0( UINT8_0_DEFAULT );
        set_uint8_1( UINT8_1_DEFAULT );
        set_uint8_2( UINT8_2_DEFAULT );
        set_uint8_3( UINT8_3_DEFAULT );
        set_uint8_4( UINT8_4_DEFAULT );
        set_uint8_5( UINT8_5_DEFAULT );
        set_uint8_6( UINT8_6_DEFAULT );
        set_uint8_7( UINT8_7_DEFAULT );
        set_uint8_8( UINT8_8_DEFAULT );
        set_uint8_9( UINT8_9_DEFAULT );


         //set_serial_level( serial_DISABLED );
        set_serial_level( serial_MSG ); // cuando cambias el magic numbre setea los mensajes de serialeo (Arduino 1,primer inicio")        
        set_st_test(ST_TEST_DEFAULT);
        set_st_mode(ST_MODE_DEFAULT );

        set_uint16_0( UINT16_0_DEFAULT );
        set_uint16_1( UINT16_1_DEFAULT );
        set_uint16_2( UINT16_3_DEFAULT );
        set_uint16_3( UINT16_3_DEFAULT );
        set_uint16_4( UINT16_4_DEFAULT );
        set_uint16_5( UINT16_5_DEFAULT );
        set_uint16_6( UINT16_6_DEFAULT );
        set_uint16_7( UINT16_7_DEFAULT );
        set_uint16_8( UINT16_8_DEFAULT );
        set_uint16_9( UINT16_9_DEFAULT );    


        set_int32_0( INT32_0_DEFAULT );
        set_int32_1( INT32_1_DEFAULT );
        set_int32_2( INT32_2_DEFAULT );
        set_int32_3( INT32_3_DEFAULT );
        set_int32_4( INT32_4_DEFAULT );
        set_int32_5( INT32_5_DEFAULT );
        set_int32_6( INT32_6_DEFAULT );
        set_int32_7( INT32_7_DEFAULT );
        set_int32_8( INT32_8_DEFAULT );
        set_int32_9( INT32_9_DEFAULT );


        set_float_0( FLOAT_0_DEFAULT );
        set_float_1( FLOAT_1_DEFAULT );
        set_float_2( FLOAT_2_DEFAULT );
        set_float_3( FLOAT_3_DEFAULT );
        set_float_4( FLOAT_4_DEFAULT );
        set_float_5( FLOAT_5_DEFAULT );
        set_float_6( FLOAT_6_DEFAULT );
        set_float_7( FLOAT_7_DEFAULT );
        set_float_8( FLOAT_8_DEFAULT );
        set_float_9( FLOAT_9_DEFAULT );

        set_float_10( FLOAT_10_DEFAULT );
        set_float_11( FLOAT_11_DEFAULT );
        set_float_12( FLOAT_12_DEFAULT );
        set_float_13( FLOAT_13_DEFAULT );
        set_float_14( FLOAT_14_DEFAULT );
        set_float_15( FLOAT_15_DEFAULT );
        set_float_16( FLOAT_16_DEFAULT );
        set_float_17( FLOAT_17_DEFAULT );
        set_float_18( FLOAT_18_DEFAULT );
        set_float_19( FLOAT_19_DEFAULT );

        set_float_20( FLOAT_20_DEFAULT );
        set_float_21( FLOAT_21_DEFAULT );
        set_float_22( FLOAT_22_DEFAULT );
        set_float_23( FLOAT_23_DEFAULT );
        set_float_24( FLOAT_24_DEFAULT );
        set_float_25( FLOAT_25_DEFAULT );
        set_float_26( FLOAT_26_DEFAULT );
        set_float_27( FLOAT_27_DEFAULT );
        set_float_28( FLOAT_28_DEFAULT );
        set_float_29( FLOAT_29_DEFAULT );

        set_float_30( FLOAT_30_DEFAULT );
        set_float_31( FLOAT_31_DEFAULT );
        set_float_32( FLOAT_32_DEFAULT );
        set_float_33( FLOAT_33_DEFAULT );
        set_float_34( FLOAT_34_DEFAULT );
        set_float_35( FLOAT_35_DEFAULT );
        set_float_36( FLOAT_36_DEFAULT );
        set_float_37( FLOAT_37_DEFAULT );
        set_float_38( FLOAT_38_DEFAULT );
        set_float_39( FLOAT_39_DEFAULT );
        
        set_float_40( FLOAT_40_DEFAULT );
        set_float_41( FLOAT_41_DEFAULT );
        set_float_42( FLOAT_42_DEFAULT );
        set_float_43( FLOAT_43_DEFAULT );
        set_float_44( FLOAT_44_DEFAULT );
        set_float_45( FLOAT_45_DEFAULT );
        set_float_46( FLOAT_46_DEFAULT );
        set_float_47( FLOAT_47_DEFAULT );
        set_float_48( FLOAT_48_DEFAULT );
        set_float_49( FLOAT_49_DEFAULT );
    
    }else {
        EEPROM.get( EEPROM_ADDRESS_UINT8_0, uint8_0 );
        EEPROM.get( EEPROM_ADDRESS_UINT8_1, uint8_1 );
        EEPROM.get( EEPROM_ADDRESS_UINT8_2, uint8_2 );
        EEPROM.get( EEPROM_ADDRESS_UINT8_3, uint8_3 );
        EEPROM.get( EEPROM_ADDRESS_UINT8_4, uint8_4 );
        EEPROM.get( EEPROM_ADDRESS_UINT8_5, uint8_5 );
        EEPROM.get( EEPROM_ADDRESS_UINT8_6, uint8_6 );
        EEPROM.get( EEPROM_ADDRESS_UINT8_7, uint8_7 );
        EEPROM.get( EEPROM_ADDRESS_UINT8_8, uint8_8 );
        EEPROM.get( EEPROM_ADDRESS_UINT8_9, uint8_9 );
        

        EEPROM.get( EEPROM_ADDRESS_SERIAL_LEVEL, serial_level );
        //EEPROM.get( EEPROM_ADDRESS_ST_MODE, st_mode );
        
       //EEPROM.get( EEPROM_ADDRESS_ST_TEST, st_test );
       //estos parametro inicializa en 0 independiente de como este en la eprrom ya que estos ejecutan el ST_LOOP
       set_st_test(ST_TEST_DEFAULT);
       set_st_mode(ST_MODE_DEFAULT );

       EEPROM.get( EEPROM_ADDRESS_UINT16_0, uint16_0 );
       EEPROM.get( EEPROM_ADDRESS_UINT16_1, uint16_1 );
       EEPROM.get( EEPROM_ADDRESS_UINT16_2, uint16_2 );
       EEPROM.get( EEPROM_ADDRESS_UINT16_3, uint16_3 );
       EEPROM.get( EEPROM_ADDRESS_UINT16_4, uint16_4 );
       EEPROM.get( EEPROM_ADDRESS_UINT16_5, uint16_5 );
       EEPROM.get( EEPROM_ADDRESS_UINT16_6, uint16_6 );
       EEPROM.get( EEPROM_ADDRESS_UINT16_7, uint16_7 );
       EEPROM.get( EEPROM_ADDRESS_UINT16_8, uint16_8 );
       EEPROM.get( EEPROM_ADDRESS_UINT16_9, uint16_9 );

       EEPROM.get( EEPROM_ADDRESS_INT32_0, int32_0 );
       EEPROM.get( EEPROM_ADDRESS_INT32_1, int32_1 ); 
       EEPROM.get( EEPROM_ADDRESS_INT32_2, int32_2 );
       EEPROM.get( EEPROM_ADDRESS_INT32_3, int32_3 );
       EEPROM.get( EEPROM_ADDRESS_INT32_4, int32_4 );
       EEPROM.get( EEPROM_ADDRESS_INT32_5, int32_5 );
       EEPROM.get( EEPROM_ADDRESS_INT32_6, int32_6 );
       EEPROM.get( EEPROM_ADDRESS_INT32_7, int32_7 );
       EEPROM.get( EEPROM_ADDRESS_INT32_8, int32_8 );
       EEPROM.get( EEPROM_ADDRESS_INT32_9, int32_9 );

       EEPROM.get( EEPROM_ADDRESS_FLOAT_0, float_0 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_1, float_1 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_2, float_2 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_3, float_3 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_4, float_4 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_5, float_5 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_6, float_6 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_7, float_7 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_8, float_8 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_9, float_9 );

       EEPROM.get( EEPROM_ADDRESS_FLOAT_10, float_10 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_11, float_11 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_12, float_12 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_13, float_13 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_14, float_14 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_15, float_15 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_16, float_16 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_17, float_17 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_18, float_18 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_19, float_19 );

       EEPROM.get( EEPROM_ADDRESS_FLOAT_20, float_20 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_21, float_21 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_22, float_22 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_23, float_23 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_24, float_24 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_25, float_25 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_26, float_26 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_27, float_27 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_28, float_28 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_29, float_29 );

       EEPROM.get( EEPROM_ADDRESS_FLOAT_30, float_30 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_31, float_31 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_32, float_32 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_33, float_33 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_34, float_34 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_35, float_35 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_36, float_36 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_37, float_37 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_38, float_38 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_39, float_39 );

       EEPROM.get( EEPROM_ADDRESS_FLOAT_40, float_40 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_41, float_41 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_42, float_42 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_43, float_43 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_44, float_44 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_45, float_45 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_46, float_46 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_47, float_47 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_48, float_48 );
       EEPROM.get( EEPROM_ADDRESS_FLOAT_49, float_49 );

                   
    }
}

uint8_t Cmemory::get_uint8_0( void )
{
    return uint8_0;
}

void Cmemory::set_uint8_0( uint8_t val )
{
    uint8_0 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT8_0, val );
}


uint8_t Cmemory::get_uint8_1( void )
{
    return uint8_1;
}

void Cmemory::set_uint8_1( uint8_t val )
{
    uint8_1 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT8_1, val );
}

uint8_t Cmemory::get_uint8_2( void )
{
    return uint8_2;
}

void Cmemory::set_uint8_2( uint8_t val )
{
    uint8_2 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT8_2, val );
}

uint8_t Cmemory::get_uint8_3( void )
{
    return uint8_3;
}

void Cmemory::set_uint8_3( uint8_t val )
{
    uint8_3 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT8_3, val );
}


uint8_t Cmemory::get_uint8_4( void )
{
    return uint8_4;
}

void Cmemory::set_uint8_4( uint8_t val )
{
    uint8_4 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT8_4, val );
}

uint8_t Cmemory::get_uint8_5( void )
{
    return uint8_5;
}

void Cmemory::set_uint8_5( uint8_t val )
{
    uint8_5 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT8_5, val );
}


uint8_t Cmemory::get_uint8_6( void )
{
    return uint8_6;
}
void Cmemory::set_uint8_6( uint8_t val )
{
    uint8_6 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT8_6, val );
}

uint8_t Cmemory::get_uint8_7( void )
{
    return uint8_7;
}

void Cmemory::set_uint8_7( uint8_t val )
{
    uint8_7 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT8_7, val );
}

uint8_t Cmemory::get_uint8_8( void )
{
    return uint8_8;
}

void Cmemory::set_uint8_8( uint8_t val )
{
    uint8_8 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT8_8, val );
}

uint8_t Cmemory::get_uint8_9( void )
{
    return uint8_9;
}

void Cmemory::set_uint8_9( uint8_t val )
{
    uint8_9 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT8_9, val );
}



uint8_t Cmemory::get_serial_level( void )
{
    return serial_level;
}

void Cmemory::set_serial_level( uint8_t enable )
{
    serial_level = enable;
    EEPROM.put( EEPROM_ADDRESS_SERIAL_LEVEL, serial_level );
}
/*
 * Estos deberia ser booleano !!!!!
 * 
 */
 
uint8_t Cmemory::get_st_test( void )
{
    return st_test;
}

void Cmemory::set_st_test( uint8_t enable )
{
    st_test = enable;
    EEPROM.put( EEPROM_ADDRESS_ST_TEST, st_test );
}

uint8_t Cmemory::get_st_mode( void )
{
    return st_mode;
}

void Cmemory::set_st_mode( uint8_t mode )
{
    st_mode = mode;
    EEPROM.put( EEPROM_ADDRESS_ST_MODE, st_mode );
}


uint16_t Cmemory::get_uint16_0( void )
{
    return uint16_0;
}

void Cmemory::set_uint16_0( uint16_t val )
{
    uint16_0 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT16_0, val );
}

uint16_t Cmemory::get_uint16_1( void )
{
    return uint16_1;
}

void Cmemory::set_uint16_1( uint16_t val )
{
    uint16_1 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT16_1, val );
}

uint16_t Cmemory::get_uint16_2( void )
{
    return uint16_2;
}

void Cmemory::set_uint16_2( uint16_t val )
{
    uint16_2 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT16_2, val );
}

uint16_t Cmemory::get_uint16_3( void )
{
    return uint16_3;
}

void Cmemory::set_uint16_3( uint16_t val )
{
    uint16_3 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT16_3, val );
}

uint16_t Cmemory::get_uint16_4( void )
{
    return uint16_4;
}

void Cmemory::set_uint16_4( uint16_t val )
{
    uint16_4 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT16_4, val );
}

uint16_t Cmemory::get_uint16_5( void )
{
    return uint16_5;
}

void Cmemory::set_uint16_5( uint16_t val )
{
    uint16_5 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT16_5, val );
}

uint16_t Cmemory::get_uint16_6( void )
{
    return uint16_6;
}

void Cmemory::set_uint16_6( uint16_t val )
{
    uint16_6 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT16_6, val );
}

uint16_t Cmemory::get_uint16_7( void )
{
    return uint16_7;
}

void Cmemory::set_uint16_7( uint16_t val )
{
    uint16_7 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT16_7, val );
}

uint16_t Cmemory::get_uint16_8( void )
{
    return uint16_8;
}

void Cmemory::set_uint16_8( uint16_t val )
{
    uint16_8 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT16_8, val );
}

uint16_t Cmemory::get_uint16_9( void )
{
    return uint16_9;
}

void Cmemory::set_uint16_9( uint16_t val )
{
    uint16_9 = val;
    EEPROM.put( EEPROM_ADDRESS_UINT16_9, val );
}



int32_t Cmemory::get_int32_0( void )
{
    return int32_0;
}

void Cmemory::set_int32_0( int32_t val )
{
    int32_0 = val;
    EEPROM.put( EEPROM_ADDRESS_INT32_0, val );
}


int32_t Cmemory::get_int32_1( void )
{
    return int32_1;
}

void Cmemory::set_int32_1( int32_t val )
{
    int32_1 = val;
    EEPROM.put( EEPROM_ADDRESS_INT32_1, val );
}

int32_t Cmemory::get_int32_2( void )
{
    return int32_2;
}

void Cmemory::set_int32_2( int32_t val )
{
    int32_2 = val;
    EEPROM.put( EEPROM_ADDRESS_INT32_2, val );
}

int32_t Cmemory::get_int32_3( void )
{
    return int32_3;
}

void Cmemory::set_int32_3( int32_t val )
{
    int32_3 = val;
    EEPROM.put( EEPROM_ADDRESS_INT32_3, val );
}


int32_t Cmemory::get_int32_4( void )
{
    return int32_4;
}

void Cmemory::set_int32_4( int32_t val )
{
    int32_4 = val;
    EEPROM.put( EEPROM_ADDRESS_INT32_4, val );
}


int32_t Cmemory::get_int32_5( void )
{
    return int32_5;
}

void Cmemory::set_int32_5( int32_t val )
{
    int32_5 = val;
    EEPROM.put( EEPROM_ADDRESS_INT32_5, val );
}

int32_t Cmemory::get_int32_6( void )
{
    return int32_6;
}

void Cmemory::set_int32_6( int32_t val )
{
    int32_6 = val;
    EEPROM.put( EEPROM_ADDRESS_INT32_6, val );
}

int32_t Cmemory::get_int32_7( void )
{
    return int32_7;
}

void Cmemory::set_int32_7( int32_t val )
{
    int32_7 = val;
    EEPROM.put( EEPROM_ADDRESS_INT32_7, val );
}

int32_t Cmemory::get_int32_8( void )
{
    return int32_8;
}

void Cmemory::set_int32_8( int32_t val )
{
    int32_8 = val;
    EEPROM.put( EEPROM_ADDRESS_INT32_8, val );
}

int32_t Cmemory::get_int32_9( void )
{
    return int32_9;
}

void Cmemory::set_int32_9( int32_t val )
{
    int32_9 = val;
    EEPROM.put( EEPROM_ADDRESS_INT32_9, val );
}

float Cmemory::get_float_0( void )
{return float_0;}
void Cmemory::set_float_0( float val )
{ float_0 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_0, val );
}
float Cmemory::get_float_1( void )
{return float_1;}
void Cmemory::set_float_1( float val )
{ float_1 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_1, val );
}
float Cmemory::get_float_2( void )
{return float_2;}
void Cmemory::set_float_2( float val )
{ float_2 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_2, val );
}
float Cmemory::get_float_3( void )
{return float_3;}
void Cmemory::set_float_3( float val )
{ float_3 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_3, val );
}
float Cmemory::get_float_4( void )
{return float_4;}
void Cmemory::set_float_4( float val )
{ float_4 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_4, val );
}
float Cmemory::get_float_5( void )
{return float_5;}
void Cmemory::set_float_5( float val )
{ float_5 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_5, val );
}
float Cmemory::get_float_6( void )
{return float_6;}
void Cmemory::set_float_6( float val )
{ float_6 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_6, val );
}
float Cmemory::get_float_7( void )
{return float_7;}
void Cmemory::set_float_7( float val )
{ float_7 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_7, val );
}
float Cmemory::get_float_8( void )
{return float_8;}
void Cmemory::set_float_8( float val )
{ float_8 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_8, val );
}
float Cmemory::get_float_9( void )
{return float_9;}
void Cmemory::set_float_9( float val )
{ float_9 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_9, val );
}



float Cmemory::get_float_10( void )
{return float_10;}
void Cmemory::set_float_10( float val )
{ float_10 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_10, val );
}
float Cmemory::get_float_11( void )
{return float_11;}
void Cmemory::set_float_11( float val )
{ float_11 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_11, val );
}
float Cmemory::get_float_12( void )
{return float_12;}
void Cmemory::set_float_12( float val )
{ float_12 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_12, val );
}
float Cmemory::get_float_13( void )
{return float_13;}
void Cmemory::set_float_13( float val )
{ float_13 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_13, val );
}
float Cmemory::get_float_14( void )
{return float_14;}
void Cmemory::set_float_14( float val )
{ float_14 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_14, val );
}
float Cmemory::get_float_15( void )
{return float_15;}
void Cmemory::set_float_15( float val )
{ float_15 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_15, val );
}
float Cmemory::get_float_16( void )
{return float_16;}
void Cmemory::set_float_16( float val )
{ float_16 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_16, val );
}
float Cmemory::get_float_17( void )
{return float_17;}
void Cmemory::set_float_17( float val )
{ float_17 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_17, val );
}
float Cmemory::get_float_18( void )
{return float_18;}
void Cmemory::set_float_18( float val )
{ float_18 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_18, val );
}
float Cmemory::get_float_19( void )
{return float_19;}
void Cmemory::set_float_19( float val )
{ float_19 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_19, val );
}

float Cmemory::get_float_20( void )
{return float_20;}
void Cmemory::set_float_20( float val )
{ float_20 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_20, val );
}
float Cmemory::get_float_21( void )
{return float_21;}
void Cmemory::set_float_21( float val )
{ float_21 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_21, val );
}
float Cmemory::get_float_22( void )
{return float_22;}
void Cmemory::set_float_22( float val )
{ float_22 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_22, val );
}
float Cmemory::get_float_23( void )
{return float_23;}
void Cmemory::set_float_23( float val )
{ float_23 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_23, val );
}
float Cmemory::get_float_24( void )
{return float_24;}
void Cmemory::set_float_24( float val )
{ float_24 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_24, val );
}
float Cmemory::get_float_25( void )
{return float_25;}
void Cmemory::set_float_25( float val )
{ float_25 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_25, val );
}
float Cmemory::get_float_26( void )
{return float_26;}
void Cmemory::set_float_26( float val )
{ float_26 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_26, val );
}
float Cmemory::get_float_27( void )
{return float_27;}
void Cmemory::set_float_27( float val )
{ float_27 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_27, val );
}
float Cmemory::get_float_28( void )
{return float_28;}
void Cmemory::set_float_28( float val )
{ float_28 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_28, val );
}
float Cmemory::get_float_29( void )
{return float_29;}
void Cmemory::set_float_29( float val )
{ float_29 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_29, val );
}


float Cmemory::get_float_30( void )
{return float_30;}
void Cmemory::set_float_30( float val )
{ float_30 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_30, val );
}
float Cmemory::get_float_31( void )
{return float_31;}
void Cmemory::set_float_31( float val )
{ float_31 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_31, val );
}
float Cmemory::get_float_32( void )
{return float_32;}
void Cmemory::set_float_32( float val )
{ float_32 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_32, val );
}
float Cmemory::get_float_33( void )
{return float_33;}
void Cmemory::set_float_33( float val )
{ float_33 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_33, val );
}
float Cmemory::get_float_34( void )
{return float_34;}
void Cmemory::set_float_34( float val )
{ float_34 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_34, val );
}
float Cmemory::get_float_35( void )
{return float_35;}
void Cmemory::set_float_35( float val )
{ float_35 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_35, val );
}
float Cmemory::get_float_36( void )
{return float_36;}
void Cmemory::set_float_36( float val )
{ float_36 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_36, val );
}
float Cmemory::get_float_37( void )
{return float_37;}
void Cmemory::set_float_37( float val )
{ float_37 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_37, val );
}
float Cmemory::get_float_38( void )
{return float_38;}
void Cmemory::set_float_38( float val )
{ float_38 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_38, val );
}
float Cmemory::get_float_39( void )
{return float_39;}
void Cmemory::set_float_39( float val )
{ float_39 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_39, val );
}


float Cmemory::get_float_40( void )
{return float_40;}
void Cmemory::set_float_40( float val )
{ float_40 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_40, val );
}
float Cmemory::get_float_41( void )
{return float_41;}
void Cmemory::set_float_41( float val )
{ float_41 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_41, val );
}
float Cmemory::get_float_42( void )
{return float_42;}
void Cmemory::set_float_42( float val )
{ float_42 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_42, val );
}
float Cmemory::get_float_43( void )
{return float_43;}
void Cmemory::set_float_43( float val )
{ float_43 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_43, val );
}
float Cmemory::get_float_44( void )
{return float_44;}
void Cmemory::set_float_44( float val )
{ float_44 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_44, val );
}
float Cmemory::get_float_45( void )
{return float_45;}
void Cmemory::set_float_45( float val )
{ float_45 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_45, val );
}
float Cmemory::get_float_46( void )
{return float_46;}
void Cmemory::set_float_46( float val )
{ float_46 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_46, val );
}
float Cmemory::get_float_47( void )
{return float_47;}
void Cmemory::set_float_47( float val )
{ float_47 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_47, val );
}
float Cmemory::get_float_48( void )
{return float_48;}
void Cmemory::set_float_48( float val )
{ float_48 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_48, val );
}
float Cmemory::get_float_49( void )
{return float_49;}
void Cmemory::set_float_49( float val )
{ float_49 = val;
  EEPROM.put( EEPROM_ADDRESS_FLOAT_49, val );
}

// Lee por el puerto serie parametros de memoryuracion en formato json.
// {read:'all-params'}        Envia todos los parametros en formato json.
// {read:'all-cfg'}           Envia todos los parametros de remoteLabLib
// {read:'all-uint8'}         Envia todos los parametros unsigned 8 bits
// {read:'all-uint16'}        Envia todos los parametros unsigned 16 bits
// {read:'all-int32'}         Envia todos los parametros signed 32 bits
// {read:'all-float'}         Envia todos los parametros float
 
// {read:'version'}           Envia  la version del firmware.
// {read:'status'}            Devuelve el estatus del ensayo.

// {read:'serial_level'}         Nivel de serialeo por puerto serie.


// {serial_level:'0'}       serial_level:0=desactivado,
// {serial_level:'1'}                 1=mensajes.
// {serial_level:'2'}                 2=info control estandar.
// {serial_level:'3'}                 3=info control arduino plotter.

// {cmd:'start'}       Comienza el ensayo.



 //   {cdd:'start',data:{distance:'20',force:'306'}} 


// {uint8_0:'250'}       uint8_0       parametro de 8 bits sin signo 
// {uint8_x:'250'}       uint8_x       parametro de 8 bits sin signo 

// {uint16_0:'250'}       uint16_0     parametro de 16 bits sin signo
// {uint16_x:'250'}       uint16_x     parametro de 16 bits sin signo 

// {int32_0:'70000'}      int32_0       parametro de 32 bits con signo
// {int32_x:'70000'}      int32_x       parametro de 32 bits con signo

// {float_0:'70.123'}      float_0      parametro float
// {float_x:'70.123'}      float_x      parametro float

// {st_test:'1'}         st_test       0 ensayo desactivado. 
//                       st_test       1 ensayo activado. 
// {st_mode:'0'}         st_mode       ST_MODE_TEST                    0  ensayo activado.
//                                     ST_MODE_HOME_M2                 1 Va al home del motor 2.
//                                     ST_MODE_CELL                    2 Lee las celdas de carga.

                                   

void Cmemory::host_cmd( void )
{
bool known_key = false;

    if ( Serial.available() ){
        StaticJsonDocument<512> doc;
        auto error = deserializeJson( doc, Serial );
        if ( !error ) {     

            if ( doc.containsKey("uint8_0") ) {
                set_uint8_0( doc["uint8_0"] );
                known_key = true;
            }   

            if ( doc.containsKey("uint8_1") ) {
                set_uint8_1( doc["uint8_1"] );
                known_key = true;
            } 

            if ( doc.containsKey("uint8_2") ) {
                set_uint8_2( doc["uint8_2"] );
                known_key = true;
            } 

            if ( doc.containsKey("uint8_3") ) {
                set_uint8_3( doc["uint8_3"] );
                known_key = true;
            }

            
            if ( doc.containsKey("uint8_4") ) {
                set_uint8_4( doc["uint8_4"] );
                known_key = true;
            } 

            if ( doc.containsKey("uint8_5") ) {
                set_uint8_5( doc["uint8_5"] );
                known_key = true;
            }   

            if ( doc.containsKey("uint8_6") ) {
                set_uint8_6( doc["uint8_6"] );
                known_key = true;
            } 

            if ( doc.containsKey("uint8_7") ) {
                set_uint8_7( doc["uint8_7"] );
                known_key = true;
            } 

            if ( doc.containsKey("uint8_8") ) {
                set_uint8_8( doc["uint8_8"] );
                known_key = true;
            }

            
            if ( doc.containsKey("uint8_9") ) {
                set_uint8_9( doc["uint8_9"] );
                known_key = true;
            }
            
            
            if ( doc.containsKey("serial_level") ) {
                set_serial_level( doc["serial_level"] );
                known_key = true;
            }  

             if ( doc.containsKey("st_mode") ) {
                set_st_mode( doc["st_mode"] );
                known_key = true;
            } 

            if ( doc.containsKey("uint16_0") ) {
                set_uint16_0( doc["uint16_0"] );
                known_key = true;
            }

            if ( doc.containsKey("uint16_1") ) {
                set_uint16_1( doc["uint16_1"] );
                known_key = true;
            }

            if ( doc.containsKey("uint16_2") ) {
                set_uint16_2( doc["uint16_2"] );
                known_key = true;
            }

            if ( doc.containsKey("uint16_3") ) {
                set_uint16_3( doc["uint16_3"] );
                known_key = true;
            }

            if ( doc.containsKey("uint16_4") ) {
                set_uint16_4( doc["uint16_4"] );
                known_key = true;
            }

            if ( doc.containsKey("uint16_5") ) {
                set_uint16_5( doc["uint16_5"] );
                known_key = true;
            }

            if ( doc.containsKey("uint16_6") ) {
                set_uint16_6( doc["uint16_6"] );
                known_key = true;
            }

            if ( doc.containsKey("uint16_7") ) {
                set_uint16_7( doc["uint16_7"] );
                known_key = true;
            }

            if ( doc.containsKey("uint16_8") ) {
                set_uint16_8( doc["uint16_8"] );
                known_key = true;
            }

            if ( doc.containsKey("uint16_9") ) {
                set_uint16_9( doc["uint16_9"] );
                known_key = true;
            }

             if ( doc.containsKey("int32_0") ) {
                set_int32_0( doc["int32_0"] );
                known_key = true;
            }

            if ( doc.containsKey("int32_1") ) {
                set_int32_1( doc["int32_1"] );
                known_key = true;
            }

            if ( doc.containsKey("int32_2") ) {
                set_int32_2( doc["int32_2"] );
                known_key = true;
            }

            if ( doc.containsKey("int32_3") ) {
                set_int32_3( doc["int32_3"] );
                known_key = true;
            }

            if ( doc.containsKey("int32_4") ) {
                set_int32_4( doc["int32_4"] );
                known_key = true;
            }

            if ( doc.containsKey("int32_5") ) {
                set_int32_5( doc["int32_5"] );
                known_key = true;
            }

            if ( doc.containsKey("int32_6") ) {
                set_int32_6( doc["int32_6"] );
                known_key = true;
            }

            if ( doc.containsKey("int32_7") ) {
                set_int32_7( doc["int32_7"] );
                known_key = true;
            }

            if ( doc.containsKey("int32_8") ) {
                set_int32_0( doc["int32_8"] );
                known_key = true;
            }

            if ( doc.containsKey("int32_9") ) {
                set_int32_9( doc["int32_9"] );
                known_key = true;
            }

            if ( doc.containsKey("float_0") ) {
                set_float_0( doc["float_0"] );
                known_key = true;
            }
            if ( doc.containsKey("float_1") ) {
                set_float_1( doc["float_1"] );
                known_key = true;
            }
            if ( doc.containsKey("float_2") ) {
                set_float_2( doc["float_2"] );
                known_key = true;
            }
            if ( doc.containsKey("float_3") ) {
                set_float_3( doc["float_3"] );
                known_key = true;
            }
            if ( doc.containsKey("float_4") ) {
                set_float_4( doc["float_4"] );
                known_key = true;
            }
            if ( doc.containsKey("float_5") ) {
                set_float_5( doc["float_5"] );
                known_key = true;
            }
            if ( doc.containsKey("float_6") ) {
                set_float_6( doc["float_6"] );
                known_key = true;
            }
            if ( doc.containsKey("float_7") ) {
                set_float_7( doc["float_7"] );
                known_key = true;
            }
            if ( doc.containsKey("float_8") ) {
                set_float_8( doc["float_8"] );
                known_key = true;
            }
            if ( doc.containsKey("float_9") ) {
                set_float_9( doc["float_9"] );
                known_key = true;
            }



            if ( doc.containsKey("float_10") ) {
                set_float_10( doc["float_10"] );
                known_key = true;
            }
            if ( doc.containsKey("float_11") ) {
                set_float_11( doc["float_11"] );
                known_key = true;
            }
            if ( doc.containsKey("float_12") ) {
                set_float_12( doc["float_12"] );
                known_key = true;
            }
            if ( doc.containsKey("float_13") ) {
                set_float_13( doc["float_13"] );
                known_key = true;
            }
            if ( doc.containsKey("float_14") ) {
                set_float_14( doc["float_14"] );
                known_key = true;
            }
            if ( doc.containsKey("float_15") ) {
                set_float_15( doc["float_15"] );
                known_key = true;
            }
            if ( doc.containsKey("float_16") ) {
                set_float_16( doc["float_16"] );
                known_key = true;
            }
            if ( doc.containsKey("float_17") ) {
                set_float_17( doc["float_17"] );
                known_key = true;
            }
            if ( doc.containsKey("float_18") ) {
                set_float_18( doc["float_18"] );
                known_key = true;
            }
            if ( doc.containsKey("float_19") ) {
                set_float_19( doc["float_19"] );
                known_key = true;
            }



            if ( doc.containsKey("float_20") ) {
                set_float_20( doc["float_20"] );
                known_key = true;
            }
            if ( doc.containsKey("float_21") ) {
                set_float_21( doc["float_21"] );
                known_key = true;
            }
            if ( doc.containsKey("float_22") ) {
                set_float_22( doc["float_22"] );
                known_key = true;
            }
            if ( doc.containsKey("float_23") ) {
                set_float_23( doc["float_23"] );
                known_key = true;
            }
            if ( doc.containsKey("float_24") ) {
                set_float_24( doc["float_24"] );
                known_key = true;
            }
            if ( doc.containsKey("float_25") ) {
                set_float_25( doc["float_25"] );
                known_key = true;
            }
            if ( doc.containsKey("float_26") ) {
                set_float_26( doc["float_26"] );
                known_key = true;
            }
            if ( doc.containsKey("float_27") ) {
                set_float_27( doc["float_27"] );
                known_key = true;
            }
            if ( doc.containsKey("float_28") ) {
                set_float_28( doc["float_28"] );
                known_key = true;
            }
            if ( doc.containsKey("float_29") ) {
                set_float_29( doc["float_29"] );
                known_key = true;
            }



            if ( doc.containsKey("float_30") ) {
                set_float_30( doc["float_30"] );
                known_key = true;
            }
            if ( doc.containsKey("float_31") ) {
                set_float_31( doc["float_31"] );
                known_key = true;
            }
            if ( doc.containsKey("float_32") ) {
                set_float_32( doc["float_32"] );
                known_key = true;
            }
            if ( doc.containsKey("float_33") ) {
                set_float_33( doc["float_33"] );
                known_key = true;
            }
            if ( doc.containsKey("float_34") ) {
                set_float_34( doc["float_34"] );
                known_key = true;
            }
            if ( doc.containsKey("float_35") ) {
                set_float_35( doc["float_35"] );
                known_key = true;
            }
            if ( doc.containsKey("float_36") ) {
                set_float_36( doc["float_36"] );
                known_key = true;
            }
            if ( doc.containsKey("float_37") ) {
                set_float_37( doc["float_37"] );
                known_key = true;
            }
            if ( doc.containsKey("float_38") ) {
                set_float_38( doc["float_38"] );
                known_key = true;
            }
            if ( doc.containsKey("float_39") ) {
                set_float_39( doc["float_39"] );
                known_key = true;
            }



            if ( doc.containsKey("float_40") ) {
                set_float_40( doc["float_40"] );
                known_key = true;
            }
            if ( doc.containsKey("float_41") ) {
                set_float_41( doc["float_41"] );
                known_key = true;
            }
            if ( doc.containsKey("float_42") ) {
                set_float_42( doc["float_42"] );
                known_key = true;
            }
            if ( doc.containsKey("float_43") ) {
                set_float_43( doc["float_43"] );
                known_key = true;
            }
            if ( doc.containsKey("float_44") ) {
                set_float_44( doc["float_44"] );
                known_key = true;
            }
            if ( doc.containsKey("float_44") ) {
                set_float_45( doc["float_45"] );
                known_key = true;
            }
            if ( doc.containsKey("float_46") ) {
                set_float_46( doc["float_46"] );
                known_key = true;
            }
            if ( doc.containsKey("float_47") ) {
                set_float_47( doc["float_47"] );
                known_key = true;
            }
            if ( doc.containsKey("float_48") ) {
                set_float_48( doc["float_48"] );
                known_key = true;
            }
            if ( doc.containsKey("float_49") ) {
                set_float_49( doc["float_49"] );
                known_key = true;
            }       

            if ( doc.containsKey("read") ) {
                String key = doc["read"];

                if( key == "all-params" ) {
                    send_all_parameters( doc );
                }
                else if( key == "all-cfg" ) {
                    send_all_cfg( doc );
                }
                else if( key == "all-uint8" ) {
                    send_all_uint8( doc );
                } else if( key == "all-uint16" ) {
                    send_all_uint16( doc );
                }
                else if( key == "all-int32" ) {
                    send_all_int32( doc );
                }
                 else if( key == "all-float" ) {
                    send_all_float( doc );
                }      
                

                
                
                else if( key == "version" ) {
                    send_version( doc );
                }else if( key == "status" ) {
                    send_status( doc );
                }else if( key == "st_mode" ) {
                    send_st_mode( doc );
                }else if( key == "serial_level" ) {
                    send_serial_level( doc );
                }else if( key == "uint8_0" ) {
                    send_uint8_0( doc );
                }else if( key == "uint8_1" ) {
                    send_uint8_1( doc );
                }else if( key == "uint8_2" ) {
                    send_uint8_2( doc );
                }else if( key == "uint8_3" ) {
                    send_uint8_3( doc );
                }else if( key == "uint8_4" ) {
                    send_uint8_4( doc );
                }else if( key == "uint8_5" ) {
                    send_uint8_5( doc );
                }else if( key == "uint8_6" ) {
                    send_uint8_6( doc );
                }else if( key == "uint8_7" ) {
                    send_uint8_7( doc );
                }else if( key == "uint8_8" ) {
                    send_uint8_8( doc );
                }else if( key == "uint8_9" ) {
                    send_uint8_9( doc );
                }else if( key == "uint16_0" ) {
                    send_uint16_0( doc );
                }else if( key == "uint16_1" ) {
                    send_uint16_1( doc );
                }else if( key == "uint16_2" ) {
                    send_uint16_2( doc );
                }else if( key == "uint16_3" ) {
                    send_uint16_3( doc );
                }else if( key == "uint16_4" ) {
                    send_uint16_4( doc );
                }else if( key == "uint16_5" ) {
                    send_uint16_5( doc );
                }else if( key == "uint16_6" ) {
                    send_uint16_6( doc );
                }else if( key == "uint16_7" ) {
                    send_uint16_7( doc );
                }else if( key == "uint16_8" ) {
                    send_uint16_8( doc );
                }else if( key == "uint16_9" ) {
                    send_uint16_9( doc );
                }else if( key == "int32_0" ) {
                    send_int32_0( doc );
                }else if( key == "int32_1" ) {
                    send_int32_1( doc );
                }else if( key == "int32_2" ) {
                    send_int32_2( doc );
                }else if( key == "int32_3" ) {
                    send_int32_3( doc );
                }else if( key == "int32_4" ) {
                    send_int32_4( doc );
                }else if( key == "int32_5" ) {
                    send_int32_5( doc );
                }else if( key == "int32_6" ) {
                    send_int32_6( doc );
                }else if( key == "int32_7" ) {
                    send_int32_7( doc );
                }else if( key == "int32_8" ) {
                    send_int32_8( doc );
                }else if( key == "int32_9" ) {
                    send_int32_9( doc );
                }


                 else if( key == "float_0" ) {
                    send_float_0( doc );
                 }else if( key == "float_1" ) {
                    send_float_1( doc );
                 }else if( key == "float_2" ) {
                    send_float_2( doc );
                 }else if( key == "float_3" ) {
                    send_float_3( doc );
                 }else if( key == "float_4" ) {
                    send_float_4( doc );
                 }else if( key == "float_5" ) {
                    send_float_5( doc );
                 }else if( key == "float_6" ) {
                    send_float_6( doc );
                 }else if( key == "float_7" ) {
                    send_float_7( doc );
                 }else if( key == "float_8" ) {
                    send_float_8( doc );
                 }else if( key == "float_9" ) {
                    send_float_9( doc );
                 }


                 else if( key == "float_10" ) {
                    send_float_10( doc );
                 }else if( key == "float_11" ) {
                    send_float_11( doc );
                 }else if( key == "float_12" ) {
                    send_float_12( doc );
                 }else if( key == "float_13" ) {
                    send_float_13( doc );
                 }else if( key == "float_14" ) {
                    send_float_14( doc );
                 }else if( key == "float_15" ) {
                    send_float_15( doc );
                 }else if( key == "float_16" ) {
                    send_float_16( doc );
                 }else if( key == "float_17" ) {
                    send_float_17( doc );
                 }else if( key == "float_18" ) {
                    send_float_18( doc );
                 }else if( key == "float_19" ) {
                    send_float_19( doc );
                 }
                 
                 else if( key == "float_20" ) {
                    send_float_20( doc );
                 }else if( key == "float_21" ) {
                    send_float_21( doc );
                 }else if( key == "float_22" ) {
                    send_float_22( doc );
                 }else if( key == "float_23" ) {
                    send_float_23( doc );
                 }else if( key == "float_24" ) {
                    send_float_24( doc );
                 }else if( key == "float_25" ) {
                    send_float_25( doc );
                 }else if( key == "float_26" ) {
                    send_float_26( doc );
                 }else if( key == "float_27" ) {
                    send_float_27( doc );
                 }else if( key == "float_28" ) {
                    send_float_28( doc );
                 }else if( key == "float_29" ) {
                    send_float_29( doc );
                 }


                 else if( key == "float_30" ) {
                    send_float_30( doc );
                 }else if( key == "float_31" ) {
                    send_float_31( doc );
                 }else if( key == "float_32" ) {
                    send_float_32( doc );
                 }else if( key == "float_33" ) {
                    send_float_33( doc );
                 }else if( key == "float_34" ) {
                    send_float_34( doc );
                 }else if( key == "float_35" ) {
                    send_float_35( doc );
                 }else if( key == "float_36" ) {
                    send_float_36( doc );
                 }else if( key == "float_37" ) {
                    send_float_37( doc );
                 }else if( key == "float_38" ) {
                    send_float_38( doc );
                 }else if( key == "float_39" ) {
                    send_float_39( doc );
                 }


                 else if( key == "float_40" ) {
                    send_float_40( doc );
                 }else if( key == "float_41" ) {
                    send_float_41( doc );
                 }else if( key == "float_42" ) {
                    send_float_42( doc );
                 }else if( key == "float_43" ) {
                    send_float_43( doc );
                 }else if( key == "float_44" ) {
                    send_float_44( doc );
                 }else if( key == "float_45" ) {
                    send_float_45( doc );
                 }else if( key == "float_46" ) {
                    send_float_46( doc );
                 }else if( key == "float_47" ) {
                    send_float_47( doc );
                 }else if( key == "float_48" ) {
                    send_float_48( doc );
                 }else if( key == "float_49" ) {
                    send_float_49( doc );
                 }
                      
                
            }

            // Usamos cdd hasta definir que unifiquemos comandos, en realidad es cmd. 
            // Segun el uso https://arduinojson.org/v6/api/jsondocument/containskey/ 
            // para preguntar sobre la clave de un objeto  se usa  const char* key1 =doc["data"]["distance"];

            
            if ( doc.containsKey("cdd") ) { //Verifica "cdd".
                String key = doc["cdd"];
                 if( key == "start" ) {    //Verifica "start".
                     const char* key1 =doc["data"]["uint8_0"];
                     const char* key2 =doc["data"]["uint8_1"];
                    if (key1 && key2) {   //Verifica "distance". "force".
                       set_uint8_0( doc["data"]["uint8_0"]);
                       set_uint8_1( doc["data"]["uint8_1"] );  
                       set_st_test( 1 );  // Comienza el ensayo.                      
                       send_ack( doc );
                     }
                  
                 }
             }           

                    
                      
            if ( doc.containsKey("cmd") ) {
                String key = doc["cmd"];                
                
                if( key == "start" ) {
                    set_st_test( 1 );  // Comienza el ensayo.
                    send_ack( doc );
                }          
            } else if( known_key == true ) {
                send_ok( doc );
            }        
        }
    }
}

/*
 *  Envia todos los parametros del experimento en formato json.
 */

void Cmemory::send_all_parameters( JsonDocument& doc )
{
    doc["uint8_0"] = get_uint8_0();
    doc["uint8_1"] = get_uint8_1();
    doc["uint8_2"] = get_uint8_2();
    doc["uint8_3"] = get_uint8_3();
    doc["uint8_4"] = get_uint8_4();
    doc["uint8_5"] = get_uint8_5();
    doc["uint8_6"] = get_uint8_6();
    doc["uint8_7"] = get_uint8_7();
    doc["uint8_8"] = get_uint8_8();
    doc["uint8_9"] = get_uint8_9(); 
     
    doc["uint16_0"] = get_uint16_0();
    doc["uint16_1"] = get_uint16_1();
    doc["uint16_2"] = get_uint16_2();
    doc["uint16_3"] = get_uint16_3();
    doc["uint16_4"] = get_uint16_4();
    doc["uint16_5"] = get_uint16_5();
    doc["uint16_6"] = get_uint16_6();
    doc["uint16_7"] = get_uint16_7();
    doc["uint16_8"] = get_uint16_8();
    doc["uint16_9"] = get_uint16_9();  


    doc["int32_0"] = get_int32_0();
    doc["int32_1"] = get_int32_1();
    doc["int32_2"] = get_int32_2();
    doc["int32_3"] = get_int32_3();
    doc["int32_4"] = get_int32_4();
    doc["int32_5"] = get_int32_5();
    doc["int32_6"] = get_int32_6();
    doc["int32_7"] = get_int32_7();
    doc["int32_8"] = get_int32_8();
    doc["int32_9"] = get_int32_9();

    doc["float_0"] = get_float_0();
    doc["float_1"] = get_float_1();
    doc["float_2"] = get_float_2();
    doc["float_3"] = get_float_3();
    doc["float_4"] = get_float_4();
    doc["float_5"] = get_float_5();
    doc["float_6"] = get_float_6();
    doc["float_7"] = get_float_7();
    doc["float_8"] = get_float_8();
    doc["float_9"] = get_float_9();

    doc["float_10"] = get_float_10();
    doc["float_11"] = get_float_11();
    doc["float_12"] = get_float_12();
    doc["float_13"] = get_float_13();
    doc["float_14"] = get_float_14();
    doc["float_15"] = get_float_15();
    doc["float_16"] = get_float_16();
    doc["float_17"] = get_float_17();
    doc["float_18"] = get_float_18();
    doc["float_19"] = get_float_19();


    doc["float_20"] = get_float_20();
    doc["float_21"] = get_float_21();
    doc["float_22"] = get_float_22();
    doc["float_23"] = get_float_23();
    doc["float_24"] = get_float_24();
    doc["float_25"] = get_float_25();
    doc["float_26"] = get_float_26();
    doc["float_27"] = get_float_27();
    doc["float_28"] = get_float_28();
    doc["float_29"] = get_float_29();


    doc["float_30"] = get_float_30();
    doc["float_31"] = get_float_31();
    doc["float_32"] = get_float_32();
    doc["float_33"] = get_float_33();
    doc["float_34"] = get_float_34();
    doc["float_35"] = get_float_35();
    doc["float_36"] = get_float_36();
    doc["float_37"] = get_float_37();
    doc["float_38"] = get_float_38();
    doc["float_39"] = get_float_39();

    doc["float_40"] = get_float_40();
    doc["float_41"] = get_float_41();
    doc["float_42"] = get_float_42();
    doc["float_43"] = get_float_43();
    doc["float_44"] = get_float_44();
    doc["float_45"] = get_float_45();
    doc["float_46"] = get_float_46();
    doc["float_47"] = get_float_47();
    doc["float_48"] = get_float_48();
    doc["float_49"] = get_float_49();
       
    serializeJsonPretty( doc, Serial );
}

/*
 *  Envia todos los parametros de calibracion de la flexion y el nivel de serialgeo.
 */

void Cmemory::send_all_uint8( JsonDocument& doc )
{
    doc["uint8_0"] = get_uint8_0();
    doc["uint8_1"] = get_uint8_1();
    doc["uint8_2"] = get_uint8_2();
    doc["uint8_3"] = get_uint8_3();
    doc["uint8_4"] = get_uint8_4();
    doc["uint8_5"] = get_uint8_5();
    doc["uint8_6"] = get_uint8_6();
    doc["uint8_7"] = get_uint8_7();
    doc["uint8_8"] = get_uint8_8();
    doc["uint8_9"] = get_uint8_9();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_all_uint16( JsonDocument& doc )
{
    doc["uint16_0"] = get_uint16_0();
    doc["uint16_1"] = get_uint16_1();
    doc["uint16_2"] = get_uint16_2();
    doc["uint16_3"] = get_uint16_3();
    doc["uint16_4"] = get_uint16_4();
    doc["uint16_5"] = get_uint16_5();
    doc["uint16_6"] = get_uint16_6();
    doc["uint16_7"] = get_uint16_7();
    doc["uint16_8"] = get_uint16_8();
    doc["uint16_9"] = get_uint16_9();
    serializeJsonPretty( doc, Serial );
}


void Cmemory::send_all_int32( JsonDocument& doc )
{
    doc["int32_0"] = get_int32_0();
    doc["int32_1"] = get_int32_1();
    doc["int32_2"] = get_int32_2();
    doc["int32_3"] = get_int32_3();
    doc["int32_4"] = get_int32_4();
    doc["int32_5"] = get_int32_5();
    doc["int32_6"] = get_int32_6();
    doc["int32_7"] = get_int32_7();
    doc["int32_8"] = get_int32_8();
    doc["int32_9"] = get_int32_9();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_all_float( JsonDocument& doc )
{
    doc["float_0"] = get_float_0();
    doc["float_1"] = get_float_1();
    doc["float_2"] = get_float_2();
    doc["float_3"] = get_float_3();
    doc["float_4"] = get_float_4();
    doc["float_5"] = get_float_5();
    doc["float_6"] = get_float_6();
    doc["float_7"] = get_float_7();
    doc["float_8"] = get_float_8();
    doc["float_9"] = get_float_9();

    doc["float_10"] = get_float_10();
    doc["float_11"] = get_float_11();
    doc["float_12"] = get_float_12();
    doc["float_13"] = get_float_13();
    doc["float_14"] = get_float_14();
    doc["float_15"] = get_float_15();
    doc["float_16"] = get_float_16();
    doc["float_17"] = get_float_17();
    doc["float_18"] = get_float_18();
    doc["float_19"] = get_float_19();


    doc["float_20"] = get_float_20();
    doc["float_21"] = get_float_21();
    doc["float_22"] = get_float_22();
    doc["float_23"] = get_float_23();
    doc["float_24"] = get_float_24();
    doc["float_25"] = get_float_25();
    doc["float_26"] = get_float_26();
    doc["float_27"] = get_float_27();
    doc["float_28"] = get_float_28();
    doc["float_29"] = get_float_29();


    doc["float_30"] = get_float_30();
    doc["float_31"] = get_float_31();
    doc["float_32"] = get_float_32();
    doc["float_33"] = get_float_33();
    doc["float_34"] = get_float_34();
    doc["float_35"] = get_float_35();
    doc["float_36"] = get_float_36();
    doc["float_37"] = get_float_37();
    doc["float_38"] = get_float_38();
    doc["float_39"] = get_float_39();

    doc["float_40"] = get_float_40();
    doc["float_41"] = get_float_41();
    doc["float_42"] = get_float_42();
    doc["float_43"] = get_float_43();
    doc["float_44"] = get_float_44();
    doc["float_45"] = get_float_45();
    doc["float_46"] = get_float_46();
    doc["float_47"] = get_float_47();
    doc["float_48"] = get_float_48();
    doc["float_49"] = get_float_49();

    serializeJsonPretty( doc, Serial );
}


void Cmemory::send_all_cfg( JsonDocument& doc )
{
    doc["version"] = FIRMWARE_VERSION;
    doc["st_mode"] =  get_st_mode();
    doc["serial_level"] =  get_serial_level();
    doc["status"] = get_st_test();
    
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint8_0( JsonDocument& doc )
{
    doc["uint8_0"] =  get_uint8_0();

    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint8_1( JsonDocument& doc )
{
    doc["uint8_1"] =  get_uint8_1();

    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint8_2( JsonDocument& doc )
{
    doc["uint8_2"] =  get_uint8_2();

    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint8_3( JsonDocument& doc )
{
    doc["uint8_3"] =  get_uint8_3();

    serializeJsonPretty( doc, Serial );
}


void Cmemory::send_uint8_4( JsonDocument& doc )
{
    doc["uint8_4"] =  get_uint8_4();

    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint8_5( JsonDocument& doc )
{
    doc["uint8_5"] =  get_uint8_5();

    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint8_6( JsonDocument& doc )
{
    doc["uint8_6"] =  get_uint8_6();

    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint8_7( JsonDocument& doc )
{
    doc["uint8_7"] =  get_uint8_7();

    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint8_8( JsonDocument& doc )
{
    doc["uint8_8"] =  get_uint8_8();

    serializeJsonPretty( doc, Serial );
}


void Cmemory::send_uint8_9( JsonDocument& doc )
{
    doc["uint8_9"] =  get_uint8_9();

    serializeJsonPretty( doc, Serial );
}

//Envia el status del test
void Cmemory::send_test_finish( void )
{
    StaticJsonDocument<512> doc;   
    doc["st_test"] = get_st_test();  
    serializeJsonPretty( doc, Serial );
}



// Envia la version del firmware.
void Cmemory::send_version( JsonDocument& doc )
{
    doc["version"] = FIRMWARE_VERSION;

    serializeJsonPretty( doc, Serial );
}


// Envia el nivel de serialeo
void Cmemory::send_serial_level( JsonDocument& doc )
{
    doc["serial_level"] =  get_serial_level();

    serializeJsonPretty( doc, Serial );
}

// Envia el estatus del ensayo.
void Cmemory::send_status( JsonDocument& doc )
{
    doc["status"] = get_st_test();

    serializeJsonPretty( doc, Serial );
}

// Envia el modo del ensayo.
void Cmemory::send_st_mode( JsonDocument& doc )
{
    doc["st_mode"] = get_st_mode();

    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint16_0( JsonDocument& doc )
{
    doc["uint16_0"] =  get_uint16_0();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint16_1( JsonDocument& doc )
{
    doc["uint16_1"] =  get_uint16_1();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint16_2( JsonDocument& doc )
{
    doc["uint16_2"] =  get_uint16_2();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint16_3( JsonDocument& doc )
{
    doc["uint16_3"] =  get_uint16_3();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint16_4( JsonDocument& doc )
{
    doc["uint16_4"] =  get_uint16_4();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint16_5( JsonDocument& doc )
{
    doc["uint16_5"] =  get_uint16_5();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_uint16_6( JsonDocument& doc )
{
    doc["uint16_6"] =  get_uint16_6();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_uint16_7( JsonDocument& doc )
{
    doc["uint16_7"] =  get_uint16_7();
    serializeJsonPretty( doc, Serial );
}


void Cmemory::send_uint16_8( JsonDocument& doc )
{
    doc["uint16_8"] =  get_uint16_8();
    serializeJsonPretty( doc, Serial );
}


void Cmemory::send_uint16_9( JsonDocument& doc )
{
    doc["uint16_9"] =  get_uint16_9();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_int32_0( JsonDocument& doc )
{
    doc["int32_0"] =  get_int32_0();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_int32_1( JsonDocument& doc )
{
    doc["int32_1"] =  get_int32_1();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_int32_2( JsonDocument& doc )
{
    doc["int32_2"] =  get_int32_2();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_int32_3( JsonDocument& doc )
{
    doc["int32_3"] =  get_int32_3();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_int32_4( JsonDocument& doc )
{
    doc["int32_4"] =  get_int32_4();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_int32_5( JsonDocument& doc )
{
    doc["int32_5"] =  get_int32_5();
    serializeJsonPretty( doc, Serial );
}


void Cmemory::send_int32_6( JsonDocument& doc )
{
    doc["int32_6"] =  get_int32_6();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_int32_7( JsonDocument& doc )
{
    doc["int32_7"] =  get_int32_7();
    serializeJsonPretty( doc, Serial );
}


void Cmemory::send_int32_8( JsonDocument& doc )
{
    doc["int32_8"] =  get_int32_8();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_int32_9( JsonDocument& doc )
{
    doc["int32_9"] =  get_int32_9();
    serializeJsonPretty( doc, Serial );
}



void Cmemory::send_float_0( JsonDocument& doc )
{
  doc["float_0"] =  get_float_0();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_1( JsonDocument& doc )
{
  doc["float_1"] =  get_float_1();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_2( JsonDocument& doc )
{
  doc["float_2"] =  get_float_2();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_3( JsonDocument& doc )
{
  doc["float_3"] =  get_float_3();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_4( JsonDocument& doc )
{
  doc["float_4"] =  get_float_4();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_5( JsonDocument& doc )
{
  doc["float_5"] =  get_float_5();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_6( JsonDocument& doc )
{
  doc["float_6"] =  get_float_6();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_7( JsonDocument& doc )
{
  doc["float_7"] =  get_float_7();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_8( JsonDocument& doc )
{
  doc["float_8"] =  get_float_8();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_9( JsonDocument& doc )
{
  doc["float_9"] =  get_float_9();
  serializeJsonPretty( doc, Serial );
}


void Cmemory::send_float_10( JsonDocument& doc )
{
  doc["float_10"] =  get_float_10();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_11( JsonDocument& doc )
{
  doc["float_11"] =  get_float_11();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_12( JsonDocument& doc )
{
  doc["float_12"] =  get_float_12();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_13( JsonDocument& doc )
{
  doc["float_13"] =  get_float_13();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_14( JsonDocument& doc )
{
  doc["float_14"] =  get_float_14();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_15( JsonDocument& doc )
{
  doc["float_15"] =  get_float_15();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_16( JsonDocument& doc )
{
  doc["float_16"] =  get_float_16();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_17( JsonDocument& doc )
{
  doc["float_17"] =  get_float_17();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_18( JsonDocument& doc )
{
  doc["float_18"] =  get_float_18();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_19( JsonDocument& doc )
{
  doc["float_19"] =  get_float_19();
  serializeJsonPretty( doc, Serial );
}


void Cmemory::send_float_20( JsonDocument& doc )
{
  doc["float_20"] =  get_float_20();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_21( JsonDocument& doc )
{
  doc["float_21"] =  get_float_21();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_22( JsonDocument& doc )
{
  doc["float_22"] =  get_float_22();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_23( JsonDocument& doc )
{
  doc["float_23"] =  get_float_23();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_24( JsonDocument& doc )
{
  doc["float_24"] =  get_float_24();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_25( JsonDocument& doc )
{
  doc["float_25"] =  get_float_25();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_26( JsonDocument& doc )
{
  doc["float_26"] =  get_float_26();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_27( JsonDocument& doc )
{
  doc["float_27"] =  get_float_27();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_28( JsonDocument& doc )
{
  doc["float_28"] =  get_float_28();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_29( JsonDocument& doc )
{
  doc["float_29"] =  get_float_29();
  serializeJsonPretty( doc, Serial );
}



void Cmemory::send_float_30( JsonDocument& doc )
{
  doc["float_30"] =  get_float_30();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_31( JsonDocument& doc )
{
  doc["float_31"] =  get_float_31();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_32( JsonDocument& doc )
{
  doc["float_32"] =  get_float_32();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_33( JsonDocument& doc )
{
  doc["float_33"] =  get_float_33();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_34( JsonDocument& doc )
{
  doc["float_34"] =  get_float_34();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_35( JsonDocument& doc )
{
  doc["float_35"] =  get_float_35();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_36( JsonDocument& doc )
{
  doc["float_36"] =  get_float_36();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_37( JsonDocument& doc )
{
  doc["float_37"] =  get_float_37();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_38( JsonDocument& doc )
{
  doc["float_38"] =  get_float_38();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_39( JsonDocument& doc )
{
  doc["float_39"] =  get_float_39();
  serializeJsonPretty( doc, Serial );
}



void Cmemory::send_float_40( JsonDocument& doc )
{
  doc["float_40"] =  get_float_40();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_41( JsonDocument& doc )
{
  doc["float_41"] =  get_float_41();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_42( JsonDocument& doc )
{
  doc["float_42"] =  get_float_42();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_43( JsonDocument& doc )
{
  doc["float_43"] =  get_float_43();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_44( JsonDocument& doc )
{
  doc["float_44"] =  get_float_44();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_45( JsonDocument& doc )
{
  doc["float_45"] =  get_float_45();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_46( JsonDocument& doc )
{
  doc["float_46"] =  get_float_46();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_47( JsonDocument& doc )
{
  doc["float_47"] =  get_float_47();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_48( JsonDocument& doc )
{
  doc["float_48"] =  get_float_48();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_float_49( JsonDocument& doc )
{
  doc["float_49"] =  get_float_49();
  serializeJsonPretty( doc, Serial );
}



// Envia el resultado en formato json
void Cmemory::send_ok( JsonDocument& doc )
{
    doc[ "result" ] = "ok";

    serializeJsonPretty( doc, Serial );
}

// Envia el resultado en formato json
void Cmemory::send_ack( JsonDocument& doc )
{
    doc[ "result" ] = "ack";

    serializeJsonPretty( doc, Serial );
}
