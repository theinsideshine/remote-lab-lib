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
#include "log.h"
#include "param.h"



#include <EEPROM.h>



CMemory::CMemory()
{
uint8_t magic_number;

    EEPROM.get( EEPROM_ADDRESS_MAGIC_NUMBER, magic_number );

   
    if( magic_number != MAGIC_NUMBER ){
        magic_number = MAGIC_NUMBER;
        EEPROM.put( EEPROM_ADDRESS_MAGIC_NUMBER, magic_number );  


         //set_serial_level( serial_DISABLED );
        set_log_level( LOG_MSG );    // Cuando cambias el magic number setea los mensajes de logeo en 1 activo        
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


        set_result0( RESULT_0_DEFAULT );
        set_result1( RESULT_1_DEFAULT );
        set_result2( RESULT_2_DEFAULT );
        set_result3( RESULT_3_DEFAULT );
        set_result4( RESULT_4_DEFAULT );
        set_result5( RESULT_5_DEFAULT );
        set_result6( RESULT_6_DEFAULT );
        set_result7( RESULT_7_DEFAULT );
        set_result8( RESULT_8_DEFAULT );
        set_result9( RESULT_9_DEFAULT );

        set_result10( RESULT_10_DEFAULT );
        set_result11( RESULT_11_DEFAULT );
        set_result12( RESULT_12_DEFAULT );
        set_result13( RESULT_13_DEFAULT );
        set_result14( RESULT_14_DEFAULT );
        set_result15( RESULT_15_DEFAULT );
        set_result16( RESULT_16_DEFAULT );
        set_result17( RESULT_17_DEFAULT );
        set_result18( RESULT_18_DEFAULT );
        set_result19( RESULT_19_DEFAULT );

        set_result20( RESULT_20_DEFAULT );
        set_result21( RESULT_21_DEFAULT );
        set_result22( RESULT_22_DEFAULT );
        set_result23( RESULT_23_DEFAULT );
        set_result24( RESULT_24_DEFAULT );
        set_result25( RESULT_25_DEFAULT );
        set_result26( RESULT_26_DEFAULT );
        set_result27( RESULT_27_DEFAULT );
        set_result28( RESULT_28_DEFAULT );
        set_result29( RESULT_29_DEFAULT );

        set_result30( RESULT_30_DEFAULT );
        set_result31( RESULT_31_DEFAULT );
        set_result32( RESULT_32_DEFAULT );
        set_result33( RESULT_33_DEFAULT );
        set_result34( RESULT_34_DEFAULT );
        set_result35( RESULT_35_DEFAULT );
        set_result36( RESULT_36_DEFAULT );
        set_result37( RESULT_37_DEFAULT );
        set_result38( RESULT_38_DEFAULT );
        set_result39( RESULT_39_DEFAULT );
        
        set_result40( RESULT_40_DEFAULT );
        set_result41( RESULT_41_DEFAULT );
        set_result42( RESULT_42_DEFAULT );
        set_result43( RESULT_43_DEFAULT );
        set_result44( RESULT_44_DEFAULT );
        set_result45( RESULT_45_DEFAULT );
        set_result46( RESULT_46_DEFAULT );
        set_result47( RESULT_47_DEFAULT );
        set_result48( RESULT_48_DEFAULT );
        set_result49( RESULT_49_DEFAULT );
    
    }else {
        
        EEPROM.get( EEPROM_ADDRESS_SERIAL_LEVEL, log_level );
        //EEPROM.get( EEPROM_ADDRESS_ST_MODE, st_mode );
        
       //EEPROM.get( EEPROM_ADDRESS_ST_TEST, st_test );
       // Estos parametro inicializa en 0 independiente de como este en la eprrom ya que estos ejecutan el ST_LOOP
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
       

      
       EEPROM.get( EEPROM_ADDRESS_RESULT_0, result0 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_1, result1 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_2, result2 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_3, result3 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_4, result4 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_5, result5 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_6, result6 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_7, result7 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_8, result8 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_9, result9 );

       EEPROM.get( EEPROM_ADDRESS_RESULT_10, result10 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_11, result11 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_12, result12 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_13, result13 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_14, result14 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_15, result15 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_16, result16 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_17, result17 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_18, result18 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_19, result19 );

       EEPROM.get( EEPROM_ADDRESS_RESULT_20, result20 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_21, result21 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_22, result22 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_23, result23 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_24, result24 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_25, result25 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_26, result26 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_27, result27 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_28, result28 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_29, result29 );

       EEPROM.get( EEPROM_ADDRESS_RESULT_30, result30 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_31, result31 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_32, result32 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_33, result33 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_34, result34 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_35, result35 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_36, result36 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_37, result37 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_38, result38 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_39, result39 );
       
       EEPROM.get( EEPROM_ADDRESS_RESULT_40, result40 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_41, result41 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_42, result42 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_43, result43 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_44, result44 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_45, result45 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_46, result46 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_47, result47 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_48, result48 );
       EEPROM.get( EEPROM_ADDRESS_RESULT_49, result49 );

                   
    }
}


uint8_t CMemory::get_log_level( void )
{
    return log_level;
}

void CMemory::set_log_level( uint8_t enable )
{
    log_level = enable;
    EEPROM.put( EEPROM_ADDRESS_SERIAL_LEVEL, log_level );
}

 
uint8_t CMemory::get_st_test( void )
{
    return st_test;
}

void CMemory::set_st_test( uint8_t enable )
{
    st_test = enable;
    EEPROM.put( EEPROM_ADDRESS_ST_TEST, st_test );
}

uint8_t CMemory::get_st_mode( void )
{
    return st_mode;
}

void CMemory::set_st_mode( uint8_t mode )
{
    st_mode = mode;
    EEPROM.put( EEPROM_ADDRESS_ST_MODE, st_mode );
}



float CMemory::get_input0( void )
{return input0;}
void CMemory::set_input0( float val )
{ input0 = val;
  EEPROM.put( EEPROM_ADDRESS_INPUT_0, val );
}
float CMemory::get_input1( void )
{return input1;}
void CMemory::set_input1( float val )
{ input1 = val;
  EEPROM.put( EEPROM_ADDRESS_INPUT_1, val );
}
float CMemory::get_input2( void )
{return input2;}
void CMemory::set_input2( float val )
{ input2 = val;
  EEPROM.put( EEPROM_ADDRESS_INPUT_2, val );
}
float CMemory::get_input3( void )
{return input3;}
void CMemory::set_input3( float val )
{ input3 = val;
  EEPROM.put( EEPROM_ADDRESS_INPUT_3, val );
}
float CMemory::get_input4( void )
{return input4;}
void CMemory::set_input4( float val )
{ input4 = val;
  EEPROM.put( EEPROM_ADDRESS_INPUT_4, val );
}



float CMemory::get_output0( void )
{return output0;}
void CMemory::set_output0( float val )
{ output0 = val;
  EEPROM.put( EEPROM_ADDRESS_OUTPUT_0, val );
}
float CMemory::get_output1( void )
{return output1;}
void CMemory::set_output1( float val )
{ output1 = val;
  EEPROM.put( EEPROM_ADDRESS_OUTPUT_1, val );
}
float CMemory::get_output2( void )
{return output2;}
void CMemory::set_output2( float val )
{ output2 = val;
  EEPROM.put( EEPROM_ADDRESS_OUTPUT_2, val );
}
float CMemory::get_output3( void )
{return output3;}
void CMemory::set_output3( float val )
{ output3 = val;
  EEPROM.put( EEPROM_ADDRESS_OUTPUT_3, val );
}
float CMemory::get_output4( void )
{return output4;}
void CMemory::set_output4( float val )
{ output4 = val;
  EEPROM.put( EEPROM_ADDRESS_OUTPUT_4, val );
}





float CMemory::get_cfg0( void )
{return cfg0;}
void CMemory::set_cfg0( float val )
{ cfg0 = val;
  EEPROM.put( EEPROM_ADDRESS_CFG_0, val );
}
float CMemory::get_cfg1( void )
{return cfg1;}
void CMemory::set_cfg1( float val )
{ cfg1 = val;
 EEPROM.put( EEPROM_ADDRESS_CFG_1, val );
}
float CMemory::get_cfg2( void )
{return cfg2;}
void CMemory::set_cfg2( float val )
{ cfg2 = val;
 EEPROM.put( EEPROM_ADDRESS_CFG_2, val );
}
float CMemory::get_cfg3( void )
{return cfg3;}
void CMemory::set_cfg3( float val )
{ cfg3 = val;
 EEPROM.put( EEPROM_ADDRESS_CFG_3, val );
}
float CMemory::get_cfg4( void )
{return cfg4;}
void CMemory::set_cfg4( float val )
{ cfg4 = val;
  EEPROM.put( EEPROM_ADDRESS_CFG_4, val );
}
float CMemory::get_cfg5( void )
{return cfg5;}
void CMemory::set_cfg5( float val )
{ cfg5 = val;
  EEPROM.put( EEPROM_ADDRESS_CFG_5, val );
}
float CMemory::get_cfg6( void )
{return cfg6;}
void CMemory::set_cfg6( float val )
{ cfg6 = val;
  EEPROM.put( EEPROM_ADDRESS_CFG_6, val );
}
float CMemory::get_cfg7( void )
{return cfg7;}
void CMemory::set_cfg7( float val )
{ cfg7 = val;
  EEPROM.put( EEPROM_ADDRESS_CFG_7, val );
}
float CMemory::get_cfg8( void )
{return cfg8;}
void CMemory::set_cfg8( float val )
{ cfg8 = val;
  EEPROM.put( EEPROM_ADDRESS_CFG_8, val );
}
float CMemory::get_cfg9( void )
{return cfg9;}
void CMemory::set_cfg9( float val )
{ cfg9 = val;
   EEPROM.put( EEPROM_ADDRESS_CFG_9, val );
}



float CMemory::get_result0( void )
{return result0;}
void CMemory::set_result0( float val )
{ result0 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_0, val );
}
float CMemory::get_result1( void )
{return result1;}
void CMemory::set_result1( float val )
{ result1 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_1, val );
}
float CMemory::get_result2( void )
{return result2;}
void CMemory::set_result2( float val )
{ result2 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_2, val );
}
float CMemory::get_result3( void )
{return result3;}
void CMemory::set_result3( float val )
{ result3 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_3, val );
}
float CMemory::get_result4( void )
{return result4;}
void CMemory::set_result4( float val )
{ result4 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_4, val );
}
float CMemory::get_result5( void )
{return result5;}
void CMemory::set_result5( float val )
{ result5 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_5, val );
}
float CMemory::get_result6( void )
{return result6;}
void CMemory::set_result6( float val )
{ result6 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_6, val );
}
float CMemory::get_result7( void )
{return result7;}
void CMemory::set_result7( float val )
{ result7 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_7, val );
}
float CMemory::get_result8( void )
{return result8;}
void CMemory::set_result8( float val )
{ result8 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_8, val );
}
float CMemory::get_result9( void )
{return result9;}
void CMemory::set_result9( float val )
{ result9 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_9, val );
}



float CMemory::get_result10( void )
{return result10;}
void CMemory::set_result10( float val )
{ result10 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_10, val );
}
float CMemory::get_result11( void )
{return result11;}
void CMemory::set_result11( float val )
{ result11 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_11, val );
}
float CMemory::get_result12( void )
{return result12;}
void CMemory::set_result12( float val )
{ result12 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_12, val );
}
float CMemory::get_result13( void )
{return result13;}
void CMemory::set_result13( float val )
{ result13 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_13, val );
}
float CMemory::get_result14( void )
{return result14;}
void CMemory::set_result14( float val )
{ result14 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_14, val );
}
float CMemory::get_result15( void )
{return result15;}
void CMemory::set_result15( float val )
{ result15 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_15, val );
}
float CMemory::get_result16( void )
{return result16;}
void CMemory::set_result16( float val )
{ result16 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_16, val );
}
float CMemory::get_result17( void )
{return result17;}
void CMemory::set_result17( float val )
{ result17 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_17, val );
}
float CMemory::get_result18( void )
{return result18;}
void CMemory::set_result18( float val )
{ result18 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_18, val );
}
float CMemory::get_result19( void )
{return result19;}
void CMemory::set_result19( float val )
{ result19 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_19, val );
}

float CMemory::get_result20( void )
{return result20;}
void CMemory::set_result20( float val )
{ result20 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_20, val );
}
float CMemory::get_result21( void )
{return result21;}
void CMemory::set_result21( float val )
{ result21 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_21, val );
}
float CMemory::get_result22( void )
{return result22;}
void CMemory::set_result22( float val )
{ result22 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_22, val );
}
float CMemory::get_result23( void )
{return result23;}
void CMemory::set_result23( float val )
{ result23 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_23, val );
}
float CMemory::get_result24( void )
{return result24;}
void CMemory::set_result24( float val )
{ result24 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_24, val );
}
float CMemory::get_result25( void )
{return result25;}
void CMemory::set_result25( float val )
{ result25 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_25, val );
}
float CMemory::get_result26( void )
{return result26;}
void CMemory::set_result26( float val )
{ result26 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_26, val );
}
float CMemory::get_result27( void )
{return result27;}
void CMemory::set_result27( float val )
{ result27 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_27, val );
}
float CMemory::get_result28( void )
{return result28;}
void CMemory::set_result28( float val )
{ result28 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_28, val );
}
float CMemory::get_result29( void )
{return result29;}
void CMemory::set_result29( float val )
{ result29 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_29, val );
}

float CMemory::get_result30( void )
{return result30;}
void CMemory::set_result30( float val )
{ result30 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_30, val );
}
float CMemory::get_result31( void )
{return result31;}
void CMemory::set_result31( float val )
{ result31 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_31, val );
}
float CMemory::get_result32( void )
{return result32;}
void CMemory::set_result32( float val )
{ result32 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_32, val );
}
float CMemory::get_result33( void )
{return result33;}
void CMemory::set_result33( float val )
{ result33 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_33, val );
}
float CMemory::get_result34( void )
{return result34;}
void CMemory::set_result34( float val )
{ result34 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_34, val );
}
float CMemory::get_result35( void )
{return result35;}
void CMemory::set_result35( float val )
{ result35 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_35, val );
}
float CMemory::get_result36( void )
{return result36;}
void CMemory::set_result36( float val )
{ result36 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_36, val );
}
float CMemory::get_result37( void )
{return result37;}
void CMemory::set_result37( float val )
{ result37 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_37, val );
}
float CMemory::get_result38( void )
{return result38;}
void CMemory::set_result38( float val )
{ result38 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_38, val );
}
float CMemory::get_result39( void )
{return result39;}
void CMemory::set_result39( float val )
{ result39 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_39, val );
}


float CMemory::get_result40( void )
{return result40;}
void CMemory::set_result40( float val )
{ result40 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_40, val );
}
float CMemory::get_result41( void )
{return result41;}
void CMemory::set_result41( float val )
{ result41 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_41, val );
}
float CMemory::get_result42( void )
{return result42;}
void CMemory::set_result42( float val )
{ result42 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_42, val );
}
float CMemory::get_result43( void )
{return result43;}
void CMemory::set_result43( float val )
{ result43 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_43, val );
}
float CMemory::get_result44( void )
{return result44;}
void CMemory::set_result44( float val )
{ result44 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_44, val );
}
float CMemory::get_result45( void )
{return result45;}
void CMemory::set_result45( float val )
{ result45 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_45, val );
}
float CMemory::get_result46( void )
{return result46;}
void CMemory::set_result46( float val )
{ result46 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_46, val );
}
float CMemory::get_result47( void )
{return result47;}
void CMemory::set_result47( float val )
{ result47 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_47, val );
}
float CMemory::get_result48( void )
{return result48;}
void CMemory::set_result48( float val )
{ result48 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_48, val );
}
float CMemory::get_result49( void )
{return result49;}
void CMemory::set_result49( float val )
{ result49 = val;
  EEPROM.put( EEPROM_ADDRESS_RESULT_49, val );
}

                                   

void CMemory::host_cmd( void )
{
bool known_key = false;

    if ( Serial.available() ){
        StaticJsonDocument<512> doc;
        auto error = deserializeJson( doc, Serial );
        if ( !error ) {     
                      
            if ( doc.containsKey("serial_level") ) {
                set_log_level( doc["serial_level"] );
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

            

            if ( doc.containsKey("result0") ) {
                set_result0( doc["result0"] );
                known_key = true;
            }
            if ( doc.containsKey("result1") ) {
                set_result1( doc["result1"] );
                known_key = true;
            }
            if ( doc.containsKey("result2") ) {
                set_result2( doc["result2"] );
                known_key = true;
            }
            if ( doc.containsKey("result3") ) {
                set_result3( doc["result3"] );
                known_key = true;
            }
            if ( doc.containsKey("result4") ) {
                set_result4( doc["result4"] );
                known_key = true;
            }
            if ( doc.containsKey("result5") ) {
                set_result5( doc["result5"] );
                known_key = true;
            }
            if ( doc.containsKey("result6") ) {
                set_result6( doc["result6"] );
                known_key = true;
            }
            if ( doc.containsKey("result7") ) {
                set_result7( doc["result7"] );
                known_key = true;
            }
            if ( doc.containsKey("result8") ) {
                set_result8( doc["result8"] );
                known_key = true;
            }
            if ( doc.containsKey("result9") ) {
                set_result9( doc["result9"] );
                known_key = true;
            }



            if ( doc.containsKey("result10") ) {
                set_result10( doc["result10"] );
                known_key = true;
            }
            if ( doc.containsKey("result11") ) {
                set_result11( doc["result11"] );
                known_key = true;
            }
            if ( doc.containsKey("result12") ) {
                set_result12( doc["result12"] );
                known_key = true;
            }
            if ( doc.containsKey("result13") ) {
                set_result13( doc["result13"] );
                known_key = true;
            }
            if ( doc.containsKey("result14") ) {
                set_result14( doc["result14"] );
                known_key = true;
            }
            if ( doc.containsKey("result15") ) {
                set_result15( doc["result15"] );
                known_key = true;
            }
            if ( doc.containsKey("result16") ) {
                set_result16( doc["result16"] );
                known_key = true;
            }
            if ( doc.containsKey("result17") ) {
                set_result17( doc["result17"] );
                known_key = true;
            }
            if ( doc.containsKey("result18") ) {
                set_result18( doc["result18"] );
                known_key = true;
            }
            if ( doc.containsKey("result19") ) {
                set_result19( doc["result19"] );
                known_key = true;
            }



            if ( doc.containsKey("result20") ) {
                set_result20( doc["result20"] );
                known_key = true;
            }
            if ( doc.containsKey("result21") ) {
                set_result21( doc["result21"] );
                known_key = true;
            }
            if ( doc.containsKey("result22") ) {
                set_result22( doc["result22"] );
                known_key = true;
            }
            if ( doc.containsKey("result23") ) {
                set_result23( doc["result23"] );
                known_key = true;
            }
            if ( doc.containsKey("result24") ) {
                set_result24( doc["result24"] );
                known_key = true;
            }
            if ( doc.containsKey("result25") ) {
                set_result25( doc["result25"] );
                known_key = true;
            }
            if ( doc.containsKey("result26") ) {
                set_result26( doc["result26"] );
                known_key = true;
            }
            if ( doc.containsKey("result27") ) {
                set_result27( doc["result27"] );
                known_key = true;
            }
            if ( doc.containsKey("result28") ) {
                set_result28( doc["result28"] );
                known_key = true;
            }
            if ( doc.containsKey("result29") ) {
                set_result29( doc["result29"] );
                known_key = true;
            }



            if ( doc.containsKey("result30") ) {
                set_result30( doc["result30"] );
                known_key = true;
            }
            if ( doc.containsKey("result31") ) {
                set_result31( doc["result31"] );
                known_key = true;
            }
            if ( doc.containsKey("result32") ) {
                set_result32( doc["result32"] );
                known_key = true;
            }
            if ( doc.containsKey("result33") ) {
                set_result33( doc["result33"] );
                known_key = true;
            }
            if ( doc.containsKey("result34") ) {
                set_result34( doc["result34"] );
                known_key = true;
            }
            if ( doc.containsKey("result35") ) {
                set_result35( doc["result35"] );
                known_key = true;
            }
            if ( doc.containsKey("result36") ) {
                set_result36( doc["result36"] );
                known_key = true;
            }
            if ( doc.containsKey("result37") ) {
                set_result37( doc["result37"] );
                known_key = true;
            }
            if ( doc.containsKey("result38") ) {
                set_result38( doc["result38"] );
                known_key = true;
            }
            if ( doc.containsKey("result39") ) {
                set_result39( doc["result39"] );
                known_key = true;
            }



            if ( doc.containsKey("result40") ) {
                set_result40( doc["result40"] );
                known_key = true;
            }
            if ( doc.containsKey("result41") ) {
                set_result41( doc["result41"] );
                known_key = true;
            }
            if ( doc.containsKey("result42") ) {
                set_result42( doc["result42"] );
                known_key = true;
            }
            if ( doc.containsKey("result43") ) {
                set_result43( doc["result43"] );
                known_key = true;
            }
            if ( doc.containsKey("result44") ) {
                set_result44( doc["result44"] );
                known_key = true;
            }
            if ( doc.containsKey("result45") ) {
                set_result45( doc["result45"] );
                known_key = true;
            }
            if ( doc.containsKey("result46") ) {
                set_result46( doc["result46"] );
                known_key = true;
            }
            if ( doc.containsKey("result47") ) {
                set_result47( doc["result47"] );
                known_key = true;
            }
            if ( doc.containsKey("result48") ) {
                set_result48( doc["result48"] );
                known_key = true;
            }
            if ( doc.containsKey("result49") ) {
                set_result49( doc["result49"] );
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
                else if( key == "all-output" ) {
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
                    send_log_level( doc );
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
                

                 else if( key == "result0" ) {
                    send_result0( doc );
                 }else if( key == "result1" ) {
                    send_result1( doc );
                 }else if( key == "result2" ) {
                    send_result2( doc );
                 }else if( key == "result3" ) {
                    send_result3( doc );
                 }else if( key == "result4" ) {
                    send_result4( doc );
                 }else if( key == "result5" ) {
                    send_result5( doc );
                 }else if( key == "result6" ) {
                    send_result6( doc );
                 }else if( key == "result7" ) {
                    send_result7( doc );
                 }else if( key == "result8" ) {
                    send_result8( doc );
                 }else if( key == "result9" ) {
                    send_result9( doc );
                 }


                 else if( key == "result10" ) {
                    send_result10( doc );
                 }else if( key == "result11" ) {
                    send_result11( doc );
                 }else if( key == "result12" ) {
                    send_result12( doc );
                 }else if( key == "result13" ) {
                    send_result13( doc );
                 }else if( key == "result14" ) {
                    send_result14( doc );
                 }else if( key == "result15" ) {
                    send_result15( doc );
                 }else if( key == "result16" ) {
                    send_result16( doc );
                 }else if( key == "result17" ) {
                    send_result17( doc );
                 }else if( key == "result18" ) {
                    send_result18( doc );
                 }else if( key == "result19" ) {
                    send_result19( doc );
                 }
                 
                 else if( key == "result20" ) {
                    send_result20( doc );
                 }else if( key == "result21" ) {
                    send_result21( doc );
                 }else if( key == "result22" ) {
                    send_result22( doc );
                 }else if( key == "result23" ) {
                    send_result23( doc );
                 }else if( key == "result24" ) {
                    send_result24( doc );
                 }else if( key == "result25" ) {
                    send_result25( doc );
                 }else if( key == "result26" ) {
                    send_result26( doc );
                 }else if( key == "result27" ) {
                    send_result27( doc );
                 }else if( key == "result28" ) {
                    send_result28( doc );
                 }else if( key == "result29" ) {
                    send_result29( doc );
                 }


                 else if( key == "result30" ) {
                    send_result30( doc );
                 }else if( key == "result31" ) {
                    send_result31( doc );
                 }else if( key == "result32" ) {
                    send_result32( doc );
                 }else if( key == "result33" ) {
                    send_result33( doc );
                 }else if( key == "result34" ) {
                    send_result34( doc );
                 }else if( key == "result35" ) {
                    send_result35( doc );
                 }else if( key == "result36" ) {
                    send_result36( doc );
                 }else if( key == "result37" ) {
                    send_result37( doc );
                 }else if( key == "result38" ) {
                    send_result38( doc );
                 }else if( key == "result39" ) {
                    send_result39( doc );
                 }


                 else if( key == "result40" ) {
                    send_result40( doc );
                 }else if( key == "result41" ) {
                    send_result41( doc );
                 }else if( key == "result42" ) {
                    send_result42( doc );
                 }else if( key == "result43" ) {
                    send_result43( doc );
                 }else if( key == "result44" ) {
                    send_result44( doc );
                 }else if( key == "result45" ) {
                    send_result45( doc );
                 }else if( key == "result46" ) {
                    send_result46( doc );
                 }else if( key == "result47" ) {
                    send_result47( doc );
                 }else if( key == "result48" ) {
                    send_result48( doc );
                 }else if( key == "result49" ) {
                    send_result49( doc );
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

void CMemory::send_all_parameters( JsonDocument& doc )
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
      
    doc["result0"] = get_result0();
    doc["result1"] = get_result1();
    doc["result2"] = get_result2();
    doc["result3"] = get_result3();
    doc["result4"] = get_result4();
    doc["result5"] = get_result5();
    doc["result6"] = get_result6();
    doc["result7"] = get_result7();
    doc["result8"] = get_result8();
    doc["result9"] = get_result9();

    doc["result10"] = get_result10();
    doc["result11"] = get_result11();
    doc["result12"] = get_result12();
    doc["result13"] = get_result13();
    doc["result14"] = get_result14();
    doc["result15"] = get_result15();
    doc["result16"] = get_result16();
    doc["result17"] = get_result17();
    doc["result18"] = get_result18();
    doc["result19"] = get_result19();


    doc["result20"] = get_result20();
    doc["result21"] = get_result21();
    doc["result22"] = get_result22();
    doc["result23"] = get_result23();
    doc["result24"] = get_result24();
    doc["result25"] = get_result25();
    doc["result26"] = get_result26();
    doc["result27"] = get_result27();
    doc["result28"] = get_result28();
    doc["result29"] = get_result29();


    doc["result30"] = get_result30();
    doc["result31"] = get_result31();
    doc["result32"] = get_result32();
    doc["result33"] = get_result33();
    doc["result34"] = get_result34();
    doc["result35"] = get_result35();
    doc["result36"] = get_result36();
    doc["result37"] = get_result37();
    doc["result38"] = get_result38();
    doc["result39"] = get_result39();

    doc["result40"] = get_result40();
    doc["result41"] = get_result41();
    doc["result42"] = get_result42();
    doc["result43"] = get_result43();
    doc["result44"] = get_result44();
    doc["result45"] = get_result45();
    doc["result46"] = get_result46();
    doc["result47"] = get_result47();
    doc["result48"] = get_result48();
    doc["result49"] = get_result49();
       
    serializeJsonPretty( doc, Serial );
}

/*
 *  Envia todos los parametros de calibracion de la flexion y el nivel de serialgeo.
 */

void CMemory::send_all_input( JsonDocument& doc )
{
    doc["input0"] = get_input0();
    doc["input1"] = get_input1();
    doc["input2"] = get_input2();
    doc["input3"] = get_input3();
    doc["input4"] = get_input4();   
    serializeJsonPretty( doc, Serial );
}

void CMemory::send_all_output( JsonDocument& doc )
{
    doc["output0"] = get_output0();
    doc["output1"] = get_output1();
    doc["output2"] = get_output2();
    doc["output3"] = get_output3();
    doc["output4"] = get_output4();
    serializeJsonPretty( doc, Serial );
}


void CMemory::send_all_cfg( JsonDocument& doc )
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
void CMemory::send_all_result( JsonDocument& doc )
{
    doc["result0"] = get_result0();
    doc["result1"] = get_result1();
    doc["result2"] = get_result2();
    doc["result3"] = get_result3();
    doc["result4"] = get_result4();
    doc["result5"] = get_result5();
    doc["result6"] = get_result6();
    doc["result7"] = get_result7();
    doc["result8"] = get_result8();
    doc["result9"] = get_result9();

    doc["result10"] = get_result10();
    doc["result11"] = get_result11();
    doc["result12"] = get_result12();
    doc["result13"] = get_result13();
    doc["result14"] = get_result14();
    doc["result15"] = get_result15();
    doc["result16"] = get_result16();
    doc["result17"] = get_result17();
    doc["result18"] = get_result18();
    doc["result19"] = get_result19();

    doc["result20"] = get_result20();
    doc["result21"] = get_result21();
    doc["result22"] = get_result22();
    doc["result23"] = get_result23();
    doc["result24"] = get_result24();
    doc["result25"] = get_result25();
    doc["result26"] = get_result26();
    doc["result27"] = get_result27();
    doc["result28"] = get_result28();
    doc["result29"] = get_result29();


    doc["result30"] = get_result30();
    doc["result31"] = get_result31();
    doc["result32"] = get_result32();
    doc["result33"] = get_result33();
    doc["result34"] = get_result34();
    doc["result35"] = get_result35();
    doc["result36"] = get_result36();
    doc["result37"] = get_result37();
    doc["result38"] = get_result38();
    doc["result39"] = get_result39();

    doc["result40"] = get_result40();
    doc["result41"] = get_result41();
    doc["result42"] = get_result42();
    doc["result43"] = get_result43();
    doc["result44"] = get_result44();
    doc["result45"] = get_result45();
    doc["result46"] = get_result46();
    doc["result47"] = get_result47();
    doc["result48"] = get_result48();
    doc["result49"] = get_result49();

    serializeJsonPretty( doc, Serial );
}


void CMemory::send_all_lib( JsonDocument& doc )
{
    doc["version"] = FIRMWARE_VERSION;
    doc["st_mode"] =  get_st_mode();
    doc["serial_level"] =  get_log_level();
    doc["status"] = get_st_test();
    
    serializeJsonPretty( doc, Serial );
}

//Envia el status del test
void CMemory::send_test_finish( void )
{
    StaticJsonDocument<512> doc;   
    doc["st_test"] = get_st_test();  
    serializeJsonPretty( doc, Serial );
}

// Envia la version del firmware.
void CMemory::send_version( JsonDocument& doc )
{
    doc["version"] = FIRMWARE_VERSION;

    serializeJsonPretty( doc, Serial );
}

// Envia el nivel de serialeo
void CMemory::send_log_level( JsonDocument& doc )
{
    doc["serial_level"] =  get_log_level();

    serializeJsonPretty( doc, Serial );
}

// Envia el estatus del ensayo.
void CMemory::send_status( JsonDocument& doc )
{
    doc["status"] = get_st_test();

    serializeJsonPretty( doc, Serial );
}

// Envia el modo del ensayo.
void CMemory::send_st_mode( JsonDocument& doc )
{
    doc["st_mode"] = get_st_mode();

    serializeJsonPretty( doc, Serial );
}

void CMemory::send_input0( JsonDocument& doc )
{
    doc["input0"] =  get_input0();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_input1( JsonDocument& doc )
{
    doc["input1"] =  get_input1();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_input2( JsonDocument& doc )
{
    doc["input2"] =  get_input2();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_input3( JsonDocument& doc )
{
    doc["input3"] =  get_input3();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_input4( JsonDocument& doc )
{
    doc["input4"] =  get_input4();
    serializeJsonPretty( doc, Serial );
}


void CMemory::send_output0( JsonDocument& doc )
{
    doc["output0"] =  get_output0();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_output1( JsonDocument& doc )
{
    doc["output1"] =  get_output1();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_output2( JsonDocument& doc )
{
    doc["output2"] =  get_output2();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_output3( JsonDocument& doc )
{
    doc["output3"] =  get_output3();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_output4( JsonDocument& doc )
{
    doc["output4"] =  get_output4();
    serializeJsonPretty( doc, Serial );
}


void CMemory::send_cfg0( JsonDocument& doc )
{
    doc["cfg0"] =  get_cfg0();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_cfg1( JsonDocument& doc )
{
    doc["cfg1"] =  get_cfg1();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_cfg2( JsonDocument& doc )
{
    doc["cfg2"] =  get_cfg2();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_cfg3( JsonDocument& doc )
{
    doc["cfg3"] =  get_cfg3();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_cfg4( JsonDocument& doc )
{
    doc["cfg4"] =  get_cfg4();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_cfg5( JsonDocument& doc )
{
    doc["cfg5"] =  get_cfg5();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_cfg6( JsonDocument& doc )
{
    doc["cfg6"] =  get_cfg6();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_cfg7( JsonDocument& doc )
{
    doc["cfg7"] =  get_cfg7();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_cfg8( JsonDocument& doc )
{
    doc["cfg8"] =  get_cfg8();
    serializeJsonPretty( doc, Serial );
}
void CMemory::send_cfg9( JsonDocument& doc )
{
    doc["cfg9"] =  get_cfg9();
    serializeJsonPretty( doc, Serial );
}

void CMemory::send_result0( JsonDocument& doc )
{
  doc["result0"] =  get_result0();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result1( JsonDocument& doc )
{
  doc["result1"] =  get_result1();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result2( JsonDocument& doc )
{
  doc["result2"] =  get_result2();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result3( JsonDocument& doc )
{
  doc["result3"] =  get_result3();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result4( JsonDocument& doc )
{
  doc["result4"] =  get_result4();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result5( JsonDocument& doc )
{
  doc["result5"] =  get_result5();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result6( JsonDocument& doc )
{
  doc["result6"] =  get_result6();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result7( JsonDocument& doc )
{
  doc["result7"] =  get_result7();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result8( JsonDocument& doc )
{
  doc["result8"] =  get_result8();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result9( JsonDocument& doc )
{
  doc["result9"] =  get_result9();
  serializeJsonPretty( doc, Serial );
}


void CMemory::send_result10( JsonDocument& doc )
{
  doc["result10"] =  get_result10();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result11( JsonDocument& doc )
{
  doc["result11"] =  get_result11();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result12( JsonDocument& doc )
{
  doc["result12"] =  get_result12();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result13( JsonDocument& doc )
{
  doc["result13"] =  get_result13();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result14( JsonDocument& doc )
{
  doc["result14"] =  get_result14();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result15( JsonDocument& doc )
{
  doc["result15"] =  get_result15();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result16( JsonDocument& doc )
{
  doc["result16"] =  get_result16();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result17( JsonDocument& doc )
{
  doc["result17"] =  get_result17();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result18( JsonDocument& doc )
{
  doc["result18"] =  get_result18();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result19( JsonDocument& doc )
{
  doc["result19"] =  get_result19();
  serializeJsonPretty( doc, Serial );
}


void CMemory::send_result20( JsonDocument& doc )
{
  doc["result20"] =  get_result20();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result21( JsonDocument& doc )
{
  doc["result21"] =  get_result21();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result22( JsonDocument& doc )
{
  doc["result22"] =  get_result22();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result23( JsonDocument& doc )
{
  doc["result23"] =  get_result23();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result24( JsonDocument& doc )
{
  doc["result24"] =  get_result24();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result25( JsonDocument& doc )
{
  doc["result25"] =  get_result25();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result26( JsonDocument& doc )
{
  doc["result26"] =  get_result26();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result27( JsonDocument& doc )
{
  doc["result27"] =  get_result27();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result28( JsonDocument& doc )
{
  doc["result28"] =  get_result28();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result29( JsonDocument& doc )
{
  doc["result29"] =  get_result29();
  serializeJsonPretty( doc, Serial );
}



void CMemory::send_result30( JsonDocument& doc )
{
  doc["result30"] =  get_result30();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result31( JsonDocument& doc )
{
  doc["result31"] =  get_result31();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result32( JsonDocument& doc )
{
  doc["result32"] =  get_result32();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result33( JsonDocument& doc )
{
  doc["result33"] =  get_result33();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result34( JsonDocument& doc )
{
  doc["result34"] =  get_result34();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result35( JsonDocument& doc )
{
  doc["result35"] =  get_result35();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result36( JsonDocument& doc )
{
  doc["result36"] =  get_result36();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result37( JsonDocument& doc )
{
  doc["result37"] =  get_result37();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result38( JsonDocument& doc )
{
  doc["result38"] =  get_result38();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result39( JsonDocument& doc )
{
  doc["result39"] =  get_result39();
  serializeJsonPretty( doc, Serial );
}



void CMemory::send_result40( JsonDocument& doc )
{
  doc["result40"] =  get_result40();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result41( JsonDocument& doc )
{
  doc["result41"] =  get_result41();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result42( JsonDocument& doc )
{
  doc["result42"] =  get_result42();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result43( JsonDocument& doc )
{
  doc["result43"] =  get_result43();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result44( JsonDocument& doc )
{
  doc["result44"] =  get_result44();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result45( JsonDocument& doc )
{
  doc["result45"] =  get_result45();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result46( JsonDocument& doc )
{
  doc["result46"] =  get_result46();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result47( JsonDocument& doc )
{
  doc["result47"] =  get_result47();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result48( JsonDocument& doc )
{
  doc["result48"] =  get_result48();
  serializeJsonPretty( doc, Serial );
}
void CMemory::send_result49( JsonDocument& doc )
{
  doc["result49"] =  get_result49();
  serializeJsonPretty( doc, Serial );
}



// Envia el resultado en formato json
void CMemory::send_ok( JsonDocument& doc )
{
    doc[ "result" ] = "ok";

    serializeJsonPretty( doc, Serial );
}

// Envia el resultado en formato json
void CMemory::send_ack( JsonDocument& doc )
{
    doc[ "result" ] = "ack";

    serializeJsonPretty( doc, Serial );
}

/* Para poder machear con los nombres en el front end, aca se fija los valores de los case en param.h 
 *  
 */

float CMemory::get_input(uint8_t param){

   switch (param) {

    case 1:

      return get_input0();

    break;

    case 2:

      return get_input1();

    break;

    case 3:

      return get_input2();

    break;

    case 4:

      return get_input3();

    break;

    case 5:

      return get_input4();

    break;
    
    default:
      return 55555;
   }
}

void CMemory::set_input(uint8_t param, float value){

   switch (param) {

    case 1:

      set_input0(value);

    break;

    case 2:

      set_input1(value);

    break;

    case 3:

      set_input2(value);

    break;

    case 4:

      set_input3(value);

    break;

    case 5:

      set_input4(value);

    break;
    
    default:

    break;
      
   }
}

float CMemory::get_output(uint8_t param)
{

   switch (param) {

    case 10:
    
      return get_output0();

    break;

    case 20:

     return get_output1();

    break;

    case 30:

      return get_output2();

    break;

    case 40:

      return get_output3();

    break;

    case 50:

     return get_output4();

    break;
    
    default:
     return 66666;
   }
}

void  CMemory::set_output(uint8_t param, float value)

{

   switch (param) {

    case 10:
    
      set_output0(value);

    break;

    case 20:

     set_output1(value);

    break;

    case 30:

      set_output2(value);

    break;

    case 40:

      set_output3(value);

    break;

    case 50:

      set_output4(value);

    break;
    
    default:
      break;
   }
}

float CMemory::get_cfg(uint8_t param){

   switch (param) {

    case 11:

      return get_cfg0();

    break;

    case 22:

      return get_cfg1();

    break;

    case 33:

      return get_cfg2();

    break;

    case 44:

      return get_cfg3();

    break;

    case 55:

      return get_cfg4();

    break;

    case 66:

      return get_cfg5();

    break;

    case 77:

      return get_cfg6();

    break;

    case 88:

      return get_cfg7();

    break;

    case 99:

      return get_cfg8();

    break;

    case 100:

      return get_cfg9();

    break;
    
    default:
      return 77777;
   }
}

void CMemory::set_cfg(uint8_t param, float value){

   switch (param) {

    case 11:

      set_cfg0(value);

    break;

    case 22:

      set_cfg1(value);

    break;

    case 33:

       set_cfg2(value);

    break;

    case 44:

      set_cfg3(value);

    break;

    case 55:

       set_cfg4(value);

    break;

    case 66:

      set_cfg5(value);

    break;

    case 77:

      set_cfg6(value);

    break;

    case 88:

       set_cfg7(value);

    break;

    case 99:

       set_cfg8(value);

    break;

    case 100:

       set_cfg9(value);

    break;
    
    default:
    break;  
   }
}

float CMemory::get_result(uint8_t param)

{

   switch (param) {

    case 0:

      return get_result0();

    break;

    case 1:

      return get_result1();

    break;

    case 2:

      return get_result2();

    break;

    case 3:

      return get_result3();

    break;

    case 4:

      return get_result4();

    break;

    case 5:

      return get_result5();

    break;

    case 6:

      return get_result6();

    break;

    case 7:

      return get_result7();

    break;

    case 8:

      return get_result8();

    break;

    case 9:

      return get_result9();

    break;

    case 10:

      return get_result0();

    break;

    case 11:

      return get_result11();

    break;

    case 12:

      return get_result12();

    break;

    case 13:

      return get_result13();

    break;

    case 14:

      return get_result14();

    break;

    case 15:

      return get_result15();

    break;

    case 16:

      return get_result16();

    break;

    case 17:

      return get_result17();

    break;

    case 18:

      return get_result18();

    break;

    case 19:

      return get_result19();

    break;

    case 20:

      return get_result20();

    break;

    case 21:

      return get_result21();

    break;

    case 22:

      return get_result22();

    break;

    case 23:

      return get_result23();

    break;

    case 24:

      return get_result24();

    break;

    case 25:

      return get_result25();

    break;

    case 26:

      return get_result26();

    break;

    case 27:

      return get_result27();

    break;

    case 28:

      return get_result28();

    break;

    case 29:

      return get_result29();

    break;

    case 30:

      return get_result30();

    break;

    case 31:

      return get_result31();

    break;

    case 32:

      return get_result32();

    break;

    case 33:

      return get_result33();

    break;

    case 34:

      return get_result34();

    break;

    case 35:

      return get_result35();

    break;

    case 36:

      return get_result36();

    break;

    case 37:

      return get_result37();

    break;

    case 38:

      return get_result38();

    break;

    case 39:

      return get_result39();

    break;

    case 40:

      return get_result40();

    break;

    case 41:

      return get_result41();

    break;

    case 42:

      return get_result42();

    break;

    case 43:

      return get_result43();

    break;

    case 44:

      return get_result44();

    break;

    case 45:

      return get_result45();

    break;

    case 46:

      return get_result46();

    break;

    case 47:

      return get_result47();

    break;

    case 48:

      return get_result48();

    break;

    case 49:

      return get_result49();

    break;
    
    default:
      return 88888;
   }
}

void CMemory::set_result(uint8_t param, float value)

{

   switch (param) {

    case 0:

       set_result0(value);

    break;

    case 1:

       set_result1(value);

    break;

    case 2:

       set_result2(value);

    break;

    case 3:

       set_result3(value);

    break;

    case 4:

      set_result4(value);

    break;

    case 5:

      set_result5(value);

    break;

    case 6:

      set_result6(value);

    break;

    case 7:

     set_result7(value);

    break;

    case 8:

      set_result8(value);

    break;

    case 9:

      set_result9(value);

    break;

    case 10:

     set_result10(value);

    break;

    case 11:

      set_result11(value);

    break;

    case 12:

      set_result12(value);

    break;

    case 13:

     set_result13(value);

    break;

    case 14:

      set_result14(value);

    break;

    case 15:

      set_result15(value);

    break;

    case 16:

      set_result16(value);

    break;

    case 17:

      set_result17(value);

    break;

    case 18:

      set_result18(value);

    break;

    case 19:

     set_result19(value);

    break;

    case 20:

      set_result20(value);

    break;

    case 21:

      set_result21(value);

    break;

    case 22:

      set_result22(value);

    break;

    case 23:

     set_result23(value);

    break;

    case 24:

     set_result24(value);

    break;

    case 25:

     set_result25(value);

    break;

    case 26:

      set_result26(value);

    break;

    case 27:

      set_result27(value);

    break;

    case 28:

      set_result28(value);

    break;

    case 29:

     set_result29(value);

    break;

    case 30:

      set_result30(value);

    break;

    case 31:

      set_result31(value);

    break;

    case 32:

     set_result32(value);

    break;

    case 33:

      set_result33(value);

    break;

    case 34:

      set_result34(value);

    break;

    case 35:

      set_result35(value);

    break;

    case 36:

      set_result36(value);

    break;

    case 37:

      set_result37(value);

    break;

    case 38:

      set_result38(value);

    break;

    case 39:

      set_result39(value);

    break;

    case 40:

      set_result40(value);

    break;

    case 41:

      set_result41(value);

    break;

    case 42:

      set_result42(value);

    break;

    case 43:

      set_result43(value);
    break;

    case 44:

      set_result44(value);

    break;

    case 45:

      set_result45(value);

    break;

    case 46:

     set_result46(value);

    break;

    case 47:

      set_result47(value);
    break;

    case 48:

      set_result48(value);

    break;

    case 49:

      set_result49(value);

    break;
    
    default:
    break;  
   }
}
