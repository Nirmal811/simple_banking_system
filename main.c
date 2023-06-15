//simple banking system
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
char name[30];
int dep_amt,amt=1000,acc_no,wd_amt;
void menu();
void deposit();
void withdraw();
void transfer();
void details_acc();
void details_tran();
void final_details();
void divider()
{
    for(int i=0 ; i < 50 ; i++)
    {
        printf("-");
    }
}
int main()
{
    int opt;
   printf("Enter your name: ");
   gets(name);

   printf("Enter your account no: ");
   scanf("%d",&acc_no);


   while(1)
   {
        menu();
   printf("Enter an option: ");
   scanf("%d",&opt);
   switch(opt)
   {
       case 1:
           system("cls");
            deposit();
            break;
       case 2:
           system("cls");
            withdraw();
            break;
       case 3:
           system("cls");
            transfer();
            break;
       case 4:
           system("cls");
            details_acc();
            break;
       case 5:
           system("cls");
            details_tran();
            break;
       case 6:
           system("cls");
            final_details();
            exit(0);
       default:
           system("cls");
        printf("\nInvalid choice!!!\n");


   }
   }

}

void menu()
{
    system("cls");
    printf("\n\t*********MAIN MENU*********\n");
    divider();
    printf("\n\t1.Deposit money\n");
    printf("\t2.Withdraw money\n");
    printf("\t3.Transfer money\n");
    printf("\t4.Account details\n");
    printf("\t5.Transaction details\n");
    printf("\t6.Exit\n");
}
void deposit()
{
    time_t tm;
    time(&tm);
    FILE *det = fopen("account.txt","a");
    printf("\n\t*********DEPOSITING MONEY*********\n");
    divider();
    printf("\n\tEnter the money: ");
    scanf("%d",&dep_amt);
    amt+=dep_amt;
    printf("\n\t*****MONEY DEPOSITED*****\n");
    fprintf(det,"Rs%d had been deposited \n",dep_amt);
    fprintf(det,"Date and time of transaction is %s \n",ctime(&tm));
    printf("\n\tCurrent Balance: %d\n",amt);
    fclose(det);
    printf("\nPress any key to continue...............\n");
    getch();
}
void withdraw()
{
    time_t tm;
    time(&tm);
    FILE *det = fopen("account.txt","a");
    printf("\n\t*********WITHDRAW MONEY*********\n");
    divider();
    printf("\n\tEnter the money: ");
    scanf("%d",&wd_amt);
    if(wd_amt>amt)
    {
        printf("\n\tYou have insufficient balance!!\n");
    }
    else
    {
     amt -= wd_amt;
    printf("\n\t*****MONEY WITHDRAWN*****\n");
    fprintf(det,"Rs%d had been withdrawn \n",wd_amt);
    fprintf(det,"Date and time of transaction is %s \n",ctime(&tm));
    printf("\n\tCurrent Balance: %d\n",amt);
    }
    fclose(det);
    printf("\nPress any key to continue...............\n");
    getch();

}
void transfer()
{
    int am,ac;
    time_t tm;
    time(&tm);
    FILE *det = fopen("account.txt","a");
    printf("\n\t*********TRANSFERRING MONEY*********\n");
    divider();
    printf("\n\tEnter the money: ");
    scanf("%d",&am);
    printf("\n\tEnter the account number to be transferred: ");
    scanf("%d",&ac);
    if(am>amt)
    {
        printf("\n\tYou have insufficient balance!!\n");
    }
    else
    {
        amt -= am;
        printf("\n\t*****MONEY TRANSFERRED*****\n");
        fprintf(det,"Rs%d had been transferred to the account %d \n",am,ac);
        fprintf(det,"Date and time of transaction is %s \n",ctime(&tm));
        printf("\n\tCurrent Balance: %d\n",amt);
    }
    fclose(det);
    printf("\nPress any key to continue...............\n");
    getch();
}
void details_acc()
{
    printf("\n*********ACCOUNT DETAILS*********\n");
    divider();
    printf("\n\tName = %s\n",name);
    printf("\tAccount number = %d\n",acc_no);
    printf("\tTotal Balance = %d\n",amt);
    printf("\nPress any key to continue.........");
    getch();
}
void details_tran()
{

    FILE *det=fopen("account.txt","r");
    char c=fgetc(det);
    if(c==EOF)
    {
        printf("\n\tNo recent transactions\n");
    }
    else
    {
        printf("\n\t*********TRANSACTION DETAILS*********\n");
        divider();
        printf("\n");
        while (c!=EOF)
        {
            printf("%c",c);
            c=fgetc(det);
        }

    }
    printf("\nPress any key to continue\n");
    getch();
}
void final_details()
{
    divider();
    printf("\n\tName: %s\n",name);
    printf("\tAccount number: %d\n",acc_no);
    printf("\tCurrent Balance: %d\n",amt);
    divider();
    printf("\nPress any key..........\n\n");
}
