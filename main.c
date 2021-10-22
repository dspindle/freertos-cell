/* Includes		       */
#include <stdint.h>
#include "sysregs.h"
#include "gic-v2.h"
#include "string.h"
#include "serial.h"
#include "printf-stdarg.h"

/* Scheduler include files.   */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
/*____________________________*/

/* Defines  		      */

/*____________________________*/

/* Interrupt Handling	      */

/*____________________________*/


/* FreeRTOS application tasks */

void uartTask(){
 while(1){
  mini_uart_putchar('a');
  vTaskDelay(500 / portTICK_PERIOD_MS); 
 } 
}
/*____________________________*/

/* Hardware init */
static void uart_enable(void){
 mini_uart_open();
}
/*___________________________ */
/*  main */
void inmate_main(void)
{
 uart_enable();
 xTaskCreate(
	uartTask,
	"UART print",
	configMINIMAL_STACK_SIZE,
	NULL,
	1,
	NULL);




 printf("vTaskStartScheduler goes active\n");
 vTaskStartScheduler();



}
