/*movie ticket booking*/
#include <stdio.h>
#include <stdlib.h>

struct book
{
  char code[20];
  char name[20];
  char date[20];
  int cost;
}b;
int seat =60;
void insert_details();
void viewall();
void find();
void book_ticket();
void old_record();

void main()
{
int ch;
do
 {
  printf("\n==========================================================");
  printf("\n");
  printf("\t movie ticket booking");
  printf("\n==========================================================");
  printf("\n press<1> insert movie");
  printf("\n press<2> view all movie");
  printf("\n press<3> find movie");
  printf("\n press<4> book ticket");
  printf("\n press<5> view all transactions");
  printf("\n press<0> exit");

  printf("enter your choice:-");
  scanf("%d",&ch);

  switch (ch)
  {
   case 1:
   insert_details();
   break;
   case 2:
   viewall();
   break;
   case 3:
   find();
   break;
   case 4:
   book_ticket();
   break;
   case 5:
   old_record();
   break;
   case 0:
   exit(0);
   break;
   defult:
   printf("entered wrong choice");
   break;
  }
 }while(ch!=0);
}

void insert_details()
{
FILE *fp;
struct book b;
printf("enter movie code:");
scanf("%s",b.code);
printf("enter the name:");
scanf("%s",b.name);
printf("enter the relice date");
scanf("%s",b.date);
printf("enter ticket price:");
scanf("%d",&b.cost);

fp=fopen("data.txt","a");

if(fp==NULL)
 {
 printf("file not found");
 }
else
 {
 fprintf(fp,"%s%s%s%d\n",b.code,b.name,b.date,b.cost);
 printf("record inserted successfully");
 }
printf("\n");
fclose(fp);
}

void find()
{
struct book b;
FILE*fp;

char ch[20];
printf(" Enter movie code:");
scanf("%s",ch);
//system("clear");
fp=fopen("data.txt","r");
if(fp==NULL)
 {
	printf("file does not found !");
	exit(1);
 }
else
 {
	while(getc(fp)!=EOF)
  {
	  fscanf(fp,"%s%s%s%d",b.code,b.name,b.date,&b.cost);
	  if(strcmp(b.code,ch)==0)
	  {
	   //printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
	   printf("\nrecord found\n");
	   printf("\n\t\tcode::%s",b.code);
	   printf("\n\t\tmovie name::%s",b.name);
	   printf("\n\t\tmovie date::%s",b.date);
	   printf("\n\t\tprice of ticket::%d",b.cost);
	  }
  }
 }
 fclose(fp);
}
void viewall()
{
char ch;
FILE *fp;
fp=fopen("data.txt","r");
if(fp==NULL)
 {
  printf("file does not found!");
  exit(1);
 }
else
 {
  system("clear");
  while((ch=fgetc(fp))!=EOF)
  printf("%c",ch);
 }
fclose(fp);
}

//for ticket booking
void book_ticket()
{
struct book b;
FILE *fp;
FILE *ufp;
int total_seat,mobile,total_amount;
char name[20];
char ch;//used in sidplay all movies
char movie_code[20];//for searching
//display all movies by default for movie code
fp=fopen("data.txt","r");
if(fp==NULL)
 {
 printf("files does not found");
 exit(1);
 }
else
 {
 system (" clear");
 while((ch=fgetc(fp))!=EOF)
 printf("%c",ch);
 }
 fclose(fp);

 //display ends
printf("\nbook ticket choose movie(1st movie code next movie name)\n");
printf("\nenter the movie code:");
scanf("%s",movie_code);
//system ("clear");
fp=fopen("data.txt","r");
if(fp==NULL)
 {
  printf("file does not found");
  exit(1);
 }
else
 {
  while(getc(fp)!=EOF)
  {
   fscanf(fp,"%s%s%s%d",b.code,b.name,b.date,&b.cost);
   if(strcmp(b.code,movie_code)==0)
   {
   //printf("%s/%s/s/%d\n",b.code,b.name,b.date,b.cost);
   printf("\n Record Found\n");
   printf("\n\t\tCode::%s",b.code);
   printf("\n\t\tMovie nane::%s",b.name);
   printf("\n\t\tdate name::%s",b.date);
   printf("\n\t\tPrice of Ticket::%d",b.cost);
   }
  }
 }
   printf("\n*Fill Details*");
   printf("\n your name:");
   scanf("%s",name);
   printf("\n mobile number:");
   scanf("%d",&mobile);
   printf("\n Total number of tickets:");
   scanf("%d",&total_seat);

   total_amount=b.cost*total_seat;
   printf("\n ENJOY MOVIE\N");
   printf("n\t\tname:%s",name);
   printf("\n\t\tmobile Number:%d",mobile);
   printf("\n\t\tmovie name:%s",b.name);
   printf("\n\t\tTotal seats:%d",total_seat);
   printf("\n\t\tcost per ticket:%d",b.cost);
   printf("\n\t\tTotal Amount:%d",total_amount);

   ufp=fopen("oldTransaction.txt","a");
   if(ufp==NULL)
   {
   printf("File not found");
   }
   else
   {
   fprintf(ufp,"%s%d%d%d%s%d\n",name,mobile,total_seat,total_amount,b.name,b.cost);
   printf("\n Record insert sucessfull to the old record file");
   }
   printf("\n");
   fclose(ufp);

   fclose(fp);
}
   //for view all user transactions
void old_record()
   {
   char ch;
   FILE*fp;
   //system("clear");
   fp=fopen("old Transaction.txt","r");
   if(fp==NULL)
   {
   printf("file does not found!");
   exit(1);
   }
   else
   {
   system("clear");
   while((ch=fgetc(fp))!=EOF)
   printf("%c",ch);
   }
   fclose(fp);
}
