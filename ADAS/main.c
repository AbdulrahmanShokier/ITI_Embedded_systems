/*
 * main.c
 *
 *  Created on: Aug 22, 2024
 *      Author: DELL
 */
#include "app.h"

int main()
{
	MUART_voidUartInit();
	//test();
	E2PROMStorePass();
	CheckPass();
	while(1);
	return 0;
}



