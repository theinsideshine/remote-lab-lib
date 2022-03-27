
 /*           

   - Compiler:           Arduino 1.8.15
   - Supported devices:  Mega

   \author              
                         LC: leandro.cintioli@alumnos.udemm.edu.ar
                         PT: pablo.tavolaro@alumnos.udemm.edu.ar

   Date:  1-04-2022

        Universidad de la Marina Mercante.
*/




#include "serial.h"
#include "memory.h"
#include "timer.h"
#include "button.h"
#include "led.h"
#include "precompilation.h"


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
 
  Led.n_blink(3, 2000);                       // 2 blinks cada 2000 ms;
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
  Serial.println("Init Serial");
  /*
      Para activar la visualisacion  enviar por serie {serial_level:'1'}
  */

  serial.msg( F("Remote Lab library - %s"), FIRMWARE_VERSION );
  serial.msg( F("UDEMM - 2022") );

#ifdef LED_PRESENT
  Led.init();
  serial.msg( F("Led init") );
  Led.n_blink(1, 2000); // 1 blinks cada 2000 ms
#endif // LED_PRESENT   



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
      Led.n_blink(5, 1000); 
      
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
