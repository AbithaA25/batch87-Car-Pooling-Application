/********************************************
 * *FILENAME	      : commuter.c
 *
 * *DESCRITION        : This file defines the functions that uses aadhar no. to 
 * 	                perform various operations of the commuter database.
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
#include <time.h>
#include "structure.h"

sc *start1,*new1,*ptr1,*prev1,*last1;

extern st *start ;

extern char *admin_pswd;


/********************************************
 * *FUNCTION NAME : register_commuter
 *
 * *DESCRIPTION   : This function add the commuter information by taking data as input from the
 *		    user with respective validations.
 *
 * *RETURNS       : aadhar_validation
 *                  integer_validation
 *                  alpha_validator
 *                  phone_validation
 *                  gender_validation
 *                  user_id_validation
 *                  password_validation
 *
 *
*********************************************/
int register_commuter()
{                     //The function register_commuter starts here
	char str[SIZE];

	if((new1  = (sc *)calloc(1,sizeof(sc))) == NULL)
	{
		printf("\nMemory Allocation failed\n");
		return EXIT_FAILURE;
	}
	 while(1)
        {
                
                printf("Enter Aadhar  no-");
                scanf("%s",str);
		
		if(integer_validation(str))
		{
			printf("enter correct Aadhar no-\n");
			continue ;
		}


		new1->aadhar = atol(str);
                if(aadhar_validation(new1->aadhar) == 0)
                {
                        continue;
                }
                if(start1)
                {
                        for(ptr1=start1;(ptr1) && ptr1->aadhar!=new1->aadhar;ptr1=ptr1->next);
                        if(ptr1)
                        {
                                printf("\nAadhar no %ld is duplicate\n",new1->aadhar);
                                return EXIT_FAILURE;
                        }
                }
                break;
        }

        while(1)
        {
        printf("Enter name-");
        scanf("%s",new1->c_name);
        if(alpha_validator(new1->c_name) == 0)
        {
                continue;
        }
        break;
        }

        while(1)
        {
		str[0] = '\0';
        printf("Enter the contact  number-");
        scanf("%s", str);
        if(phone_validation(str))
		{
			break;
		}
		else
		{
			printf("please enter correct phone number\n");
		}
			
	}
	
	new1->c_pno = atol(str);
       

       
        while(1)
        {
	
                printf("Enter Gender-");
                scanf("%s", new1->c_gender);
                if(gender_validation(new1->c_gender) == 0)
                {
                        continue;
                }
                break;
        
	}


        while(1)
	{
	printf("CREATE USER ID\n");
	scanf("%s",new1->user_id);
	if(userid_validation(new1->user_id) == 0)
	{
		continue;
	}
	break;
	}

	while(1)
	{
		printf("CREATE PASSWORD\n");
		scanf("%s",new1->pswd);
		
		if(password_validation(new1->pswd))
		{
			break;
		}
		else 
		{
			printf("Minumum one capital , small and integer no special characters \n");
		}
	}

	
	
	if(!start1)
	{
		start1=new1;
		new1->next=NULL;
	}
	else if(new1->aadhar < start1->aadhar)
	{
	 	new1->next = start1;
		start1 = new1;
	}
	else
	{
		for(ptr1 = start1;(ptr1) && ptr1->aadhar < new1->aadhar; prev1 = ptr1, ptr1 = ptr1->next);
		prev1->next = new1;
		new1->next = ptr1;
	}


	printf("Registration Successfull\n");
        
	return EXIT_SUCCESS;
}//The function register_commuter ends here

/********************************************
 * *FUNCTION NAME : modify_details_C 
 *
 * *DESCRIPTION   : This function edit the commuter information by taking aadhar no. as an 
 * 		    input from the user with respective validations.
 *
 * *RETURNS       : aadhar_validation
 *                  alpha_validation
 *                  phone_validation
 *                  gender_validation
 *
*********************************************/

int modify_details_C()
{                    //The function modify_details_C starts here

	char str[SIZE];
	if(!start1)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
        long int mano;
        while(1)
        {
        printf("\nEnter Aadhar no for editing-");
        scanf("%ld",&mano);
        if(aadhar_validation(mano)  == 0)
        {
        continue;
        }
        break;
        };
	for(ptr1 = start1;(ptr1) && ptr1->aadhar != mano;ptr1=ptr1->next);
	if(!ptr1)
	{
		printf("\nAadhar no %ld not found\n",mano);
		return EXIT_FAILURE;
	}
		printf("\nOld name is %10s , Phone no. is %3ld , Gender is %s\n",ptr1->c_name,ptr1->c_pno,ptr1->c_gender);
	
	 while(1)
        {
        printf("Enter new name-");
        scanf("%s",ptr1->c_name);
        if(alpha_validator(ptr1->c_name) == 0)
        {
                continue;
        }
        break;
        }
        
	while(1)
	{
		printf("Enter phone number :");
		scanf("%s",str);

		if(phone_validation(str))
		{
			break;
		}
		else
		{
			printf("please enter correct phone number\n");
		}

	}

	ptr1->c_pno = atol(str);
        

        while(1)
        {
        printf("Enter Gender-");
        scanf("%s", ptr1->c_gender);
        if(gender_validation(ptr1->c_gender) == 0)
        {
                continue;

        }
        break;
        }
	printf("Commuter data updated\n");
	return EXIT_SUCCESS;
}//The function modify_details_C ends here



/********************************************
 * *FUNCTION NAME : searching_for_cab
 *
 * *DESCRIPTION   : This function searches for cars available by taking source and destination as an
 * 		    input from the user.
 *
 * *RETURNS       : No Returns
 *
 *
 *
*********************************************/

int searching_for_cab()
{



	st *root = start ;

	st *t_root = start ;
	sc *temp = ptr1 ;

	char ch;
	int amount;
	char dummy_vehicle[20] ;

	printf("\t---PRESENT RUNNING ROUTES ARE----\n");


	printf("ENTER THE SOURCE POINT \n");
	scanf(" %c",&temp->source);
	printf("ENTER THE DESTINATION POINT \n");
	scanf(" %c",&temp->Destination);

	for(t_root = start;(t_root) ;t_root = t_root->next)
	{

		if(t_root->source[0] == temp->source  && t_root->dest[0] == temp->Destination)
		{
			printf("%c to %c vehicle model %s\n",t_root->source[0] ,t_root->dest[0],t_root->type_of_v);
		}
	}


	printf("enter the vehicle model \n");
	scanf("%s",dummy_vehicle);

	while(root != NULL)
	{

		if((root->source[0] ==temp->source  && root->dest[0] == temp->Destination) && (strcmp(dummy_vehicle ,root->type_of_v ) == 0))
		{

				printf("Distance is :: %d\n",root->distance);

				root->amount = root->distance *root->charge*30; 

				printf("charge per km is ::%d total amount per month is  %d \n",root->charge,root->amount);

				printf("To confirm The Ride user need to pay 10 percentage of total amount \n");

				printf("enter Y to pay \n");
				printf("enter N to exit\n");
				scanf(" %c",&ch);

				if(ch=='y' || ch == 'Y')
				{
					printf("enter the amount how much you want pay minimum is 10 percentage \n");
					scanf("%d",&amount);

					 if(((amount/(float)root->amount)*100 ) >= 10 )
					 {
					 	root->amount = root->amount - amount ;

					 	root->max += 1;

					 	printf("Your service is availed !!\n");
						
					 }
					 else
					 	printf("please enter the correct amount\n");
				}
				else
				{
					printf("thank you\n");
				}

			}

		root = root ->next;
	}
}



/********************************************
 * *FUNCTION NAME : delete_com_details
 *
 * *DESCRIPTION   : This function delete the commuter data from database by taking 
 * 		    Aadhar no. as an input from the user
 *
 * *RETURNS       : aadhar_validation
 *
*********************************************/
int delete_com_details()
{
	if(!start1)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	long int mano;

        while(1)
        {
        printf("\nEnter Aadhar no for deleting-");
        scanf("%ld",&mano);
        if(aadhar_validation(mano)  == 0)
        {
        continue;
        }
        break;
        };
	
	if(mano == start1->aadhar)
	{
		ptr1=start1;
		start1=start1->next;
		free(ptr1);
	}
	else
	{
		for(ptr1=start1;(ptr1) && ptr1->aadhar!=mano;prev1=ptr1,ptr1=ptr1->next);
		if(!ptr1)
		{
			printf("\nAadhar no %ld not found for deletion \n",mano);
			return EXIT_FAILURE;
		}
		prev1->next=ptr1->next;
		free(ptr1);
	}
	printf("Commuter data deleted Successfully\n");
	return EXIT_SUCCESS;
}

/********************************************
 * *FUNCTION NAME : view_com_details
 *
 * *DESCRIPTION   : This function view the commuter information  
 * 		    and show the comuter details.
 *
 * *RETURNS       : No Returns
 *
 *
 *
*********************************************/
int view_com_details()
{
	if(!start1)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	printf("\n AADHAR_NO  NAME  PHONE_NO  GENDER \n");
	for(ptr1=start1;(ptr1);ptr1=ptr1->next)
	{
		
		printf("******************************************\n");
		printf("Adhar Number %ld\n",ptr1->aadhar);
		printf("NAME : %s\n",ptr1->c_name);
		printf("PHONE_NO : %ld\n",ptr1->c_pno);
		printf("GENDER : %s\n",ptr1->c_gender);
		
		printf("SOURCE : %c \n",ptr1->source);
		printf("DESTINATION : %c\n",ptr1->Destination);
		
		printf("******************************************\n");
	
	}
	printf("\n");
	return EXIT_SUCCESS;
}



/******************************************************
 * *FUNCTION NAME : login_commuter
 *
 * *DESCRIPTION   : This function perform login operation by commuter
 *		  
 * *RETURNS       : modify_details_C
 *
********************************************************/
int login_commuter()
{
	char user_name[10] , str[10] , str1[10];

	int c ;

	long int dummy_adhar ;

	if(!start1)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}


	printf("ENTER THE USER ID \n");
	scanf("%s",user_name);
	printf("ENTER THE PASSWAORD\n");
	scanf("%s",str);

	for(ptr1=start1;(ptr1);ptr1=ptr1->next)
	{

		if(strcmp(ptr1->user_id ,user_name) == 0)
		{
			if(strcmp(ptr1->pswd ,str) == 0)
			{
				printf("HI :%s\n",ptr1->c_name);


				printf("\t1) To Change The Personal Infromation\n");
				printf("\t2) To avail the services\n");
				printf("\t3) To Request Admin to discontinue the service\n");

				scanf("%d",&c);

				if(c ==1)
				{
					modify_details_C();
				}
				else if(c == 2)
				{

					printf("Enter Aadhar number \n");
					scanf("%ld",&dummy_adhar);

					if(dummy_adhar == ptr1->aadhar)
					{
						searching_for_cab();
					}
					else
						printf("Aadhar number is not correct \n");
				}
				else if(c == 3)
				{
					printf(" enter admin password to discontinue the service \n");

					scanf("%s",str1);

					if(strcmp(str1 ,admin_pswd) == 0)
					{
						delete_com_details();
					}
					else
					{
						printf("INCORRECT PASWORD\n");
					}
				}

			}
			else
				printf("INCORECT PASSWORD\n");
		}

	}


}


/********************************************
 * *FUNCTION NAME : commuter_to_list
 *
 * *DESCRIPTION   : This function allocate memory for the commuter to open and read the file
 * 		    from beginning till end of file and put each commuter into the list.
 *
 * *RETURNS       : No Returns
 *
 *
 *
*********************************************/
int commuter_to_list()
{

	FILE *fp;
	tc tc1;
	if((fp=fopen("Commuter","rb"))==NULL)
	{
		printf("\nFile is not there to reaad from\n");
		return EXIT_FAILURE;
	}
	fread(&tc1,sizeof(tc),1,fp);
	while(!feof(fp))
	{
		if((new1=(sc *)calloc(1,sizeof(sc)))==NULL)
		{
			printf("\nMemory Allocation failed\n");
			return EXIT_FAILURE;
		}
		new1->aadhar = tc1.aadhar;
		strcpy(new1->c_name, tc1.c_name);
		strcpy(new1->c_gender, tc1.c_gender);
		new1->c_pno = tc1.c_pno;
		new1->source = tc1.source;
		new1->Destination = tc1.Destination;
		strcpy(new1->user_id, tc1.user_id);
		strcpy(new1->pswd, tc1.pswd);
		

		if(!start1)
		{
			start1 = last1 = new1;
			new1->next=NULL;
		}
		else
		{
			last1->next=new1;
			last1=new1;
			new1->next=NULL;
		}
		fread(&tc1,sizeof(tc),1,fp);
	}
	fclose(fp);
	return EXIT_SUCCESS;
}


/********************************************
 * *FUNCTION NAME : list_to_commuter
 *
 * *DESCRIPTION   : This function is used to write commuter data into the file
 * 		    by traversing the list.
 *
 * *RETURNS       : No Returns
 *
 *
 *
*********************************************/
int list_to_commuter()
{
	tc tc2;
	if(!start1)
	{
		printf("\nList is empty\n");
		return EXIT_FAILURE;
	}
	FILE *fp1;
	if((fp1=fopen("Commuter","wb"))==NULL)
	{
		printf("\nFile is not there to reaad from\n");
		return EXIT_FAILURE;
	}
	for(ptr1=start1;(ptr1);ptr1=ptr1->next)
	{
		tc2.aadhar = ptr1->aadhar;
		strcpy(tc2.c_name, ptr1->c_name);
		strcpy(tc2.c_gender , ptr1->c_gender);
		tc2.c_pno = ptr1->c_pno;
		tc2.source = ptr1->source;
		tc2.Destination = ptr1->Destination;
		strcpy(tc2.user_id, ptr1->user_id);
		strcpy(tc2.pswd, ptr1->pswd);


		fwrite(&tc2,sizeof(tc),1,fp1);
		
	}
	
	fclose(fp1);
	return EXIT_SUCCESS;
}


