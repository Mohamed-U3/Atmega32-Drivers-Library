/*
 * SPI_interface.h
 *
 *  Created on: Mar 13, 2024
 *      Author: Adel
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidMastrInit();
void SPI_voidSlaveInit();
u8 SPI_u8Transcieve(u8 copy_u8Data);

#endif /* SPI_INTERFACE_H_ */
