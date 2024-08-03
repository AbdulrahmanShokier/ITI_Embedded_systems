#include<stdio.h>
#include<string.h>
#include"Std_Types.h"
#include"Interface_definition.h"
#include"Counfig.h"






int main(void)
{
	u8 L_u8_Choosen_option;
	u8 L_u8_Entered_Password;
	u8 L_u8_Password_Tracker=0;

	printf("************welcome************\n\n\n");
	printf("You are in the main window\n\n");
	printf("Choose the option you want\n");
	printf("1- Enter admin mode\n");
	printf("2- Enter user mode\n");
	printf("3- Exit\n");

	scanf("%d",&L_u8_Choosen_option);
	fflush(stdin);

	if (First_Choice == L_u8_Choosen_option)
	{
		while(L_u8_Password_Tracker<3)
		{
		printf("Please Enter the password\n");

		scanf("%d",&L_u8_Entered_Password);
		fflush(stdin);;

		if(L_u8_Entered_Password == DefaultPassword )
		{
			void_Admin_Mode();
			main();
		}
		else
		{
			printf("The password is wrong!\n");
			printf("Try again\n");
			++L_u8_Password_Tracker;
		}
		}
	}
	else if (Second_Choice == L_u8_Choosen_option)
	{
		;
	}
	else if (Third_Choice == L_u8_Choosen_option)
	{
		return 0;
	}
	else
	{
		printf("wrong Selection!\n");
		void_Admin_Mode();
	}






	return 0;
}
