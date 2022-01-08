/**
 project name: Movie Ticket Booking System
 Student name: Jubayer Al Mahmud
 ID Number   : 212902039
**/

#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include"decleration.c"

/**
int changeprize(int); (user define function)
void reservation(int *, int, int );
int choice1(void);
void cancel(int *);
void ticket1(int choice, char name[10], int id2, int price);
void ticket2(int choice, char name[10], int id2, int price);
void ticket3(int choice, char name[10], int id2, int price);
int cmovie(void);
int movie(void);
void details(void);
**/

#include"moviedetails.c"ssz

/**
struct moviedetails
{
    char name[25];
    char phone[15];
    int seat;
    int id;
};
**/

struct moviedetails person[300];
int count=0; // global variable, which is not constant
int id2 = 1000;

int main() // main function
{
    int **seat, choice, price=500, slection, i;
    seat=(int )calloc(101,sizeof(int));
    for (i=0; i<3; i++)
        *(seat+i)=(int *)calloc(101,sizeof(int ));
    int x;

    while(x!=5) //
    {
        choice = choice1();
        switch(choice)
        {
        case 1:
            price = changeprize(price);
            break;
        case 2:
            details();
            break;
        case 3:
            slection = movie();
            reservation(seat[slection-1],price,slection);
            count++;
            break;
        case 4:
            slection = cmovie();
            cancel(seat[slection-1]);
            break;
        case 5:
            x=5;
            break;
        default:
            printf("Choice not available\n");
            break;
        }
    }
}
int changeprize(int prize) //user define function
{
    char pass[10],pak[10]="pass";
    printf("\tEnter the password to change price of ticket: ");
    scanf("%s",&pass);
    if (strcmp(pass, pak)==0)
    {
        printf("\tPlease enter new price: ");
        scanf("%d",&prize);
        system("PAUSE");
        system("CLS");
    }
    else
        printf("\tThe entered password is wrong! ");
    return prize;
}
void reservation(int *array,int price,int slection)
{
    int i,j;
    printf("\n                                SCREEN\n\n\n");
    for (i=1; i<=100; i++)
    {
        if (array[i]==0)
            printf("%d\t",i);
        else
            printf("*\t",i);
        if(i%10==0)
            printf("\n\n");
    }
    printf("\tPlease enter your name: ");
    scanf(" %19[^\n]%*[^\n]",&person[count].name);
    printf("\tPlease enter your phone number: ");
    scanf("%u",&person[count].phone);
    printf("\tWhich seat number you want? ");
    scanf("%d",&j);
    if (j>100||j<1)
    {
        printf("\tseat1 number is unavailable in this theater\n");
        printf("\tPlease re-enter seat number: ");
        scanf("%d",&j);
    }
    if (array[j]==1)
    {
        printf("\t Sorry, this ticket is already booked! Please choose another seat.\n");
        scanf("%d",&j);
    }
    else
        array[j]=1;
    person[count].seat=j;
    if (slection==1)
        ticket1(j,person[count].name,id2,price);
    else if (slection==2)
        ticket2(j,person[count].name,id2,price);
    else
        ticket3(j,person[count].name,id2,price);
    id2++;
}
int choice1(void)
{
    int choice;
    printf("\n\t\t                       Movie Ticket Booking\n               ");
    printf("\n\t\t  ==================================================================\n");
    printf("\t\t ||             1. To edit price of ticket (only admin):           ||\n");
    printf("\t\t ||             2. To view reserved tickets (only admin):          ||\n");
    printf("\t\t ||             3. To puchase ticket:                              ||\n");
    printf("\t\t ||             4. To cancel the seat:                             ||\n");
    printf("\t\t ||             5. Exit system:                                    ||\n");
    printf("\t\t ||                                                                ||\n");
    printf(" \t\t  ==================================================================");
    printf("\n\n \t\t\t\t  Enter your choice: ");
    scanf("%d",&choice);

    return choice;
}
void cancel(int *array)
{
    int Cseat,i,stop;
    printf("Please enter ID number of ticket: ");
    scanf("%d",&Cseat);
    for (i=0; i<300; i++)
    {
        if(Cseat==person[i].id)
        {
            stop=5;
            system("cls");
            printf("%s your seat is %d cancelled",person[i].name,person[i].seat);
            array[person[i].seat]=0;
            i=300;
        }
    }
    if (stop!=5)
        printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
}
void ticket1(int choice,char name[10],int id2,int price)
{
    system("cls");
    printf("\n\n");
    printf("\t-----------------THEATER BOOKING TICKET----------------\n");
    printf("\t============================================================\n");
    printf("\t Booking ID : %d \t\t\tShow Name : Avengers: EndGame\n",id2);
    printf("\t Customer  : %s\n",name);
    printf("\t\t\t                              Date      : 29-04-2019\n");
    printf("\t                                              Time      : 08:00 pm\n");
    printf("\t                                              Hall      : 02\n");
    printf("\t                                              seats No. : %d  \n",choice);
    printf("\t                                              price .   : %d  \n\n",price);
    person[count].id=id2;
    printf("\t============================================================\n");
    return;
}
void details(void)
{
    int i;
    char pass[10],pak[10]="pass";
    printf("Enter the password to see details: ");
    scanf("%s",&pass);
    if (strcmp(pass,pak)==0)
    {
        for (i=0; i<count; i++)
        {
            printf("seat no: %d is booked by %s booking id is %d\n",person[i].seat,person[i].name,person[i].id);
        }
    }
    else
        printf("Entered password is wrong. Please try again.\nThank you\n");
    system("PAUSE");
    system("CLS");

}
int movie(void)
{
    int i;
    system("cls");
    printf("\t\t\t which movie you want to see?\n");
    printf("\t\t\t----------------------------\n\n");
    printf("\t\t\t press 1 for Avengers: EndGame\n\n");
    printf("\t\t\t press 2 for Captain Marvel\n\n");
    printf("\t\t\t press 3 for Spider-Man: Far From Home\n");
    scanf("%d",&i);
    system("cls");
    return i;
}
void ticket2(int choice,char name[10],int id2,int price)
{
    system("cls");
    printf("\n\n");
    printf("\t-----------------THEATER BOOKING TICKET----------------\n");
    printf("\t============================================================\n");
    printf("\t Booking ID : %d \t\t\tShow Name : Captain Marvel\n",id2);
    printf("\t Customer  : %s\n",name);
    printf("\t\t\t                              Date      : 15-04-2019\n");
    printf("\t                                              Time      : 09:00pm\n");
    printf("\t                                              Hall      : 03\n");
    printf("\t                                              seats No. : %d  \n",choice);
    printf("\t                                              price .   : %d  \n\n",price);
    person[count].id=id2;
    printf("\t============================================================\n");
    return;
}
int cmovie(void)
{
    int i;
    printf("\t\t\t which movie ticket you want to cancel\n");
    printf("\t\t\t-------------------------------------\n");
    printf("\t\t\t press 1 for Avengers: EndGame\n\n");
    printf("\t\t\t press 2 for Captain Marvel\n\n");
    printf("\t\t\t press 3 for Spider-Man: Far From Home\n");
    scanf("%d",&i);
    return i;
}
void ticket3(int choice,char name[10],int id2,int price)
{
    system("cls");
    printf("\n\n");
    printf("\t-----------------THEATER BOOKING TICKET----------------\n");
    printf("\t============================================================\n");
    printf("\t Booking ID : %d \t\t\tShow Name : Spider-Man: Far From Home \n",id2);
    printf("\t Customer  : %s\n",name);
    printf("\t\t\t                              Date      : 5-07-2019\n");
    printf("\t                                              Time      : 10:00pm\n");
    printf("\t                                              Hall      : 04\n");
    printf("\t                                              seats No. : %d  \n",choice);
    printf("\t                                              price . : %d  \n\n",price);
    person[count].id=id2;
    printf("\t============================================================\n");

    return;
}
