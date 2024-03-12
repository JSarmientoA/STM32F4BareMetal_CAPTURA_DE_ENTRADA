#include <stdint.h>
#include <stdio.h> // Para poder usar printf()
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "timer.h"
/*Este programa conecta el canal 1 del tima 2 al pin 5 del purto e intercambia su valor
 * entre 1 y 0 (0v-3.3v). Por medio de un puente entre PA5 y PA6 capturan los eventos de caombio
 * asendente pormedio de PA6*/

int MarcaTiempo = 0;
/*Conectar PA5 a PA6 fisicamente en la targeta*/
int main(void){

	ConfitGPIOA5y6EnModoAlternativos();
	tim2_modo_comparacion();
	Tim3ModoCapturaEntrada();
	while(1){
		/*Valida la vandera CC1IF.*/
		while(!(TIM3->SR & CC1IF));
		/*Valida la vandera CC1IF. Cuando se detacta un flanco
		 * asendente se activa la bandera CC1IF*/

		/*Leer el valor capturado*/
		MarcaTiempo = TIM3->CCR1;
		/*Se lee el valor del regidtro CCR1*/

	}
}
