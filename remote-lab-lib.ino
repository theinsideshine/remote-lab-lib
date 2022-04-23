
 /*           

   - Compiler:           Arduino 1.8.15
   - Supported devices:  Mega

   \author              
                         LC: leandro.cintioli@alumnos.udemm.edu.ar
                         PT: pablo.tavolaro@alumnos.udemm.edu.ar

   Date:  1-04-2022

        Universidad de la Marina Mercante.
*/


// *********************************************
// **************Json lectura*******************

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


// *********************************************
// **************Json escritura*****************

// {input0:'250.2',input1:'250.3',input2:'250.4',input3:'250.5',input4:'250.6'}
// {input0:'250'}       input0       parametro de entrada tipo float 
// {inputx:'250'}       inputx       

// {output0:'250'}      output0       parametro de salida tipo float 
// {outputx:'250'}      outputx  

// {cfg0:'250'}      cfg0       parametro de configuracion tipo float 
// {cfgx:'250'}      cfgx 

// {result0:'70.123'}      result0      parametro float
// {resultx:'70.123'}      resultx      p

// *********************************************
// ****Comando de ejecucion del experimento*****

// {cmd:'start'}       Comienza el ensayo.} 

// *********************************************
// **************Estado de la Lib****************
// {st_test:'1'}         st_test       0 ensayo desactivado. 
//                       st_test       1 ensayo activado. 
// {st_mode:'0'}         st_mode       Modo de operacion normal, ensayo activado.
// {st_mode:'100'}       st_mode       Experimento de prueba 1. 
// {st_mode:'101'}       st_mode       Experimento de prueba 2.  
// {st_mode:'102'}       st_mode       Experimento de prueba 3. 
// {st_mode:'103'}       st_mode       Experimento de prueba 4.    
// {st_mode:'200'}       st_mode       Experimento de demo   1.                           




#include "log.h"
#include "memory.h"
#include "led.h"
#include "param.h"



/*
 * Estado del loop principal de ejecucion
 */

#define ST_LOOP_INIT                    0     // Inicializa el programa (carga la memoryuracion).
#define ST_LOOP_IDLE                    1     // Espera la recepcion por comando.
#define ST_LOOP_RUN_TEST                2     // Experimento en ejecucion. 
#define ST_LOOP_END_TEST                3     // Termino el ensayo.
#define ST_MODE_RUN_EXAMPLE1            4     // Experimento1 para ejecutar desde el frontEnd.
#define ST_MODE_RUN_EXAMPLE2            5     // Experimento2 para ejecutar desde el frontEnd.
#define ST_MODE_RUN_EXAMPLE3            6     // Experimento3 para ejecutar desde el frontEnd.
#define ST_MODE_RUN_EXAMPLE4            7     // Experimento4 para ejecutar desde el frontEnd.
#define ST_MODE_RUN_DEMO1               8     // Demo del uso del estamo mode.
/*
 * Clases del sistema
 */

CLog    Log;                              // Manejo del puerto serie.
CMemory Memory;                           // Manejo de la memoria EEPROM.
CLed     Led;                             // Manejo del led.

static void experiment( void );          // Experimento escrito por el usuario. 
static void run_example1( void );        // Experimento de prueba 1.
static void run_example2( void );        // Experimento de prueba 2.
static void run_example3( void );        // Experimento de prueba 3.
static void run_example4( void );        // Experimento de prueba 4.
static void run_demo1( void);            // Demo del uso del estado mode.

/*
 * realizz el final de ensayo
 * vuelve el st_test = 0 y envia el valor al servidor.
 */

void end_experiment( void ) {
 
  //Led.n_blink(3, 1000);                       // 2 blinks cada 2000 ms;
  Log.msg( F("Experimento terminado"));
  
  Memory.set_st_test( false );
  Memory.send_test_finish(); // Informa al servidor que termino el ensayo.
}

/*
 *  Inicializa los dispositivos del ensayo 
 */

void setup()
{
  Log.init( Memory.get_log_level() );// Carga el nivel de logeo en memoria
  Serial.println("Init Serial");
  /*
      Para activar la visualisacion  enviar por serie {serial_level:'1'}
  */

  Log.msg( F("Remote Lab library - %s"), FIRMWARE_VERSION );
  Log.msg( F("UDEMM - 2022") );

  Led.init();
  Log.msg( F("Led init") );
  Led.n_blink(2, 500); // 1 blinks cada 2000 ms

  Log.msg( F("Sistema inicializado") );

}
 
/*
 *Loop de control 
 */

void loop()
{
  static uint8_t  st_loop = ST_LOOP_INIT;   
  
  // Verifica si el host envio un JSON con parametros a procesar.
  Memory.host_cmd();
  
  // Actualiza el nivel de serial para detener en tiempo real el envio de parametros.
  Log.set_level( Memory.get_log_level() );
  
  switch ( st_loop ) {

    case ST_LOOP_INIT:

      st_loop = ST_LOOP_IDLE ;

    break;

    // Espera comando de ejecucion
    case ST_LOOP_IDLE:      
       
      if (Memory.get_st_test() == true ) {                   // Espera que se comienzo al ensayo.        
        st_loop = ST_LOOP_RUN_TEST; 
      }else if (Memory.get_st_mode() == ST_MODE_RUN1 ) { // Espera el modo runExample1
        st_loop =  ST_MODE_RUN_EXAMPLE1 ;
      }else if (Memory.get_st_mode() == ST_MODE_RUN2 ) { // Espera el modo runExample1
        st_loop =  ST_MODE_RUN_EXAMPLE2 ;
      }else if (Memory.get_st_mode() == ST_MODE_RUN3 ) { // Espera el modo runExample1
        st_loop =  ST_MODE_RUN_EXAMPLE3 ;
      }else if (Memory.get_st_mode() == ST_MODE_RUN4 ) { // Espera el modo runExample1
        st_loop =  ST_MODE_RUN_EXAMPLE4 ;
      }else if (Memory.get_st_mode() == ST_MODE_DEMO ) { // Espera el modo runExample1
        st_loop =  ST_MODE_RUN_DEMO1 ;
      }
      
      
    break;
      // Ejecuta el ensayo.
    case ST_LOOP_RUN_TEST:    
       
      Log.msg( F("Comienzo del experimento") );         
      experiment();                      
      st_loop = ST_LOOP_END_TEST;
      
    break;    
      
     // Termina el ensayo.
    case ST_LOOP_END_TEST:  
    // Envia comando de final de experimento  
       end_experiment();   
      st_loop = ST_LOOP_IDLE;
      
      break;   

      case ST_MODE_RUN_EXAMPLE1:                    
     
      run_example1();      
       st_loop = ST_LOOP_END_TEST;
      
      break;

      case ST_MODE_RUN_EXAMPLE2:                    
     
      run_example2();      
      st_loop = ST_LOOP_IDLE;
      
      break;
      
      case ST_MODE_RUN_EXAMPLE3:  
      run_example3();      
      st_loop = ST_LOOP_IDLE;
      
      break;

      case ST_MODE_RUN_EXAMPLE4:  
      run_example4();      
      st_loop = ST_LOOP_IDLE;
      
      break;

      case ST_MODE_RUN_DEMO1:  
      run_demo1();      
      st_loop = ST_LOOP_IDLE;
      
      break;

      default:
      st_loop = ST_LOOP_INIT;

  }
#ifdef ST_DEBUG // Definir esta macro si se desea ver el StateMachine
  Log.msg( F("ST_LOOP= %d"), st_loop );
#endif //ST_DEBUG
}



 /*
  *  Experimento de prueba 1.
  */

static void run_example1( void ){
  
   Log.msg( F("Ejemplo de prueba 1"));
   Led.n_blink(2, 500);
   Memory.set_output(ACELERACION, ( Memory.get_input(FUERZA)  + Memory.get_cfg(INPUT0_ADD) ) + ( 2 *  Memory.get_cfg(INPUT0_MUL)) );
   Memory.set_output(MILIMETROS,  ( Memory.get_input(PESO)    + Memory.get_cfg(INPUT1_ADD) ) + ( 2 *  Memory.get_cfg(INPUT1_MUL)));
   Memory.set_output(AMPER,       ( Memory.get_input(ENERGIA) + Memory.get_cfg(INPUT2_ADD) ) + ( 2 *  Memory.get_cfg(INPUT2_MUL)));
   Memory.set_output(NEWTON,      ( Memory.get_input(TENSION) + Memory.get_cfg(INPUT3_ADD) ) + ( 2 *  Memory.get_cfg(INPUT3_MUL)));
   Memory.set_output(ANGULO,      ( Memory.get_input(POTENCIA)+ Memory.get_cfg(INPUT4_ADD) ) + ( 2 *  Memory.get_cfg(INPUT4_MUL)));
   Log.msg( F("Fin de prueba 1"));
   Memory.set_st_mode( ST_MODE_TEST );
}

/*
  *  Experimento de prueba 2.
  */

static void run_example2( void ){

  float t_blinkF; 
  float n_blinkF;
  
  Log.msg( F("Ejemplo de prueba 2"));

  n_blinkF=  Memory.get_cfg(INPUT0_MUL); // Carga el numero de blinks.
  t_blinkF=  Memory.get_cfg(INPUT1_MUL); // Carga el tiempo de blinks.

    /*
   * Trampa para evitar errores en el ingreso de datos antes del cast 
   * Si el numero es negativo que ponga el min. Si no luego del cast no puede identificare el signo.
   * 
   */

  if ( n_blinkF < 0) {
    n_blinkF = N_BLINK_MIN;
  }

  if ( t_blinkF < 0) {
    t_blinkF = T_BLINK_MIN ;
  }
  
   
  
  Led.n_blink((uint8_t) n_blinkF, (uint16_t) t_blinkF);  
  Log.msg( F("Fin de prueba 2"));
   Memory.set_st_mode( ST_MODE_TEST );
}



 /*
  *  Experimento de prueba 3.
  */

static void run_example3( void ){
   uint8_t i;
   Log.msg( F("Ejemplo de prueba 3"));
   Led.n_blink(2, 500);

   for (i=0; i<50 ; i++){
    Memory.set_result(i,i);
   }
   Log.msg( F("Fin de prueba 3"));
   Memory.set_st_mode( ST_MODE_TEST );
}


/*
  *  Experimento de prueba 4.
  */

static void run_example4( void ){
   uint8_t i;
   Log.msg( F("Ejemplo de prueba 4"));
   Led.n_blink(2, 500);

   for (i=0; i<50 ; i++){
    Memory.set_result(i,49-i);
   }
   Log.msg( F("Fin de prueba 4"));
   Memory.set_st_mode( ST_MODE_TEST );
}



/* 
 *  Demo de uso del estado mode
 */

static void run_demo1( void ){

  Led.n_blink(10, 100);
  
  
}
 
/*
 * Experimento de usuario: Demo Arduino Plotter
 * este codigo se usa en el video:  https://youtu.be/7ykRqe4GuWU 
 */
/*
 static void experiment( void ){
  // Escribir experimento 
  uint16_t raw, filtered,danger_point=2500;
   uint8_t state=0; 
   
  Led.n_blink(5, 500);
  for (raw=0;raw<5000;raw++){
      filtered = raw+1 ;
      if (filtered >danger_point ){ 
        state=1 ;
      }
      Log.ctrl (raw, filtered,state,danger_point);
  }
  */
  
  /*
   * Aca el usuario escribe su experimento.
 */

 static void experiment( void ){
  // Escribir experimento  
   
  Led.n_blink(5, 500);
   Memory.set_input(FUERZA, 15);
   Memory.set_output(ACELERACION,  Memory.get_input(FUERZA)  + 4 );
   
   
  
 }
