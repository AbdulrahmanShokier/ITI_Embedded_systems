/*
 * DIO_Interface.h
 *
 *  Created on: Aug 2, 2024
 *      Author: DELL
 */

#ifndef MCAL_MDIO_DIO_INTERFACE_H_
#define MCAL_MDIO_DIO_INTERFACE_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define PIN_OUTPUT 1
#define PIN_INPUT 0

#define PORT_OUTPUT 0XFF
#define PORT_INPUT 0X0
#define HIGH 1
#define LOW 0

#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3
#define PINB4 4
#define PINB5 5
#define PINB6 6
#define PINB7 7

#define PINC0 0
#define PINC1 1
#define PINC2 2
#define PINC3 3
#define PINC4 4
#define PINC5 5
#define PINC6 6
#define PINC7 7

#define PIND0 0
#define PIND1 1
#define PIND2 2
#define PIND3 3
#define PIND4 4
#define PIND5 5
#define PIND6 6
#define PIND7 7

#define PINA0 0
#define PINA1 1
#define PINA2 2
#define PINA3 3
#define PINA4 4
#define PINA5 5
#define PINA6 6
#define PINA7 7


void MDIO_void_SetDir(u8 A_u8_PortNum,u8 A_u8_PinNum,u8 A_u8_PinDir);
void MDIO_void_PinWrite(u8 A_u8_PortNum,u8 A_u8_PinNum,u8 A_u8_PinValue);
u8 MDIO_u8_PinRead(u8 A_u8_PortNum,u8 A_u8_PinNum);
void MDIO_void_PinToggle(u8 A_u8_PortNum,u8 A_u8_PinNum);
void MDIO_void_PortSetDir(u8 A_u8_PortNum,u8 A_u8_PortDir);
void MDIO_void_PortWrite(u8 A_u8_PortNum,u8 A_u8_PortValue);
u8 MDIO_u8_PortRead(u8 A_u8_PortNum);
void MDIO_void_PortWriteHigh(u8 A_u8_PortNum,u8 A_u8_PortValue);



#endif /* MCAL_MDIO_DIO_INTERFACE_H_ */
