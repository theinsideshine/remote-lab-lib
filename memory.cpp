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

        set_distance( DISTANCE_DEFAULT );
        set_force( FORCE_DEFAULT );
        set_reaction1(REACTION1_DEFAULT );
        set_reaction2(REACTION2_DEFAULT );         
        set_flexion(FLEXION_DEFAULT);
        set_step_cal( STEP_CAL_DEFAULT );
        set_step_k( STEP_K_DEFAULT );        
        
        //set_serial_level( serial_DISABLED );
        set_serial_level( serial_MSG ); // cuando cambias el magic numbre setea los mensajes de serialeo (Arduino 1,primer inicio")        
        set_st_test(ST_TEST_DEFAULT);
        set_st_mode(ST_MODE_DEFAULT );

        
    }else {
        EEPROM.get( EEPROM_ADDRESS_DISTANCE, distance );
        EEPROM.get( EEPROM_ADDRESS_FORCE, force);
        EEPROM.get( EEPROM_ADDRESS_REACTION_1, reaction1 );
        EEPROM.get( EEPROM_ADDRESS_REACTION_2, reaction2 );       
        EEPROM.get( EEPROM_ADDRESS_FLEXION, flexion );
        EEPROM.get( EEPROM_ADDRESS_STEP_CAL, step_cal );
        EEPROM.get( EEPROM_ADDRESS_STEP_K, step_k );

        EEPROM.get( EEPROM_ADDRESS_serial_LEVEL, serial_level );
        //EEPROM.get( EEPROM_ADDRESS_ST_MODE, st_mode );
        
       //EEPROM.get( EEPROM_ADDRESS_ST_TEST, st_test );
       //estos parametro inicializa en 0 independiente de como este en la eprrom ya que estos ejecutan el ST_LOOP
       set_st_test(ST_TEST_DEFAULT);
       set_st_mode(ST_MODE_DEFAULT );
       
        
    }
}

uint16_t Cmemory::get_distance( void )
{
    return distance;
}

void Cmemory::set_distance( uint16_t val )
{
    distance = val;
    EEPROM.put( EEPROM_ADDRESS_DISTANCE, val );
}

float Cmemory::get_force( void )
{
    return force;
}

void Cmemory::set_force( float val )
{
    force = val;
    EEPROM.put( EEPROM_ADDRESS_FORCE, val );
}

float Cmemory::get_reaction1( void )
{
    return reaction1;
}

void Cmemory::set_reaction1( float val )
{
   
    reaction1 = val;
    EEPROM.put( EEPROM_ADDRESS_REACTION_1, val );
}

float Cmemory::get_reaction2( void )
{
    return reaction2;
}

void Cmemory::set_reaction2( float val )
{
    reaction2 = val;
    EEPROM.put( EEPROM_ADDRESS_REACTION_2, val );
}



float Cmemory::get_flexion( void )
{
    return flexion;
}

void Cmemory::set_flexion( float val )
{
    flexion = val;
    EEPROM.put( EEPROM_ADDRESS_FLEXION, val );
}

uint32_t Cmemory::get_step_cal( void )
{
    return step_cal;
}

void Cmemory::set_step_cal( uint32_t val )
{
    step_cal = val;
    EEPROM.put( EEPROM_ADDRESS_STEP_CAL, val );
}

float Cmemory::get_step_k( void )
{
    return step_k;
}

void Cmemory::set_step_k ( float val )
{
    step_k = val;
    EEPROM.put( EEPROM_ADDRESS_STEP_K, val );
}

uint8_t Cmemory::get_serial_level( void )
{
    return serial_level;
}

void Cmemory::set_serial_level( uint8_t enable )
{
    serial_level = enable;
    EEPROM.put( EEPROM_ADDRESS_serial_LEVEL, serial_level );
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


// Lee por el puerto serie parametros de memoryuracion en formato json.
// {info:'all-params'}        Envia todos los parametros en formato json.
// {info:'all-calibration'}   Envia todos los parametros en formato json de calibracion de la flexion y el nivel de serialeo.
// {info:'version'}           Envia  la version del firmware.
// {info:'status'}            Devuelve el estatus del ensayo.
// {info:'reaction_one'}      Devuelve la reaction1 del ensayo.
// {info:'reaction_two'}      Devuelve la reaction2 del ensayo.
// {info:'flexion'}           Devuelve la flexion del ensayo.
// {info:'st_mode'}           Devuelve el modo del ensayo.
// {info:'step_cal'}          Devuelve la cantidad de pasos contados para la calibracion de step_k.
// {info:'step_k'}            Constante de calibracion de flexion.
// {info:'serial_level'}         Nivel de serialeo por puerto serie.


// {serial_level:'0'}       serial_level:0=desactivado,
// {serial_level:'1'}                 1=mensajes.
// {serial_level:'2'}                 2=info control estandar.
// {serial_level:'3'}                 3=info control arduino plotter.

// {cmd:'start'}       Comienza el ensayo.



 //   {cdd:'start',data:{distance:'20',force:'306'}} 


// {distance:'290'}      distance      Distancia en mm donde se aplica la fuerza.
// {force:'2000'}        force         Fuerza a aplicar en g.
// {reaction_one:'1'}    reaction_one  Fuerza de reaccion uno, en g.
// {reaction_two:'2'}    reaction_two  Fuerza de reaccion dos, en g.
// {flexion:'0.12630'}   flexion       Flexion del ensayo, en cm.
// {st_test:'1'}         st_test       0 ensayo desactivado. 
//                       st_test       1 ensayo activado. 
// {st_mode:'0'}         st_mode       ST_MODE_TEST                    0  ensayo activado.
//                                     ST_MODE_HOME_M2                 1 Va al home del motor 2.
//                                     ST_MODE_CELL                    2 Lee las celdas de carga.
//  {step_cal:'2000'}    step_cal      Devuelve la cantidad de pasos contados para la calibracion de step_k.
//  {step_k:'0.123456'}  step_k        Constante de calibracion de flexion.
                                   

void Cmemory::host_cmd( void )
{
bool known_key = false;

    if ( Serial.available() ){
        StaticJsonDocument<512> doc;
        auto error = deserializeJson( doc, Serial );
        if ( !error ) {
          
            if ( doc.containsKey("distance") ) {
                set_distance( doc["distance"] );
                known_key = true;
            }

            if ( doc.containsKey("force") ) {
                float temp = doc["force"];                
                set_force( doc["force"] );
                known_key = true;
            }

            if ( doc.containsKey("reaction_one") ) {
                set_reaction1( doc["reaction_one"] );
                known_key = true;
            }

            if ( doc.containsKey("reaction_two") ) {
                set_reaction2( doc["reaction_two"] );
                known_key = true;
            }

            if ( doc.containsKey("flexion") ) {
                set_flexion( doc["flexion"] );
                known_key = true;
            }

             if ( doc.containsKey("step_cal") ) {
                set_step_cal( doc["step_cal"] );
                known_key = true;
            }

            if ( doc.containsKey("step_k") ) {
                set_step_k( doc["step_k"] );
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
                   

            if ( doc.containsKey("info") ) {
                String key = doc["info"];

                if( key == "all-params" ) {
                    send_all_params( doc );
                }else if( key == "all-calibration" ) {
                    send_all_calibration( doc );
                }else if( key == "version" ) {
                    send_version( doc );
                }else if( key == "status" ) {
                    send_status( doc );
                }else if( key == "reaction_one" ) {
                    send_reaction_one( doc );
                }else if( key == "reaction_two" ) {
                    send_reaction_two( doc );
                }else if( key == "flexion" ) {
                    send_flexion( doc );
                }else if( key == "st_mode" ) {
                    send_st_mode( doc );
                }else if( key == "step_cal" ) {
                    send_step_cal( doc );
                }else if( key == "step_k" ) {
                    send_step_k( doc );
                }else if( key == "serial_level" ) {
                    send_serial_level( doc );
                }
                
            }

            // Usamos cdd hasta definir que unifiquemos comandos, en realidad es cmd. 
            // Segun el uso https://arduinojson.org/v6/api/jsondocument/containskey/ 
            // para preguntar sobre la clave de un objeto  se usa  const char* key1 =doc["data"]["distance"];

            
            if ( doc.containsKey("cdd") ) { //Verifica "cdd".
                String key = doc["cdd"];
                 if( key == "start" ) {    //Verifica "start".
                     const char* key1 =doc["data"]["distance"];
                     const char* key2 =doc["data"]["force"];
                    if (key1 && key2) {   //Verifica "distance". "force".
                       set_distance( doc["data"]["distance"]);
                       set_force( doc["data"]["force"] );  
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

void Cmemory::send_all_params( JsonDocument& doc )
{
    doc["distance"] = get_distance();
    doc["force"] =  get_force();
    doc["reaction_one"] = get_reaction1();
    doc["reaction_two"] =  get_reaction2();
    doc["flexion"] = get_flexion();             
    doc["st_test"] = get_st_test();    
   
    serializeJsonPretty( doc, Serial );
}

/*
 *  Envia todos los parametros de calibracion de la flexion y el nivel de serialgeo.
 */

void Cmemory::send_all_calibration( JsonDocument& doc )
{
    doc["step_cal"] = get_step_cal();
    doc["step_k"] =  get_step_k();
    doc["serial_level"] =  get_serial_level();
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

// Envia la reaccion 1
void Cmemory::send_reaction_one( JsonDocument& doc )
{
    doc["reaction_one"] =  get_reaction1();;

    serializeJsonPretty( doc, Serial );
}

// Envia la reaccion 2
void Cmemory::send_reaction_two( JsonDocument& doc )
{
    doc["reaction_two"] =  get_reaction2();;

    serializeJsonPretty( doc, Serial );
}

// Envia la flexion de contar los pasos del motor2
void Cmemory::send_flexion( JsonDocument& doc )
{
    doc["flexion"] =  get_flexion();

    serializeJsonPretty( doc, Serial );
}

// Envia la cantidad de pasos contados para la calibracion de ktep.
void Cmemory::send_step_cal( JsonDocument& doc )
{
    doc["step_cal"] =  get_step_cal();

    serializeJsonPretty( doc, Serial );
}

// Envia step_k
void Cmemory::send_step_k( JsonDocument& doc )
{
    doc["step_k"] =  get_step_k();

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
    doc["status"] = get_st_test();;

    serializeJsonPretty( doc, Serial );
}

// Envia el modo del ensayo.
void Cmemory::send_st_mode( JsonDocument& doc )
{
    doc["st_mode"] = get_st_mode();;

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
