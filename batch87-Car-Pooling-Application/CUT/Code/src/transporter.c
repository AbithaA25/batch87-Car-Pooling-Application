/********************************************
 * *FILENAME	      : transporter.c
 *
 * *DESCRITION        : This file defines the functions that uses Unique ID to 
 * 	                perform various operations of the Transporter database.
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

st *start,*new,*ptr,*prev,*last;

char *admin_pswd = "Group8";

/********************************************
 * *FUNCTION NAME : register_transporter
 *
 * *DESCRIPTION   : This function add the transporter information by taking data as input from the 
 *		    user with respective validations.
 *
 * *RETURNS       : integer_validation
 *                  alpha_validator
 *                  phone_validation
 *                  gender_validation
 *                  point_validation
 *                  distance_validation
 *                  car_type_validation
 *                  capacity_validation
 *                  user_id_validation
 *                  password_validation
 *
*********************************************/

int register_transporter()
{                         //The register_transporter function starts here


	long int num = 0;
	char str[SIZE];

	if((new  = (st *)calloc(1,sizeof(st))) == NULL)
	{
		printf("\nMemory Allocation failed\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		printf("Enter the Driving License number\n");
		scanf("%s",str);
		
		if(integer_validation(str))
		{
			printf("enter correct driving licence number\n");
			
			continue ;
		}
	       new->d_no = atol(str);
	       //checking for duplication
                if(start)
                {
                        for(ptr=start;(ptr) && ptr->d_no!=new->d_no;ptr=ptr->next);
                        if(ptr)
                        {
                                printf("\nDriving License no %ld is duplicate\n",new->d_no);
                                continue;
				//return EXIT_FAILURE;
                        }
                        
                }
                break;
        }
	while(1)
	{
        printf("Enter the name-");
        scanf("%s",new->t_name);
        if(alpha_validator(new->t_name) == 0)
        {
                continue;
        }
        break;
        }



       while(1)
	{
		str[0] = '\0';
		printf("Enter contact number-\n");
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
	
	new->t_pno = atol(str);
        while(1)
        {
        printf("Enter Gender-");
        scanf("%s",new->t_gender);
        if(gender_validation(new->t_gender) == 0)
        {
                continue;

        }
        break;
        }

        while(1)
        {
	printf("Routes are A, B, C, D, E, F\n");
        printf("Enter the Source point-");
        scanf("%s", new->source);
        printf("Enter the Destination point-");
        scanf("%s", new->dest);

        if(point_validation(new->source, new->dest) == 0)
        {
            continue;
        }
        break;
        }

	while(1)
	{
		str[0] = '\0';
		printf("Enter the distance in Km\n");
		scanf("%s",str);

		if(integer_validation(str))
		{
			printf("enter correct Distance\n");
			continue ;
		}

	new->distance = atoi(str);
       
	if(distance_validation(new->source, new->dest, new->distance)==0)
	{
		continue;
	}
	break;
	}

        while(1)
        {
        printf("Enter Type of Vehicle - MICRO, SEDAN, SUV, MINIVAN");
        scanf("%s", new->type_of_v);
	
        if(car_type_validation(new->type_of_v) == 0)
        {
                continue;

        }
        break;
        }
        

        while(1)
        {
		str[0] = '\0';
       
        printf("Enter the no. of commutators can transport-");
        scanf("%s", str);
        if(integer_validation(str))
		{
			printf("Enter the correct no.\n");
			continue ;
	        }
	new->capacity = atoi(str);
        if(capacity_validation(new->type_of_v, new->capacity) == 0)
        {
                continue;
        }
        break;
        }

        while(1)
        {
		str[0] = '\0';
        printf("Enter 1 for AC or 2 for NON AC-");
        scanf("%s", str);
		if(integer_validation(str))
		{
			printf("Enter 1 for AC or 2 for Non AC\n");
			
			continue ;
		}
	new->ac_nonac = atoi(str);
        int flag = 0;
        if(new->ac_nonac == 1 || new->ac_nonac == 2)
        {
                flag = 1;
        }
        if(flag == 0)
        {
                printf("Must be either 1 or 2\n");
                continue;
        }

        break;
        }

	while(1)
	{

		str[0] = '\0';
		printf("Enter the charge per km \n");
		scanf("%s",str);
		if(integer_validation(str))
		{
			printf("Enter the charge per km \n");
			
			continue ;
		}
	        new->charge = atoi(str);
      

		if(new->charge > 0 && new->charge <= 5)
		{
			break;
		}

		else
		{
			printf("charge per km must be less than or equal 5 RS only \n");
			continue;
		}
		break;
	}



	time_t t1;
	int ans;

	srand((unsigned) time (&t1));
	printf("\n");
        ans = rand() % 50;
	new->unique_id = ans;
        while(1)
	{
	printf("CREATE USER ID\n");
	scanf("%s",new->user_id);
	if(userid_validation(new->user_id) == 0)
	{
		continue;
	}
	break;
	}

	while(1)
	{
	printf("CREATE PASSWORD\n");
	scanf("%s",new->pswd);
	if(password_validation(new->pswd) == 0)
	{
		continue;
	}
	break;
	}
	
	printf("Your unique ID is %d\n", ans);
        printf("Registration Successfull\n");
	
	if(!start)
	{
		start=new;
		new->next=NULL;
	}
	else if(new->d_no < start->d_no)
	{
	 	new->next = start;
		start = new;
	}
	else
	{
		for(ptr = start;(ptr) && ptr->d_no < new->d_no; prev = ptr, ptr = ptr->next);
		prev->next = new;
		new->next = ptr;
	}

	return EXIT_SUCCESS;
}//The register_transporter function ends here

/********************************************
 * *FUNCTION NAME : modify_details_T
 *
 * *DESCRIPTION   : This function edit the transporter information by taking Unique id as an 
 * 		    input from the user with respective validations.
 *
 * *RETURNS       : integer_validation
 *                  alpha_validator
 *                  phone_validation
 *                  gender_validation
 *
*********************************************/
int modify_details_T()
{                   //The modify_details_T function starts here
	char str[SIZE];
	if(!start)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	int muno;
	while(1)
        {
        
        printf("\nEnter your respective Unique ID for editing-");
		scanf("%s",str);
		if(integer_validation(str))
		{
			printf("Enter your respective Unique ID for editing \n");
			
			continue ;
		}
	        muno = atoi(str);
              break;
        }

	for(ptr=start;(ptr) && ptr->unique_id!=muno;ptr=ptr->next);
	
	if(!ptr)
	{
		printf("\nUnique ID %d not found\n",muno);
		return EXIT_FAILURE;
	}
		printf("\n Old name is %10s , Phone no. is %3ld , Gender is %s\n",ptr->t_name,ptr->t_pno,ptr->t_gender);
	
	
	while(1)
	{
		printf("Enter the name\n");
		scanf("%s",new->t_name);
		if(alpha_validator(new->t_name) == 0)
		{
			continue;
		}
		break;
	}
	while(1)
	{
		printf("Enter the contact number\n");
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
	
	new->t_pno = atol(str);

	while(1)
        {
        printf("Enter Gender-");
        scanf("%s", ptr->t_gender);
        if(gender_validation(ptr->t_gender) == 0)
        {
                continue;

        }
        break;
        }
        printf("Transporer data is updated\n"); 
	return EXIT_SUCCESS;
}//The modify_details_T function ends here


/********************************************
 * *FUNCTION NAME : delete_tra_details
 *
 * *DESCRIPTION   : This function delete the transporter data from database by taking 
 * 		    Unique id as an input from the user
 *
 * *RETURNS       : integer_validation
 *
*********************************************/
int delete_tra_details()
{                      //The delete_tra_details function starts here
	char str[SIZE];
	if(!start)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	int muno;
        while(1)
        {
        printf("\nEnter your respective Unique ID for deleting-");
		scanf("%s",str);
		if(integer_validation(str))
		{
			printf("Enter your respective Unique ID for deleting \n");
			
			continue ;
		}
	        muno = atoi(str);
              break;
        }

	if(muno == start->unique_id)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	else
	{
		for(ptr=start;(ptr) && ptr->unique_id != muno;prev=ptr,ptr=ptr->next);
		if(!ptr)
		{
			printf("\nUnique ID %d not found for deletion \n",muno);
			return EXIT_FAILURE;
		}

		prev->next=ptr->next;
		free(ptr);
	}
	printf("Transporter data deleted Successfully\n");
	return EXIT_SUCCESS;
}//The delete_tra_details function ends here

/********************************************
 * *FUNCTION NAME : view_tra_details
 *
 * *DESCRIPTION   : This function view the transporter information and show the bowler details.
 *
 * *RETURNS       : No Returns
 *
 *
 *
*********************************************/
int view_tra_details()
{
	if(!start)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		printf("******************************************\n");
		printf("LICENSE_NO : %ld\n",ptr->d_no);
		printf("UNIQUE_ID id %d\n",ptr->unique_id);
		printf("NAME : %s\n",ptr->t_name);
		printf("PHONE_NO : %ld\n",ptr->t_pno);
		printf("GENDER : %s\n",ptr->t_gender);
		printf("SOURCE : %s \n",ptr->source);
		printf("DESTINATION : %s\n",ptr->dest);
		printf("TYPE_OF_VEHICLE : %s\n",ptr->type_of_v);
		printf("CAPACITY :%d\n",ptr->capacity);
		
		if(ptr->ac_nonac == 1)
			printf("AC \n");
		else 
			printf("NON -AC\n");
		printf("CHARGE KM : %d\n",ptr->charge);
		printf("******************************************\n");
		
	}
	printf("\n");
	return EXIT_SUCCESS;
}



/******************************************************
 * *FUNCTION NAME : login_transporter
 *
 * *DESCRIPTION   : This function perform login operation by transporter
 *		  
 * *RETURNS       : modify_details_T
 *
********************************************************/
int login_transporter()
{
	char user_name[SIZE] , str[SIZE] , str1[SIZE];
	
	char test[2];
	int c ;
		
	if(!start)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	
		
	printf("ENTER THE USER ID \n");
	scanf("%s",user_name);
	printf("ENTER THE PASSWAORD\n");
	scanf("%s",str);
	
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		
		if(strcmp(ptr->user_id ,user_name) == 0)
		{
			if(strcmp(ptr->pswd ,str) == 0)
			{
				printf("HI :%s\n",ptr->t_name);
				
				printf("TRANSPORTER IS NOT ALLOWED TO CHANGE THE ROUTE\n");
				printf("\t1) To Change The Personal Infromation\n");
				printf("\t2) To Request Admin to change ROUTE info\n");

				scanf("%d",&c);
				
				if(c ==1)
				{
					modify_details_T();
					return 0;
				}
				else if(c == 2)
				{
					printf(" enter admin password to modify ROUTE \n");
					
					scanf("%s",str1);
					
					if(strcmp(str1 ,admin_pswd) == 0)	
					{
						printf("ADMIN MODE ACTIVATED\n");
						
						
						printf("enter the source point\n");
						scanf(" %c",&ptr->source[0]);
						
						printf("enter the destination point\n");
						scanf(" %c",&ptr->dest[0]);
						
						
						return 0;
					}
					else 
					{
						printf("INCORRECT PASWORD FOR ADMIN\n");
					}		
				} 
				
			}
			else 
				printf("INCORECT PASSWORD FOR USER\n");
		}		
		
	}	
			
	
}

/********************************************
 * *FUNCTION NAME : transporter_to_list 
 *
 * *DESCRIPTION   : This function allocate memory for the transporter to open and read the file 
 * 		    from beginning till end of file and put each transporter into the list.
 *
 * *RETURNS       : No Returns 
 *
 *
 *
*********************************************/

int transporter_to_list()
{

	FILE *p;
	tt t1;
	if((p=fopen("Transporter","rb"))==NULL)
	{
		printf("\nFile is not there to read from\n");
		return EXIT_FAILURE;
	}

	fread(&t1, sizeof(tt), 1, p);
	while(!feof(p))
	{
		if((new=(st *)calloc(1,sizeof(st)))==NULL)
		{
			printf("\nMemory Allocation failed\n");
			return EXIT_FAILURE;
		}
		new->d_no = t1.d_no;
		strcpy(new->t_name, t1.t_name);
		new->t_pno = t1.t_pno;
		strcpy(new->t_gender, t1.t_gender);
		strcpy(new->source,t1.source);
		strcpy(new->dest, t1.dest);
		new->max = t1.max;
		new->distance = t1.distance;
		new->amount = t1.amount;
		strcpy(new->type_of_v, t1.type_of_v);
		new->capacity = t1.capacity;
		new->ac_nonac = t1.ac_nonac;
		new->charge = t1.charge;
		new->unique_id = t1.unique_id;
		strcpy(new->user_id, t1.user_id);
		strcpy(new->pswd, t1.pswd);


		if(!start)
		{
			start = last = new;
			new->next=NULL;
		}
		else
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
		fread(&t1,sizeof(tt),1,p);
	}
	fclose(p);
	return EXIT_SUCCESS;
}


/********************************************
 * *FUNCTION NAME : list_to_transporter
 *
 * *DESCRIPTION   : This function is used to write transporter data into the file
 * 		    by traversing the list.
 *
 * *RETURNS       : No Returns
 *
 *
 *
*********************************************/
int list_to_transporter()
{
	tt t2;
	if(!start)
	{
		printf("\nList is empty\n");
		return EXIT_FAILURE;
	}
	FILE *p1;
	if((p1=fopen("Transporter","wb"))==NULL)
	{ 
		printf("\nFile is not there to reaad from\n");
		return EXIT_FAILURE;
	}
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		t2.d_no = ptr->d_no;
		strcpy(t2.t_name, ptr->t_name);
		t2.t_pno = ptr->t_pno;
		strcpy(t2.t_gender ,  ptr->t_gender);
		strcpy(t2.source, ptr->source);
		strcpy(t2.dest, ptr->dest );
		t2.max = ptr->max;
		t2.distance = ptr->distance;
		t2.amount = ptr->amount;
		strcpy(t2.type_of_v, ptr->type_of_v);
		t2.capacity = ptr->capacity;
		t2.ac_nonac = ptr->ac_nonac;
		t2.charge = ptr->charge;
		t2.unique_id = ptr->unique_id;
		strcpy(t2.user_id, ptr->user_id);
		strcpy(t2.pswd, ptr->pswd);


		fwrite(&t2,sizeof(tt),1,p1);
		
	}
	
	fclose(p1);

	return EXIT_SUCCESS;
}

