/*
 * SPI_program.c
 *
 *  Created on: Mar 13, 2024
 *      Author: Adel
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SPI_register.h"
#include "SPI_interface.h"


void SPI_voidMastrInit()
{

  SET_BIT(SPCR,SPCR_MSTR);

  SET_BIT(SPCR,SPCR_SPR0);
  CLR_BIT(SPCR,SPCR_SPR1);
  CLR_BIT(SPSR,SPSR_SPI2X);


  SET_BIT(SPCR,SPCR_SPE);

}
void SPI_voidSlaveInit()
{
  SET_BIT(SPCR,SPCR_SPE);
  CLR_BIT(SPCR,SPCR_MSTR);

}
u8 SPI_u8Transcieve(u8 copy_u8Data)
{
	SPDR=copy_u8Data;

	while(GET_BIT(SPSR,SPSR_SPIF)==0);

	return SPDR;
}
