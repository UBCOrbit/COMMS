#include "tx_rx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include <string.h>

#define HIGH 1
#define LOW 0

char len = 1;
char temp_RxBuffer;
char hspi2;




//+++++++ Function Definitions +++++++++++++++++++++
//==================================================


//==================================================

//==================================================

void chipStart(void){
																		//Serial.print("Chip reset: ");
	//writes LOW to chip select pin
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);//digitalWrite(CS,LOW);
	//waits for MISO to go LOW
	while( (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2)) == HIGH);
	//writes HIGH to chip select pin
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_12, GPIO_PIN_SET);//digitalWrite(CS,HIGH);

	//resets the chip (sends it to reset state)
	HAL_SPI_TransmitReceive (&hspi2, SRES, &temp_RxBuffer, sizeof(SRES), 5000);//sendSPI(SRES,0);
	//writes LOW to chip select pin
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);//digitalWrite(CS,LOW);
	//waits for MISO to go LOW
	while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2));
	//writes HIGH to chip select pin
	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);//digitalWrite(CS,HIGH);

															//  Serial.print("PASSED \n");
/*force idle*/
	//puts the transceiver in IDLE mode
	HAL_SPI_TransmitReceive (&hspi2, SIDLE, &temp_RxBuffer, sizeof(SRES), 5000);//sendSPI(SIDLE,0);
	//go to NO OPERATION & stay stay there until calibration is finished (??)
	do HAL_SPI_TransmitReceive (&hspi2, SNOP, &temp_RxBuffer, sizeof(SRES), 5000);//sendSPI(SNOP,0);
	while((bytei&0b111000)==MCAL);


/*register setup*/
	//sends the addresses and data of all the registers to the transceiver(??)
	for(unsigned short i = 0 ; i < /*# of registers*/(sizeof(standardRegisters)/sizeof(registerSetting_t)) ; i++)
		HAL_SPI_TransmitReceive (&hspi2, standardRegisters[i].addr, &temp_RxBuffer, sizeof(char), 5000);//sendSPI(standardRegisters[i].addr, standardRegisters[i].data);

	//does the same for the extended registers
	for(short i = 0;i < (sizeof(extendedRegisters)/sizeof(registerSetting_t)); i++)
		HAL_SPI_TransmitReceive (&hspi2, standardRegisters[i].addr, &temp_RxBuffer, sizeof(char), 5000);//sendSPIEX(extendedRegisters[i].addr, extendedRegisters[i].data,0);


/*register write check*/
												//Serial.print("Register write test 0b00110001\n");
	//send pre-amble configuration to transceiver to be printed later
	HAL_SPI_TransmitReceive (&hspi2, 0b10000000+PREAMBLE_CFG0, 0, sizeof(registerSetting_t), 5000);//sendSPI(0b10000000+PREAMBLE_CFG0,0);
	//following: print statements for checking values in registers
/*
//  Serial.print("Register value: ");
//  Serial.print(datai,BIN);
//  Serial.print("\n");
*/

/*extended register write check*/
												//  Serial.print("Extended register write test CC3C3C\n");
  HAL_SPI_TransmitReceive (&hspi2, FREQ2, 0, 1, 5000);
  //  sendSPIEX(FREQ2,0,1);

  	  	  	  	  	  	  	  	  	  	  	  	//  Serial.print("Register value: ");
  	  	  	  	  	  	  	  	  	  	  	  	//  Serial.print(datai,HEX);
  HAL_SPI_TransmitReceive (&hspi2, FREQ1, 0, 1, 5000);
  //sendSPIEX(FREQ1,0,1);

  	  	  	  	  	  	  	  	  	  	  	  	  //  Serial.print(datai,HEX);

  HAL_SPI_TransmitReceive (&hspi2, FREQ0, 0, 1, 5000);
  //sendSPIEX(FREQ0,0,1);

  	  	  	  	  	  	  	  	  	  	  	  	  //  Serial.print(datai,HEX);
  	  	  	  	  	  	  	  	  	  	  	  	  //  Serial.print("\n");


	//stay in NO OPERATION until calibration is finished (??)
	do HAL_SPI_TransmitReceive (&hspi2, SNOP, &temp_RxBuffer, sizeof(SRES), 5000);//sendSPI(SNOP,0);
	while((bytei&0b111000)==MCAL);

	return;
}


//==================================================




//==================================================




//==================================================


