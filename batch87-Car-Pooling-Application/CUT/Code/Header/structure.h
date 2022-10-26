#ifndef STRUCTURE_H
#define STRUCTURE_H
#define pragma pack(1)

typedef struct transporter
{
     long int d_no; //drivinglicenseno
     char t_name[20];
     long int t_pno;
     char t_gender[2];
     char source[2];
     char dest[2];
     int  max ; //to calculate busiest route
     int distance ;
     int amount ; //payment by commuter
     char type_of_v[20];
     int capacity;
     int ac_nonac;
     int charge;
     int unique_id;
     char user_id[10];
     char pswd[10];
   

     struct transporter *next;
}st;


typedef struct commuter
{
     long int aadhar;
     char c_name[20];
     char c_gender[2];
     long int c_pno;
     //char t_gender;
     char source ;
     char Destination ;
     char user_id[10];
     char pswd[10];


     struct commuter *next;
}sc;

typedef struct temp1
{

     long int d_no; //drivinglicenseno
     char t_name[20];
     long int t_pno;
     char t_gender[2];
     char source[2];
     char dest[2];
     int  max ;
     int distance ;
     int amount ;
     char type_of_v[20];
     int capacity;
     int ac_nonac;
     int charge;
     int unique_id;
     char user_id[10];
     char pswd[10];
   
}tt;

typedef struct temp2
{
     long int aadhar;
     char c_name[20];
     char c_gender[2];
     long int c_pno;
     char source ;
     char Destination ;
     char user_id[10];
     char pswd[10];

}tc;

// functions from transporter.c
int register_transporter();
int login_transporter();
int modify_details_T();
int searching_for_cab();
int delete_tra_details();
int view_tra_details();

// functions from commuter.c
int register_commuter();
int modify_details_C();
int login_commuter();
int searching_for_cab();
int delete_com_details();
int view_com_details();


// functions from transporter.c for file handling
int transporter_to_list();
int list_to_transporter();

// functions from commuter.c for file handling
int commuter_to_list();
int list_to_commuter();


// function from show_reports.c
int busy_route();
int show_routes();

// functions from main.c
int transporter_data(); //function for first option to show options
int commuter_data(); //function for second option to show options
int admin(); // function for third option
int maintain_transporter();//func of sub third
int maintain_commuter();//sub third

//functions from validation.c
int aadhar_validation(long int);
int alpha_validator(char *s);
int gender_validation(char *s);
int point_validation(char *s, char *t);
int car_type_validation(char *s);
int capacity_validation(char *s, int);
int distance_validation(char *s, char *d, int n);
int userid_validation(char *s);
int password_validation(char *s);
int phone_validation(char *s);
int integer_validation(char *s);


#define SIZE 20

#endif



