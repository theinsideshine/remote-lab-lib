
 /*           

   - Compiler:           Arduino 1.8.15
   - Supported devices:  Mega

   \author              
                         LC: leandro.cintioli@alumnos.udemm.edu.ar
                         PT: pablo.tavolaro@alumnos.udemm.edu.ar

   Date:  1-04-2022

        Universidad de la Marina Mercante.
*/


// Lee por el puerto serie parametros de memoryuracion en formato json.
// {read:'all-params'}        Envia todos los parametros en formato json.
// {read:'all-input'}         Envia todos los parametros de entrada.
// {read:'all-output'}        Envia todos los parametros de salida.
// {read:'all-cfg'}           Envia todos los parametros de configuracion
// {read:'all-lib'}           Envia todos los parametros de configuracion de remoteLabLib
// {read:'all-result'}         Envia todos los parametros de resultados
 
// {read:'version'}           Envia  la version del firmware.
// {read:'status'}            Devuelve el estatus del ensayo.

// {read:'serial_level'}         Nivel de serialeo por puerto serie.


// {serial_level:'0'}       serial_level:0=desactivado,
// {serial_level:'1'}                 1=mensajes.
// {serial_level:'2'}                 2=info control estandar.
// {serial_level:'3'}                 3=info control arduino plotter.

// {cmd:'start'}       Comienza el ensayo.



 //   {cdd:'start',data:{distance:'20',force:'306'}} 

// {input0:'250.2',input1:'250.3',input2:'250.4',input3:'250.5',input4:'250.6'}
// {input0:'250'}       input0       parametro de entrada tipo float 
// {inputx:'250'}       inputx       

// {output0:'250'}      output0       parametro de salida tipo float 
// {outputx:'250'}      outputx  

// {cfg0:'250'}      cfg0       parametro de configuracion tipo float 
// {cfgx:'250'}      cfgx 



// {float_0:'70.123'}      float_0      parametro float
// {float_x:'70.123'}      float_x      parametro float

// {st_test:'1'}         st_test       0 ensayo desactivado. 
//                       st_test       1 ensayo activado. 
// {st_mode:'0'}         st_mode       ST_MODE_TEST                    0  ensayo activado.
//                                     ST_MODE_HOME_M2                 1 Va al home del motor 2.
//                                     ST_MODE_CELL                    2 Lee las celdas de carga.




#include "serial.h"
#include "memory.h"
#include "led.h"



/*
 * Estado del loop principal de ejecucion
 */

#define ST_LOOP_INIT                    0     // Inicializa el programa (carga la memoryuracion).
#define ST_LOOP_IDLE                    1     // Espera la recepcion por comando.
#define ST_LOOP_HOME_M1                 2     // Busca la referencia del Motor 1.
#define ST_LOOP_HOME_M2                 3     // Busca la referencia del Motor 1.
#define ST_LOOP_POINT_M1                4     // Se mueve m1 cantidada de pasos requeridos en mm.

#define ST_LOOP_FORCE_M2                5     // Se mueve m2 hasta que encuentra la fuerza requerida en kilos.
#define ST_LOOP_GET_R1                  6     // Lee la celda de carga reaction1. 
#define ST_LOOP_GET_R2                  7     // Lee la celda de carga reaction2. 
#define ST_LOOP_GET_FLEXION             8     // Calcula la flexion y la guarda en la memoryuracion
#define ST_LOOP_OFF_TEST                9    // Termino el ensayo.
#define ST_LOOP_MODE_HOME_M2            10    // Se mueve al home 2.
#define ST_LOOP_MODE_CELL               11    // Lee las celdas de carga.



/*
 * Clases del sistema
 */

Cserial    serial;
Cmemory memory;
CLed     Led;
 


/*
 * memoryura el final de ensayo
 * vuelve el st_test = 0 y envia el valor al servidor.
 */

void end_experiment( void ) {
 
  //Led.n_blink(3, 1000);                       // 2 blinks cada 2000 ms;
  serial.msg( F("Experimento terminado"));
  
  memory.set_st_test( false );
  memory.send_test_finish(); // Informa al servidor que termino el ensayo.
}

/*
 *  Inicializa los dispositivos del ensayo segun opciones de precompilacion.
 */

void setup()
{
  serial.init( memory.get_serial_level() );
  //Serial.println("Init Serial");
  /*
      Para activar la visualisacion  enviar por serie {serial_level:'1'}
  */

  serial.msg( F("Remote Lab library - %s"), FIRMWARE_VERSION );
  serial.msg( F("UDEMM - 2022") );


  Led.init();
  serial.msg( F("Led init") );
  Led.n_blink(2, 500); // 1 blinks cada 2000 ms
 



  serial.msg( F("Sistema inicializado") );

}
 
/*
 *Loop de control del Ensayo viga simplemente apoyada 
 */

void loop()
{
  static uint8_t  st_loop = ST_LOOP_INIT;   
  
  // Verifica si el host envio un JSON con parametros a procesar.
  memory.host_cmd();
  
  // Actualiza el nivel de serial para detener en tiempo real el envio de parametros.
  serial.set_level( memory.get_serial_level() );
  
  switch ( st_loop ) {

    case ST_LOOP_INIT:

      st_loop = ST_LOOP_IDLE ;

    break;

    // Espera "eventos" de ejecucion
    case ST_LOOP_IDLE:

      
       
      if (memory.get_st_test() == true ) {                   // Espera que se comienzo al ensayo.        
        st_loop = ST_LOOP_HOME_M2; 
      }
      
    break;

    
    case ST_LOOP_HOME_M2:    

       
      serial.msg( F("Comienzo del experimento") );         
      Led.n_blink(5, 500);
     
      
      st_loop = ST_LOOP_OFF_TEST;
      
    break;    
      
     // Termina el ensayo.
    case ST_LOOP_OFF_TEST:  
    // Envia comando de final de experimento  
       end_experiment();   
      st_loop = ST_LOOP_IDLE;
      
      break;      

      default:
      st_loop = ST_LOOP_INIT;

  }
#ifdef ST_DEBUG
  serial.msg( F("ST_LOOP= %d"), st_loop );
#endif //ST_DEBUG



}
