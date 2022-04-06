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
#include <ArduinoJson.h>

#define FIRMWARE_VERSION                "1.0.03" // Error de tipeo en all-output
                                               
                                                  
//#define EEPROM_ADDRESS_memory         4       // Direccion en la epprom donde se almacena la memoryuracion.
#define MAGIC_NUMBER                    22    // Numero magico para detectar memoria sin inicializar.

#define ST_TEST_DEFAULT                 0              //  Estado del test pòr defecto.
#define ST_MODE_DEFAULT                 ST_MODE_TEST   //  Modo de operacion del sistema. 

#define INPUT_0_DEFAULT               0.1 
#define INPUT_1_DEFAULT               1.1             
#define INPUT_2_DEFAULT               2.2  
#define INPUT_3_DEFAULT               3.2  
#define INPUT_4_DEFAULT               4.4  

#define OUTPUT_0_DEFAULT               11.9 
#define OUTPUT_1_DEFAULT               10.9 
#define OUTPUT_2_DEFAULT               20.9 
#define OUTPUT_3_DEFAULT               30.9
#define OUTPUT_4_DEFAULT               40.9 
 

#define CFG_0_DEFAULT                  7000.123
#define CFG_1_DEFAULT                  7000.124
#define CFG_2_DEFAULT                  7000.125
#define CFG_3_DEFAULT                  7000.126
#define CFG_4_DEFAULT                  7000.127
#define CFG_5_DEFAULT                  7000.128
#define CFG_6_DEFAULT                  7000.129
#define CFG_7_DEFAULT                  7000.131
#define CFG_8_DEFAULT                  7000.132
#define CFG_9_DEFAULT                  7000.133


#define RESULT_0_DEFAULT             70.123
#define RESULT_1_DEFAULT             70.124
#define RESULT_2_DEFAULT             70.125
#define RESULT_3_DEFAULT             70.126
#define RESULT_4_DEFAULT             70.127
#define RESULT_5_DEFAULT             70.128
#define RESULT_6_DEFAULT             70.129
#define RESULT_7_DEFAULT             70.131
#define RESULT_8_DEFAULT             70.132
#define RESULT_9_DEFAULT             70.133


#define RESULT_10_DEFAULT             80.123
#define RESULT_11_DEFAULT             80.124
#define RESULT_12_DEFAULT             80.125
#define RESULT_13_DEFAULT             80.126
#define RESULT_14_DEFAULT             80.127
#define RESULT_15_DEFAULT             80.128
#define RESULT_16_DEFAULT             80.129
#define RESULT_17_DEFAULT             80.131
#define RESULT_18_DEFAULT             80.132
#define RESULT_19_DEFAULT             80.133


#define RESULT_20_DEFAULT             90.123
#define RESULT_21_DEFAULT             90.124
#define RESULT_22_DEFAULT             90.125
#define RESULT_23_DEFAULT             90.126
#define RESULT_24_DEFAULT             90.127
#define RESULT_25_DEFAULT             90.128
#define RESULT_26_DEFAULT             90.129
#define RESULT_27_DEFAULT             90.131
#define RESULT_28_DEFAULT             90.132
#define RESULT_29_DEFAULT             90.133

#define RESULT_30_DEFAULT             100.123
#define RESULT_31_DEFAULT             100.124
#define RESULT_32_DEFAULT             100.125
#define RESULT_33_DEFAULT             100.126
#define RESULT_34_DEFAULT             100.127
#define RESULT_35_DEFAULT             100.128
#define RESULT_36_DEFAULT             100.129
#define RESULT_37_DEFAULT             100.131
#define RESULT_38_DEFAULT             100.132
#define RESULT_39_DEFAULT             100.133

#define RESULT_40_DEFAULT             110.123
#define RESULT_41_DEFAULT             110.124
#define RESULT_42_DEFAULT             110.125
#define RESULT_43_DEFAULT             110.126
#define RESULT_44_DEFAULT             110.127
#define RESULT_45_DEFAULT             110.128
#define RESULT_46_DEFAULT             110.129
#define RESULT_47_DEFAULT             110.131
#define RESULT_48_DEFAULT             110.132
#define RESULT_49_DEFAULT             110.133






// Mapa de direcciones de los campos de memoryuracion en la EEPROM.
#define EEPROM_ADDRESS_MAGIC_NUMBER     0

// Unsigned 8 bits
// Para remote-lab-lib
#define EEPROM_ADDRESS_ST_TEST          (EEPROM_ADDRESS_MAGIC_NUMBER + sizeof(uint8_t))  
#define EEPROM_ADDRESS_ST_MODE          (EEPROM_ADDRESS_ST_TEST      + sizeof(uint8_t))  
#define EEPROM_ADDRESS_SERIAL_LEVEL     (EEPROM_ADDRESS_ST_MODE      + sizeof(uint8_t))


// float

#define EEPROM_ADDRESS_INPUT_0      (EEPROM_ADDRESS_SERIAL_LEVEL + sizeof(uint8_t))
#define EEPROM_ADDRESS_INPUT_1      (EEPROM_ADDRESS_INPUT_0  + sizeof(float))
#define EEPROM_ADDRESS_INPUT_2      (EEPROM_ADDRESS_INPUT_1  + sizeof(float))
#define EEPROM_ADDRESS_INPUT_3      (EEPROM_ADDRESS_INPUT_2  + sizeof(float))
#define EEPROM_ADDRESS_INPUT_4      (EEPROM_ADDRESS_INPUT_3  + sizeof(float))


#define EEPROM_ADDRESS_OUTPUT_0      (EEPROM_ADDRESS_INPUT_4 + sizeof(float))
#define EEPROM_ADDRESS_OUTPUT_1      (EEPROM_ADDRESS_OUTPUT_0  + sizeof(float))
#define EEPROM_ADDRESS_OUTPUT_2      (EEPROM_ADDRESS_OUTPUT_1  + sizeof(float))
#define EEPROM_ADDRESS_OUTPUT_3      (EEPROM_ADDRESS_OUTPUT_2  + sizeof(float))
#define EEPROM_ADDRESS_OUTPUT_4      (EEPROM_ADDRESS_OUTPUT_3  + sizeof(float))

#define EEPROM_ADDRESS_CFG_0      (EEPROM_ADDRESS_OUTPUT_4 + sizeof(float))
#define EEPROM_ADDRESS_CFG_1      (EEPROM_ADDRESS_CFG_0  + sizeof(float))
#define EEPROM_ADDRESS_CFG_2      (EEPROM_ADDRESS_CFG_1  + sizeof(float))
#define EEPROM_ADDRESS_CFG_3      (EEPROM_ADDRESS_CFG_2  + sizeof(float))
#define EEPROM_ADDRESS_CFG_4      (EEPROM_ADDRESS_CFG_3  + sizeof(float))
#define EEPROM_ADDRESS_CFG_5      (EEPROM_ADDRESS_CFG_4  + sizeof(float))
#define EEPROM_ADDRESS_CFG_6      (EEPROM_ADDRESS_CFG_5  + sizeof(float))
#define EEPROM_ADDRESS_CFG_7      (EEPROM_ADDRESS_CFG_6  + sizeof(float))
#define EEPROM_ADDRESS_CFG_8      (EEPROM_ADDRESS_CFG_7  + sizeof(float))
#define EEPROM_ADDRESS_CFG_9      (EEPROM_ADDRESS_CFG_8  + sizeof(float))


#define EEPROM_ADDRESS_RESULT_0      (EEPROM_ADDRESS_CFG_9    + sizeof(float))
#define EEPROM_ADDRESS_RESULT_1      (EEPROM_ADDRESS_RESULT_0  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_2      (EEPROM_ADDRESS_RESULT_1  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_3      (EEPROM_ADDRESS_RESULT_2  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_4      (EEPROM_ADDRESS_RESULT_3  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_5      (EEPROM_ADDRESS_RESULT_4  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_6      (EEPROM_ADDRESS_RESULT_5  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_7      (EEPROM_ADDRESS_RESULT_6  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_8      (EEPROM_ADDRESS_RESULT_7  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_9      (EEPROM_ADDRESS_RESULT_8  + sizeof(float))

#define EEPROM_ADDRESS_RESULT_10      (EEPROM_ADDRESS_RESULT_9  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_11      (EEPROM_ADDRESS_RESULT_10  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_12      (EEPROM_ADDRESS_RESULT_11  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_13      (EEPROM_ADDRESS_RESULT_12  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_14      (EEPROM_ADDRESS_RESULT_13  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_15      (EEPROM_ADDRESS_RESULT_14  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_16      (EEPROM_ADDRESS_RESULT_15  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_17      (EEPROM_ADDRESS_RESULT_16  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_18      (EEPROM_ADDRESS_RESULT_17  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_19      (EEPROM_ADDRESS_RESULT_18  + sizeof(float))

#define EEPROM_ADDRESS_RESULT_20      (EEPROM_ADDRESS_RESULT_19  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_21      (EEPROM_ADDRESS_RESULT_20  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_22      (EEPROM_ADDRESS_RESULT_21  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_23      (EEPROM_ADDRESS_RESULT_22  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_24      (EEPROM_ADDRESS_RESULT_23  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_25      (EEPROM_ADDRESS_RESULT_24  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_26      (EEPROM_ADDRESS_RESULT_25  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_27      (EEPROM_ADDRESS_RESULT_26  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_28      (EEPROM_ADDRESS_RESULT_27  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_29      (EEPROM_ADDRESS_RESULT_28  + sizeof(float))

#define EEPROM_ADDRESS_RESULT_30      (EEPROM_ADDRESS_RESULT_29  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_31      (EEPROM_ADDRESS_RESULT_30  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_32      (EEPROM_ADDRESS_RESULT_31  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_33      (EEPROM_ADDRESS_RESULT_32  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_34      (EEPROM_ADDRESS_RESULT_33  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_35      (EEPROM_ADDRESS_RESULT_34  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_36      (EEPROM_ADDRESS_RESULT_35  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_37      (EEPROM_ADDRESS_RESULT_36  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_38      (EEPROM_ADDRESS_RESULT_37  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_39      (EEPROM_ADDRESS_RESULT_38  + sizeof(float))

#define EEPROM_ADDRESS_RESULT_40      (EEPROM_ADDRESS_RESULT_39  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_41      (EEPROM_ADDRESS_RESULT_40  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_42      (EEPROM_ADDRESS_RESULT_41  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_43      (EEPROM_ADDRESS_RESULT_42  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_44      (EEPROM_ADDRESS_RESULT_43  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_45      (EEPROM_ADDRESS_RESULT_44  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_46      (EEPROM_ADDRESS_RESULT_45  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_47      (EEPROM_ADDRESS_RESULT_46  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_48      (EEPROM_ADDRESS_RESULT_47  + sizeof(float))
#define EEPROM_ADDRESS_RESULT_49      (EEPROM_ADDRESS_RESULT_48  + sizeof(float))


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

    uint8_t get_serial_level( void );
    void set_serial_level( uint8_t enable );

    uint8_t get_st_test( void );
    void set_st_test( uint8_t enable );

    uint8_t get_st_mode( void );
    void set_st_mode( uint8_t mode ); 


    float get_input0( void );
    void  set_input0( float parameter );
    float get_input1( void );
    void  set_input1( float parameter );
    float get_input2( void );
    void  set_input2( float parameter );
    float get_input3( void );
    void  set_input3( float parameter );    
    float get_input4( void );
    void  set_input4( float parameter );
     

    float get_output0( void );
    void  set_output0( float parameter );
    float get_output1( void );
    void  set_output1( float parameter );
    float get_output2( void );
    void  set_output2( float parameter );
    float get_output3( void );
    void  set_output3( float parameter );
    float get_output4( void );
    void  set_output4( float parameter ); 


    float get_cfg0( void );
    void  set_cfg0( float parameter );
    float get_cfg1( void );
    void  set_cfg1( float parameter );
    float get_cfg2( void );
    void  set_cfg2( float parameter );
    float get_cfg3( void );
    void  set_cfg3( float parameter );
    float get_cfg4( void );
    void  set_cfg4( float parameter ); 
    float get_cfg5( void );
    void  set_cfg5( float parameter );
    float get_cfg6( void );
    void  set_cfg6( float parameter );
    float get_cfg7( void );
    void  set_cfg7( float parameter );
    float get_cfg8( void );
    void  set_cfg8( float parameter );
    float get_cfg9( void );
    void  set_cfg9( float parameter ); 

    float get_result_0( void );
    void  set_result_0( float parameter );
    float get_result_1( void );
    void  set_result_1( float parameter );
    float get_result_2( void );
    void  set_result_2( float parameter );
    float get_result_3( void );
    void  set_result_3( float parameter ); 
    float get_result_4( void );
    void  set_result_4( float parameter );
    float get_result_5( void );
    void  set_result_5( float parameter ); 
    float get_result_6( void );
    void  set_result_6( float parameter ); 
    float get_result_7( void );
    void  set_result_7( float parameter ); 
    float get_result_8( void );
    void  set_result_8( float parameter ); 
    float get_result_9( void );
    void  set_result_9( float parameter );   

    float get_result_10( void );
    void  set_result_10( float parameter );
    float get_result_11( void );
    void  set_result_11( float parameter );
    float get_result_12( void );
    void  set_result_12( float parameter );
    float get_result_13( void );
    void  set_result_13( float parameter ); 
    float get_result_14( void );
    void  set_result_14( float parameter );
    float get_result_15( void );
    void  set_result_15( float parameter ); 
    float get_result_16( void );
    void  set_result_16( float parameter ); 
    float get_result_17( void );
    void  set_result_17( float parameter ); 
    float get_result_18( void );
    void  set_result_18( float parameter ); 
    float get_result_19( void );
    void  set_result_19( float parameter );   

    float get_result_20( void );
    void  set_result_20( float parameter );
    float get_result_21( void );
    void  set_result_21( float parameter );
    float get_result_22( void );
    void  set_result_22( float parameter );
    float get_result_23( void );
    void  set_result_23( float parameter ); 
    float get_result_24( void );
    void  set_result_24( float parameter );
    float get_result_25( void );
    void  set_result_25( float parameter ); 
    float get_result_26( void );
    void  set_result_26( float parameter ); 
    float get_result_27( void );
    void  set_result_27( float parameter ); 
    float get_result_28( void );
    void  set_result_28( float parameter ); 
    float get_result_29( void );
    void  set_result_29( float parameter );  

    float get_result_30( void );
    void  set_result_30( float parameter );
    float get_result_31( void );
    void  set_result_31( float parameter );
    float get_result_32( void );
    void  set_result_32( float parameter );
    float get_result_33( void );
    void  set_result_33( float parameter ); 
    float get_result_34( void );
    void  set_result_34( float parameter );
    float get_result_35( void );
    void  set_result_35( float parameter ); 
    float get_result_36( void );
    void  set_result_36( float parameter ); 
    float get_result_37( void );
    void  set_result_37( float parameter ); 
    float get_result_38( void );
    void  set_result_38( float parameter ); 
    float get_result_39( void );
    void  set_result_39( float parameter );     

    float get_result_40( void );
    void  set_result_40( float parameter );
    float get_result_41( void );
    void  set_result_41( float parameter );
    float get_result_42( void );
    void  set_result_42( float parameter );
    float get_result_43( void );
    void  set_result_43( float parameter ); 
    float get_result_44( void );
    void  set_result_44( float parameter );
    float get_result_45( void );
    void  set_result_45( float parameter ); 
    float get_result_46( void );
    void  set_result_46( float parameter ); 
    float get_result_47( void );
    void  set_result_47( float parameter ); 
    float get_result_48( void );
    void  set_result_48( float parameter ); 
    float get_result_49( void );
    void  set_result_49( float parameter );  
    

    void host_cmd( void );
    void send_test_finish(void);

  private:
    uint8_t serial_level;         // 0 = serial de informacion de control desactivada.
    uint8_t st_test;            // Estado del ensayo 
    uint8_t st_mode;            // Modo del ensayo


    float input0; 
    float input1; 
    float input2; 
    float input3; 
    float input4;

    float output0; 
    float output1;
    float output2;
    float output3;
    float output4;

    float cfg0;
    float cfg1;
    float cfg2;
    float cfg3;
    float cfg4;
    float cfg5;
    float cfg6;
    float cfg7;
    float cfg8;
    float cfg9;

    float result_0;
    float result_1;
    float result_2;
    float result_3;
    float result_4;
    float result_5;
    float result_6;
    float result_7;
    float result_8;
    float result_9;

    float result_10;
    float result_11;
    float result_12;
    float result_13;
    float result_14;
    float result_15;
    float result_16;
    float result_17;
    float result_18;
    float result_19;

    float result_20;
    float result_21;
    float result_22;
    float result_23;
    float result_24;
    float result_25;
    float result_26;
    float result_27;
    float result_28;
    float result_29;

    float result_30;
    float result_31;
    float result_32;
    float result_33;
    float result_34;
    float result_35;
    float result_36;
    float result_37;
    float result_38;
    float result_39;

    float result_40;
    float result_41;
    float result_42;
    float result_43;
    float result_44;
    float result_45;
    float result_46;
    float result_47;
    float result_48;
    float result_49;
 
    
    void send_all_parameters( JsonDocument& );
    void send_all_input( JsonDocument& doc );
    void send_all_output( JsonDocument& doc );
    void send_all_cfg( JsonDocument& doc );
    void send_all_result( JsonDocument& doc );
    void send_all_lib( JsonDocument& doc );
    void send_version( JsonDocument& );
    void send_ok( JsonDocument& );
    void send_ack( JsonDocument& );
    void send_status( JsonDocument& doc );    
    void send_serial_level( JsonDocument& doc );
    void send_st_mode( JsonDocument& doc );

    void send_input0(JsonDocument& doc);
    void send_input1(JsonDocument& doc);
    void send_input2(JsonDocument& doc);
    void send_input3(JsonDocument& doc);
    void send_input4(JsonDocument& doc);

    void send_output0(JsonDocument& doc);
    void send_output1(JsonDocument& doc);
    void send_output2(JsonDocument& doc);
    void send_output3(JsonDocument& doc);
    void send_output4(JsonDocument& doc);
    
    void send_cfg0(JsonDocument& doc); 
    void send_cfg1(JsonDocument& doc); 
    void send_cfg2(JsonDocument& doc); 
    void send_cfg3(JsonDocument& doc); 
    void send_cfg4(JsonDocument& doc); 
    void send_cfg5(JsonDocument& doc); 
    void send_cfg6(JsonDocument& doc); 
    void send_cfg7(JsonDocument& doc); 
    void send_cfg8(JsonDocument& doc); 
    void send_cfg9(JsonDocument& doc);   
   
   void send_result_0(JsonDocument& doc);    
   void send_result_1(JsonDocument& doc);    
   void send_result_2(JsonDocument& doc);    
   void send_result_3(JsonDocument& doc);    
   void send_result_4(JsonDocument& doc);    
   void send_result_5(JsonDocument& doc);    
   void send_result_6(JsonDocument& doc);    
   void send_result_7(JsonDocument& doc);    
   void send_result_8(JsonDocument& doc);    
   void send_result_9(JsonDocument& doc); 

   void send_result_10(JsonDocument& doc);    
   void send_result_11(JsonDocument& doc);    
   void send_result_12(JsonDocument& doc);    
   void send_result_13(JsonDocument& doc);    
   void send_result_14(JsonDocument& doc);    
   void send_result_15(JsonDocument& doc);    
   void send_result_16(JsonDocument& doc);    
   void send_result_17(JsonDocument& doc);    
   void send_result_18(JsonDocument& doc);    
   void send_result_19(JsonDocument& doc);

   void send_result_20(JsonDocument& doc);    
   void send_result_21(JsonDocument& doc);    
   void send_result_22(JsonDocument& doc);    
   void send_result_23(JsonDocument& doc);    
   void send_result_24(JsonDocument& doc);    
   void send_result_25(JsonDocument& doc);    
   void send_result_26(JsonDocument& doc);    
   void send_result_27(JsonDocument& doc);    
   void send_result_28(JsonDocument& doc);    
   void send_result_29(JsonDocument& doc);

   void send_result_30(JsonDocument& doc);    
   void send_result_31(JsonDocument& doc);    
   void send_result_32(JsonDocument& doc);    
   void send_result_33(JsonDocument& doc);    
   void send_result_34(JsonDocument& doc);    
   void send_result_35(JsonDocument& doc);    
   void send_result_36(JsonDocument& doc);    
   void send_result_37(JsonDocument& doc);    
   void send_result_38(JsonDocument& doc);    
   void send_result_39(JsonDocument& doc);

   void send_result_40(JsonDocument& doc);    
   void send_result_41(JsonDocument& doc);    
   void send_result_42(JsonDocument& doc);    
   void send_result_43(JsonDocument& doc);    
   void send_result_44(JsonDocument& doc);    
   void send_result_45(JsonDocument& doc);    
   void send_result_46(JsonDocument& doc);    
   void send_result_47(JsonDocument& doc);    
   void send_result_48(JsonDocument& doc);    
   void send_result_49(JsonDocument& doc);

   
};

#endif // memory_H
