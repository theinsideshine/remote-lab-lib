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

#define FIRMWARE_VERSION                "1.0.01" //Se agrego estructura de datos 
                                               
                                                  
//#define EEPROM_ADDRESS_memory         4       // Direccion en la epprom donde se almacena la memoryuracion.
#define MAGIC_NUMBER                    21    // Numero magico para detectar memoria sin inicializar.

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


#define FLOAT_0_DEFAULT             70.123
#define FLOAT_1_DEFAULT             70.124
#define FLOAT_2_DEFAULT             70.125
#define FLOAT_3_DEFAULT             70.126
#define FLOAT_4_DEFAULT             70.127
#define FLOAT_5_DEFAULT             70.128
#define FLOAT_6_DEFAULT             70.129
#define FLOAT_7_DEFAULT             70.131
#define FLOAT_8_DEFAULT             70.132
#define FLOAT_9_DEFAULT             70.133


#define FLOAT_10_DEFAULT             80.123
#define FLOAT_11_DEFAULT             80.124
#define FLOAT_12_DEFAULT             80.125
#define FLOAT_13_DEFAULT             80.126
#define FLOAT_14_DEFAULT             80.127
#define FLOAT_15_DEFAULT             80.128
#define FLOAT_16_DEFAULT             80.129
#define FLOAT_17_DEFAULT             80.131
#define FLOAT_18_DEFAULT             80.132
#define FLOAT_19_DEFAULT             80.133


#define FLOAT_20_DEFAULT             90.123
#define FLOAT_21_DEFAULT             90.124
#define FLOAT_22_DEFAULT             90.125
#define FLOAT_23_DEFAULT             90.126
#define FLOAT_24_DEFAULT             90.127
#define FLOAT_25_DEFAULT             90.128
#define FLOAT_26_DEFAULT             90.129
#define FLOAT_27_DEFAULT             90.131
#define FLOAT_28_DEFAULT             90.132
#define FLOAT_29_DEFAULT             90.133

#define FLOAT_30_DEFAULT             100.123
#define FLOAT_31_DEFAULT             100.124
#define FLOAT_32_DEFAULT             100.125
#define FLOAT_33_DEFAULT             100.126
#define FLOAT_34_DEFAULT             100.127
#define FLOAT_35_DEFAULT             100.128
#define FLOAT_36_DEFAULT             100.129
#define FLOAT_37_DEFAULT             100.131
#define FLOAT_38_DEFAULT             100.132
#define FLOAT_39_DEFAULT             100.133

#define FLOAT_40_DEFAULT             110.123
#define FLOAT_41_DEFAULT             110.124
#define FLOAT_42_DEFAULT             110.125
#define FLOAT_43_DEFAULT             110.126
#define FLOAT_44_DEFAULT             110.127
#define FLOAT_45_DEFAULT             110.128
#define FLOAT_46_DEFAULT             110.129
#define FLOAT_47_DEFAULT             110.131
#define FLOAT_48_DEFAULT             110.132
#define FLOAT_49_DEFAULT             110.133






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


#define EEPROM_ADDRESS_FLOAT_0      (EEPROM_ADDRESS_CFG_9    + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_1      (EEPROM_ADDRESS_FLOAT_0  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_2      (EEPROM_ADDRESS_FLOAT_1  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_3      (EEPROM_ADDRESS_FLOAT_2  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_4      (EEPROM_ADDRESS_FLOAT_3  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_5      (EEPROM_ADDRESS_FLOAT_4  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_6      (EEPROM_ADDRESS_FLOAT_5  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_7      (EEPROM_ADDRESS_FLOAT_6  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_8      (EEPROM_ADDRESS_FLOAT_7  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_9      (EEPROM_ADDRESS_FLOAT_8  + sizeof(float))

#define EEPROM_ADDRESS_FLOAT_10      (EEPROM_ADDRESS_FLOAT_9  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_11      (EEPROM_ADDRESS_FLOAT_10  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_12      (EEPROM_ADDRESS_FLOAT_11  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_13      (EEPROM_ADDRESS_FLOAT_12  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_14      (EEPROM_ADDRESS_FLOAT_13  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_15      (EEPROM_ADDRESS_FLOAT_14  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_16      (EEPROM_ADDRESS_FLOAT_15  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_17      (EEPROM_ADDRESS_FLOAT_16  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_18      (EEPROM_ADDRESS_FLOAT_17  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_19      (EEPROM_ADDRESS_FLOAT_18  + sizeof(float))

#define EEPROM_ADDRESS_FLOAT_20      (EEPROM_ADDRESS_FLOAT_19  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_21      (EEPROM_ADDRESS_FLOAT_20  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_22      (EEPROM_ADDRESS_FLOAT_21  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_23      (EEPROM_ADDRESS_FLOAT_22  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_24      (EEPROM_ADDRESS_FLOAT_23  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_25      (EEPROM_ADDRESS_FLOAT_24  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_26      (EEPROM_ADDRESS_FLOAT_25  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_27      (EEPROM_ADDRESS_FLOAT_26  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_28      (EEPROM_ADDRESS_FLOAT_27  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_29      (EEPROM_ADDRESS_FLOAT_28  + sizeof(float))

#define EEPROM_ADDRESS_FLOAT_30      (EEPROM_ADDRESS_FLOAT_29  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_31      (EEPROM_ADDRESS_FLOAT_30  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_32      (EEPROM_ADDRESS_FLOAT_31  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_33      (EEPROM_ADDRESS_FLOAT_32  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_34      (EEPROM_ADDRESS_FLOAT_33  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_35      (EEPROM_ADDRESS_FLOAT_34  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_36      (EEPROM_ADDRESS_FLOAT_35  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_37      (EEPROM_ADDRESS_FLOAT_36  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_38      (EEPROM_ADDRESS_FLOAT_37  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_39      (EEPROM_ADDRESS_FLOAT_38  + sizeof(float))

#define EEPROM_ADDRESS_FLOAT_40      (EEPROM_ADDRESS_FLOAT_39  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_41      (EEPROM_ADDRESS_FLOAT_40  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_42      (EEPROM_ADDRESS_FLOAT_41  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_43      (EEPROM_ADDRESS_FLOAT_42  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_44      (EEPROM_ADDRESS_FLOAT_43  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_45      (EEPROM_ADDRESS_FLOAT_44  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_46      (EEPROM_ADDRESS_FLOAT_45  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_47      (EEPROM_ADDRESS_FLOAT_46  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_48      (EEPROM_ADDRESS_FLOAT_47  + sizeof(float))
#define EEPROM_ADDRESS_FLOAT_49      (EEPROM_ADDRESS_FLOAT_48  + sizeof(float))


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

    float get_float_0( void );
    void  set_float_0( float parameter );
    float get_float_1( void );
    void  set_float_1( float parameter );
    float get_float_2( void );
    void  set_float_2( float parameter );
    float get_float_3( void );
    void  set_float_3( float parameter ); 
    float get_float_4( void );
    void  set_float_4( float parameter );
    float get_float_5( void );
    void  set_float_5( float parameter ); 
    float get_float_6( void );
    void  set_float_6( float parameter ); 
    float get_float_7( void );
    void  set_float_7( float parameter ); 
    float get_float_8( void );
    void  set_float_8( float parameter ); 
    float get_float_9( void );
    void  set_float_9( float parameter );   

    float get_float_10( void );
    void  set_float_10( float parameter );
    float get_float_11( void );
    void  set_float_11( float parameter );
    float get_float_12( void );
    void  set_float_12( float parameter );
    float get_float_13( void );
    void  set_float_13( float parameter ); 
    float get_float_14( void );
    void  set_float_14( float parameter );
    float get_float_15( void );
    void  set_float_15( float parameter ); 
    float get_float_16( void );
    void  set_float_16( float parameter ); 
    float get_float_17( void );
    void  set_float_17( float parameter ); 
    float get_float_18( void );
    void  set_float_18( float parameter ); 
    float get_float_19( void );
    void  set_float_19( float parameter );   

    float get_float_20( void );
    void  set_float_20( float parameter );
    float get_float_21( void );
    void  set_float_21( float parameter );
    float get_float_22( void );
    void  set_float_22( float parameter );
    float get_float_23( void );
    void  set_float_23( float parameter ); 
    float get_float_24( void );
    void  set_float_24( float parameter );
    float get_float_25( void );
    void  set_float_25( float parameter ); 
    float get_float_26( void );
    void  set_float_26( float parameter ); 
    float get_float_27( void );
    void  set_float_27( float parameter ); 
    float get_float_28( void );
    void  set_float_28( float parameter ); 
    float get_float_29( void );
    void  set_float_29( float parameter );  

    float get_float_30( void );
    void  set_float_30( float parameter );
    float get_float_31( void );
    void  set_float_31( float parameter );
    float get_float_32( void );
    void  set_float_32( float parameter );
    float get_float_33( void );
    void  set_float_33( float parameter ); 
    float get_float_34( void );
    void  set_float_34( float parameter );
    float get_float_35( void );
    void  set_float_35( float parameter ); 
    float get_float_36( void );
    void  set_float_36( float parameter ); 
    float get_float_37( void );
    void  set_float_37( float parameter ); 
    float get_float_38( void );
    void  set_float_38( float parameter ); 
    float get_float_39( void );
    void  set_float_39( float parameter );     

    float get_float_40( void );
    void  set_float_40( float parameter );
    float get_float_41( void );
    void  set_float_41( float parameter );
    float get_float_42( void );
    void  set_float_42( float parameter );
    float get_float_43( void );
    void  set_float_43( float parameter ); 
    float get_float_44( void );
    void  set_float_44( float parameter );
    float get_float_45( void );
    void  set_float_45( float parameter ); 
    float get_float_46( void );
    void  set_float_46( float parameter ); 
    float get_float_47( void );
    void  set_float_47( float parameter ); 
    float get_float_48( void );
    void  set_float_48( float parameter ); 
    float get_float_49( void );
    void  set_float_49( float parameter );  
    

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

    float float_0;
    float float_1;
    float float_2;
    float float_3;
    float float_4;
    float float_5;
    float float_6;
    float float_7;
    float float_8;
    float float_9;

    float float_10;
    float float_11;
    float float_12;
    float float_13;
    float float_14;
    float float_15;
    float float_16;
    float float_17;
    float float_18;
    float float_19;

    float float_20;
    float float_21;
    float float_22;
    float float_23;
    float float_24;
    float float_25;
    float float_26;
    float float_27;
    float float_28;
    float float_29;

    float float_30;
    float float_31;
    float float_32;
    float float_33;
    float float_34;
    float float_35;
    float float_36;
    float float_37;
    float float_38;
    float float_39;

    float float_40;
    float float_41;
    float float_42;
    float float_43;
    float float_44;
    float float_45;
    float float_46;
    float float_47;
    float float_48;
    float float_49;
 
    
    void send_all_parameters( JsonDocument& );
    void send_all_input( JsonDocument& doc );
    void send_all_output( JsonDocument& doc );
    void send_all_cfg( JsonDocument& doc );
    void send_all_float( JsonDocument& doc );
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
   
   void send_float_0(JsonDocument& doc);    
   void send_float_1(JsonDocument& doc);    
   void send_float_2(JsonDocument& doc);    
   void send_float_3(JsonDocument& doc);    
   void send_float_4(JsonDocument& doc);    
   void send_float_5(JsonDocument& doc);    
   void send_float_6(JsonDocument& doc);    
   void send_float_7(JsonDocument& doc);    
   void send_float_8(JsonDocument& doc);    
   void send_float_9(JsonDocument& doc); 

   void send_float_10(JsonDocument& doc);    
   void send_float_11(JsonDocument& doc);    
   void send_float_12(JsonDocument& doc);    
   void send_float_13(JsonDocument& doc);    
   void send_float_14(JsonDocument& doc);    
   void send_float_15(JsonDocument& doc);    
   void send_float_16(JsonDocument& doc);    
   void send_float_17(JsonDocument& doc);    
   void send_float_18(JsonDocument& doc);    
   void send_float_19(JsonDocument& doc);

   void send_float_20(JsonDocument& doc);    
   void send_float_21(JsonDocument& doc);    
   void send_float_22(JsonDocument& doc);    
   void send_float_23(JsonDocument& doc);    
   void send_float_24(JsonDocument& doc);    
   void send_float_25(JsonDocument& doc);    
   void send_float_26(JsonDocument& doc);    
   void send_float_27(JsonDocument& doc);    
   void send_float_28(JsonDocument& doc);    
   void send_float_29(JsonDocument& doc);

   void send_float_30(JsonDocument& doc);    
   void send_float_31(JsonDocument& doc);    
   void send_float_32(JsonDocument& doc);    
   void send_float_33(JsonDocument& doc);    
   void send_float_34(JsonDocument& doc);    
   void send_float_35(JsonDocument& doc);    
   void send_float_36(JsonDocument& doc);    
   void send_float_37(JsonDocument& doc);    
   void send_float_38(JsonDocument& doc);    
   void send_float_39(JsonDocument& doc);

   void send_float_40(JsonDocument& doc);    
   void send_float_41(JsonDocument& doc);    
   void send_float_42(JsonDocument& doc);    
   void send_float_43(JsonDocument& doc);    
   void send_float_44(JsonDocument& doc);    
   void send_float_45(JsonDocument& doc);    
   void send_float_46(JsonDocument& doc);    
   void send_float_47(JsonDocument& doc);    
   void send_float_48(JsonDocument& doc);    
   void send_float_49(JsonDocument& doc);

   
};

#endif // memory_H
