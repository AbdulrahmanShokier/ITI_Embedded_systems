#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

void MUART_voidUartInit (void) ;

void MUART_voidUartSend(u8 A_u8Data) ;

u8 MUART_u8UartRecieve(void) ;

void MUART_voidUartSendString(u8* A_pu8Str) ;

#endif /* MCAL_UART_UART_INT_H_ */
