#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct subscriber
{
char phonenumber[20];
char name[50];
float amount;
}s;
struct customer
{
char bot[30];
char p[30];
}acc;
void addrecords();
void listrecords();
void modifyrecords();
void deleterecords();
void searchrecords();
void payment();
void existing();
void reg();
void main()
{
int password;
  int phonenumber;
  char log;
system("cls");
printf("\n\n\n\t\t     WELCOME TO OUR TELECOM BILLING SERVICE\n\n\n");
printf("  1 : EXISTING USER\n");
printf("  2 : NEW REGISTRATION\n");
log=getche();
system("cls");
switch(log)
{
case '1':
existing();
break;
case '2':
reg();
break;
default:
printf("\n\nChoose correct option");
getche();
}
}
void reg()
{
FILE *fp;
char done;
fp=fopen("Accounts.txt","a+");
if(fp==0)
{
fp=fopen("Accounts.txt","w+");
printf("\n\nPress ENTER to continue");
getche();
}
while(1)
{
printf("\n Enter Username: ");
scanf("%s",&acc.bot);
fflush(stdin);
printf("\n Enter Password: ");
gets(acc.p);
fwrite(&acc,sizeof(acc),1,fp);
fflush(stdin);
printf("Successfully Registered");
printf("\nPress esc to exit, any other key to register new user");
done=getche();
if(done==27)
{
main();
}
fclose(fp);
}
}
void existing()
{
FILE *fp;
char bot1[30],p1[30];
int rohan=1,r,v;
fp=fopen("Accounts.txt","r+");
if(fp!=0)
{
printf("\n\n\t\t\t\tPLEASE LOG IN");
printf("\n\n  Username: ");
scanf("%s",&bot1);
fflush(stdin);
printf("\n  Password: ");
scanf("%s",&p1);
fflush(stdin);
r=strlen(p1);
system("cls");
while(fread(&acc,sizeof(acc),1,fp)==1)
{
if(stricmp(acc.bot,bot1)==0)
{
if(strcmp(acc.p,p1)==0)
{
printf("\n\n\n  Username: %s",bot1);
printf("\n\n  Password: ");
for(v=0;v<r;v++)
{
printf("*");
}
printf("\n\n\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
rohan=0;
break;
}
}
else
{
continue;
}
}
if (rohan==1)
{
printf("\n\n\n\n\n\n\n\n\n\t\t\t\t USER NOT FOUND");
printf("\n\n\n\t\t\t\tPLEASE TRY AGAIN");
getche();
exit(0);
}
fclose(fp);
}
getche();
system("cls");
 printf("********************************************************************************");
  printf("\n\t\t---WELCOME TO THE TELECOM BILLING MANAGEMENT SYSTEM---");
  printf("\n********************************************************************************");


  while (1)
  {
    char choice;
    printf("\n ENTER:\n A : for adding new records.\n L : for list of records");
    printf("\n M : for modifying records.\n P : for payment");
    printf("\n S : for searching records.");
    printf("\n D : for deleting records.\n E : for exit\n");
    choice=getche();
    choice=toupper(choice);
    switch(choice)
    {
      case 'P':
	payment();break;
      case 'A':
	addrecords();break;
      case 'L':
	listrecords();break;
      case 'M':
	modifyrecords();break;
      case 'S':
	searchrecords();break;
      case 'D':
	deleterecords();break;
      case 'E':
	 system("cls");
	printf("\n\n\n\n\n\n\n\t\t\t\t  THANK YOU");
	printf("\n\n\n\n\n\t\t\t FOR USING OUR TELECOM SERVICE");
	getche();
	exit(0);
	break;
      default:

	printf("Incorrect Input");
	printf("\nAny key to continue");
	getche();
    }
  }
}
void addrecords()
{
  FILE *f;
  char test;
  f=fopen("Telecom.txt","a+");
  if(f==0)
  {   f=fopen("Telecom.txt","w+");

    printf("Please wait while we configure your computer\n");
    printf("/npress any key to continue");
    getche();
  }
  while(1)
  {

    printf("\n Enter phone number:");
    scanf("%s",&s.phonenumber);
    printf("\n Enter name:");
    fflush(stdin);
    scanf("%[^\n]",&s.name);
    printf("\n Enter amount:");
    scanf("%f",&s.amount);
    fwrite(&s,sizeof(s),1,f);
    fflush(stdin);
    printf("\n1 record successfully added");
    printf("\n Press esc key to exit, any other key to add other record:");
    test=getche();
    if(test==27)
      break;
  }
  fclose(f);
}
void listrecords()
{
  FILE *f;
  int i;
  if((f=fopen("Telecom.txt","r"))==NULL)
    exit(0);

  printf("Phone Number\t\tUser Name\t\t\tAmount\n");
  for(i=0;i<79;i++)
    printf("-");
  while(fread(&s,sizeof(s),1,f)==1)
  {
    printf("\n%-10s\t\t%-20s\t\tRs. %.2f /-",s.phonenumber,s.name,s.amount);
  }
  printf("\n");
  for(i=0;i<79;i++)
    printf("-");

fclose(f);
getche();
}
void deleterecords()
{
  FILE *f,*t;
  int i=1;
  char phonenumber[20];
  if((t=fopen("temp.txt","w+"))==NULL)
  {
  exit(0);
  }
  if((f=fopen("Telecom.txt","r"))==NULL)
  exit(0);

  printf("\nEnter the phone number to be deleted from the Database: \n");
  fflush(stdin);
  scanf("%s",phonenumber);
  while(fread(&s,sizeof(s),1,f)==1)
  {
    if(strcmp(s.phonenumber,phonenumber)==0)
    {       i=0;
      continue;

    }
    else
      fwrite(&s,sizeof(s),1,t);
  }
  if(i==1)
  {
    printf("Phone number %s not found",phonenumber);
    remove("Telecom.txt");
    rename("temp.txt","Telecom.txt");
    getche();
    fclose(f);
    fclose(t);
    main();
  }
  remove("Telecom.txt");
  rename("temp.txt","Telecom.txt");


  printf("\nThe Number %s Successfully Deleted!!!!",phonenumber);
  fclose(f);
  fclose(t);
  getche();
}
void searchrecords()
{
  FILE *f;
  char phonenumber[20];
  int flag=1;
  f=fopen("Telecom.txt","r+");
  if(f==0)
    exit(0);
  fflush(stdin);

  printf("\nEnter Phone Number to search in our database: \n");
  scanf("%s", phonenumber);
  while(fread(&s,sizeof(s),1,f)==1)
  {
    if(strcmp(s.phonenumber,phonenumber)==0)
    {
      printf("\nRecord Found: ");
      printf("\n\nPhonenumber: %s\nName: %s\nAmount: Rs.%0.2f\n",s.phonenumber,s.name,s.amount);
      flag=0;
      break;
    }
    else
    {
    continue;
    }
    }
    if(flag==1)
    {
      printf("\n\nRequested Phone Number Not found in our database");
    }
  getche();
  fclose(f);
}
void modifyrecords()
{
  FILE *f;
  char phonenumber[20];
  long int size=sizeof(s);
  if((f=fopen("Telecom.txt","r+"))==NULL)
    exit(0);

  printf("\nEnter phone number of the subscriber to modify:\n");
  scanf("%[^\n]",phonenumber);
  fflush(stdin);
  while(fread(&s,sizeof(s),1,f)==1)
  {
    if(strcmp(s.phonenumber,phonenumber)==0)
    {

      printf("\n Enter phone number:");
      scanf("%s",&s.phonenumber);
      printf("\n Enter name: ");
      fflush(stdin);
      scanf("%[^\n]",&s.name);
      printf("\n Enter amount: ");
      scanf("%f",&s.amount);
      fseek(f,-size,SEEK_CUR);
      fwrite(&s,sizeof(s),1,f);
      break;
    }
  }
  fclose(f);
}
void payment()
{
  FILE *f;
  char phonenumber[20];
  long int size=sizeof(s);
  float amt;
  int i;
  if((f=fopen("Telecom.txt","r+"))==NULL)
    exit(0);
  system("cls");
  printf("\nEnter phone number of the subscriber for payment: \n\n");
  scanf("%[^\n]",phonenumber);
  fflush(stdin);
  while(fread(&s,sizeof(s),1,f)==1)
  {
    if(strcmp(s.phonenumber,phonenumber)==0)
    {

      printf("\n Phone No.: %s",s.phonenumber);
      printf("\n Name: %s",s.name);
      printf("\n Current amount: %f",s.amount);
      printf("\n");
      for(i=0;i<79;i++)
	printf("-");
      printf("\n\nEnter amount of payment :");
      fflush(stdin);
      scanf(" %f",&amt);
      s.amount=s.amount-amt;
      fseek(f,-size,SEEK_CUR);
  getche();
      fwrite(&s,sizeof(s),1,f);
      break;
    }
  }
  printf("\nTHANK YOU %s FOR YOUR TIMELY PAYMENTS",s.name);
  fclose(f);
getch();
}