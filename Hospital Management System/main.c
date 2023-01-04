/*
    Project Name : Hospital Management System
    Author Name  : Pranto Bapary
    Date         : December 24, 2022
*/

// Header Files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#define maxSize 10

// Global Variables
int valid = 0;
int len = 0;

// Structure
typedef struct patient
{
    int age;
    char gender;
    char first_name[20];
    char last_name[20];
    char address[30];
    char phone[15];
    char problem[50];
    char doctor[20];
} patient;

// Stack
int top = -1;
patient stack[maxSize];

// Functions
void title();
void inner_title();
void login();
void main_menu();
void add_record();
void view_record();
void search_record();
void update_record();
void delete_record();
void bubbleSort(patient stack[], int size);
int linearSearch(patient stack[], int size, char name[]);
void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
// Main Function
int main()
{
    system("COLOR 3");
    title();
    login();
    return 0;
}

// title function is used to display the name of the hospital
void title()
{
    printf("\n\t\t\t--------------------------------------\n");
    printf("\t\t\t       Welcome to Pran Hospital       \n");
    printf("\t\t\t--------------------------------------\n");
}

// inner_title function will display the name of the hospital in large size
void inner_title()
{
    printf("\n\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t                   Welcome to Pran Hospital       \n");
    printf("\t\t\t----------------------------------------------------------------\n");
}

// login function is Used to login into the main_menu function
void login()
{
    int pass_count = 0;
    int try_limit = 3;
    char username[20];
    char password[20];
    char original_username[20] = "Pranto";
    char original_password[20] = "1234";

    do
    {
        printf("\n\t\t\tEnter Your Username and Password\n\n\n");
        printf("\t\t\tEnter Your Username : ");
        gets(username);

        printf("\n\t\t\tEnter Your Password : ");
        gets(password);

        if (strcmp(username, original_username) == 0 && strcmp(password, original_password) == 0)
        {
            printf("\n\t\t\tLogin Successful");
            getch();
            system("cls");
            main_menu();
            break;
        }
        else
        {
            try_limit--;
            system("cls");
            inner_title();
            printf("\n\t\t\tIncorrect Username and Password. You Can Try %d more times \n\n", try_limit);
        }
        pass_count++;

    } while (pass_count <= 2);

    if (pass_count > 2)
    {
        printf("\n\t\t\tSorry You've crossed the limit. You cannot login.");
        getch();
    }
    else
    {
        main_menu();
    }
}

// main_menu function is used to display the services provided by the hospital
void main_menu()
{
    system("cls");
    title();
    int choice;

    printf("\n\t\t\t1. Add Patients Record\n\n");
    printf("\t\t\t2. View Patients Record\n\n");
    printf("\t\t\t3. Search Patients Record\n\n");
    printf("\t\t\t4. Update Patients Record\n\n");
    printf("\t\t\t5. Remove Patients Record\n\n");
    printf("\t\t\t6. Exit\n\n\n");

    printf("\t\t\tEnter Your Choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        add_record();
        break;

    case 2:
        view_record();
        break;

    case 3:
        search_record();
        break;

    case 4:
        update_record();
        break;

    case 5:
        delete_record();
        break;

    case 6:
        printf("\n\t\t\tThank You. Visit Us Next Time.");
        exit(1);
        break;

    default:
        printf("\n\n\t\t\tInvalid Input. Please Try Again");
        break;
    }
}

// add record is to add new patients record
void add_record()
{
    char add_more_record;
    system("cls");
    inner_title();

    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!Add Patient Records!!!!!!!!!!!!!!!!!!!!!!!\n");

    do
    {
        top++;
        printf("\n\t\t\tSerial No : %d\n", top + 1);
    A:
        fflush(stdin);
        printf("\n\t\t\tEnter Your First Name   : ");
        gets(stack[top].first_name);
        stack[top].first_name[0] = toupper(stack[top].first_name[0]);

        if (strlen(stack[top].first_name) > 20 || strlen(stack[top].first_name) < 4)
        {
            printf("\n\t\t\tName is too short or too long\n");
            goto A;
        }
        else
        {
            for (len = 0; len < strlen(stack[top].first_name); len++)
            {
                if (isalpha(stack[top].first_name[len]))
                    valid = 1;
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf("\n\t\t\tInvalid Name. Enter Correct Name\n");
                goto A;
            }
        }

    B:
        printf("\n\t\t\tEnter Your Last Name    : ");
        gets(stack[top].last_name);
        stack[top].last_name[0] = toupper(stack[top].last_name[0]);

        if (strlen(stack[top].last_name) > 20 || strlen(stack[top].last_name) < 4)
        {
            printf("\n\t\t\tName is too short or too long\n");
            goto B;
        }
        else
        {
            for (len = 0; len < strlen(stack[top].last_name); len++)
            {
                if (isalpha(stack[top].last_name[len]))
                    valid = 1;
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf("\n\t\t\tInvalid Name. Enter Correct Name\n");
                goto B;
            }
        }

        printf("\n\t\t\tEnter Your Gender (F/M) : ");
        scanf("%c", &stack[top].gender);

        stack[top].gender = toupper(stack[top].gender);
        fflush(stdin);

        printf("\n\t\t\tEnter Your Age          : ");
        scanf("%d", &stack[top].age);

        fflush(stdin);
        printf("\n\t\t\tEnter Your Phone Number : ");
        gets(stack[top].phone);

    C:
        printf("\n\t\t\tEnter Your Full Address : ");
        gets(stack[top].address);
        stack[top].address[0] = toupper(stack[top].address[0]);

        if (strlen(stack[top].address) > 30 || strlen(stack[top].address) < 5)
        {
            printf("\n\t\t\tAddress is too short or too long\n");
            goto C;
        }

        printf("\n\t\t\tEnter Your Problem      : ");
        gets(stack[top].problem);
        stack[top].problem[0] = toupper(stack[top].problem[0]);

    D:
        printf("\n\t\t\tEnter the Doctor You Want to Visit : ");
        gets(stack[top].doctor);
        stack[top].doctor[0] = toupper(stack[top].doctor[0]);

        if (strlen(stack[top].doctor) > 20 || strlen(stack[top].doctor) < 4)
        {
            printf("\n\t\t\tDoctor's Name is too short or too long\n");
            goto D;
        }

        printf("\n\n\t\t\t         Record Added Successfully\n");

        printf("\n\t\t\t Do You Want to Add More Records (Y/N) : ");
        scanf("%c", &add_more_record);

        add_more_record = toupper(add_more_record);
        fflush(stdin);

        if (top == maxSize - 1)
        {
            printf("\n\t\t\t   Sorry!!!Stack is Full!!!Can't Add!!\n");
            break;
        }

    } while (add_more_record != 'N');

    printf("\n\t\t\t   Thank You.Press Any Key to Continue ");
    getch();
    main_menu();
}
// view_record function is used to view the total patients record
void view_record()
{
    system("cls");
    inner_title();

    int row;
    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!!View Patient Records!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    if (top == -1)
    {
        printf("\n\t\t\t      Sorry!!!Stack is Empty!!!No Data Found to Show!!!\n");
        printf("\n\t\t\t   T          Thank You.Press Any Key to Continue ");
        getch();
        main_menu();
    }
    else
    {
        gotoxy(8, 8);
        printf("Full Name");

        gotoxy(23, 8);
        printf("Gender");

        gotoxy(33, 8);
        printf("Age");

        gotoxy(43, 8);
        printf("Phone");

        gotoxy(54, 8);
        printf("Full Address");

        gotoxy(71, 8);
        printf("Problem");

        gotoxy(85, 8);
        printf("Prescribed Doctor");

        printf("\n\t-----------------------------------------------------------------------------------------------\n");

        // bubble sort is used to sort the data in ascending way in terms of ages
        bubbleSort(stack, top + 1);
        row = 10;

        for (int i = 0; i <= top; i++)
        {
            gotoxy(8, row);
            printf("%s %s", stack[i].first_name, stack[i].last_name);

            gotoxy(25, row);
            printf("%c", stack[i].gender);

            gotoxy(33, row);
            printf("%d", stack[i].age);

            gotoxy(40, row);
            printf("%s", stack[i].phone);

            gotoxy(55, row);
            printf("%s", stack[i].address);

            gotoxy(73, row);
            printf("%s", stack[i].problem);

            gotoxy(90, row);
            printf("%s", stack[i].doctor);
            row++;
        }
    }

    printf("\n\n\t\t\t\tPress Any Key to Go Back to the Main Menu");
    getch();
    main_menu();
}

// search_record to search the records by name
void search_record()
{

    char first_name[20];
    char search_again;

    system("cls");
    inner_title();

    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!Search Patient Records!!!!!!!!!!!!!!!!!!!!!!!!\n");

    fflush(stdin);
    printf("\n\n\t\t\tEnter the First Name of the Patient : ");
    gets(first_name);

    first_name[0] = toupper(first_name[0]);
    int index = linearSearch(stack, top + 1, first_name);

    if (index == -1)
    {
        printf("\n\n\t\t\t\t   Sorry!!!Record Not Found!\n");
        goto check_more;
    }

    else
    {
        gotoxy(8, 11);
        printf("Full Name");

        gotoxy(23, 11);
        printf("Gender");

        gotoxy(33, 11);
        printf("Age");

        gotoxy(43, 11);
        printf("Phone");

        gotoxy(54, 11);
        printf("Full Address");

        gotoxy(71, 11);
        printf("Problem");

        gotoxy(85, 11);
        printf("Prescribed Doctor");

        printf("\n\t-----------------------------------------------------------------------------------------------\n");

        gotoxy(8, 13);
        printf("%s %s", stack[index].first_name, stack[index].last_name);

        gotoxy(25, 13);
        printf("%c", stack[index].gender);

        gotoxy(33, 13);
        printf("%d", stack[index].age);

        gotoxy(40, 13);
        printf("%s", stack[index].phone);

        gotoxy(55, 13);
        printf("%s", stack[index].address);

        gotoxy(73, 13);
        printf("%s", stack[index].problem);

        gotoxy(90, 13);
        printf("%s", stack[index].doctor);
    }

check_more:

    fflush(stdin);
    printf("\n\n\t\t\tDo You Want to Search More [Y/N] ? ");
    scanf("%c", &search_again);

    if (toupper(search_again) == 'Y')
        search_record();

    else if (toupper(search_again) == 'N')
    {
        printf("\n\n\t\t\t             !!!Thank You!!!");
        printf("\n\n\t\t\tPress Any Key to Go Back to the Main Menu");
        getch();
        main_menu();
    }

    else
    {
        printf("\n\n\t\t\t    Invalid Choice.Please Try Agaain");
        goto check_more;
    }
}

// update_record function to update the existing data
void update_record()
{
    system("cls");
    inner_title();
    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!Update Patients Record!!!!!!!!!!!!!!!!!!!!!!!!\n");

    char first_name[20];
    char ch;

    fflush(stdin);
    printf("\n\t\t\tEnter the First Name of the Patient : ");
    gets(first_name);

    first_name[0] = toupper(first_name[0]);
    int index = linearSearch(stack, top + 1, first_name);

    printf("\n\t\t\t         !!!!!!!!!!!!!!!Existing Records!!!!!!!!!!!!!!!!\n\n\n");

    if (index == -1)
    {
        printf("\n\n\t\t\t\t           Sorry!!!Record Not Found!\n");
        getch();
        main_menu();
    }
    else
    {
        gotoxy(8, 11);
        printf("Full Name");

        gotoxy(23, 11);
        printf("Gender");

        gotoxy(33, 11);
        printf("Age");

        gotoxy(43, 11);
        printf("Phone");

        gotoxy(54, 11);
        printf("Full Address");

        gotoxy(71, 11);
        printf("Problem");

        gotoxy(85, 11);
        printf("Prescribed Doctor");

        printf("\n\t-----------------------------------------------------------------------------------------------\n");

        gotoxy(8, 13);
        printf("%s %s", stack[index].first_name, stack[index].last_name);

        gotoxy(25, 13);
        printf("%c", stack[index].gender);

        gotoxy(33, 13);
        printf("%d", stack[index].age);

        gotoxy(40, 13);
        printf("%s", stack[index].phone);

        gotoxy(55, 13);
        printf("%s", stack[index].address);

        gotoxy(73, 13);
        printf("%s", stack[index].problem);

        gotoxy(90, 13);
        printf("%s", stack[index].doctor);
    }

    fflush(stdin);
    printf("\n\n\t\t\tEnter Your New First Name   : ");
    gets(stack[index].first_name);
    stack[index].first_name[0] = toupper(stack[index].first_name[0]);

    fflush(stdin);
    printf("\n\t\t\tEnter Your New Last Name    : ");
    gets(stack[index].last_name);
    stack[index].last_name[0] = toupper(stack[index].last_name[0]);

    printf("\n\t\t\tEnter Your Gender (F/M)     : ");
    scanf("%c", &stack[index].gender);

    stack[index].gender = toupper(stack[index].gender);
    fflush(stdin);

    printf("\n\t\t\tEnter Your Age              : ");
    scanf("%d", &stack[index].age);

    fflush(stdin);
    printf("\n\t\t\tEnter Your Phone Number     : ");
    gets(stack[index].phone);

    printf("\n\t\t\tEnter Your Full Address     : ");
    gets(stack[index].address);
    stack[index].address[0] = toupper(stack[index].address[0]);

    printf("\n\t\t\tEnter Your Problem          : ");
    gets(stack[index].problem);
    stack[index].problem[0] = toupper(stack[index].problem[0]);

    printf("\n\t\t\tEnter the Doctor You Want to Visit : ");
    gets(stack[index].doctor);
    stack[index].doctor[0] = toupper(stack[index].doctor[0]);

    printf("\n\n\t\t\t         Record Updated Successfully\n");
    printf("\n\t\t\tPress Any Key to Go Back to the Main Menu");

    getch();
    main_menu();
}

// delete record is to delete the last records
void delete_record()
{
    system("cls");
    inner_title();
    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!Remove Patients Record!!!!!!!!!!!!!!!!!!!!!!!!\n\n");

    int row;
    char ch;
    printf("\n\t\t\t         !!!!!!!!!!!!!!!Existing Records!!!!!!!!!!!!!!!!\n");

    if (top == -1)
    {
        printf("\n\t\t\t           Sorry!!!Stack is Empty!!!Nothing to Delete!\n");
        printf("\n\t\t\t                Thank You.Press Any Key to Continue ");
        getch();
        main_menu();
    }
    else
    {
        gotoxy(8, 10);
        printf("Full Name");

        gotoxy(23, 10);
        printf("Gender");

        gotoxy(33, 10);
        printf("Age");

        gotoxy(43, 10);
        printf("Phone");

        gotoxy(54, 10);
        printf("Full Address");

        gotoxy(71, 10);
        printf("Problem");

        gotoxy(85, 10);
        printf("Prescribed Doctor");

        printf("\n\t-----------------------------------------------------------------------------------------------\n");

        row = 12;
        for (int i = top; i >= 0; i--)
        {
            gotoxy(8, row);
            printf("%s %s", stack[i].first_name, stack[i].last_name);

            gotoxy(25, row);
            printf("%c", stack[i].gender);

            gotoxy(33, row);
            printf("%d", stack[i].age);

            gotoxy(40, row);
            printf("%s", stack[i].phone);

            gotoxy(55, row);
            printf("%s", stack[i].address);

            gotoxy(73, row);
            printf("%s", stack[i].problem);

            gotoxy(90, row);
            printf("%s", stack[i].doctor);
            row++;
        }

        printf("\n\n\t\t\t              Press 'R' to Release a Patient : ");
        ch = getche();

        if (toupper(ch) == 'R')
        {
            top--;
            printf("\n\n\t\t\t                 Record Removed Successfully\n");
        }
    }

    printf("\n\t\t\t          Press Any Key to Go Back to the Main Menu");
    getch();
    main_menu();
}

// bubbleSort for sorting the data by age
void bubbleSort(patient stack[], int size)
{
    patient temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (stack[j].age > stack[j + 1].age)
            {
                temp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = temp;
            }
        }
    }
}

// linearSearch for searching the data by name
int linearSearch(patient stack[], int size, char name[])
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(stack[i].first_name, name) == 0)
            return i;
    }
    return -1;
}