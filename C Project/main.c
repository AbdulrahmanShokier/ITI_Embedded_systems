#include<stdio.h>
#include<string.h>
#include"Std_Types.h"
#include"Interface_definition.h"
#include"Counfig.h"


Slots R_struct_Slots[AvailableSlots]=
{
	{"2:30to3:00",Available,0},
	{"3:00to3:30",Available,0},
	{"3:30to4:00",Available,0},
	{"4:00to4:30",Available,0},
	{"4:30to5:00",Available,0}

};



int main(void)
{
	u8 L_u8_Choosen_option;
	s32 L_s32_Entered_Password;
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
		while(L_u8_Password_Tracker<NumberOfPasswordTries)
		{
		printf("Please Enter the password\n");

		scanf("%d",&L_s32_Entered_Password);
		fflush(stdin);;
		printf("%d\n",L_s32_Entered_Password);
		if(L_s32_Entered_Password == DefaultPassword )
		{
			void_Admin_Mode();
			//main();
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
		void_User_Mode();
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
