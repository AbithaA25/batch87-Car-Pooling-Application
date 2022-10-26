/*********************************************************
 * * FILENAME    : show_reports.c
 *
 * * DESCRIPTION : This file defines the function that would be used by the program to 
 * 		   generate various reports about the Vehicles and Buiest route details using the database.
 *
 *
 * Revision History:
 * 
 *	 Date 				NAME 					Reason
 *
 * 25th Oct 2022        	       ---              		         ---
 *
 *    
 ********************************************************/


#include <stdio.h>
#include <string.h>

#include "structure.h"

extern st *start ;

st *ptrh;

/********************************************************
 *FUNCTION NAME  : show_routes
 *
 *DESCRIPTION    : This function displays the
                   details of the Vehicles present inside the database.
 *
 *
 *RETURNS        :  No returns
 *
 *
 *******************************************************/

int show_routes()
{
	
	for(ptrh=start;(ptrh);ptrh=ptrh->next)
	{
		printf("******************************************\n");
		printf("NAME : %s\n",ptrh->t_name);
		printf("VEHICLE : %s \n",ptrh->type_of_v);
		printf("SOURCE : %s \n",ptrh->source);
		printf("DESTINATION : %s\n",ptrh->dest);	
		printf("******************************************\n");
	}
	printf("\n");
	
}


/********************************************************
 *FUNCTION NAME  : busy_route
 *
 *DESCRIPTION    : This function displays the busiest route based on the commuters registered.
 *
 *
 *RETURNS        :  No returns
 *
 *
 *******************************************************/

int busy_route()
{

	int big = 0 ;
	
	char st = '\0', end = '\0';
	
	
	for(ptrh=start;(ptrh);ptrh=ptrh->next)
	{
	

		if(big < ptrh->max)
		{
				big = ptrh->max ;
				st = ptrh->source[0];
				end=ptrh->dest[0];

		}
	}
	
	
		printf("******************************************\n");
		printf("\n");
	printf("BUSIEST ROUTE IS %c to %c in terms of No. of commuters registered for the route\n",st,end);
	  printf("\n");
		printf("******************************************\n");

}

