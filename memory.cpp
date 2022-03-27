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

// Lee por el puerto serie parametros de memoryuracion en formato json.
// {read:'all-params'}        Envia todos los parametros en formato json.
// {read:'all-cfg'}           Envia todos los parametros de remoteLabLib
// {read:'all-uint8'}         Envia todos los parametros unsigned 8 bits
// {read:'all-uint16'}        Envia todos los parametros unsigned 16 bits
// {read:'all-int32'}         Envia todos los parametros signed 32 bits
 
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
// {uint8_1:'250'}       uint8_1       parametro de 8 bits sin signo 
// {uint8_2:'250'}       uint8_2       parametro de 8 bits sin signo 
// {uint8_3:'250'}       uint8_3       parametro de 8 bits sin signo 
// {uint8_4:'250'}       uint8_4       parametro de 8 bits sin signo 
// {uint8_5:'250'}       uint8_5       parametro de 8 bits sin signo 
// {uint8_6:'250'}       uint8_6       parametro de 8 bits sin signo 
// {uint8_7:'250'}       uint8_7       parametro de 8 bits sin signo 
// {uint8_8:'250'}       uint8_8       parametro de 8 bits sin signo 
// {uint8_9:'250'}       uint8_9       parametro de 8 bits sin signo

// {uint16_0:'250'}       uint16_0       parametro de 16 bits sin signo
// {uint16_1:'250'}       uint16_1       parametro de 16 bits sin signo 
// {uint16_2:'250'}       uint16_2       parametro de 16 bits sin signo 
// {uint16_3:'250'}       uint16_3       parametro de 16 bits sin signo 
// {uint16_4:'250'}       uint16_4       parametro de 16 bits sin signo 
// {uint16_5:'250'}       uint16_5       parametro de 16 bits sin signo 
// {uint16_6:'250'}       uint16_6       parametro de 16 bits sin signo 
// {uint16_7:'250'}       uint16_7       parametro de 16 bits sin signo 
// {uint16_8:'250'}       uint16_8       parametro de 16 bits sin signo 
// {uint16_9:'250'}       uint16_9       parametro de 16 bits sin signo 


// {int32_0:'70000'}      int32_0       parametro de 32 bits con signo
// {int32_1:'70000'}      int32_1       parametro de 32 bits con signo
// {int32_2:'70000'}      int32_2       parametro de 32 bits con signo
// {int32_3:'70000'}      int32_3       parametro de 32 bits con signo
// {int32_4:'70000'}      int32_4       parametro de 32 bits con signo
// {int32_5:'70000'}      int32_5       parametro de 32 bits con signo
// {int32_6:'70000'}      int32_6       parametro de 32 bits con signo
// {int32_7:'70000'}      int32_7       parametro de 32 bits con signo
// {int32_8:'70000'}      int32_8       parametro de 32 bits con signo
// {int32_9:'70000'}      int32_9       parametro de 32 bits con signo



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
