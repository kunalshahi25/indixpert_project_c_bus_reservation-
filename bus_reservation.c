#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char reg_user_id[20];
char user_id[20];
char password[20];
char reg_password[20];
char reg_password[20];
char reg_password_cnfrm[20];
char first_name[20], last_name[20];
int flag = 0;
int j = 3;
int cancel101 = 0, cancel102 = 0, cancel103 = 0, cancel104 = 0;
int cancel105 = 0, cancel106 = 0, cancel107 = 0, cancel108 = 0;
int no_seats101, no_seats102, no_seats103, no_seats104;
int no_seats105, no_seats106, no_seats107, no_seats108;

int bnum;
void bus_reg_info()
{
    printf("\n\033[1;33m*****BUS RESERVATION SYSTEM*****\033[0m\n");
    printf("\n");
    printf("\033[1;31m    ===Sign Up===    \033[0m\n");
    printf("\n");
    printf("Enter Your First Name: ");
    scanf(" %[^\n]", &first_name);
    printf("Enter Your Last Name: ");
    scanf(" %[^\n]", &last_name);
    printf("Enter user id: ");
    scanf(" %[^\n]", &reg_user_id);
    printf("Enter password: ");
    scanf("%s", &reg_password);
    printf("Confirm password: ");
    scanf("%s", &reg_password_cnfrm);
    if (strcmp(reg_password, reg_password_cnfrm) == 0)
    {
        printf("\n\033[1;32mSign Up Successful. Welcome !\033[0m");
    }
    else
    {
        printf("\033[1;31mPassword Not Matched.\n\033[0m");
        for (int i = 0; i < 3; i++)
        {
            printf("\033[1;31m    ===Sign Up===    \033[0m\n");
            printf("\n");
            printf("Enter Your First Name: ");
            scanf(" %[^\n]", &first_name);
            printf("Enter Your Last Name: ");
            scanf(" %[^\n]", &last_name);
            printf("Enter user id: ");
            scanf(" %[^\n]", &reg_user_id);
            printf("Enter password: ");
            scanf("%s", &reg_password);
            printf("Confirm password: ");
            scanf("%s", &reg_password_cnfrm);
            if (strcmp(reg_password, reg_password_cnfrm) == 0)
            {
                printf("\n\033[1;32mSign Up successful. Welcome,\033[0m \033[1;31m%s %s\033[0m \033[1;32m!\033[0m\n", first_name, last_name);
                flag = 1;
                if (flag == 1)
                {
                    break;
                }
            }
            else
                printf("\033[1;31mYou have %d attempt left.\033[0m\n", --j);
            if (j == 0)
            {
                exit(0);
            }
        }
    }

    printf("Sign Up Completed.");

    printf("\n");
}
int bus_login_info()
{
    int option;

    printf("1. Login.");
    printf("\n2. Exit.");
    printf("\nEnter your choice: ");
    scanf("%d", &option);
    return option;
}
void bus_login()
{
    printf("Please enter user id: ");
    scanf(" %[^\n]", &user_id);
    printf("Please enter password: ");
    scanf(" %s", &password);
    if (strcmp(user_id, reg_user_id) == 0 && strcmp(password, reg_password) == 0) // comparing name and password
    {
        printf("\n\033[1;32mLogin successful. Welcome,\033[0m \033[1;31m%s %s\033[0m \033[1;32m!\033[0m\n", first_name, last_name);
    }
    else
    {
        printf("\033[1;31mInvalid user id or password.\033[0m");
        for (int i = 0; i < 3; i++)
        {
            printf("\nPlease enter user id: ");
            scanf(" %[^\n]", user_id);
            printf("Please enter password: ");
            scanf(" %s", password);
            if (strcmp(user_id, reg_user_id) == 0 && strcmp(password, reg_password) == 0)
            {
                printf("\n\033[1;32mLogin successful. Welcome,\033[0m \033[1;31m%s %s\033[0m \033[1;32m!\033[0m\n", first_name, last_name);
                flag = 1;
                if (flag == 1)
                {
                    break;
                }
            }
            else
                printf("\033[1;31mYou have %d attempt left.\033[0m\n", --j);
            if (j == 0)
            {
                exit(0);
            }
        }
    }
}
int user_menu()
{
    int choice;
    printf("\033[1;33m=== User Menu ===\n\033[0m");
    printf("\033[1;33m1. Book a Ticket.\033[0m");
    printf("\n\033[1;33m2. Cancel a Ticket.\033[0m");
    printf("\n\033[1;33m3. Check Bus Status.\033[0m");
    printf("\n\033[1;33m4. Logout.\033[0m");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}
int booking_ticket();
void canceling_ticket();
void bus_status_ticket();
void bus_menu()
{
    printf("\n\033[1;35m101:            Delhi to Uttarakhand.\033[0m");
    printf("\n\033[1;35m102:            Delhi to Uttarakhand.(AC)\033[0m");
    printf("\n\033[1;35m103:            Delhi to Bihar.\033[0m");
    printf("\n\033[1;35m104:            Delhi to Bihar.(AC)\033[0m");
    printf("\n\033[1;35m105:            Delhi to Haryana.\033[0m");
    printf("\n\033[1;35m106:            Delhi to Haryana.(AC)\033[0m");
    printf("\n\033[1;35m107:            Delhi to Rajasthan.\033[0m");
    printf("\n\033[1;35m108:            Delhi to Rajasthan.(AC)\033[0m");
}
int bus_type_ticket()
{
    int bus_type;
    printf("\n\033[1;33m=== Bus Type ===\n\033[0m");
    printf("\033[1;33m1. AC Bus.\033[0m");
    printf("\n\033[1;33m2. Non-AC Bus.\033[0m");
    printf("\nEnter your choice: ");
    scanf("%d", &bus_type);
    return bus_type;
}

int main()
{
    bus_reg_info();
    int option = bus_login_info();
    if (option == 1)
    {
        bus_login();
        printf("\n");
        while (1)
        {
            printf("\n");
            int choice = user_menu();

            printf("\n");

            if (choice == 1)
            {
                bus_menu();
                printf("\n");
                booking_ticket();
            }
            else if (choice == 2)
            {
                bus_menu();
                printf("\n");
                canceling_ticket();
            }
            else if (choice == 3)
            {
                bus_menu();
                printf("\n");
                bus_status_ticket();
            }
            else if (choice == 4)
            {
                printf("\033[1;31mLogin Back Again !\033[0m");
                exit(0);
            }
            else
            {
                printf("\nPlease Select Correct Option..");
            }
        }
    }
}
int booking_ticket()
{

    printf("\033[1;35mBooking Ticket.\033[0m");
    int choice_bus = bus_type_ticket();
    if (choice_bus == 1)
    {
        printf("\nEnter Bus Number: ");
        scanf(" %d", &bnum);
        if (bnum == 102)
        {
            printf("Enter Number of Seats(MAX : 50): ");
            scanf("%d", &no_seats102);
            printf("\n");
            if (no_seats102 > 50 || no_seats102 < 0)
            {
                printf("\033[1;31mSorry, Bus has 50 Seats Only !\033[0m");
                printf("\n");
                booking_ticket();
            }
            else
            {
                printf("\n");
                printf("\n \033[1;32mBooking Successful ! %d seats booked on Bus number %d. \033[0m\n", no_seats102, bnum);
            }
        }
        else if (bnum == 104)
        {
            printf("Enter Number of Seats(MAX : 50): ");
            scanf("%d", &no_seats104);
            printf("\n");
            if (no_seats104 > 50 || no_seats104 < 0)
            {
                printf("\033[1;31mSorry, Bus has 50 Seats Only !\033[0m");
                printf("\n");
                booking_ticket();
            }
            else
            {
                printf("\n");
                printf("\n \033[1;32mBooking Successful ! %d seats booked on Bus number %d\033[0m\n", no_seats104, bnum);
            }
        }
        else if (bnum == 106)
        {
            printf("Enter Number of Seats(MAX : 50): ");
            scanf("%d", &no_seats106);
            printf("\n");
            if (no_seats106 > 50 || no_seats106 < 0)
            {
                printf("\033[1;31mSorry, Bus has 50 Seats Only !\033[0m");
                printf("\n");
                booking_ticket();
            }
            else
            {
                printf("\n");
                printf("\n \033[1;32mBooking Successful ! %d seats booked on Bus number %d\033[0m\n", no_seats106, bnum);
            }
        }
        else if (bnum == 108)
        {
            printf("Enter Number of Seats(MAX : 50): ");
            scanf("%d", &no_seats108);
            printf("\n");
            if (no_seats108 > 50 || no_seats108 < 0)
            {
                printf("\033[1;31mSorry, Bus has 50 Seats Only !\033[0m");
                printf("\n");
                booking_ticket();
            }
            else
            {
                printf("\n");
                printf("\n \033[1;32mBooking Successful ! %d seats booked on Bus number %d\033[0m\n", no_seats108, bnum);
            }
        }
        else
        {
            printf("\033[1;31mSorry, Bus not available !\033[0m");
            printf("\n");
            booking_ticket();
        }
    }
    else if (choice_bus == 2)
    {
        printf("\nEnter Bus Number: ");
        scanf("%d", &bnum);
        if (bnum == 101)
        {
            printf("Enter Number of Seats(MAX : 50): ");
            scanf("%d", &no_seats101);
            printf("\n");
            if (no_seats101 > 50 || no_seats101 < 0)
            {
                printf("\033[1;31mSorry, Bus has 50 Seats Only !\033[0m");
                printf("\n");
                booking_ticket();
            }
            else
            {
                printf("\n");
                printf("\n \033[1;32mBooking Successful ! %d seats booked on Bus number %d. \033[0m\n", no_seats101, bnum);
            }
        }
        else if (bnum == 103)
        {
            printf("Enter Number of Seats(MAX : 50): ");
            scanf("%d", &no_seats103);
            printf("\n");
            if (no_seats103 > 50 || no_seats103 < 0)
            {
                printf("\033[1;31mSorry, Bus has 50 Seats Only !\033[0m");
                printf("\n");
                booking_ticket();
            }
            else
            {
                printf("\n");
                printf("\n \033[1;32mBooking Successful ! %d seats booked on Bus number %d\033[0m\n", no_seats103, bnum);
            }
        }
        else if (bnum == 105)
        {
            printf("Enter Number of Seats(MAX : 50): ");
            scanf("%d", &no_seats105);
            printf("\n");
            if (no_seats105 > 50 || no_seats105 < 0)
            {
                printf("\033[1;31mSorry, Bus has 50 Seats Only !\033[0m");
                printf("\n");
                booking_ticket();
            }
            else
            {
                printf("\n");
                printf("\n \033[1;32mBooking Successful ! %d seats booked on Bus number %d\033[0m\n", no_seats105, bnum);
            }
        }
        else if (bnum == 107)
        {
            printf("Enter Number of Seats(MAX : 50): ");
            scanf("%d", &no_seats107);
            printf("\n");
            if (no_seats107 > 50 || no_seats107 < 0)
            {
                printf("\033[1;31mSorry, Bus has 50 Seats Only !\033[0m");
                printf("\n");
                booking_ticket();
            }
            else
            {
                printf("\n");
                printf("\n \033[1;32mBooking Successful ! %d seats booked on Bus number %d\033[0m\n", no_seats107, bnum);
            }
        }
        else
        {
            printf("\033[1;31mSorry, Bus not available !\033[0m");
            printf("\n");
            booking_ticket();
        }
    }
    else
    {
        printf("\033[1;31mPlease Enter a valid Bus Number.\033[0m\n");
        printf("\n");
        booking_ticket();
    }
}

void canceling_ticket()
{
    int bnum;
    int choice_bus = bus_type_ticket();
    if (choice_bus == 1)
    {
        printf("\nEnter Bus Number: ");
        scanf("%d", &bnum);
        if (bnum == 102)
        {
            printf("Enter Number of seats to cancel: ");
            scanf("%d", &cancel102);
            if (cancel102 != 0 && cancel102 <= no_seats102)
            {
                printf("\n \033[1,32mCancellation Successful ! %d seats canceled on Bus Number %d\033[0m\n", cancel102, bnum);
            }
            else
            {
                printf("\n \033[1,31mSorry, You have not booked that much seat !\033[0m\n");
            }
        }
        else if (bnum == 104)
        {
            printf("Enter Number of seats to cancel: ");
            scanf("%d", &cancel104);
            if (cancel104 != 0 && cancel104 <= no_seats104)
            {
                printf("\n \033[1,32mCancellation Successful ! %d seats canceled on Bus Number %d\033[0m\n", cancel104, bnum);
            }
            else
            {
                printf("\n \033[1,31mSorry, You have not booked that much seat !\033[0m\n");
            }
        }
        else if (bnum == 106)
        {
            printf("Enter Number of seats to cancel: ");
            scanf("%d", &cancel106);
            if (cancel106 != 0 && cancel106 <= no_seats106)
            {
                printf("\n \033[1,32mCancellation Successful ! %d seats canceled on Bus Number %d\033[0m\n", cancel106, bnum);
            }
            else
            {
                printf("\n \033[1,31mSorry, You have not booked that much seat !\033[0m\n");
            }
        }
        else if (bnum == 108)
        {
            printf("Enter Number of seats to cancel: ");
            scanf("%d", &cancel108);
            if (cancel108 != 0 && cancel108 <= no_seats108)
            {
                printf("\n \033[1,32mCancellation Successful ! %d seats canceled on Bus Number %d\033[0m\n", cancel108, bnum);
            }
            else
            {
                printf("\n \033[1,31mSorry, You have not booked that much seat !\033[0m\n");
            }
        }
        else
        {
            printf("\n \033[1,31mInvalid Bus Number !\033[0m");
            canceling_ticket();
        }
    }
    else if (choice_bus == 2)
    {
        printf("\nEnter Bus Number: ");
        scanf("%d", &bnum);
        if (bnum == 101)
        {
            printf("Enter Number of seats to cancel: ");
            scanf("%d", &cancel101);
            if (cancel101 != 0 && cancel101 <= no_seats101)
            {
                printf("\n \033[1,32mCancellation Successful ! %d seats canceled on Bus Number %d\033[0m\n", cancel101, bnum);
            }
            else
            {
                printf("\n \033[1,31mSorry, You have not booked that much seat !\033[0m\n");
            }
        }
        else if (bnum == 103)
        {
            printf("Enter Number of seats to cancel: ");
            scanf("%d", &cancel103);
            if (cancel103 != 0 && cancel103 <= no_seats103)
            {
                printf("\n \033[1,32mCancellation Successful ! %d seats canceled on Bus Number %d\033[0m\n", cancel103, bnum);
            }
            else
            {
                printf("\n \033[1,31mSorry, You have not booked that much seat !\033[0m\n");
            }
        }
        else if (bnum == 105)
        {
            printf("Enter Number of seats to cancel: ");
            scanf("%d", &cancel105);
            if (cancel105 != 0 && cancel105 <= no_seats105)
            {
                printf("\n \033[1,32mCancellation Successful ! %d seats canceled on Bus Number %d\033[0m\n", cancel105, bnum);
            }
            else
            {
                printf("\n \033[1,31mSorry, You have not booked that much seat !\033[0m\n");
            }
        }
        else if (bnum == 107)
        {
            printf("Enter Number of seats to cancel: ");
            scanf("%d", &cancel107);
            if (cancel107 != 0 && cancel107 <= no_seats107)
            {
                printf("\n \033[1,32mCancellation Successful ! %d seats canceled on Bus Number %d\033[0m\n", cancel107, bnum);
            }
            else
            {
                printf("\n \033[1,31mSorry, You have not booked that much seat !\033[0m\n");
            }
        }
        else
        {
            printf("\n \033[1,31mInvalid Bus Number !\033[0m");
            canceling_ticket();
        }
    }

    else
    {
        printf("\033[1;31mPlease Enter a valid Bus Number.\033[0m\n");
        printf("\n");
        canceling_ticket();
    }
}
void bus_status_ticket()
{
    printf("\nPlease enter Bus Number: ");
    scanf("%d", &bnum);
    if (bnum == 101)
    {
        printf("\033[1;34mBus Number:                 %d\033[0m", bnum);
        printf("\n\033[1;34mSource city:                Delhi\033[0m");
        printf("\n\033[1;34mDestination City:           Uttarakhand\033[0m");
        printf("\n\033[1;34mTotal Seats:                50\033[0m");
        printf("\n\033[1;34mAvailable Seats:            %d\033[0m", 50 - no_seats101 + cancel101);
        printf("\n\033[1;34mBooked Seats:               %d\033[0m", no_seats101 - cancel101);
        printf("\n\033[1;34mFare per person:            500.00\033[0m");
        printf("\n\033[1;34mYour total fare:            %d\033[0m", 500 * (no_seats101 - cancel101));
    }
    else if (bnum == 103)
    {
        printf("\033[1;34mBus Number:                 %d\033[0m", bnum);
        printf("\n\033[1;34mSource city:                Delhi\033[0m");
        printf("\n\033[1;34mDestination City:           Bihar\033[0m");
        printf("\n\033[1;34mTotal Seats:                50\033[0m");
        printf("\n\033[1;34mAvailable Seats:            %d\033[0m", 50 - no_seats103 + cancel103);
        printf("\n\033[1;34mBooked Seats:               %d\033[0m", no_seats103 - cancel103);
        printf("\n\033[1;34mFare per person:            500.00\033[0m");
        printf("\n\033[1;34mYour total fare:            %d\033[0m", 500 * (no_seats103 - cancel103));
    }
    else if (bnum == 105)
    {
        printf("\033[1;34mBus Number:                 %d\033[0m", bnum);
        printf("\n\033[1;34mSource city:                Delhi\033[0m");
        printf("\n\033[1;34mDestination City:           Haryana\033[0m");
        printf("\n\033[1;34mTotal Seats:                50\033[0m");
        printf("\n\033[1;34mAvailable Seats:            %d\033[0m", 50 - no_seats105 + cancel105);
        printf("\n\033[1;34mBooked Seats:               %d\033[0m", no_seats105 - cancel105);
        printf("\n\033[1;34mFare per person:            500.00\033[0m");
        printf("\n\033[1;34mYour total fare:            %d\033[0m", 500 * (no_seats105 - cancel105));
    }
    else if (bnum == 107)
    {
        printf("\033[1;34mBus Number:                 %d\033[0m", bnum);
        printf("\n\033[1;34mSource city:                Delhi\033[0m");
        printf("\n\033[1;34mDestination City:           Rsjasthan\033[0m");
        printf("\n\033[1;34mTotal Seats:                50\033[0m");
        printf("\n\033[1;34mAvailable Seats:            %d\033[0m", 50 - no_seats107 + cancel107);
        printf("\n\033[1;34mBooked Seats:               %d\033[0m", no_seats107 - cancel107);
        printf("\n\033[1;34mFare per person:            500.00\033[0m");
        printf("\n\033[1;34mYour total fare:            %d\033[0m", 500 * (no_seats107 - cancel107));
    }
    else if (bnum == 102)
    {
        printf("\033[1;34mBus Number:                 %d\033[0m", bnum);
        printf("\n\033[1;34mSource city:                Delhi\033[0m");
        printf("\n\033[1;34mDestination City:           Uttarakhand\033[0m");
        printf("\n\033[1;34mTotal Seats:                50\033[0m");
        printf("\n\033[1;34mAvailable Seats:            %d\033[0m", 50 - no_seats102 + cancel102);
        printf("\n\033[1;34mBooked Seats:               %d\033[0m", no_seats102 - cancel102);
        printf("\n\033[1;34mFare per person:            1000.00\033[0m");
        printf("\n\033[1;34mYour total fare:            %d\033[0m", 1000 * (no_seats102 - cancel102));
    }
    else if (bnum == 104)
    {
        printf("\033[1;34mBus Number:                 %d\033[0m", bnum);
        printf("\n\033[1;34mSource city:                Delhi\033[0m");
        printf("\n\033[1;34mDestination City:           Bihar\033[0m");
        printf("\n\033[1;34mTotal Seats:                50\033[0m");
        printf("\n\033[1;34mAvailable Seats:            %d\033[0m", 50 - no_seats104 + cancel104);
        printf("\n\033[1;34mBooked Seats:               %d\033[0m", no_seats104 - cancel104);
        printf("\n\033[1;34mFare per person:            1000.00\033[0m");
        printf("\n\033[1;34mYour total fare:            %d\033[0m", 1000 * (no_seats104 - cancel104));
    }
    else if (bnum == 106)
    {
        printf("\033[1;34mBus Number:                 %d\033[0m", bnum);
        printf("\n\033[1;34mSource city:                Delhi\033[0m");
        printf("\n\033[1;34mDestination City:           Harayana\033[0m");
        printf("\n\033[1;34mTotal Seats:                50\033[0m");
        printf("\n\033[1;34mAvailable Seats:            %d\033[0m", 50 - no_seats106 + cancel106);
        printf("\n\033[1;34mBooked Seats:               %d\033[0m", no_seats106 - cancel106);
        printf("\n\033[1;34mFare per person:            1000.00\033[0m");
        printf("\n\033[1;34mYour total fare:            %d\033[0m", 1000 * (no_seats106 - cancel106));
    }
    else if (bnum == 108)
    {
        printf("\033[1;34mBus Number:                 %d\033[0m", bnum);
        printf("\n\033[1;34mSource city:                Delhi\033[0m");
        printf("\n\033[1;34mDestination City:           Rajasthan\033[0m");
        printf("\n\033[1;34mTotal Seats:                50\033[0m");
        printf("\n\033[1;34mAvailable Seats:            %d\033[0m", 50 - no_seats108 + cancel108);
        printf("\n\033[1;34mBooked Seats:               %d\033[0m", no_seats108 - cancel108);
        printf("\n\033[1;34mFare per person:            500.00\033[0m");
        printf("\n\033[1;34mYour total fare:            %d\033[0m", 500 * (no_seats108 - cancel108));
    }
    else
    {
        printf("\n\033[1;34mInvalid Bus Number.\033[0m");
    }
}