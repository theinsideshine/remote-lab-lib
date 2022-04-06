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


         //set_serial_level( serial_DISABLED );
        set_serial_level( serial_MSG ); // cuando cambias el magic numbre setea los mensajes de serialeo (Arduino 1,primer inicio")        
        set_st_test(ST_TEST_DEFAULT);
        set_st_mode(ST_MODE_DEFAULT );

        set_input0( INPUT_0_DEFAULT );
        set_input1( INPUT_1_DEFAULT );
        set_input2( INPUT_2_DEFAULT );
        set_input3( INPUT_3_DEFAULT );
        set_input4( INPUT_4_DEFAULT );

        set_output0( OUTPUT_0_DEFAULT );
        set_output1( OUTPUT_1_DEFAULT );
        set_output2( OUTPUT_2_DEFAULT );
        set_output3( OUTPUT_3_DEFAULT );
        set_output4( OUTPUT_4_DEFAULT );

        set_cfg0( CFG_0_DEFAULT );
        set_cfg1( CFG_1_DEFAULT ); 
        set_cfg2( CFG_3_DEFAULT );
        set_cfg3( CFG_2_DEFAULT );
        set_cfg4( CFG_4_DEFAULT );
        set_cfg5( CFG_5_DEFAULT );
        set_cfg6( CFG_6_DEFAULT ); 
        set_cfg7( CFG_7_DEFAULT );
        set_cfg8( CFG_8_DEFAULT );
        set_cfg9( CFG_9_DEFAULT );       


        set_result_0( RESULT_0_DEFAULT );
        set_result_1( RESULT_1_DEFAULT );
        set_result_2( RESULT_2_DEFAULT );
        set_result_3( RESULT_3_DEFAULT );
        set_result_4( RESULT_4_DEFAULT );
        set_result_5( RESULT_5_DEFAULT );
        set_result_6( RESULT_6_DEFAULT );
        set_result_7( RESULT_7_DEFAULT );
        set_result_8( RESULT_8_DEFAULT );
        set_result_9( RESULT_9_DEFAULT );

        set_result_10( RESULT_10_DEFAULT );
        set_result_11( RESULT_11_DEFAULT );
        set_result_12( RESULT_12_DEFAULT );
        set_result_13( RESULT_13_DEFAULT );
        set_result_14( RESULT_14_DEFAULT );
        set_result_15( RESULT_15_DEFAULT );
        set_result_16( RESULT_16_DEFAULT );
        set_result_17( RESULT_17_DEFAULT );
        set_result_18( RESULT_18_DEFAULT );
        set_result_19( RESULT_19_DEFAULT );

        set_result_20( RESULT_20_DEFAULT );
        set_result_21( RESULT_21_DEFAULT );
        set_result_22( RESULT_22_DEFAULT );
        set_result_23( RESULT_23_DEFAULT );
        set_result_24( RESULT_24_DEFAULT );
        set_result_25( RESULT_25_DEFAULT );
        set_result_26( RESULT_26_DEFAULT );
        set_result_27( RESULT_27_DEFAULT );
        set_result_28( RESULT_28_DEFAULT );
        set_result_29( RESULT_29_DEFAULT );

        set_result_30( RESULT_30_DEFAULT );
        set_result_31( RESULT_31_DEFAULT );
        set_result_32( RESULT_32_DEFAULT );
        set_result_33( RESULT_33_DEFAULT );
        set_result_34( RESULT_34_DEFAULT );
        set_result_35( RESULT_35_DEFAULT );
        set_result_36( RESULT_36_DEFAULT );
        set_result_37( RESULT_37_DEFAULT );
        set_result_38( RESULT_38_DEFAULT );
        set_result_39( RESULT_39_DEFAULT );
        
        set_result_40( RESULT_40_DEFAULT );
        set_result_41( RESULT_41_DEFAULT );
        set_result_42( RESULT_42_DEFAULT );
        set_result_43( RESULT_43_DEFAULT );
        set_result_44( RESULT_44_DEFAULT );
        set_result_45( RESULT_45_DEFAULT );
        set_result_46( RESULT_46_DEFAULT );
        set_result_47( RESULT_47_DEFAULT );
        set_result_48( RESULT_48_DEFAULT );
        set_result_49( RESULT_49_DEFAULT );
    
    }else {
        
        EEPROM.get( EEPROM_ADDRESS_SERIAL_LEVEL, serial_level );
        //EEPROM.get( EEPROM_ADDRESS_ST_MODE, st_mode );
        
       //EEPROM.get( EEPROM_ADDRESS_ST_TEST, st_test );
       //estos parametro inicializa en 0 independiente de como este en la eprrom ya que estos ejecutan el ST_LOOP
       set_st_test(ST_TEST_DEFAULT);
       set_st_mode(ST_MODE_DEFAULT );

       EEPROM.get( EEPROM_ADDRESS_INPUT_0, input0 );
       EEPROM.get( EEPROM_ADDRESS_INPUT_1, input1 );
       EEPROM.get( EEPROM_ADDRESS_INPUT_2, input2 );
       EEPROM.get( EEPROM_ADDRESS_INPUT_3, input3 );
       EEPROM.get( EEPROM_ADDRESS_INPUT_4, input4 );

       EEPROM.get( EEPROM_ADDRESS_OUTPUT_0, output0 );
       EEPROM.get( EEPROM_ADDRESS_OUTPUT_1, output1 );
       EEPROM.get( EEPROM_ADDRESS_OUTPUT_2, output2 );
       EEPROM.get( EEPROM_ADDRESS_OUTPUT_3, output3 );
       EEPROM.get( EEPROM_ADDRESS_OUTPUT_4, output4 );


       EEPROM.get( EEPROM_ADDRESS_CFG_0, cfg0 );
       EEPROM.get( EEPROM_ADDRESS_CFG_1, cfg1 );
       EEPROM.get( EEPROM_ADDRESS_CFG_2, cfg2 );
       EEPROM.get( EEPROM_ADDRESS_CFG_3, cfg3 );
       EEPROM.get( EEPROM_ADDRESS_CFG_4, cfg4 );
       EEPROM.get( EEPROM_ADDRESS_CFG_5, cfg5 );
       EEPROM.get( EEPROM_ADDRESS_CFG_6, cfg6 );
       EEPROM.get( EEPROM_ADDRESS_CFG_7, cfg7 );
       EEPROM.get( EEPROM_ADDRESS_CFG_8, cfg8 );
       EEPROM.get( EEPROM_ADDRESS_CFG_9, cfg9 );
       

      
       EEPROM.get( EEPROM_ADDRESS_RESULT_0, result_0 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_1, result_1 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_2, result_2 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_3, result_3 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_4, result_4 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_5, result_5 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_6, result_6 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_7, result_7 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_8, result_8 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_9, result_9 );

       EEPROM.get( EEPROM_ADDRESS_RESULT_10, result_10 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_11, result_11 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_12, result_12 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_13, result_13 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_14, result_14 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_15, result_15 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_16, result_16 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_17, result_17 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_18, result_18 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_19, result_19 );

       EEPROM.get( EEPROM_ADDRESS_RESULT_20, result_20 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_21, result_21 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_22, result_22 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_23, result_23 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_24, result_24 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_25, result_25 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_26, result_26 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_27, result_27 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_28, result_28 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_29, result_29 );

       EEPROM.get( EEPROM_ADDRESS_RESULT_30, result_30 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_31, result_31 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_32, result_32 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_33, result_33 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_34, result_34 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_35, result_35 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_36, result_36 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_37, result_37 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_38, result_38 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_39, result_39 );

       EEPROM.get( EEPROM_ADDRESS_RESULT_40, result_40 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_41, result_41 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_42, result_42 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_43, result_43 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_44, result_44 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_45, result_45 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_46, result_46 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_47, result_47 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_48, result_48 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_49, result_49 );

                   
    }
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



float Cmemory::get_input0( void )
{return input0;}
void Cmemory::set_input0( float val )
{ input0 = val;
  EEPROM.put( EEPROM_ADDRESS_INPUT_0, val );
}
float Cmemory::get_input1( void )
{return input1;}
void Cmemory::set_input1( float val )
{ input1 = val;
  EEPROM.put( EEPROM_ADDRESS_INPUT_1, val );
}
float Cmemory::get_input2( void )
{return input2;}
void Cmemory::set_input2( float val )
{ input2 = val;
  EEPROM.put( EEPROM_ADDRESS_INPUT_2, val );
}
float Cmemory::get_input3( void )
{return input3;}
void Cmemory::set_input3( float val )
{ input3 = val;
  EEPROM.put( EEPROM_ADDRESS_INPUT_3, val );
}
float Cmemory::get_input4( void )
{return input4;}
void Cmemory::set_input4( float val )
{ input4 = val;
  EEPROM.put( EEPROM_ADDRESS_INPUT_4, val );
}



float Cmemory::get_output0( void )
{return output0;}
void Cmemory::set_output0( float val )
{ output0 = val;
  EEPROM.put( EEPROM_ADDRESS_OUTPUT_0, val );
}
float Cmemory::get_output1( void )
{return output1;}
void Cmemory::set_output1( float val )
{ output1 = val;
  EEPROM.put( EEPROM_ADDRESS_OUTPUT_1, val );
}
float Cmemory::get_output2( void )
{return output2;}
void Cmemory::set_output2( float val )
{ output2 = val;
  EEPROM.put( EEPROM_ADDRESS_OUTPUT_2, val );
}
float Cmemory::get_output3( void )
{return output3;}
void Cmemory::set_output3( float val )
{ output3 = val;
  EEPROM.put( EEPROM_ADDRESS_OUTPUT_3, val );
}
float Cmemory::get_output4( void )
{return output4;}
void Cmemory::set_output4( float val )
{ output4 = val;
  EEPROM.put( EEPROM_ADDRESS_OUTPUT_4, val );
}





float Cmemory::get_cfg0( void )
{return cfg0;}
void Cmemory::set_cfg0( float val )
{ cfg0 = val;
  EEPROM.put( EEPROM_ADDRESS_CFG_0, val );
}
float Cmemory::get_cfg1( void )
{return cfg1;}
void Cmemory::set_cfg1( float val )
{ cfg1 = val;
 EEPROM.put( EEPROM_ADDRESS_CFG_1, val );
}
float Cmemory::get_cfg2( void )
{return cfg2;}
void Cmemory::set_cfg2( float val )
{ cfg2 = val;
 EEPROM.put( EEPROM_ADDRESS_CFG_2, val );
}
float Cmemory::get_cfg3( void )
{return cfg3;}
void Cmemory::set_cfg3( float val )
{ cfg3 = val;
 EEPROM.put( EEPROM_ADDRESS_CFG_3, val );
}
float Cmemory::get_cfg4( void )
{return cfg4;}
void Cmemory::set_cfg4( float val )
{ cfg4 = val;
  EEPROM.put( EEPROM_ADDRESS_CFG_4, val );
}
float Cmemory::get_cfg5( void )
{return cfg5;}
void Cmemory::set_cfg5( float val )
{ cfg5 = val;
  EEPROM.put( EEPROM_ADDRESS_CFG_5, val );
}
float Cmemory::get_cfg6( void )
{return cfg6;}
void Cmemory::set_cfg6( float val )
{ cfg6 = val;
  EEPROM.put( EEPROM_ADDRESS_CFG_6, val );
}
float Cmemory::get_cfg7( void )
{return cfg7;}
void Cmemory::set_cfg7( float val )
{ cfg7 = val;
  EEPROM.put( EEPROM_ADDRESS_CFG_7, val );
}
float Cmemory::get_cfg8( void )
{return cfg8;}
void Cmemory::set_cfg8( float val )
{ cfg8 = val;
  EEPROM.put( EEPROM_ADDRESS_CFG_8, val );
}
float Cmemory::get_cfg9( void )
{return cfg9;}
void Cmemory::set_cfg9( float val )
{ cfg9 = val;
   EEPROM.put( EEPROM_ADDRESS_CFG_9, val );
}



float Cmemory::get_result_0( void )
{return result_0;}
void Cmemory::set_result_0( float val )
{ result_0 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_0, val );
}
float Cmemory::get_result_1( void )
{return result_1;}
void Cmemory::set_result_1( float val )
{ result_1 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_1, val );
}
float Cmemory::get_result_2( void )
{return result_2;}
void Cmemory::set_result_2( float val )
{ result_2 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_2, val );
}
float Cmemory::get_result_3( void )
{return result_3;}
void Cmemory::set_result_3( float val )
{ result_3 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_3, val );
}
float Cmemory::get_result_4( void )
{return result_4;}
void Cmemory::set_result_4( float val )
{ result_4 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_4, val );
}
float Cmemory::get_result_5( void )
{return result_5;}
void Cmemory::set_result_5( float val )
{ result_5 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_5, val );
}
float Cmemory::get_result_6( void )
{return result_6;}
void Cmemory::set_result_6( float val )
{ result_6 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_6, val );
}
float Cmemory::get_result_7( void )
{return result_7;}
void Cmemory::set_result_7( float val )
{ result_7 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_7, val );
}
float Cmemory::get_result_8( void )
{return result_8;}
void Cmemory::set_result_8( float val )
{ result_8 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_8, val );
}
float Cmemory::get_result_9( void )
{return result_9;}
void Cmemory::set_result_9( float val )
{ result_9 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_9, val );
}



float Cmemory::get_result_10( void )
{return result_10;}
void Cmemory::set_result_10( float val )
{ result_10 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_10, val );
}
float Cmemory::get_result_11( void )
{return result_11;}
void Cmemory::set_result_11( float val )
{ result_11 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_11, val );
}
float Cmemory::get_result_12( void )
{return result_12;}
void Cmemory::set_result_12( float val )
{ result_12 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_12, val );
}
float Cmemory::get_result_13( void )
{return result_13;}
void Cmemory::set_result_13( float val )
{ result_13 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_13, val );
}
float Cmemory::get_result_14( void )
{return result_14;}
void Cmemory::set_result_14( float val )
{ result_14 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_14, val );
}
float Cmemory::get_result_15( void )
{return result_15;}
void Cmemory::set_result_15( float val )
{ result_15 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_15, val );
}
float Cmemory::get_result_16( void )
{return result_16;}
void Cmemory::set_result_16( float val )
{ result_16 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_16, val );
}
float Cmemory::get_result_17( void )
{return result_17;}
void Cmemory::set_result_17( float val )
{ result_17 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_17, val );
}
float Cmemory::get_result_18( void )
{return result_18;}
void Cmemory::set_result_18( float val )
{ result_18 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_18, val );
}
float Cmemory::get_result_19( void )
{return result_19;}
void Cmemory::set_result_19( float val )
{ result_19 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_19, val );
}

float Cmemory::get_result_20( void )
{return result_20;}
void Cmemory::set_result_20( float val )
{ result_20 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_20, val );
}
float Cmemory::get_result_21( void )
{return result_21;}
void Cmemory::set_result_21( float val )
{ result_21 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_21, val );
}
float Cmemory::get_result_22( void )
{return result_22;}
void Cmemory::set_result_22( float val )
{ result_22 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_22, val );
}
float Cmemory::get_result_23( void )
{return result_23;}
void Cmemory::set_result_23( float val )
{ result_23 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_23, val );
}
float Cmemory::get_result_24( void )
{return result_24;}
void Cmemory::set_result_24( float val )
{ result_24 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_24, val );
}
float Cmemory::get_result_25( void )
{return result_25;}
void Cmemory::set_result_25( float val )
{ result_25 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_25, val );
}
float Cmemory::get_result_26( void )
{return result_26;}
void Cmemory::set_result_26( float val )
{ result_26 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_26, val );
}
float Cmemory::get_result_27( void )
{return result_27;}
void Cmemory::set_result_27( float val )
{ result_27 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_27, val );
}
float Cmemory::get_result_28( void )
{return result_28;}
void Cmemory::set_result_28( float val )
{ result_28 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_28, val );
}
float Cmemory::get_result_29( void )
{return result_29;}
void Cmemory::set_result_29( float val )
{ result_29 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_29, val );
}


float Cmemory::get_result_30( void )
{return result_30;}
void Cmemory::set_result_30( float val )
{ result_30 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_30, val );
}
float Cmemory::get_result_31( void )
{return result_31;}
void Cmemory::set_result_31( float val )
{ result_31 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_31, val );
}
float Cmemory::get_result_32( void )
{return result_32;}
void Cmemory::set_result_32( float val )
{ result_32 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_32, val );
}
float Cmemory::get_result_33( void )
{return result_33;}
void Cmemory::set_result_33( float val )
{ result_33 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_33, val );
}
float Cmemory::get_result_34( void )
{return result_34;}
void Cmemory::set_result_34( float val )
{ result_34 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_34, val );
}
float Cmemory::get_result_35( void )
{return result_35;}
void Cmemory::set_result_35( float val )
{ result_35 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_35, val );
}
float Cmemory::get_result_36( void )
{return result_36;}
void Cmemory::set_result_36( float val )
{ result_36 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_36, val );
}
float Cmemory::get_result_37( void )
{return result_37;}
void Cmemory::set_result_37( float val )
{ result_37 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_37, val );
}
float Cmemory::get_result_38( void )
{return result_38;}
void Cmemory::set_result_38( float val )
{ result_38 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_38, val );
}
float Cmemory::get_result_39( void )
{return result_39;}
void Cmemory::set_result_39( float val )
{ result_39 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_39, val );
}


float Cmemory::get_result_40( void )
{return result_40;}
void Cmemory::set_result_40( float val )
{ result_40 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_40, val );
}
float Cmemory::get_result_41( void )
{return result_41;}
void Cmemory::set_result_41( float val )
{ result_41 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_41, val );
}
float Cmemory::get_result_42( void )
{return result_42;}
void Cmemory::set_result_42( float val )
{ result_42 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_42, val );
}
float Cmemory::get_result_43( void )
{return result_43;}
void Cmemory::set_result_43( float val )
{ result_43 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_43, val );
}
float Cmemory::get_result_44( void )
{return result_44;}
void Cmemory::set_result_44( float val )
{ result_44 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_44, val );
}
float Cmemory::get_result_45( void )
{return result_45;}
void Cmemory::set_result_45( float val )
{ result_45 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_45, val );
}
float Cmemory::get_result_46( void )
{return result_46;}
void Cmemory::set_result_46( float val )
{ result_46 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_46, val );
}
float Cmemory::get_result_47( void )
{return result_47;}
void Cmemory::set_result_47( float val )
{ result_47 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_47, val );
}
float Cmemory::get_result_48( void )
{return result_48;}
void Cmemory::set_result_48( float val )
{ result_48 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_48, val );
}
float Cmemory::get_result_49( void )
{return result_49;}
void Cmemory::set_result_49( float val )
{ result_49 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_49, val );
}

                                   

void Cmemory::host_cmd( void )
{
bool known_key = false;

    if ( Serial.available() ){
        StaticJsonDocument<512> doc;
        auto error = deserializeJson( doc, Serial );
        if ( !error ) {     
                      
            if ( doc.containsKey("serial_level") ) {
                set_serial_level( doc["serial_level"] );
                known_key = true;
            }  

             if ( doc.containsKey("st_mode") ) {
                set_st_mode( doc["st_mode"] );
                known_key = true;
            } 



            if ( doc.containsKey("input0") ) {
                set_input0( doc["input0"] );
                known_key = true;
            }
            if ( doc.containsKey("input1") ) {
                set_input1( doc["input1"] );
                known_key = true;
            }
            if ( doc.containsKey("input2") ) {
                set_input2( doc["input2"] );
                known_key = true;
            }
            if ( doc.containsKey("input3") ) {
                set_input3( doc["input3"] );
                known_key = true;
            }
            if ( doc.containsKey("input4") ) {
                set_input4( doc["input4"] );
                known_key = true;
            }



            if ( doc.containsKey("output0") ) {
                set_output0( doc["output0"] );
                known_key = true;
            }
            if ( doc.containsKey("output1") ) {
                set_output1( doc["output1"] );
                known_key = true;
            }
            if ( doc.containsKey("output2") ) {
                set_output2( doc["output2"] );
                known_key = true;
            }
            if ( doc.containsKey("output3") ) {
                set_output3( doc["output3"] );
                known_key = true;
            }
            if ( doc.containsKey("output4") ) {
                set_output4( doc["output4"] );
                known_key = true;
            }


            if ( doc.containsKey("cfg0") ) {
                set_cfg0( doc["cfg0"] );
                known_key = true;
            }
            if ( doc.containsKey("cfg1") ) {
                set_cfg1( doc["cfg1"] );
                known_key = true;
            }
            if ( doc.containsKey("cfg2") ) {
                set_cfg2( doc["cfg2"] );
                known_key = true;
            }
            if ( doc.containsKey("cfg3") ) {
                set_cfg3( doc["cfg3"] );
                known_key = true;
            }
            if ( doc.containsKey("cfg4") ) {
                set_cfg4( doc["cfg4"] );
                known_key = true;
            }
            if ( doc.containsKey("cfg5") ) {
                set_cfg5( doc["cfg5"] );
                known_key = true;
            }
            if ( doc.containsKey("cfg6") ) {
                set_cfg6( doc["cfg6"] );
                known_key = true;
            }
            if ( doc.containsKey("cfg7") ) {
                set_cfg7( doc["cfg7"] );
                known_key = true;
            }
            if ( doc.containsKey("cfg8") ) {
                set_cfg8( doc["cfg8"] );
                known_key = true;
            }
            if ( doc.containsKey("cfg9") ) {
                set_cfg9( doc["cfg9"] );
                known_key = true;
            }

            

            if ( doc.containsKey("result_0") ) {
                set_result_0( doc["result_0"] );
                known_key = true;
            }
            if ( doc.containsKey("result_1") ) {
                set_result_1( doc["result_1"] );
                known_key = true;
            }
            if ( doc.containsKey("result_2") ) {
                set_result_2( doc["result_2"] );
                known_key = true;
            }
            if ( doc.containsKey("result_3") ) {
                set_result_3( doc["result_3"] );
                known_key = true;
            }
            if ( doc.containsKey("result_4") ) {
                set_result_4( doc["result_4"] );
                known_key = true;
            }
            if ( doc.containsKey("result_5") ) {
                set_result_5( doc["result_5"] );
                known_key = true;
            }
            if ( doc.containsKey("result_6") ) {
                set_result_6( doc["result_6"] );
                known_key = true;
            }
            if ( doc.containsKey("result_7") ) {
                set_result_7( doc["result_7"] );
                known_key = true;
            }
            if ( doc.containsKey("result_8") ) {
                set_result_8( doc["result_8"] );
                known_key = true;
            }
            if ( doc.containsKey("result_9") ) {
                set_result_9( doc["result_9"] );
                known_key = true;
            }



            if ( doc.containsKey("result_10") ) {
                set_result_10( doc["result_10"] );
                known_key = true;
            }
            if ( doc.containsKey("result_11") ) {
                set_result_11( doc["result_11"] );
                known_key = true;
            }
            if ( doc.containsKey("result_12") ) {
                set_result_12( doc["result_12"] );
                known_key = true;
            }
            if ( doc.containsKey("result_13") ) {
                set_result_13( doc["result_13"] );
                known_key = true;
            }
            if ( doc.containsKey("result_14") ) {
                set_result_14( doc["result_14"] );
                known_key = true;
            }
            if ( doc.containsKey("result_15") ) {
                set_result_15( doc["result_15"] );
                known_key = true;
            }
            if ( doc.containsKey("result_16") ) {
                set_result_16( doc["result_16"] );
                known_key = true;
            }
            if ( doc.containsKey("result_17") ) {
                set_result_17( doc["result_17"] );
                known_key = true;
            }
            if ( doc.containsKey("result_18") ) {
                set_result_18( doc["result_18"] );
                known_key = true;
            }
            if ( doc.containsKey("result_19") ) {
                set_result_19( doc["result_19"] );
                known_key = true;
            }



            if ( doc.containsKey("result_20") ) {
                set_result_20( doc["result_20"] );
                known_key = true;
            }
            if ( doc.containsKey("result_21") ) {
                set_result_21( doc["result_21"] );
                known_key = true;
            }
            if ( doc.containsKey("result_22") ) {
                set_result_22( doc["result_22"] );
                known_key = true;
            }
            if ( doc.containsKey("result_23") ) {
                set_result_23( doc["result_23"] );
                known_key = true;
            }
            if ( doc.containsKey("result_24") ) {
                set_result_24( doc["result_24"] );
                known_key = true;
            }
            if ( doc.containsKey("result_25") ) {
                set_result_25( doc["result_25"] );
                known_key = true;
            }
            if ( doc.containsKey("result_26") ) {
                set_result_26( doc["result_26"] );
                known_key = true;
            }
            if ( doc.containsKey("result_27") ) {
                set_result_27( doc["result_27"] );
                known_key = true;
            }
            if ( doc.containsKey("result_28") ) {
                set_result_28( doc["result_28"] );
                known_key = true;
            }
            if ( doc.containsKey("result_29") ) {
                set_result_29( doc["result_29"] );
                known_key = true;
            }



            if ( doc.containsKey("result_30") ) {
                set_result_30( doc["result_30"] );
                known_key = true;
            }
            if ( doc.containsKey("result_31") ) {
                set_result_31( doc["result_31"] );
                known_key = true;
            }
            if ( doc.containsKey("result_32") ) {
                set_result_32( doc["result_32"] );
                known_key = true;
            }
            if ( doc.containsKey("result_33") ) {
                set_result_33( doc["result_33"] );
                known_key = true;
            }
            if ( doc.containsKey("result_34") ) {
                set_result_34( doc["result_34"] );
                known_key = true;
            }
            if ( doc.containsKey("result_35") ) {
                set_result_35( doc["result_35"] );
                known_key = true;
            }
            if ( doc.containsKey("result_36") ) {
                set_result_36( doc["result_36"] );
                known_key = true;
            }
            if ( doc.containsKey("result_37") ) {
                set_result_37( doc["result_37"] );
                known_key = true;
            }
            if ( doc.containsKey("result_38") ) {
                set_result_38( doc["result_38"] );
                known_key = true;
            }
            if ( doc.containsKey("result_39") ) {
                set_result_39( doc["result_39"] );
                known_key = true;
            }



            if ( doc.containsKey("result_40") ) {
                set_result_40( doc["result_40"] );
                known_key = true;
            }
            if ( doc.containsKey("result_41") ) {
                set_result_41( doc["result_41"] );
                known_key = true;
            }
            if ( doc.containsKey("result_42") ) {
                set_result_42( doc["result_42"] );
                known_key = true;
            }
            if ( doc.containsKey("result_43") ) {
                set_result_43( doc["result_43"] );
                known_key = true;
            }
            if ( doc.containsKey("result_44") ) {
                set_result_44( doc["result_44"] );
                known_key = true;
            }
            if ( doc.containsKey("result_44") ) {
                set_result_45( doc["result_45"] );
                known_key = true;
            }
            if ( doc.containsKey("result_46") ) {
                set_result_46( doc["result_46"] );
                known_key = true;
            }
            if ( doc.containsKey("result_47") ) {
                set_result_47( doc["result_47"] );
                known_key = true;
            }
            if ( doc.containsKey("result_48") ) {
                set_result_48( doc["result_48"] );
                known_key = true;
            }
            if ( doc.containsKey("result_49") ) {
                set_result_49( doc["result_49"] );
                known_key = true;
            }       

            if ( doc.containsKey("read") ) {
                String key = doc["read"];

                if( key == "all-params" ) {
                    send_all_parameters( doc );
                }
                else if( key == "all-input" ) {
                    send_all_input( doc );
                }
                else if( key == "all-ouput" ) {
                    send_all_output( doc );
                } else if( key == "all-cfg" ) {
                    send_all_cfg( doc );
                }
                else if( key == "all-lib" ) {
                    send_all_lib( doc );
                }
                 else if( key == "all-result" ) {
                    send_all_result( doc );
                }           
                
                else if( key == "version" ) {
                    send_version( doc );
                }else if( key == "status" ) {
                    send_status( doc );
                }else if( key == "st_mode" ) {
                    send_st_mode( doc );
                }else if( key == "serial_level" ) {
                    send_serial_level( doc );
                }
                
                else if( key == "input0" ) {
                    send_input0( doc );
                }else if( key == "input1" ) {
                    send_input1( doc );
                }else if( key == "input2" ) {
                    send_input2( doc );
                }else if( key == "input3" ) {
                    send_input3( doc );
                }else if( key == "input4" ) {
                    send_input4( doc );
                }


                else if( key == "output0" ) {
                    send_output0( doc );
                }else if( key == "output1" ) {
                    send_output1( doc );
                }else if( key == "output2" ) {
                    send_output2( doc );
                }else if( key == "output3" ) {
                    send_output3( doc );
                }else if( key == "output4" ) {
                    send_output4( doc );
                }

                else if( key == "cfg0" ) {
                    send_cfg0( doc );
                }
                else if( key == "cfg1" ) {
                    send_cfg1( doc );
                } 
                else if( key == "cfg2" ) {
                    send_cfg2( doc );
                }
                else if( key == "cfg3" ) {
                    send_cfg3( doc );
                }
                else if( key == "cfg4" ) {
                    send_cfg4( doc );
                }
                else if( key == "cfg5" ) {
                    send_cfg5( doc );
                }
                else if( key == "cfg6" ) {
                    send_cfg6( doc );
                }
                else if( key == "cfg7" ) {
                    send_cfg7( doc );
                }
                else if( key == "cfg8" ) {
                    send_cfg8( doc );
                }
                else if( key == "cfg9" ) {
                    send_cfg9( doc );
                }
                

                 else if( key == "result_0" ) {
                    send_result_0( doc );
                 }else if( key == "result_1" ) {
                    send_result_1( doc );
                 }else if( key == "result_2" ) {
                    send_result_2( doc );
                 }else if( key == "result_3" ) {
                    send_result_3( doc );
                 }else if( key == "result_4" ) {
                    send_result_4( doc );
                 }else if( key == "result_5" ) {
                    send_result_5( doc );
                 }else if( key == "result_6" ) {
                    send_result_6( doc );
                 }else if( key == "result_7" ) {
                    send_result_7( doc );
                 }else if( key == "result_8" ) {
                    send_result_8( doc );
                 }else if( key == "result_9" ) {
                    send_result_9( doc );
                 }


                 else if( key == "result_10" ) {
                    send_result_10( doc );
                 }else if( key == "result_11" ) {
                    send_result_11( doc );
                 }else if( key == "result_12" ) {
                    send_result_12( doc );
                 }else if( key == "result_13" ) {
                    send_result_13( doc );
                 }else if( key == "result_14" ) {
                    send_result_14( doc );
                 }else if( key == "result_15" ) {
                    send_result_15( doc );
                 }else if( key == "result_16" ) {
                    send_result_16( doc );
                 }else if( key == "result_17" ) {
                    send_result_17( doc );
                 }else if( key == "result_18" ) {
                    send_result_18( doc );
                 }else if( key == "result_19" ) {
                    send_result_19( doc );
                 }
                 
                 else if( key == "result_20" ) {
                    send_result_20( doc );
                 }else if( key == "result_21" ) {
                    send_result_21( doc );
                 }else if( key == "result_22" ) {
                    send_result_22( doc );
                 }else if( key == "result_23" ) {
                    send_result_23( doc );
                 }else if( key == "result_24" ) {
                    send_result_24( doc );
                 }else if( key == "result_25" ) {
                    send_result_25( doc );
                 }else if( key == "result_26" ) {
                    send_result_26( doc );
                 }else if( key == "result_27" ) {
                    send_result_27( doc );
                 }else if( key == "result_28" ) {
                    send_result_28( doc );
                 }else if( key == "result_29" ) {
                    send_result_29( doc );
                 }


                 else if( key == "result_30" ) {
                    send_result_30( doc );
                 }else if( key == "result_31" ) {
                    send_result_31( doc );
                 }else if( key == "result_32" ) {
                    send_result_32( doc );
                 }else if( key == "result_33" ) {
                    send_result_33( doc );
                 }else if( key == "result_34" ) {
                    send_result_34( doc );
                 }else if( key == "result_35" ) {
                    send_result_35( doc );
                 }else if( key == "result_36" ) {
                    send_result_36( doc );
                 }else if( key == "result_37" ) {
                    send_result_37( doc );
                 }else if( key == "result_38" ) {
                    send_result_38( doc );
                 }else if( key == "result_39" ) {
                    send_result_39( doc );
                 }


                 else if( key == "result_40" ) {
                    send_result_40( doc );
                 }else if( key == "result_41" ) {
                    send_result_41( doc );
                 }else if( key == "result_42" ) {
                    send_result_42( doc );
                 }else if( key == "result_43" ) {
                    send_result_43( doc );
                 }else if( key == "result_44" ) {
                    send_result_44( doc );
                 }else if( key == "result_45" ) {
                    send_result_45( doc );
                 }else if( key == "result_46" ) {
                    send_result_46( doc );
                 }else if( key == "result_47" ) {
                    send_result_47( doc );
                 }else if( key == "result_48" ) {
                    send_result_48( doc );
                 }else if( key == "result_49" ) {
                    send_result_49( doc );
                 }
                      
                
            }

            // Usamos cdd hasta definir que unifiquemos comandos, en realidad es cmd. 
            // Segun el uso https://arduinojson.org/v6/api/jsondocument/containskey/ 
            // para preguntar sobre la clave de un objeto  se usa  const char* key1 =doc["data"]["distance"];

            
            if ( doc.containsKey("cdd") ) { //Verifica "cdd".
                String key = doc["cdd"];
                 if( key == "start" ) {    //Verifica "start".
                     const char* key1 =doc["data"]["input0"];
                     const char* key2 =doc["data"]["input1"];
                    if (key1 && key2) {   //Verifica "distance". "force".
                       set_input0( doc["data"]["input0"]);
                       set_input1( doc["data"]["input1"] );  
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
    doc["input0"] = get_input0();
    doc["input1"] = get_input1();
    doc["input2"] = get_input2();
    doc["input3"] = get_input3();
    doc["input4"] = get_input4();

    doc["output0"] = get_output0();
    doc["output1"] = get_output1();
    doc["output2"] = get_output2();
    doc["output3"] = get_output3();
    doc["output4"] = get_output4();

    doc["cfg0"] = get_cfg0();  
    doc["cfg1"] = get_cfg1();  
    doc["cfg2"] = get_cfg2();  
    doc["cfg3"] = get_cfg3();  
    doc["cfg4"] = get_cfg4();  
    doc["cfg5"] = get_cfg5();  
    doc["cfg6"] = get_cfg6();  
    doc["cfg7"] = get_cfg7();  
    doc["cfg8"] = get_cfg8();  
    doc["cfg9"] = get_cfg9();  
      
    doc["result_0"] = get_result_0();
    doc["result_1"] = get_result_1();
    doc["result_2"] = get_result_2();
    doc["result_3"] = get_result_3();
    doc["result_4"] = get_result_4();
    doc["result_5"] = get_result_5();
    doc["result_6"] = get_result_6();
    doc["result_7"] = get_result_7();
    doc["result_8"] = get_result_8();
    doc["result_9"] = get_result_9();

    doc["result_10"] = get_result_10();
    doc["result_11"] = get_result_11();
    doc["result_12"] = get_result_12();
    doc["result_13"] = get_result_13();
    doc["result_14"] = get_result_14();
    doc["result_15"] = get_result_15();
    doc["result_16"] = get_result_16();
    doc["result_17"] = get_result_17();
    doc["result_18"] = get_result_18();
    doc["result_19"] = get_result_19();


    doc["result_20"] = get_result_20();
    doc["result_21"] = get_result_21();
    doc["result_22"] = get_result_22();
    doc["result_23"] = get_result_23();
    doc["result_24"] = get_result_24();
    doc["result_25"] = get_result_25();
    doc["result_26"] = get_result_26();
    doc["result_27"] = get_result_27();
    doc["result_28"] = get_result_28();
    doc["result_29"] = get_result_29();


    doc["result_30"] = get_result_30();
    doc["result_31"] = get_result_31();
    doc["result_32"] = get_result_32();
    doc["result_33"] = get_result_33();
    doc["result_34"] = get_result_34();
    doc["result_35"] = get_result_35();
    doc["result_36"] = get_result_36();
    doc["result_37"] = get_result_37();
    doc["result_38"] = get_result_38();
    doc["result_39"] = get_result_39();

    doc["result_40"] = get_result_40();
    doc["result_41"] = get_result_41();
    doc["result_42"] = get_result_42();
    doc["result_43"] = get_result_43();
    doc["result_44"] = get_result_44();
    doc["result_45"] = get_result_45();
    doc["result_46"] = get_result_46();
    doc["result_47"] = get_result_47();
    doc["result_48"] = get_result_48();
    doc["result_49"] = get_result_49();
       
    serializeJsonPretty( doc, Serial );
}

/*
 *  Envia todos los parametros de calibracion de la flexion y el nivel de serialgeo.
 */

void Cmemory::send_all_input( JsonDocument& doc )
{
    doc["input0"] = get_input0();
    doc["input1"] = get_input1();
    doc["input2"] = get_input2();
    doc["input3"] = get_input3();
    doc["input4"] = get_input4();   
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_all_output( JsonDocument& doc )
{
    doc["output0"] = get_output0();
    doc["output1"] = get_output1();
    doc["output2"] = get_output2();
    doc["output3"] = get_output3();
    doc["output4"] = get_output4();
    serializeJsonPretty( doc, Serial );
}


void Cmemory::send_all_cfg( JsonDocument& doc )
{
    doc["cfg0"] = get_cfg0();  
    doc["cfg1"] = get_cfg1();  
    doc["cfg2"] = get_cfg2();  
    doc["cfg3"] = get_cfg3();  
    doc["cfg4"] = get_cfg4();  
    doc["cfg5"] = get_cfg5();  
    doc["cfg6"] = get_cfg6();  
    doc["cfg7"] = get_cfg7();  
    doc["cfg8"] = get_cfg8();  
    doc["cfg9"] = get_cfg9();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_all_result( JsonDocument& doc )
{
    doc["result_0"] = get_result_0();
    doc["result_1"] = get_result_1();
    doc["result_2"] = get_result_2();
    doc["result_3"] = get_result_3();
    doc["result_4"] = get_result_4();
    doc["result_5"] = get_result_5();
    doc["result_6"] = get_result_6();
    doc["result_7"] = get_result_7();
    doc["result_8"] = get_result_8();
    doc["result_9"] = get_result_9();

    doc["result_10"] = get_result_10();
    doc["result_11"] = get_result_11();
    doc["result_12"] = get_result_12();
    doc["result_13"] = get_result_13();
    doc["result_14"] = get_result_14();
    doc["result_15"] = get_result_15();
    doc["result_16"] = get_result_16();
    doc["result_17"] = get_result_17();
    doc["result_18"] = get_result_18();
    doc["result_19"] = get_result_19();


    doc["result_20"] = get_result_20();
    doc["result_21"] = get_result_21();
    doc["result_22"] = get_result_22();
    doc["result_23"] = get_result_23();
    doc["result_24"] = get_result_24();
    doc["result_25"] = get_result_25();
    doc["result_26"] = get_result_26();
    doc["result_27"] = get_result_27();
    doc["result_28"] = get_result_28();
    doc["result_29"] = get_result_29();


    doc["result_30"] = get_result_30();
    doc["result_31"] = get_result_31();
    doc["result_32"] = get_result_32();
    doc["result_33"] = get_result_33();
    doc["result_34"] = get_result_34();
    doc["result_35"] = get_result_35();
    doc["result_36"] = get_result_36();
    doc["result_37"] = get_result_37();
    doc["result_38"] = get_result_38();
    doc["result_39"] = get_result_39();

    doc["result_40"] = get_result_40();
    doc["result_41"] = get_result_41();
    doc["result_42"] = get_result_42();
    doc["result_43"] = get_result_43();
    doc["result_44"] = get_result_44();
    doc["result_45"] = get_result_45();
    doc["result_46"] = get_result_46();
    doc["result_47"] = get_result_47();
    doc["result_48"] = get_result_48();
    doc["result_49"] = get_result_49();

    serializeJsonPretty( doc, Serial );
}


void Cmemory::send_all_lib( JsonDocument& doc )
{
    doc["version"] = FIRMWARE_VERSION;
    doc["st_mode"] =  get_st_mode();
    doc["serial_level"] =  get_serial_level();
    doc["status"] = get_st_test();
    
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

void Cmemory::send_input0( JsonDocument& doc )
{
    doc["input0"] =  get_input0();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_input1( JsonDocument& doc )
{
    doc["input1"] =  get_input1();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_input2( JsonDocument& doc )
{
    doc["input2"] =  get_input2();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_input3( JsonDocument& doc )
{
    doc["input3"] =  get_input3();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_input4( JsonDocument& doc )
{
    doc["input4"] =  get_input4();
    serializeJsonPretty( doc, Serial );
}


void Cmemory::send_output0( JsonDocument& doc )
{
    doc["output0"] =  get_output0();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_output1( JsonDocument& doc )
{
    doc["output1"] =  get_output1();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_output2( JsonDocument& doc )
{
    doc["output2"] =  get_output2();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_output3( JsonDocument& doc )
{
    doc["output3"] =  get_output3();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_output4( JsonDocument& doc )
{
    doc["output4"] =  get_output4();
    serializeJsonPretty( doc, Serial );
}


void Cmemory::send_cfg0( JsonDocument& doc )
{
    doc["cfg0"] =  get_cfg0();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_cfg1( JsonDocument& doc )
{
    doc["cfg1"] =  get_cfg1();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_cfg2( JsonDocument& doc )
{
    doc["cfg2"] =  get_cfg2();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_cfg3( JsonDocument& doc )
{
    doc["cfg3"] =  get_cfg3();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_cfg4( JsonDocument& doc )
{
    doc["cfg4"] =  get_cfg4();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_cfg5( JsonDocument& doc )
{
    doc["cfg5"] =  get_cfg5();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_cfg6( JsonDocument& doc )
{
    doc["cfg6"] =  get_cfg6();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_cfg7( JsonDocument& doc )
{
    doc["cfg7"] =  get_cfg7();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_cfg8( JsonDocument& doc )
{
    doc["cfg8"] =  get_cfg8();
    serializeJsonPretty( doc, Serial );
}
void Cmemory::send_cfg9( JsonDocument& doc )
{
    doc["cfg9"] =  get_cfg9();
    serializeJsonPretty( doc, Serial );
}

void Cmemory::send_result_0( JsonDocument& doc )
{
  doc["result_0"] =  get_result_0();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_1( JsonDocument& doc )
{
  doc["result_1"] =  get_result_1();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_2( JsonDocument& doc )
{
  doc["result_2"] =  get_result_2();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_3( JsonDocument& doc )
{
  doc["result_3"] =  get_result_3();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_4( JsonDocument& doc )
{
  doc["result_4"] =  get_result_4();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_5( JsonDocument& doc )
{
  doc["result_5"] =  get_result_5();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_6( JsonDocument& doc )
{
  doc["result_6"] =  get_result_6();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_7( JsonDocument& doc )
{
  doc["result_7"] =  get_result_7();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_8( JsonDocument& doc )
{
  doc["result_8"] =  get_result_8();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_9( JsonDocument& doc )
{
  doc["result_9"] =  get_result_9();
  serializeJsonPretty( doc, Serial );
}


void Cmemory::send_result_10( JsonDocument& doc )
{
  doc["result_10"] =  get_result_10();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_11( JsonDocument& doc )
{
  doc["result_11"] =  get_result_11();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_12( JsonDocument& doc )
{
  doc["result_12"] =  get_result_12();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_13( JsonDocument& doc )
{
  doc["result_13"] =  get_result_13();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_14( JsonDocument& doc )
{
  doc["result_14"] =  get_result_14();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_15( JsonDocument& doc )
{
  doc["result_15"] =  get_result_15();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_16( JsonDocument& doc )
{
  doc["result_16"] =  get_result_16();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_17( JsonDocument& doc )
{
  doc["result_17"] =  get_result_17();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_18( JsonDocument& doc )
{
  doc["result_18"] =  get_result_18();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_19( JsonDocument& doc )
{
  doc["result_19"] =  get_result_19();
  serializeJsonPretty( doc, Serial );
}


void Cmemory::send_result_20( JsonDocument& doc )
{
  doc["result_20"] =  get_result_20();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_21( JsonDocument& doc )
{
  doc["result_21"] =  get_result_21();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_22( JsonDocument& doc )
{
  doc["result_22"] =  get_result_22();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_23( JsonDocument& doc )
{
  doc["result_23"] =  get_result_23();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_24( JsonDocument& doc )
{
  doc["result_24"] =  get_result_24();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_25( JsonDocument& doc )
{
  doc["result_25"] =  get_result_25();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_26( JsonDocument& doc )
{
  doc["result_26"] =  get_result_26();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_27( JsonDocument& doc )
{
  doc["result_27"] =  get_result_27();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_28( JsonDocument& doc )
{
  doc["result_28"] =  get_result_28();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_29( JsonDocument& doc )
{
  doc["result_29"] =  get_result_29();
  serializeJsonPretty( doc, Serial );
}



void Cmemory::send_result_30( JsonDocument& doc )
{
  doc["result_30"] =  get_result_30();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_31( JsonDocument& doc )
{
  doc["result_31"] =  get_result_31();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_32( JsonDocument& doc )
{
  doc["result_32"] =  get_result_32();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_33( JsonDocument& doc )
{
  doc["result_33"] =  get_result_33();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_34( JsonDocument& doc )
{
  doc["result_34"] =  get_result_34();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_35( JsonDocument& doc )
{
  doc["result_35"] =  get_result_35();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_36( JsonDocument& doc )
{
  doc["result_36"] =  get_result_36();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_37( JsonDocument& doc )
{
  doc["result_37"] =  get_result_37();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_38( JsonDocument& doc )
{
  doc["result_38"] =  get_result_38();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_39( JsonDocument& doc )
{
  doc["result_39"] =  get_result_39();
  serializeJsonPretty( doc, Serial );
}



void Cmemory::send_result_40( JsonDocument& doc )
{
  doc["result_40"] =  get_result_40();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_41( JsonDocument& doc )
{
  doc["result_41"] =  get_result_41();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_42( JsonDocument& doc )
{
  doc["result_42"] =  get_result_42();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_43( JsonDocument& doc )
{
  doc["result_43"] =  get_result_43();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_44( JsonDocument& doc )
{
  doc["result_44"] =  get_result_44();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_45( JsonDocument& doc )
{
  doc["result_45"] =  get_result_45();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_46( JsonDocument& doc )
{
  doc["result_46"] =  get_result_46();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_47( JsonDocument& doc )
{
  doc["result_47"] =  get_result_47();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_48( JsonDocument& doc )
{
  doc["result_48"] =  get_result_48();
  serializeJsonPretty( doc, Serial );
}
void Cmemory::send_result_49( JsonDocument& doc )
{
  doc["result_49"] =  get_result_49();
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
