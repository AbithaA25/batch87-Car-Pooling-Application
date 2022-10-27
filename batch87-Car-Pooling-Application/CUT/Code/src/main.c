 /********************************************
 * *FILENAME	      : main.c
 *
 * *DESCRIPTION        : This file defines the functions that consists of various subfunctions 
 * 			to perform certain operations. 
 *
 * Revision History   :	       
 *
 * 	Date			Name			Reason
 *
 * 25th Oct 2022		----			-----
 *
 *
*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../header/structure.h"



/********************************************************
 * *FUNCTION NAME : main 
 *
 * *DESCRIPTION   : This function calls the other functions to performs various 
 * 		    operations by taking choice option from the user. 
 *
 * *RETURNS       : transporter_data function
 *		    commuter_data function
 *                  admin function
 *                  exit - exit the main function
 *
********************************************************/
int transporter_data();

extern int searching_for_cab();

extern st *start ;
extern sc *start1;
extern st *new;
extern sc *new1;

int main()
{
	int choice=0;
	transporter_to_list();
	commuter_to_list();
	while(choice!=4)
	{
		system("clear");
		printf("-------CAR POOLING APPLICATION---------\n");
		printf("1.Transporter\n2.Commuter\n3.Admin\n4.Exit\n");
		printf("Enter Your Choice: \n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: transporter_data();
				break;
			case 2: commuter_data();
				break;
				
			case 3: admin();
			       break;
			case 4:
			       break;
			default: printf("Invalid Choice!\n");
		}
		
	}
	list_to_transporter();
	list_to_commuter();
	return EXIT_SUCCESS;
}
/********************************************************
 * *FUNCTION NAME : transporter_data
 *
 * *DESCRIPTION   : This function is used to performs register and log in operations of transporter
 *                  by taking choice option from the user.
 *
 * *RETURNS       : register_transporter - adding transporter data
 * 		    login_transporter   - logging in using transporter data
 *
 *
********************************************************/
int transporter_data()
{
	int choice1 = 0;
        system("clear");
	while(choice1!=3)
	{
		printf("1.Register your details\n2.Login into account \n3.Back to the main Menu\n");
		scanf("%d",&choice1);
		switch(choice1)
		{
			case 1: register_transporter();
				break;
			case 2: login_transporter();
				break; 
			case 3: 
				break;
			default: printf("Invalid Choice!\n\n");
		}
		system("read a");
		system("clear");
	}
	return 1; //CHANGES
}

/********************************************************
 * *FUNCTION NAME : commuter_data
 *
 * *DESCRIPTION   : This function is used to performs register and log in operations of commuter
 *                  by taking choice option from the user.
 *
 * *RETURNS       : register_commuter - adding commuter data
 * 		    login_commuter  - logging in using commuter data
 *
 *
********************************************************/

int commuter_data()
{
	int choice1 = 0;
	system("clear");
	while(choice1!=3)
	{
		printf("1.Register your details\n2.Login into acount \n3.Back to the main Menu\n");
		scanf("%d",&choice1);
		switch(choice1)
		{
			case 1: register_commuter();
				break;
			case 2:login_commuter();
				break;
			case 3: 
				break;
			default: printf("Invalid Choice!\n\n");
			
		}
		system("read a");
		system("clear");
	}
	return 1;//changes
}
/********************************************************
 * *FUNCTION NAME : admin
 *
 * *DESCRIPTION   : This function is used to performs various operations of transporter and commuter,
 * 		    routes report and busiest route report by taking choice option from the user.
 *
 * *RETURNS       : maintain_transporter  - contains functions to perform various operations of transporter
 * 		    maintain_commuter - contains functions to perform various operations of commuter 
 *                  show_routes  - shows routes report
 *                  busy_route  - shows busiest route report
 *
 *
********************************************************/

int admin()
{

	int choice1 = 0;
        system("clear");
	while(choice1!=5)
	{
	printf("\n1.Maintain Transporter data\n2.Maintain Commuter data\n3.All Trasporter Details \n4.To know the Busy route \n5.Back to the main-menu\n");
		scanf("%d",&choice1);
		switch(choice1)
		{
			case 1: maintain_transporter();
				break;
			case 2: maintain_commuter();
				break;
			case 3: show_routes();
				break;
			case 4: busy_route();
				break;
			case 5: 
				break;
			default: printf("Invalid Choice!\n\n");
			
		}
		system("read a");
		system("clear");
	}
	return 1;
}


/********************************************************
 * *FUNCTION NAME : maintain_transporter
 *
 * *DESCRIPTION   : This function is used to performs various operations of transporter
 * 		    database by taking choice option from the user.
 *
 * *RETURNS       : register_transporter  - adding transporter data
 * 		    modify_details_T   - editing transporter data
 * 		    delete_tra_details - deleting transporter data
 *		    view_tra_details - view transporter data
 *
 *
********************************************************/
int maintain_transporter()
{
	int ch = 0;
	system("clear");
	while(ch!=5)
	{
		printf("\n....TRANSPORTER DATA ENTRY....\n");
		printf("1.Add Transporter Data\n2.Edit Transporter Data\n3.Delete Transporter Data\n4.View Transporter Data\n5.Admin menu");
		printf("\nEnter choice-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:register_transporter();
			       break;
			case 2:modify_details_T();
			       break;
			case 3:delete_tra_details();
			       break;
			case 4:view_tra_details();
			       break;
			case 5:
			       break;
			default:printf("\ninvalid choice\n");
			
		}
		system("read a");
		system("clear");
	}
	return 1;
}

/********************************************************
 * *FUNCTION NAME : maintain_commuter
 *
 * *DESCRIPTION   : This function is used to performs various operations of commuter
 * 		    database by taking choice option from the user.
 *
 * *RETURNS       : register_commuter  - adding commuter data
 * 		    modify_details_C   - editing commuter data
 * 		    delete_com_details - deleting commuter data
 *		    view_com_details - view commuter data
 *
 *
********************************************************/
int maintain_commuter()
{
	int ch = 0;
	system("clear");
	while(ch!=5)
	{
		printf("\n....COMMUTER DATA ENTRY....\n");
		printf("1.Add Commuter Data\n2.Edit Commuter Data\n3.Delete Commuter Data\n4.View Commuter Data\n5.Admin menu");
		printf("\nEnter choice-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:register_commuter();
			       break;
			case 2:modify_details_C();
			       break;
			case 3:delete_com_details();
			       break;
			case 4:view_com_details();
			       break;
			case 5:
			       break;
			default:printf("\ninvalid choice\n");
		}
		system("read a");
		system("clear");
	}
	return 1;
}



