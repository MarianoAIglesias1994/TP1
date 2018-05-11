/* Copyright 2016, Eric Pernia.
 * All rights reserved.
 *
 * This file is part sAPI library for microcontrollers.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * Date: 2016-04-26
 */

/*==================[inclusions]=============================================*/

//#include "blinky.h"   // <= own header (optional)
#include "sapi.h"       // <= sAPI header
#include "TP1.h"       // Inclusion para compilacion condicional

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

#ifdef TP1_3

/* FUNCION que se ejecuta cada vez que ocurre un Tick. */
void myTickHook( void *ptr ){

	static bool_t ledState = OFF;

	gpioMap_t led = (gpioMap_t)ptr;

	if( ledState ){
		ledState = OFF;
	}
	else{
		ledState = ON;
	}
	gpioWrite( led, ledState );
}

#endif // TP1_3


#ifdef TP1_4

#define TICKRATE_MS 10
#define LED_TOGGLE_MS 500

/* FUNCION que se ejecuta cada vez que ocurre un Tick. */
void myTickHook( void *ptr ){

	static bool_t ledState = OFF;

	gpioMap_t led = (gpioMap_t)ptr;

	if( ledState ){
		ledState = OFF;
	}
	else{
		ledState = ON;
	}
	gpioWrite( led, ledState );
}

#endif // TP1_4


#ifdef TP1_4_d

#define TICKRATE_MS 10
#define LED_TOGGLE_MS 500

/* FUNCION que se ejecuta cada vez que ocurre un Tick. */
void myTickHook( void *ptr ){

	static bool_t ledState = OFF;

	gpioMap_t led = (gpioMap_t)ptr;

	if( ledState ){
		ledState = OFF;
	}
	else{
		ledState = ON;
	}
	gpioWrite( led, ledState );
}

#endif // TP1_4_d

#ifdef TP1_5

#define TICKRATE_MS 10
#define LED_TOGGLE_MS 500

/* FUNCION que se ejecuta cada vez que ocurre un Tick. */
void myTickHook( void *ptr ){

	static bool_t ledState = OFF;

	gpioMap_t led = (gpioMap_t)ptr;

	if( ledState ){
		ledState = OFF;
	}
	else{
		ledState = ON;
	}
	gpioWrite( led, ledState );
}

#endif // TP1_5


#ifdef TP1_6

#define TICKRATE_MS 10
#define LED_TOGGLE_MS 500

/* FUNCION que se ejecuta cada vez que ocurre un Tick. */
void myTickHook( void *ptr ){

	static bool_t ledState = OFF;

	gpioMap_t led = (gpioMap_t)ptr;

	if( ledState ){
		ledState = OFF;
	}
	else{
		ledState = ON;
	}
	gpioWrite( led, ledState );
}

#endif // TP1_6







/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void){

   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

#ifdef TP1_1

   /* ------------- REPETIR POR SIEMPRE ------------- */
   while(1) {

	   /* Prendo el led azul */
	   gpioWrite( LEDB, ON );

	   delay(500);

	   /* Apago el led azul */
	   gpioWrite( LEDB, OFF );

	   delay(500);

   }

#endif // TP1_1

#ifdef TP1_2

   gpioConfig( GPIO0, GPIO_INPUT );

   gpioConfig( GPIO1, GPIO_OUTPUT );

   /* Variable para almacenar el valor de tecla leido */
   bool_t valor;

   /* ------------- REPETIR POR SIEMPRE ------------- */
   while(1) {

	   valor = !gpioRead( TEC1 );
	   gpioWrite( LEDB, valor );

	   valor = !gpioRead( TEC2 );
	   gpioWrite( LED1, valor );

	   valor = !gpioRead( TEC3 );
	   gpioWrite( LED2, valor );

	   valor = !gpioRead( TEC4 );
	   gpioWrite( LED3, valor );

	   valor = !gpioRead( GPIO0 );
	   gpioWrite( GPIO1, valor );

   }

#endif // TP1_2

#ifdef TP1_3

   /* Inicializar el conteo de Ticks con resolucion de 50ms (se ejecuta
      periodicamente una interrupcion cada 50ms que incrementa un contador de
      Ticks obteniendose una base de tiempos). */
   tickConfig( 50 );

   /* Se agrega ademas un "tick hook" nombrado myTickHook. El tick hook es
      simplemente una funcion que se ejecutara peri�odicamente con cada
      interrupcion de Tick, este nombre se refiere a una funcion "enganchada"
      a una interrupcion.
      El segundo parametro es el parametro que recibe la funcion myTickHook
      al ejecutarse. En este ejemplo se utiliza para pasarle el led a titilar.
   */
   tickCallbackSet( myTickHook, (void*)LEDR );
   delay(1000);

   /* ------------- REPETIR POR SIEMPRE ------------- */
      while(1) {
         tickCallbackSet( myTickHook, (void*)LEDG );
         delay(1000);
         tickCallbackSet( myTickHook, (void*)LEDB );
         delay(1000);
         tickCallbackSet( myTickHook, (void*)LED1 );
         delay(1000);
         tickCallbackSet( myTickHook, (void*)LED2 );
         delay(1000);
         tickCallbackSet( myTickHook, (void*)LED3 );
         delay(1000);
         tickCallbackSet( myTickHook, (void*)LEDR );
         delay(1000);
      }

#endif // TP1_3

#ifdef TP1_4

   tickConfig( TICKRATE_MS );

   tickCallbackSet( myTickHook, (void*)LEDR );
   delay(1000);

   /* ------------- REPETIR POR SIEMPRE ------------- */
      while(1) {
         tickCallbackSet( myTickHook, (void*)LEDG );
         delay(LED_TOGGLE_MS);
         tickCallbackSet( myTickHook, (void*)LEDB );
         delay(LED_TOGGLE_MS);
         tickCallbackSet( myTickHook, (void*)LED1 );
         delay(LED_TOGGLE_MS);
         tickCallbackSet( myTickHook, (void*)LED2 );
         delay(LED_TOGGLE_MS);
         tickCallbackSet( myTickHook, (void*)LED3 );
         delay(LED_TOGGLE_MS);
         tickCallbackSet( myTickHook, (void*)LEDR );
         delay(LED_TOGGLE_MS);
      }

#endif // TP1_4

#ifdef TP1_4_d

   tickConfig( TICKRATE_MS );

   tickCallbackSet( myTickHook, (void*)LEDR );
   delay(1000);

   int LED = LEDR;

   /* ------------- REPETIR POR SIEMPRE ------------- */
      while(1) {
         tickCallbackSet( myTickHook, (void*)LED );
         LED++;
         LED = LEDR + LED % 5;
         delay(LED_TOGGLE_MS);
      }

#endif // TP1_4_d

#ifdef TP1_5

   tickConfig( TICKRATE_MS );

   tickCallbackSet( myTickHook, (void*)LEDR );
   delay(1000);

   /* The DEBUG* functions are sAPI debug print functions.
    Code that uses the DEBUG* functions will have their I/O routed to
    the sAPI DEBUG UART. */
   DEBUG_PRINT_ENABLE;
   /* UART for debug messages. */
   debugPrintConfigUart( UART_USB, 115200 );
   debugPrintString( "DEBUG c/sAPI\r\n" );


   /* ------------- REPETIR POR SIEMPRE ------------- */
      while(1) {
         tickCallbackSet( myTickHook, (void*)LEDG );
         delay(LED_TOGGLE_MS);
         debugPrintString( "LED Toggle\n" );
         tickCallbackSet( myTickHook, (void*)LEDB );
         delay(LED_TOGGLE_MS);
         debugPrintString( "LED Toggle\n" );
         tickCallbackSet( myTickHook, (void*)LED1 );
         delay(LED_TOGGLE_MS);
         debugPrintString( "LED Toggle\n" );
         tickCallbackSet( myTickHook, (void*)LED2 );
         delay(LED_TOGGLE_MS);
         debugPrintString( "LED Toggle\n" );
         tickCallbackSet( myTickHook, (void*)LED3 );
         delay(LED_TOGGLE_MS);
         debugPrintString( "LED Toggle\n" );
         tickCallbackSet( myTickHook, (void*)LEDR );
         delay(LED_TOGGLE_MS);
         debugPrintString( "LED Toggle\n" );
      }

#endif // TP1_5

#ifdef TP1_6

      gpioConfig( GPIO0, GPIO_INPUT );
      gpioConfig( GPIO1, GPIO_OUTPUT );

      /* Variable para almacenar el valor de tecla leido */
      bool_t valor;

      tickConfig( TICKRATE_MS );

      /* The DEBUG* functions are sAPI debug print functions.
     Code that uses the DEBUG* functions will have their I/O routed to
     the sAPI DEBUG UART. */
      DEBUG_PRINT_ENABLE;
      /* UART for debug messages. */
      debugPrintConfigUart( UART_USB, 115200 );
      debugPrintString( "DEBUG c/sAPI\r\n" );

      int LED = LEDR;

      /* ------------- REPETIR POR SIEMPRE ------------- */
         while(1) {
        	 valor = !gpioRead( TEC1 );
        	 if(valor){
        		 for(LED = LEDR; LED <= LED3+1; LED++){
        			 tickCallbackSet( myTickHook, (void*)LED );
        			 debugPrintString( "LED Toggle because of TEC1\n" );
        			 delay(LED_TOGGLE_MS);
        		 }
        	 }
        	 valor = !gpioRead( TEC2 );
        	 if(valor){
        		 for(LED = LEDR; LED <= LED3+1; LED++){
        			 tickCallbackSet( myTickHook, (void*)LED );
        			 debugPrintString( "LED Toggle because of TEC2\n" );
        			 delay(LED_TOGGLE_MS);
        		 }
        	 }
        	 valor = !gpioRead( TEC3 );
        	 if(valor){
        		 for(LED = LEDR; LED <= LED3+1; LED++){
        			 tickCallbackSet( myTickHook, (void*)LED );
        			 debugPrintString( "LED Toggle because of TEC3\n" );
        			 delay(LED_TOGGLE_MS);
        		 }
        	 }
        	 valor = !gpioRead( TEC4 );
        	 if(valor){
        		 for(LED = LEDR; LED <= LED3+1; LED++){
        			 tickCallbackSet( myTickHook, (void*)LED );
        			 debugPrintString( "LED Toggle because of TEC4\n" );
        			 delay(LED_TOGGLE_MS);
        		 }
        	 }
        	 valor = !gpioRead( GPIO0 );
        	 if(valor){
        		 for(LED = LEDR; LED <= LED3+1; LED++){
        			 tickCallbackSet( myTickHook, (void*)LED );
        			 debugPrintString( "LED Toggle because of GPIO0\n" );
        			 delay(LED_TOGGLE_MS);
        		 }
        	 }
         }


#endif // TP1_6


   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
   return 0 ;
}

/*==================[end of file]============================================*/
