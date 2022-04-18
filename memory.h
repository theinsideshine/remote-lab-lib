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

#define FIRMWARE_VERSION                "2.0.03" // Se completaron Setter y getter faltantes. Se cambio result_x por resultx.
                                                 // v2.0.02  Se agrego modo de experimento de prueba2      
                                                  
//#define EEPROM_ADDRESS_memory         4       // Direccion en la epprom donde se almacena la memoryuracion.
#define MAGIC_NUMBER                    45    // Numero magico para detectar memoria sin inicializar.

#define ST_TEST_DEFAULT                 0              //  Estado del test pòr defecto.
#define ST_MODE_DEFAULT                 ST_MODE_TEST   //  Modo de operacion del sistema. 

#define INPUT_0_DEFAULT               0.1 
#define INPUT_1_DEFAULT               1.1             
#define INPUT_2_DEFAULT               2.2  
#define INPUT_3_DEFAULT               3.2  
#define INPUT_4_DEFAULT               4.4  

#define OUTPUT_0_DEFAULT               110.9 
#define OUTPUT_1_DEFAULT               100.9 
#define OUTPUT_2_DEFAULT               200.9 
#define OUTPUT_3_DEFAULT               300.9
#define OUTPUT_4_DEFAULT               400.9 
 

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


#define RESULT_0_DEFAULT             700.123
#define RESULT_1_DEFAULT             700.124
#define RESULT_2_DEFAULT             700.125
#define RESULT_3_DEFAULT             700.126
#define RESULT_4_DEFAULT             700.127
#define RESULT_5_DEFAULT             700.128
#define RESULT_6_DEFAULT             700.129
#define RESULT_7_DEFAULT             700.131
#define RESULT_8_DEFAULT             700.132
#define RESULT_9_DEFAULT             700.133


#define RESULT_10_DEFAULT             800.123
#define RESULT_11_DEFAULT             800.124
#define RESULT_12_DEFAULT             800.125
#define RESULT_13_DEFAULT             800.126
#define RESULT_14_DEFAULT             800.127
#define RESULT_15_DEFAULT             800.128
#define RESULT_16_DEFAULT             800.129
#define RESULT_17_DEFAULT             800.131
#define RESULT_18_DEFAULT             800.132
#define RESULT_19_DEFAULT             800.133


#define RESULT_20_DEFAULT             900.123
#define RESULT_21_DEFAULT             900.124
#define RESULT_22_DEFAULT             900.125
#define RESULT_23_DEFAULT             900.126
#define RESULT_24_DEFAULT             900.127
#define RESULT_25_DEFAULT             900.128
#define RESULT_26_DEFAULT             900.129
#define RESULT_27_DEFAULT             900.131
#define RESULT_28_DEFAULT             900.132
#define RESULT_29_DEFAULT             900.133

#define RESULT_30_DEFAULT             1000.123
#define RESULT_31_DEFAULT             1000.124
#define RESULT_32_DEFAULT             1000.125
#define RESULT_33_DEFAULT             1000.126
#define RESULT_34_DEFAULT             1000.127
#define RESULT_35_DEFAULT             1000.128
#define RESULT_36_DEFAULT             1000.129
#define RESULT_37_DEFAULT             1000.131
#define RESULT_38_DEFAULT             1000.132
#define RESULT_39_DEFAULT             1000.133

#define RESULT_40_DEFAULT             1100.123
#define RESULT_41_DEFAULT             1100.124
#define RESULT_42_DEFAULT             1100.125
#define RESULT_43_DEFAULT             1100.126
#define RESULT_44_DEFAULT             1100.127
#define RESULT_45_DEFAULT             1100.128
#define RESULT_46_DEFAULT             1100.129
#define RESULT_47_DEFAULT             1100.131
#define RESULT_48_DEFAULT             1100.132
#define RESULT_49_DEFAULT             1100.133






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
#define ST_MODE_RUN1                    100               // Experimento de prueba 1.
#define ST_MODE_RUN2                    101               // Experimento de prueba 2.
#define ST_MODE_RUN3                    102               // Experimento de prueba 3.
#define ST_MODE_RUN4                    103               // Experimento de prueba 4.



class CMemory
{
  public:
    CMemory();

    uint8_t get_log_level( void );
    void set_log_level( uint8_t enable );

    uint8_t get_st_test( void );
    void set_st_test( uint8_t enable );

    uint8_t get_st_mode( void );
    void set_st_mode( uint8_t mode ); 


   
    

    void host_cmd( void );
    void send_test_finish(void);


   // Getter and setter's. 
   
   float get_input(uint8_t param); 
   void  set_input(uint8_t param, float value); 

   float get_output(uint8_t param);  
   void  set_output(uint8_t param, float value);

   
   float get_cfg(uint8_t param); 
   void set_cfg(uint8_t param, float value);


   float get_result(uint8_t param); 
   void  set_result(uint8_t param, float value);
   

  private:
    uint8_t log_level;         // 0 = serial de informacion de control desactivada.
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

    float result0;
    float result1;
    float result2;
    float result3;
    float result4;
    float result5;
    float result6;
    float result7;
    float result8;
    float result9;

    float result10;
    float result11;
    float result12;
    float result13;
    float result14;
    float result15;
    float result16;
    float result17;
    float result18;
    float result19;
    float result20;
    float result21;
    float result22;
    float result23;
    float result24;
    float result25;
    float result26;
    float result27;
    float result28;
    float result29;

    float result30;
    float result31;
    float result32;
    float result33;
    float result34;
    float result35;
    float result36;
    float result37;
    float result38;
    float result39;

    float result40;
    float result41;
    float result42;
    float result43;
    float result44;
    float result45;
    float result46;
    float result47;
    float result48;
    float result49;


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

    float get_result0( void );
    void  set_result0( float parameter );
    float get_result1( void );
    void  set_result1( float parameter );
    float get_result2( void );
    void  set_result2( float parameter );
    float get_result3( void );
    void  set_result3( float parameter ); 
    float get_result4( void );
    void  set_result4( float parameter );
    float get_result5( void );
    void  set_result5( float parameter ); 
    float get_result6( void );
    void  set_result6( float parameter ); 
    float get_result7( void );
    void  set_result7( float parameter ); 
    float get_result8( void );
    void  set_result8( float parameter ); 
    float get_result9( void );
    void  set_result9( float parameter );   
    float get_result10( void );
    void  set_result10( float parameter );
    float get_result11( void );
    void  set_result11( float parameter );
    float get_result12( void );
    void  set_result12( float parameter );
    float get_result13( void );
    void  set_result13( float parameter ); 
    float get_result14( void );
    void  set_result14( float parameter );
    float get_result15( void );
    void  set_result15( float parameter ); 
    float get_result16( void );
    void  set_result16( float parameter ); 
    float get_result17( void );
    void  set_result17( float parameter ); 
    float get_result18( void );
    void  set_result18( float parameter ); 
    float get_result19( void );
    void  set_result19( float parameter );   
    float get_result20( void );
    void  set_result20( float parameter );
    float get_result21( void );
    void  set_result21( float parameter );
    float get_result22( void );
    void  set_result22( float parameter );
    float get_result23( void );
    void  set_result23( float parameter ); 
    float get_result24( void );
    void  set_result24( float parameter );
    float get_result25( void );
    void  set_result25( float parameter ); 
    float get_result26( void );
    void  set_result26( float parameter ); 
    float get_result27( void );
    void  set_result27( float parameter ); 
    float get_result28( void );
    void  set_result28( float parameter ); 
    float get_result29( void );
    void  set_result29( float parameter );  
    float get_result30( void );
    void  set_result30( float parameter );
    float get_result31( void );
    void  set_result31( float parameter );
    float get_result32( void );
    void  set_result32( float parameter );
    float get_result33( void );
    void  set_result33( float parameter ); 
    float get_result34( void );
    void  set_result34( float parameter );
    float get_result35( void );
    void  set_result35( float parameter ); 
    float get_result36( void );
    void  set_result36( float parameter ); 
    float get_result37( void );
    void  set_result37( float parameter ); 
    float get_result38( void );
    void  set_result38( float parameter ); 
    float get_result39( void );
    void  set_result39( float parameter );     
    float get_result40( void );
    void  set_result40( float parameter );
    float get_result41( void );
    void  set_result41( float parameter );
    float get_result42( void );
    void  set_result42( float parameter );
    float get_result43( void );
    void  set_result43( float parameter ); 
    float get_result44( void );
    void  set_result44( float parameter );
    float get_result45( void );
    void  set_result45( float parameter ); 
    float get_result46( void );
    void  set_result46( float parameter ); 
    float get_result47( void );
    void  set_result47( float parameter ); 
    float get_result48( void );
    void  set_result48( float parameter ); 
    float get_result49( void );
    void  set_result49( float parameter );  
 
    
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
    void send_log_level( JsonDocument& doc );
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
   
   void send_result0(JsonDocument& doc);    
   void send_result1(JsonDocument& doc);    
   void send_result2(JsonDocument& doc);    
   void send_result3(JsonDocument& doc);    
   void send_result4(JsonDocument& doc);    
   void send_result5(JsonDocument& doc);    
   void send_result6(JsonDocument& doc);    
   void send_result7(JsonDocument& doc);    
   void send_result8(JsonDocument& doc);    
   void send_result9(JsonDocument& doc); 

   void send_result10(JsonDocument& doc);    
   void send_result11(JsonDocument& doc);    
   void send_result12(JsonDocument& doc);    
   void send_result13(JsonDocument& doc);    
   void send_result14(JsonDocument& doc);    
   void send_result15(JsonDocument& doc);    
   void send_result16(JsonDocument& doc);    
   void send_result17(JsonDocument& doc);    
   void send_result18(JsonDocument& doc);    
   void send_result19(JsonDocument& doc);

   void send_result20(JsonDocument& doc);    
   void send_result21(JsonDocument& doc);    
   void send_result22(JsonDocument& doc);    
   void send_result23(JsonDocument& doc);    
   void send_result24(JsonDocument& doc);    
   void send_result25(JsonDocument& doc);    
   void send_result26(JsonDocument& doc);    
   void send_result27(JsonDocument& doc);    
   void send_result28(JsonDocument& doc);    
   void send_result29(JsonDocument& doc);

   void send_result30(JsonDocument& doc);    
   void send_result31(JsonDocument& doc);    
   void send_result32(JsonDocument& doc);    
   void send_result33(JsonDocument& doc);    
   void send_result34(JsonDocument& doc);    
   void send_result35(JsonDocument& doc);    
   void send_result36(JsonDocument& doc);    
   void send_result37(JsonDocument& doc);    
   void send_result38(JsonDocument& doc);    
   void send_result39(JsonDocument& doc);

   void send_result40(JsonDocument& doc);    
   void send_result41(JsonDocument& doc);    
   void send_result42(JsonDocument& doc);    
   void send_result43(JsonDocument& doc);    
   void send_result44(JsonDocument& doc);    
   void send_result45(JsonDocument& doc);    
   void send_result46(JsonDocument& doc);    
   void send_result47(JsonDocument& doc);    
   void send_result48(JsonDocument& doc);    
   void send_result49(JsonDocument& doc);

  
   
};

#endif // memory_H
