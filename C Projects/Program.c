/*
 * Program.c

 *
 *  Created on: Aug 1, 2024
 *      Author: abdo4
 */

#include<stdio.h>
#include<string.h>
#include"Std_Types.h"
#include"Interface_definition.h"
#include"Counfig.h"

u8 u8_ArrayIndex = 0;
s32 L_u8_Entered_ID;
u8 L_u8_Entered_Age;
u8 L_u8_Entered_Gender;
s8 R_s8_Entered_Name[MaxNameSize];
s32 L_s32_iteration ;
u8 L_u8_Choosen_option;
Patient* PointerToPatientsData=R_struct_Patients;

Slots* PointerToSlots=R_struct_Slots;

void void_Admin_Mode(void)
{
	printf("*******************************\n");
	printf("Welcome to Admin Mode\n\n");
	printf("Choose the option you want\n");
	printf("1- Add New patient\n");
	printf("2- Edit existing patient\n");
	printf("3- Reserve A slot \n");
	printf("4- Cancel A Reservation\n");
	printf("5- Exit Admin mode\n");

	scanf("%d",&L_u8_Choosen_option);
	fflush(stdin);

	if (First_Choice == L_u8_Choosen_option)
	{
		AdmOpt1_void_Add_new_Patient(PointerToPatientsData);
	}
	else if (Second_Choice == L_u8_Choosen_option)
	{
		AdmOpt2_void_Edit_Existing_Patient(PointerToPatientsData);
	}
	else if (Third_Choice == L_u8_Choosen_option)
	{
		AdmOpt3_void_Reserve_A_Slot(PointerToSlots,PointerToPatientsData);
	}
	else if (Fourth_Choice == L_u8_Choosen_option)
	{
		AdmOpt4_void_Cancel_Reservation(PointerToSlots,PointerToPatientsData);
	}
	else if (Fifth_Choice == L_u8_Choosen_option)
	{
		main();
	}
	else
	{
		printf("wrong Selection!\n");
		void_Admin_Mode();
	}
}

void AdmOpt1_void_Add_new_Patient(Patient* PointerToPatientsData)
{

	if(u8_ArrayIndex>=NumberOfPatients)
	{
		printf("Sorry you can Snot enter a new patient");
	}
	else
	{
		printf("You chose to add a new patient!\n\n");
		printf("Enter the patient ID  \'Remember it must be unique\'\n");
		scanf("%d",&L_u8_Entered_ID);
		fflush(stdin);

		for (L_s32_iteration = IterationStart; L_s32_iteration < NumberOfPatients ; L_s32_iteration++)
		{
			if(L_u8_Entered_ID == PointerToPatientsData[L_s32_iteration].L_u8_ID)
			{
				printf("This Id is already taken by a Patient\n");
				printf("Try again\n");
				AdmOpt1_void_Add_new_Patient(PointerToPatientsData);
			}
			else
			{

			}
		}

		printf("This Id is available\n");
		printf("Please continue\n");
		printf("Enter the patient Name\n");
		scanf("%19s",&R_s8_Entered_Name);
		fflush(stdin);
		printf("Enter the patient Age\n");
		scanf("%d",&L_u8_Entered_Age);
		fflush(stdin);
		printf("Enter the patient Gender\n");
		scanf("%c",&L_u8_Entered_Gender);
		fflush(stdin);
		PointerToPatientsData[u8_ArrayIndex].L_u8_ID=L_u8_Entered_ID;
		PointerToPatientsData[u8_ArrayIndex].L_u8_Age=L_u8_Entered_Age;
		PointerToPatientsData[u8_ArrayIndex].L_u8_Gender=L_u8_Entered_Gender;
		strcpy(PointerToPatientsData[u8_ArrayIndex].R_s8_Name,R_s8_Entered_Name);
		u8_ArrayIndex++ ;
		printf("you successfully added a new patient!\n\n");
		printf("*******************************\n");
		void_Admin_Mode();

	}




}

void AdmOpt2_void_Edit_Existing_Patient(Patient *PointerToPatientsData)
{
	printf("*******************************\n");
	printf("You chose to edit an existing patient data!\n\n");
	printf("Enter the patient ID '\n");
	scanf("%d",&L_u8_Entered_ID);
	fflush(stdin);

	for (L_s32_iteration = IterationStart; L_s32_iteration < NumberOfPatients ; L_s32_iteration++)
	{
		if(L_u8_Entered_ID == PointerToPatientsData[L_s32_iteration].L_u8_ID)
		{
			printf("This Id is existing!\n");
			break;
		}
		else
		{
			printf("This Id does not exist!\n");
			printf("Try adding it first\n");
			void_Admin_Mode();
		}
	}
	printf("You can edit this patient data\n");
	printf("Choose the data you want to change\n");
	printf("1- The ID\n");
	printf("2- The age\n");
	printf("3- The gender\n");
	printf("4- The name\n");

	scanf("%d",&L_u8_Choosen_option);
	fflush(stdin);

	if (First_Choice == L_u8_Choosen_option)
	{
		printf("Enter the new ID\n");
		scanf("%d",&L_u8_Entered_ID);
		fflush(stdin);

		PointerToPatientsData[L_s32_iteration].L_u8_ID=L_u8_Entered_ID;


	}
	else if (Second_Choice == L_u8_Choosen_option)
	{
		printf("Enter the new age\n");
		scanf("%d",&L_u8_Entered_Age);
		fflush(stdin);

		PointerToPatientsData[L_s32_iteration].L_u8_Age=L_u8_Entered_Age;

	}
	else if (Third_Choice == L_u8_Choosen_option)
	{
		printf("Enter the new gender\n");
		scanf("%c",&L_u8_Entered_Gender);
		fflush(stdin);

		PointerToPatientsData[L_s32_iteration].L_u8_Gender=L_u8_Entered_Gender;

	}
	else if (Fourth_Choice == L_u8_Choosen_option)
	{
		printf("Enter the new Name\n");
		scanf("%19s",&R_s8_Entered_Name);
		fflush(stdin);

		strcpy(PointerToPatientsData[L_s32_iteration].R_s8_Name,R_s8_Entered_Name);

	}

	else
	{
		printf("wrong Selection");
		AdmOpt2_void_Edit_Existing_Patient(PointerToPatientsData);
	}
	printf("Do You want to change another data?\n\n");
	printf("1- Yes\n");
	printf("2- No\n");

	scanf("%d",&L_u8_Choosen_option);
	fflush(stdin);

	if (First_Choice == L_u8_Choosen_option)
	{
		AdmOpt2_void_Edit_Existing_Patient(PointerToPatientsData);
	}
	else if (Second_Choice == L_u8_Choosen_option)
	{
		void_Admin_Mode();
	}
	else
	{
		printf("Wrong selection\n");
		void_Admin_Mode();
	}


}

void AdmOpt3_void_Reserve_A_Slot(Slots*PointerToSlots,Patient *PointerToPatientsData)
{
	printf("*******************************\n\n");
	printf("You chose to Reserve a slot!\n\n");
	printf("Enter the patient ID '\n");
	scanf("%d",&L_u8_Entered_ID);
	fflush(stdin);

	for (L_s32_iteration = IterationStart; L_s32_iteration < NumberOfPatients ; L_s32_iteration++)
	{
		if(L_u8_Entered_ID == PointerToPatientsData[L_s32_iteration].L_u8_ID)
		{
			printf("This Id is existing!\n");
			break;
		}
		else
		{
			printf("This Id does not exist!\n");
			printf("Try adding it first\n");
			void_Admin_Mode();
		}
	}
	for(L_s32_iteration = IterationStart ; L_s32_iteration < AvailableSlots ; L_s32_iteration++)
	{
		if (PointerToSlots[L_s32_iteration].L_u8_avaliability_Of_Slot == Available)
		{
			printf("%d- %19s\n",L_s32_iteration+1,PointerToSlots[L_s32_iteration].R_s8_time);
		}
		else
		{

		}

	}
	printf("Choose the time that suits you\n");
	scanf("%d",&L_u8_Choosen_option);
	fflush(stdin);
	if (First_Choice == L_u8_Choosen_option)
	{
		PointerToSlots[First_Choice-1].L_u8_avaliability_Of_Slot = Not_Available;
		PointerToSlots[First_Choice-1].L_u8_Patient_ID = L_u8_Entered_ID;
	}
	else if (Second_Choice == L_u8_Choosen_option)
	{
		PointerToSlots[Second_Choice-1].L_u8_avaliability_Of_Slot = Not_Available;
		PointerToSlots[Second_Choice-1].L_u8_Patient_ID = L_u8_Entered_ID;
	}
	else if (Third_Choice == L_u8_Choosen_option)
	{
		PointerToSlots[Third_Choice-1].L_u8_avaliability_Of_Slot = Not_Available;
		PointerToSlots[Third_Choice-1].L_u8_Patient_ID = L_u8_Entered_ID;
	}
	else if (Fourth_Choice == L_u8_Choosen_option)
	{
		PointerToSlots[Fourth_Choice-1].L_u8_avaliability_Of_Slot = Not_Available;
		PointerToSlots[Fourth_Choice-1].L_u8_Patient_ID = L_u8_Entered_ID;
	}
	else if (Fifth_Choice == L_u8_Choosen_option)
	{
		PointerToSlots[Fifth_Choice-1].L_u8_avaliability_Of_Slot = Not_Available;
		PointerToSlots[Fifth_Choice-1].L_u8_Patient_ID = L_u8_Entered_ID;
	}
	else
	{
		printf("wrong Selection!\n");
		AdmOpt3_void_Reserve_A_Slot(PointerToSlots,PointerToPatientsData);
	}
	printf("You reserved a slot successfully!\n\n ");
	void_Admin_Mode();




}

void AdmOpt4_void_Cancel_Reservation(Slots *PointerToSlots,Patient *PointerToPatientsData)
{
	printf("You chose to cancel a slot!\n\n");
	printf("Enter the patient ID '\n");
	scanf("%d",&L_u8_Entered_ID);
	fflush(stdin);

	for (L_s32_iteration = IterationStart; L_s32_iteration < NumberOfPatients ; L_s32_iteration++)
	{
		if(L_u8_Entered_ID == PointerToPatientsData[L_s32_iteration].L_u8_ID)
		{
			printf("This Id is existing!\n");
			break;
		}
		else
		{
			printf("This Id does not exist!\n");
			printf("Try adding it first\n");
			void_Admin_Mode();
		}
	}

	for(L_s32_iteration = IterationStart ; L_s32_iteration < AvailableSlots ; L_s32_iteration++)
	{
		if (PointerToSlots[L_s32_iteration].L_u8_Patient_ID == L_u8_Entered_ID)
		{
			PointerToSlots[L_s32_iteration].L_u8_avaliability_Of_Slot = Available;
			PointerToSlots[L_s32_iteration].L_u8_Patient_ID = 0;
			printf("The reservation has been canceled successfully\n");
			break;
		}
		else
		{

		}

	}
	if(L_s32_iteration == AvailableSlots)
	{
		printf("This ID does not have a reservation\n");
	}
	void_Admin_Mode();
}




void void_User_Mode(void)
{
	printf("*******************************\n");
	printf("Welcome to user Mode\n\n");
	printf("Choose the option you want\n");
	printf("1- View patient Record\n");
	printf("2- View today reservations\n");
	printf("3- Exit user mode\n");

	scanf("%d",&L_u8_Choosen_option);
	fflush(stdin);

	if (First_Choice == L_u8_Choosen_option)
	{
		UsrOp1_void_View_Record(PointerToPatientsData);
	}
	else if (Second_Choice == L_u8_Choosen_option)
	{
		UsrOp2_void_View_Reserv(PointerToSlots,PointerToPatientsData);
	}
	else if (Third_Choice == L_u8_Choosen_option)
	{
		main();
	}
	else
	{
		printf("wrong Selection!\n");
		void_User_Mode();
	}
}

void UsrOp1_void_View_Record(Patient* PointerToPatientsData)
{
	printf("Enter the patient ID you want to view his data \n");
	scanf("%d",&L_u8_Choosen_option);
	fflush(stdin);

	for (L_s32_iteration = IterationStart; L_s32_iteration < NumberOfPatients ; L_s32_iteration++)
	{
		if(L_u8_Entered_ID == PointerToPatientsData[L_s32_iteration].L_u8_ID)
		{
			printf("This Id is correct \n");
			printf("The Id is %d \n",PointerToPatientsData[L_s32_iteration].L_u8_ID);
			printf("The Age is %d \n",PointerToPatientsData[L_s32_iteration].L_u8_Age);
			printf("The Gender is %c \n",PointerToPatientsData[L_s32_iteration].L_u8_Gender);
			printf("The Name is %s \n",PointerToPatientsData[L_s32_iteration].R_s8_Name);
			break;
		}
		else
		{
			printf("This Id isn't available");
			printf("Try again");
			UsrOp1_void_View_Record(PointerToPatientsData);
		}
	}

}

void UsrOp2_void_View_Reserv(Slots*PointerToSlots,Patient *PointerToPatientsData)
{
	for(L_s32_iteration = IterationStart ; L_s32_iteration < AvailableSlots ; L_s32_iteration++)
		{
			if (PointerToSlots[L_s32_iteration].L_u8_avaliability_Of_Slot == Not_Available)
			{
				printf("%d- %19s and the id is %d\n",L_s32_iteration+1,PointerToSlots[L_s32_iteration].R_s8_time,PointerToSlots[L_s32_iteration].L_u8_Patient_ID);
			}
			else
			{

			}

		}
	void_User_Mode();
}





