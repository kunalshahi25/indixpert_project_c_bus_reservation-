#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char reg_user_id[20];
char user_id[20];
char password[20];
char reg_password[20];
char first_name[20],last_name[20];
int flag = 0;
int j=3;
// int bus_num[100];
int no_seats101,no_seats102,no_seats103,no_seats104;
// int avail_seats101 = 50 - no_seats101;
// int avail_seats102 = 50 - no_seats102;
// int avail_seats103 = 50 - no_seats103;
// int avail_seats104 = 50 - no_seats104;
int bnum;
void bus_reg_info(){
    printf("\n*****BUS RESERVATION SYSTEM*****\n");
    printf("Enter Your First Name: ");
    scanf(" %[^\n]",&first_name);
    printf("Enter Your Last Name: ");
    scanf(" %[^\n]",&last_name);
    printf("Enter user id: ");
    scanf(" %[^\n]",&reg_user_id);
    printf("Enter password: ");
    scanf("%s",&reg_password);
    printf("\n");
}
int bus_login_info(){
    int option;
    
    printf("1. Login.");
    printf("\n2. Exit.");
    printf("\nEnter your choice: ");
    scanf("%d",&option);
    return option;
}
void bus_login(){
    printf("Please enter user id: ");
    scanf(" %[^\n]",&user_id);
    printf("Please enter password: ");
    scanf(" %s",&password);
    if(strcmp(user_id,reg_user_id)==0 && strcmp(password,reg_password)==0){
        printf("\nLogin successful. Welcome, %s %s!\n",first_name,last_name);
    }
    else{
        printf("Invalid user id or password. Format is \"name@123\"");
        for (int i = 0; i < 3; i++)
        {
            printf("\nPlease enter user id: ");
            scanf(" %[^\n]",user_id);
            printf("Please enter password: ");
            scanf(" %s",password);
            if(strcmp(user_id,reg_user_id)==0 && strcmp(password,reg_password)==0){
            printf("\nLogin successful. Welcome, %s %s!\n",first_name,last_name);
            flag=1;
            if (flag==1)
            {
                break;
            }
            }
            else
            printf("You have %d attempt left.\n",--j);
            if (j == 0)
            {
                exit(0);
            }
            
        }
        
    }
}
int user_menu(){
    int choice;
        printf("=== User Menu ===\n");
        printf("1. Book a Ticket.");
        printf("\n2. Cancel a Ticket.");
        printf("\n3. Check Bus Status.");
        printf("\n4. Logout.");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
    return choice;        
}
int booking_ticket();
void canceling_ticket();
void bus_status_ticket();
void bus_menu(){
    printf("\n101: Delhi to Uttarakhand.\n");
    printf("102: Delhi to Bihar");
    printf("\n103: Delhi to Haryana");
    printf("\n104: Delhi to Rajasthan");
}

 
int main(){
    bus_reg_info();
    int option = bus_login_info();
    if (option==1)
    {
        bus_login();
        printf("\n");
        while(1){
            printf("\n");
            int choice =user_menu();
            
            printf("\n");
            
            if (choice == 1)
            {
                bus_menu();
                booking_ticket();
            }
            else if(choice==2)
            {
                bus_menu();  
                canceling_ticket();  
            }
            else if (choice == 3)
            {
                bus_menu();
                bus_status_ticket();
            }
            else if (choice == 4)
            {
                printf("Login Back Again !");
                exit(0);
            }
            else{
                printf("\nPlease Select Correct Option..");
            }
        }
    }
    
}
int booking_ticket(){
    
    printf("\nEnter Bus Number: ");
    scanf("%d",&bnum);
    if (bnum == 101)
    {
        printf("Enter Number of Seats: ");
        scanf("%d",&no_seats101);
        printf("\n");
        if(no_seats101 > 50 || no_seats101 < 0){
            printf("Sorry, Bus has 50 Seats Only !");
            printf("\n");
            booking_ticket();
        }
        printf("\n");
        printf("\n Booking Successful ! %d seats booked on Bus number %d\n",no_seats101,bnum);    
    }
    else if (bnum == 102)
    {
        printf("Enter Number of Seats: ");
        scanf("%d",&no_seats102);
        printf("\n");
        if(no_seats102 > 50 || no_seats102 < 0){
            printf("Sorry, Bus has 50 Seats Only !");
            printf("\n");
            booking_ticket();
        }
        printf("\n");
        printf("\n Booking Successful ! %d seats booked on Bus number %d\n",no_seats102,bnum);    
    }
    else if (bnum == 103)
    {
        printf("Enter Number of Seats: ");
        scanf("%d",&no_seats103);
        printf("\n");
        if(no_seats103 > 50 || no_seats103 < 0){
            printf("Sorry, Bus has 50 Seats Only !");
            printf("\n");
            booking_ticket();
        }
        printf("\n");
        printf("\n Booking Successful ! %d seats booked on Bus number %d\n",no_seats103,bnum);    
    }
    else if (bnum == 104)
    {
        printf("Enter Number of Seats: ");
        scanf("%d",&no_seats104);
        printf("\n");
        if(no_seats104 > 50 || no_seats104 < 0){
            printf("Sorry, Bus has 50 Seats Only !");
            printf("\n");
            booking_ticket();
        }
        printf("\n");
        printf("\n Booking Successful ! %d seats booked on Bus number %d\n",no_seats104,bnum);    
    }
    else {
        printf("\n Bus Number Not Found !\n");
        booking_ticket();
    }
    return bnum;
}
void canceling_ticket(){
    int bnum, cancel;
    printf("Enter Bus Number: ");
    scanf("%d",&bnum);
    printf("Enter Number of seats to cancel: ");
    scanf("%d",&cancel);
    if (cancel!=0 && bnum !=0)
    {
     printf("\n Cancellation Successful ! %d seats canceled on Bus Number %d\n",cancel,bnum);
    }

}
void bus_status_ticket(){
    printf("\nPlease enter Bus Number: ");
    scanf("%d",&bnum);
    if (bnum ==101)
    {
        printf("Bus Number:                 %d",bnum);
        printf("\nSource city:                Delhi");
        printf("\nDestination City:           Uttarakhand");
        printf("\nTotal Seats:                50");
        printf("\nAvailable Seats:            %d",50 - no_seats101);
        printf("\nFare per person:            500.00");
        printf("Your total fare:              %d",500*no_seats101);
    }
    else if (bnum ==102)
    {
        printf("Bus Number:                 %d",bnum);
        printf("\nSource city:                Delhi");
        printf("\nDestination City:           Bihar");
        printf("\nTotal Seats:                50");
        printf("\nAvailable Seats:            %d",50 - no_seats102);
        printf("\nFare per person:            500.00");
        printf("Your total fare:              %d",500*no_seats102);
    }
    else if (bnum ==103)
    {
        printf("Bus Number:                 %d",bnum);
        printf("\nSource city:                Delhi");
        printf("\nDestination City:           Haryana");
        printf("\nTotal Seats:                50");
        printf("\nAvailable Seats:            %d",50 - no_seats103);
        printf("\nFare per person:            500.00");
        printf("Your total fare:              %d",500*no_seats103);
    }
    else if (bnum ==104)
    {
        printf("Bus Number:                 %d",bnum);
        printf("\nSource city:                Delhi");
        printf("\nDestination City:           Rsjasthan");
        printf("\nTotal Seats:                50");
        printf("\nAvailable Seats:            %d",50 - no_seats104);
        printf("\nFare per person:            500.00");
        printf("Your total fare:              %d",500*no_seats104);
    }
    else{
        printf("\nInvalid Bus Number");
    }
}