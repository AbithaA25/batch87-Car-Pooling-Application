/********************************************
 * *FILENAME	      : validations.c
 *
 * *DESCRITION        : This file defines the function that would be used by the program to 
 * 			validate various input feilds when the user enters the data. 
 * 	    
 *
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
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "structure.h"

/******************************************************
 * *FUNCTION NAME : integer_validation
 *
 * *DESCRIPTION   : This function perform validation operations of integer when user enters the data
 * 		    and displays the respective message.
 *		  
 * *RETURNS       : No return
 *
********************************************************/
int integer_validation(char *str)
{
	long int num ;

	int len =0 , count = 0;

	if(strlen(str) > 6)
	{
		num = atol(str);
	}
	else
	{
	        num = atoi(str);
	}
	len = strlen(str);

	if(num <= 0)
	{
		return 1;
	}
	else
	{
		do{

			num /= 10;
			++count;

		  }while(num != 0);

		  if(len == count)
		  	return 0;
		  else
		  	return 1;
        }
}

/******************************************************
 * *FUNCTION NAME : alpha_validation
 *
 * *DESCRIPTION   : This function perform validation operations of alphabets when user enters the data
 * 		    and displays the respective message.
 *		  
 * *RETURNS       : No return
 *
********************************************************/
int alpha_validator(char *s)
{

        //validation for alphabets
        for(char *p=s;*p!='\0';p++)
        {
                if((!isalpha(*p)) && (*p!=' '))
		{
			printf("Enter valid name !!\n");
                        return 0;
		}
        }
        //validation for length
        if(strlen(s)>15 || strlen(s) < 5)
        {
                printf("Enter name within the length of 5 to 15\n");
                return 0;
        }
        return 1;
}


/******************************************************
 * *FUNCTION NAME : gender_validation
 *
 * *DESCRIPTION   : This function perform validation operations of gender when user enters the data
 * 		    and displays the respective message.
 *		  
 * *RETURNS       : No return
 *
********************************************************/
int gender_validation(char *s)
{
        int flag = 0;
	if(strlen(s) == 1)
	{
        if(isalpha(s[0]))
        {
                char c = s[0];
                switch(c)
                {
                        case 'm':
                        case 'M':
                                flag = 1;
                                break;
                        case 'f':
                        case 'F':
                                flag = 1;
                                break;
                        default:
                                printf("Unspecified Gender.\n");
                }
                if(flag == 0)
                {
                        printf("Not M OR F\n");
                        return 0;
                }



        }
        if(!isalpha(s[0]))
        {
                printf("The input is not a character\n");
                return 0;
        }
	}
	else
	{
		printf("Enter either M or F\n");
		return 0;
	}
        return 1;
}

/******************************************************
 * *FUNCTION NAME : phone_validation
 *
 * *DESCRIPTION   : This function perform validation operations of phone number when user enters the data
 * 		    and displays the respective message.
 *		  
 * *RETURNS       : No return
 *
********************************************************/
int phone_validation(char *str)
{

	long int num ;

	int len =0 , count = 0;

	len = strlen(str);

	if(len == 10)
	{
		return 1;
	}
	else if(num <= 0 || len < 10 || len > 10)
	{
		return 0;
	}
	else
	{
		num = atoi(str);
		do {

			num /= 10;
			++count;

		  }while(num != 0);

		  if(len == count)
		  	return 1;
		  else
		  	return 0;
        }
}

/******************************************************
 * *FUNCTION NAME : point_validation
 *
 * *DESCRIPTION   : This function perform validation operations of source and destination points when user enters the data
 * 		    and displays the respective message.
 *		  
 * *RETURNS       : No return
 *
********************************************************/

int point_validation(char *s, char *t)
{
        char routes_arr[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
        int flag = 0, aflag =0;
	if(strlen(s) == 1)
	{
        if(isalpha(s[0]))
        {

        for(int i = 0; i < 6; i++)
        {
                if(s[0] == routes_arr[i])
                {
                      flag = 1;
                      break;
                }
        }
        if(flag == 0 )
        {
                        printf("The source is not from the valid points\n");
                        return 0;
        }

        if(t[0] != s[0])
        {
        for(int i = 0; i < 6; i++)
        {
                if(t[0] == routes_arr[i])
                {
                        aflag = 1;
                        break;
                }
        }

           if(aflag == 0)
           {
                        printf("Invalid destination route\n");
                        return 0;
            }
        }
        else
        {
                printf("The Destination cannot be the source\n");
                return 0;
        }
        }
        else
        {
                printf("Input is not a character\n");
                return 0;
        }
	}
	else
	{
		printf("Input must be A or B or C or D or E or F\n");
		return 0;
	}

        return 1;
}

/******************************************************
 * *FUNCTION NAME : distance_validation
 *
 * *DESCRIPTION   : This function perform validation operations of distance when user enters the data
 * 		    and displays the respective message.
 *		  
 * *RETURNS       : No return
 *
********************************************************/
int distance_validation(char *s, char *d, int e)
{
	int a;
	if(s[0] < d[0])
	{
		a = d[0] - s[0];
		if(e != a)
		{
			printf("Must be %d km\n",a);
			return 0;
		}
		else
			return 1;
	}
	else if(s[0] > d[0])
	{
		a = s[0] - d[0];
		if(e != a)
		{
			printf("Must be %d km\n",a);
			return 0;
		}
		else 
			return 1;
	}
	return 1;
}

/******************************************************
 * *FUNCTION NAME : car_type_validation
 *
 * *DESCRIPTION   : This function perform validation operations of type of vehicle when user enters the data
 * 		    and displays the respective message.
 *		  
 * *RETURNS       : No return
 *
********************************************************/
int car_type_validation(char *s)
{
        //validation for alpha
        for(char *p=s;*p!='\0';p++)
        {
                if((!isalpha(*p)) && (*p!=' '))
		{
			printf("Enter valid input !! must be characters \n");
                        return 0;
		}
        }
        //validation for length
        if(strlen(s)>9 || strlen(s) <3 )
        {
                printf("Enter  within the length of 8\n");
                return 0;
        }
        int flag = 0;
	for(int i = 0; s[i]; i++)
	{
		s[i] = tolower(s[i]);
	}
        if(strcmp(s, "micro") == 0 || strcmp(s, "sedan")== 0 || strcmp(s, "suv")== 0 || strcmp( s, "minivan") == 0 )
        {
                flag = 1;
        }
        if(flag == 0)
        {
                printf("Enter valid vehicle type\n");
                return 0;
        }
        return 1;
}

/******************************************************
 * *FUNCTION NAME : capacity_validation
 *
 * *DESCRIPTION   : This function perform validation operations of capacity when user enters the data
 * 		    and displays the respective message.
 *		  
 * *RETURNS       : No return
 *
********************************************************/
int capacity_validation(char *s, int n)
{
	for(int i = 0; s[i]; i++)
	{
		s[i] = tolower(s[i]);
	}
        if((strcmp(s, "micro" ) == 0) && (n == 3))
        {
                return 1;
        }
        if(strcmp(s, "sedan" ) == 0 && (n == 4))
        {
                return 1;
        }
        if(strcmp(s, "suv" ) == 0 && (n == 6))
        {
                return 1;
        }
        if(strcmp(s, "minivan" ) == 0 && (n == 7))
        {
                return 1;
        }

        printf("Enter Valid capacity as 3 for micro, 4 for Sedan, 6 for Suv & 7 for minivan\n");
        return 0;
}

/******************************************************
 * *FUNCTION NAME : aadhar_validation
 *
 * *DESCRIPTION   : This function perform validation operations of aadhar when user enters the data
 * 		    and displays the respective message.
 *		  
 * *RETURNS       : No return
 *
********************************************************/
int aadhar_validation(long int num)
{

                        if(num < 100000000000|| num >999999999999) //Checking if the length of the aadhar no should be 12 digits only else it will print invalid message
                        {
                                printf("\nInvalid Length. Length should only of 12 digits.\n");
                                return 0;
                        }

                        return 1;

}

/******************************************************
 * *FUNCTION NAME : userid_validation
 *
 * *DESCRIPTION   : This function perform validation operations of userid when user enters the data
 * 		    and displays the respective message.
 *		  
 * *RETURNS       : No return
 *
********************************************************/
int userid_validation(char *s)
{
	if(strlen(s) >8 || strlen(s) < 5)
	{
		printf("The User id must be less than 8 or greater than 5\n");
		return 0;
	}
	return 1;
}

/******************************************************
 * *FUNCTION NAME : password_validation
 *
 * *DESCRIPTION   : This function perform validation operations of password when user enters the data
 * 		    and displays the respective message.
 *		  
 * *RETURNS       : No return
 *
********************************************************/
int password_validation(char *str)
{
	char *ptr = str;

	int c_count = 0 , s_count = 0 , i_count = 0;
	while(*ptr !='\0')
	{
		if(*ptr >= 'A' && *ptr <= 'Z')
		{
			c_count = 1;
		}
		else if(*ptr >= 'a' && *ptr <= 'z')
		{
			s_count = 1;
		}
		else if(*ptr >= 48 && *ptr <= 57 )
		{
			i_count = 1;
		}
		else
		{
			return 0;
		}

		ptr++;
	}

	if(c_count && s_count && i_count )
	return 1;
	else
	{
		printf("must contain atleast 1 Capital character , 1 small character & 1 integer\n");
	        return 0;
	}
}



