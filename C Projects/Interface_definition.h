/*
 * Interface_definition.h
 *
 *  Created on: Aug 1, 2024
 *      Author: abdo4
 */
#include"Std_Types.h"
#include"Counfig.h"

#ifndef INTERFACE_DEFINITION_H_
#define INTERFACE_DEFINITION_H_

#define IterationStart 0

#define Not_reserved 0

#define Available 0

#define Not_Available 1
/*****Switch Cases*****/

#define First_Choice  1
#define Second_Choice 2
#define Third_Choice  3
#define Fourth_Choice 4
#define Fifth_Choice  5
/************************************/

#define First_slot   1
#define Second_slot  2
#define Third_slot   3
#define Fourth_slot  4
#define Fifth_slot   5


/************************************/


typedef struct
{
	s8 R_s8_Name[MaxNameSize];
	u8 L_u8_Age;
	u8 L_u8_Gender;
	u8 L_u8_ID;

}Patient;

Patient R_struct_Patients[NumberOfPatients];

typedef struct
{
	s8 R_s8_time[MaxNameSize];
	u8 L_u8_avaliability_Of_Slot;
	u8 L_u8_Patient_ID;

}Slots;



Slots R_struct_Slots[AvailableSlots]=
{
		{"2:30to3:00",Available,0},
		{"3:00to3:30",Available,0},
		{"3:30to4:00",Available,0},
		{"4:00to4:30",Available,0},
		{"4:30to5:00",Available,0}

};


/*****************Admin*******************/

void void_Admin_Mode(void);
void AdmOpt1_void_Add_new_Patient(Patient* PointerToPatientsData);
void AdmOpt2_void_Edit_Existing_Patient(Patient* PointerToPatientsData);
void AdmOpt3_void_Reserve_A_Slot(Slots* PointerToSlots,Patient *PointerToPatientsData);
void AdmOpt4_void_Cancel_Reservation(Slots* PointerToSlots,Patient *PointerToPatientsData);


/******************User*********************/

void void_User_Mode(void);
void UsrOp1_void_View_Record(Patient* PointerToPatientsData);
void UsrOp2_void_View_Reserv(Slots*PointerToSlots,Patient *PointerToPatientsData);

/*******************************************/
//u8 exit_u8(void);
int main(void);
/*******************************************/


#endif /* INTERFACE_DEFINITION_H_ */
