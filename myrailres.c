#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"myrailres.h"
#include"conio2.h"
#include<errno.h>



void screen_background()
{
    int i;
    clrscr();


    textcolor(CYAN);
    for(i=0;i<120;i++)
    {
        printf("*");
    }
    for(i=0;i<120;i++)
    {
        printf("*");
    }

    gotoxy(50,3);
    textcolor(WHITE);
    printf("RAILWAY RESERVATION SYSTEM\n");

    textcolor(CYAN);
     for(i=0;i<120;i++)
    {
        printf("*");
    }
    for(i=0;i<120;i++)
    {
        printf("*");
    }

      gotoxy(90,29);
      textcolor(LIGHTMAGENTA);
      printf("WITH LOVE -$@nd@rbh1910");
      textcolor(WHITE);



}



int passenger_menu()
{
    int ch,i;
    clrscr();
    screen_background();


    gotoxy(55,8);
    textcolor(YELLOW);
    printf("CUSTOMER SERVICES\n");
    for(i=0;i<120;i++)
    {
        printf("-");
    }

    gotoxy(55,10);
    textcolor(GREEN);
    printf("1-VIEW TRAIN CHART");

    gotoxy(55,11);
    printf("2-BOOK TICKET");

    gotoxy(55,12);
    printf("3-VIEW BOOKING");

    gotoxy(55,13);
    printf("4-SEARCH BOOKING VIA MOBILE.NO");

    gotoxy(55,14);
    printf("5-CANCEL TICKET");

    gotoxy(110,6);
    textcolor(LIGHTRED);
    printf("0-TO EXIT");

    textcolor(WHITE);
    gotoxy(55,15);
    printf("ENTER CHOICE : ");
    fflush(stdin);
    scanf("%d",&ch);
    return ch;
}



int admin_menu()
{
    int ch,i;
    clrscr();
    screen_background();


    gotoxy(55,8);
    textcolor(YELLOW);
    printf("ADMIN SERVICES\n");
    for(i=0;i<120;i++)
    {
        printf("-");
    }

    textcolor(GREEN);
    gotoxy(55,10);
    printf("1-PREPARE TRAIN CHART");

    gotoxy(55,11);
    printf("2-ADD TRAINS");

    gotoxy(55,12);
    printf("3-VIEW TRAIN CHART");

    gotoxy(55,13);
    printf("4-BOOK TICKET");

    gotoxy(55,14);
    printf("5-VIEW BOOKED TICKET DETAILS");

    gotoxy(55,15);
    printf("6-VIEW TRAIN BOOKINGS");

    gotoxy(55,16);
    printf("7-SEARCH BOOKINGS VIA MOBILE.NO");

    gotoxy(55,17);
    printf("8-VIEW ALL BOOKINGS FOR THE DAY");

    gotoxy(55,18);
    printf("9-CANCEL TICKET");

    gotoxy(55,19);
    printf("10-CANCEL TRAIN");

    gotoxy(55,20);
    printf("11-SHUTDOWN ");


    gotoxy(110,6);
    textcolor(LIGHTRED);
    printf("0-TO LOGOUT");

    textcolor(WHITE);
    gotoxy(55,21);
    printf("ENTER CHOICE : ");
    fflush(stdin);
    scanf("%d",&ch);
    return ch;
}



void view_train_chart()
{
    clrscr();
    int size;
    FILE*fp=fopen("trainchart.dat","rb");
    if(fp==NULL)
    {
        textcolor(RED);
        gotoxy(50,25);
        printf("CHART NOT PREPARED YET");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return;
    }

    Train T;
    int i,row=12;
    screen_background();


    gotoxy(58,8);
    textcolor(YELLOW);
    printf("TRAIN CHART\n");
    textcolor(WHITE);
    for(i=0;i<120;i++)
    {
        printf("-");
    }

    textcolor(YELLOW);
    gotoxy(3,10);
    printf("TRAIN.NO");

    gotoxy(22,10);
    printf("SOURCE");

    gotoxy(41,10);
    printf("DESTINATION");

    gotoxy(60,10);
    printf("FIRST A.C FARE");

    gotoxy(79,10);
    printf("SECOND A.C FARE");

    gotoxy(98,10);
    printf("DISTANCE");

    gotoxy(108,10);
    printf("DEPARTURE\n");


    textcolor(WHITE);
    for(i=0;i<120;i++)
    {
        printf("-");
    }
    fseek(fp,0,SEEK_END);
    size=ftell(fp);
    rewind(fp);
    for(i=0;i<size/sizeof(Train);i++)
    {

        fread(&T,sizeof(Train),1,fp);
        gotoxy(3,row);
        fprintf(stdout,"%s",T.train_no);

        gotoxy(22,row);
        fprintf(stdout,"%.10s",T.from);

        gotoxy(41,row);
        fprintf(stdout,"%.10s",T.to);


        gotoxy(60,row);
        printf("INR %.5d",T.fac_fare);

        gotoxy(79,row);
        printf("INR %.5d",T.sac_fare);

        gotoxy(98,row);
        printf("%.5d KMS",T.distance);

        gotoxy(108,row);
        printf("%.2f HRS",T.time);

        row++;


    }

     gotoxy(50,28);
     printf("PRESS ANY KEY TO CONTINUE");
     getch();
     fclose(fp);
    return;


}



void prepare_chart()
{
    clrscr();
    screen_background();
    char ch;

    FILE*fp=fopen("trainchart.dat","wb");
     if(fp==NULL)
     {
         textcolor(RED);
        gotoxy(50,25);
        printf("ERROR!!!COULD NOT PREPARE CHART");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return;
     }


     Train T;


     do
     {
         int repeat;
         clrscr();
         screen_background();


         textcolor(WHITE);
         gotoxy(50,10);
         printf("ENTER TRAIN.NO : ");
         while(1)
         {
             fflush(stdin);
             fscanf(stdin,"%s",T.train_no);
             strcpy(T.train_no,strupr(T.train_no));
             repeat=check_train_no_repetition(T.train_no);

             if(repeat==1)
             {
                 continue;
                 gotoxy(45,25);
                 textcolor(RED);
                 printf("TRAIN.NO ALREADY IN USE.TRY OTHER ONE");
                 gotoxy(67,10);
                 printf("\t\t\t\t\t\t");
                 gotoxy(67,10);
                 textcolor(WHITE);

             }

             if(repeat==0)
             {
                 break;
             }
         }

         if(strcmp(T.train_no,"0")==0)
         {
             return;
         }

         gotoxy(50,25);
         printf("\t\t\t\t\t\t\t\t\t\t");


         gotoxy(50,11);
         printf("ENTER SOURCE STATION : ");
         fflush(stdin);
         fscanf(stdin,"%s",T.from);
         strcpy(T.from,strupr(T.from));

          if(strcmp(T.from,"0")==0)
         {
             return;
         }

         gotoxy(50,12);
         printf("ENTER DESTINATION STATION : ");
         fflush(stdin);
         fscanf(stdin,"%s",T.to);
         strcpy(T.to,strupr(T.to));

          if(strcmp(T.to,"0")==0)
         {
             return;
         }

         gotoxy(50,13);
         printf("ENTER FIRST A.C FARE : ");
         fflush(stdin);
         fscanf(stdin,"%d",&T.fac_fare);

          if(T.fac_fare==0)
         {
             return;
         }

         gotoxy(50,14);
         printf("ENTER SECOND A.C FARE : ");
         fflush(stdin);
         fscanf(stdin,"%d",&T.sac_fare);

          if(T.sac_fare==0)
         {
             return;
         }

         gotoxy(50,15);
         printf("ENTER DISTANCE (IN KM) : ");
         fflush(stdin);
         fscanf(stdin,"%d",&T.distance);

          if(T.distance==0)
         {
             return;
         }

         gotoxy(50,16);
         printf("ENTER DEPATURE TIME FROM SOURCE (IN 24-HOUR FORMAT ) : ");
         fflush(stdin);
         fscanf(stdin,"%f",&T.time);

          if(T.time==0)
         {
             return;
         }


         fwrite(&T,sizeof(Train),1,fp);


         gotoxy(50,17);
         printf("DO YOU WANT TO MAKE MORE ENTERIES? (Y/N) : ");
         fflush(stdin);
         scanf("%c",&ch);

         }while(ch=='y'||ch=='Y');


         getch();

fclose(fp);
}


int user_type()
{
    int ch,i;
    clrscr();
    screen_background();

    printf("\n");


    gotoxy(59,10);
    textcolor(YELLOW);
    printf("USER MENU\n");

    for(i=0;i<120;i++)
        printf("-");
     gotoxy(57,12);
     textcolor(WHITE);
     printf("SELECT USER TYPE");

     textcolor(YELLOW);
     gotoxy(30,16);
     printf("1-CUSTOMER");
     gotoxy(90,16);
     printf("2-ADMIN");
     gotoxy(100,9);
     textcolor(LIGHTRED);
     printf("PRESS 0 TO EXIT");

     textcolor(WHITE);
     gotoxy(59,17);
     printf("ENTER CHOICE : ");
     scanf("%d",&ch);
     return ch;

}


void addtrains()
{
    char ch;
    clrscr();
    FILE*fp=fopen("trainchart.dat","ab");
    if(fp==NULL)
    {
        gotoxy(50,25);
        textcolor(LIGHTRED);
        printf("ERROR!!! CANNOT CONNECT TO RESOURCE FILE");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return;
    }

    Train T;

     do
     {
         int repeat;
         clrscr();
         screen_background();


         textcolor(WHITE);
         gotoxy(50,10);
         printf("ENTER TRAIN.NO : ");
          while(1)
         {
             fflush(stdin);
             fscanf(stdin,"%s",T.train_no);
             strcpy(T.train_no,strupr(T.train_no));
             repeat=check_train_no_repetition(T.train_no);

             if(repeat==1)
             {

                 gotoxy(45,25);
                 textcolor(RED);
                 printf("TRAIN.NO ALREADY IN USE.TRY OTHER ONE");
                 gotoxy(67,10);
                 printf("\t\t\t\t\t\t");
                 gotoxy(67,10);
                 textcolor(WHITE);
                 continue;

             }

             if(repeat==0)
             {
                 break;
             }
         }

         gotoxy(45,25);
         printf("\t\t\t\t\t\t\t\t\t\t");


          if(strcmp(T.train_no,"0")==0)
         {
             return;
         }

         gotoxy(50,11);
         printf("ENTER SOURCE STATION : ");
         fflush(stdin);
         fscanf(stdin,"%s",T.from);
         strcpy(T.from,strupr(T.from));

          if(strcmp(T.from,"0")==0)
         {
             return;
         }

         gotoxy(50,12);
         printf("ENTER DESTINATION STATION : ");
         fflush(stdin);
         fscanf(stdin,"%s",T.to);
         strcpy(T.to,strupr(T.to));

          if(strcmp(T.to,"0")==0)
         {
             return;
         }

         gotoxy(50,13);
         printf("ENTER FIRST A.C FARE : ");
         fflush(stdin);
         fscanf(stdin,"%d",&T.fac_fare);

          if(T.fac_fare==0)
         {
             return;
         }

         gotoxy(50,14);
         printf("ENTER SECOND A.C FARE : ");
         fflush(stdin);
         fscanf(stdin,"%d",&T.sac_fare);

          if(T.sac_fare==0)
         {
             return;
         }

         gotoxy(50,15);
         printf("ENTER DISTANCE (IN KM) : ");
         fflush(stdin);
         fscanf(stdin,"%d",&T.distance);

          if(T.distance==0)
         {
             return;
         }

         gotoxy(50,16);
         printf("ENTER DEPATURE TIME FROM SOURCE (IN 24-HOUR FORMAT) : ");
         fflush(stdin);
         fscanf(stdin,"%f",&T.time);

          if(T.time==0)
         {
             return;
         }


         fwrite(&T,sizeof(Train),1,fp);

         gotoxy(50,17);
         printf("DO YOU WANT TO MAKE MORE ENTERIES? (Y/N) : ");
         fflush(stdin);
         scanf("%c",&ch);

         }while(ch=='y'||ch=='Y');

fclose(fp);
}





int access_control()
{
    int ch,i;
    clrscr();
    screen_background();

    printf("\n");


    gotoxy(59,10);
    textcolor(LIGHTBLUE);
    printf("WELCOME ADMIN\n");

     textcolor(YELLOW);
    for(i=0;i<120;i++)
        printf("-");
     gotoxy(47,12);
     textcolor(WHITE);
     printf("HOW WOULD YOU LIKE TO MOVE FURTHER?");

     textcolor(YELLOW);
     gotoxy(30,16);
     printf("1-LOGIN");
     gotoxy(90,16);
     printf("2-SIGN-UP");
     gotoxy(100,9);
     textcolor(LIGHTRED);
     printf("PRESS 0 TO EXIT");

     textcolor(WHITE);
     gotoxy(59,17);
     printf("ENTER CHOICE : ");
     scanf("%d",&ch);
     return ch;



}




void sign_up()
{

Admin A;
char trypassword[11],ac[11],chance;
const char accesscode[11]={"sandarbh"};
    int i;

     FILE*fp=fopen("admindetails.dat","ab+");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(30,25);
        printf("SORRY CANNOT CONNECT TO RESOURCE FILE AT THE MOMENT TRY AGAIN LATER.INCONVINIENCE IS REGRETTED");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return;
    }


    do
    {

    clrscr();
    screen_background();

    gotoxy(60,8);
    textcolor(YELLOW);
    printf("SIGN-UP\n");

    for(i=0;i<120;i++)
    {
        printf("*");
    }





    gotoxy(100,6);
    textcolor(LIGHTRED);
    printf("PRESS 0 TO EXIT");


    gotoxy(50,11);
    textcolor(WHITE);
    printf("CREATE YOUR LOGIN CREDENTIALS");

    gotoxy(50,13);
    printf("ENTER YOUR FULL NAME : ");
    fflush(stdin);
    fscanf(stdin,"%s",A.name);
    strcpy(A.name,strupr(A.name));

    if(strcmp(A.name,"0")==0)
        return;

    gotoxy(50,14);
    printf("ENTER YOUR EMAIL ID : ");
    fflush(stdin);
    fscanf(stdin,"%s",A.email_id);
    if(strcmp(A.email_id,"0")==0)
        return;

    while(1)
    {
        gotoxy(50,15);
    printf("ENTER YOUR AGE(IN YRS) : ");
    fflush(stdin);
    fscanf(stdin,"%d",&A.age);
    if(A.age==0)
        {
            return;
        }

        if(A.age<70)
        {
        break;
        }

        else
            {
                gotoxy(75,15);
        printf("   ");
        gotoxy(40,28);
        textcolor(LIGHTRED);
        printf("ERROR!!! INVALID INPUT .AGE SHOULD BE LESS THAN 70.TRY AGAIN ");

        textcolor(WHITE);
            }
    }


        gotoxy(40,28);
        printf("\t\t\t\t\t\t\t\t\t\t\t");


    while(1)
    {
        gotoxy(50,16);
    printf("ENTER YOUR GENDER (M/F/T) : ");
    fflush(stdin);
    fscanf(stdin,"%c",&A.gender);
    if(A.gender=='0')
        return;

    if(A.gender=='m'||A.gender=='M'||A.gender=='f'||A.gender=='F'||A.gender=='t'||A.gender=='T')
    {
        if(A.gender>97)
         A.gender=A.gender-32;

        break;


    }
    else
    {
        gotoxy(78,16);
        printf("   ");
        gotoxy(40,28);
        textcolor(LIGHTRED);
        printf("ERROR!!! INVALID INPUT .GENDER CAN BE M/F/T ONLY.TRY AGAIN ");

        textcolor(WHITE);
    }

    }

        gotoxy(40,28);
        printf("\t\t\t\t\t\t\t\t\t\t\t");
   while(1)
   {
        gotoxy(50,17);
    printf("ENTER YOUR MOBILE.NO (10-DIGIT) : ");
    fflush(stdin);
    fscanf(stdin,"%s",A.mob);
    if(strcmp(A.mob,"0")==0)
        return;

        if(strlen(A.mob)!=10)
           {
               gotoxy(45,28);
               textcolor(RED);
               printf("ERROR!!!INVALID MOBILE.NO (10 DIGITS ONLY)");
               gotoxy(84,17);
               printf("\t\t\t\t\t");
               gotoxy(84,17);
               textcolor(WHITE);
               continue;
           }

        else if(strlen(A.mob)==10)
            break;
   }

   gotoxy(45,28);
   printf("\t\t\t\t\t\t\t");

    gotoxy(50,18);
    printf("ENTER ACCESS CODE : ");
    fflush(stdin);
    for(i=0;i<strlen(accesscode);i++)
    {
        fflush(stdin);
        ac[i]=getch();
        printf("*");
    }
    if(strcmp(ac,"0")==0)
        return;

    gotoxy(50,19);
    printf("ENTER YOUR PASSWORD (10-DIGIT MAX,NO SPACES) : ");
    fflush(stdin);
    for(i=0;i<10;i++)
    {
        fflush(stdin);
        trypassword[i]=getch();
        printf("*");
    }

    if(strcmp(trypassword,"0")==0)
        return;

    gotoxy(50,20);
    printf("CONFIRM YOUR PASSWORD : ");
    fflush(stdin);
    for(i=0;i<strlen(trypassword);i++)
    {
        fflush(stdin);
        A.password[i]=getch();
        printf("*");
    }
    if(strcmp(A.password,"0")==0)
        return;



    if(strcmp(A.password,trypassword)==0&&strcmp(ac,accesscode)==0)
        break;

        gotoxy(30,28);
        textcolor(LIGHTRED);
        printf("ERROR!!! INVALID PASSWORD OR THE ACCESS CODE .DO YOU WANT TO TRY AGAIN? (Y/N) : ");
        fflush(stdin);
        scanf("%c",&chance);
        clrscr();

    }while(chance=='Y'||chance=='y');

     if(chance=='n'||chance=='N')
    return;

    fwrite(&A,sizeof(Admin),1,fp);
    fclose(fp);
    gotoxy(40,25);
    textcolor(LIGHTGREEN);
    printf("ACCOUNT CREATED AND CREDENTIALS SAVED SUCCESSFULLY");
    gotoxy(50,28);
    printf("PRESS ANY KEY TO CONTINUE");
    getch();





}



int login()
{
      FILE*fp=fopen("admindetails.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(55,25);
        printf("PLEASE SIGN-UP FIRST");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return 0;
    }


     Admin A;
     char tryemail[30],trypassword[11];
     int i;

     for(int j=1;j<=3;j++)
        {
            clrscr();
            screen_background();

            gotoxy(2,6);
            textcolor(CYAN);
            printf("ATTEMPT %d OF 3",j);

            gotoxy(60,8);
            textcolor(YELLOW);
            printf("LOGIN\n");

           for(i=0;i<120;i++)
                {
                    printf("*");
                }





           gotoxy(100,6);
           textcolor(LIGHTRED);
           printf("PRESS 0 TO EXIT");


           gotoxy(50,11);
           textcolor(WHITE);
           printf("VERIFY YOUR LOGIN CREDENTIALS");


           fflush(stdin);
           gotoxy(50,13);
           printf("ENTER YOUR EMAIL ID : ");
           fflush(stdin);
           fscanf(stdin,"%s",tryemail);
           if(strcmp(tryemail,"0")==0)
             return 0;


           fflush(stdin);
           gotoxy(50,14);
           printf("ENTER YOUR PASSWORD (10-DIGIT MAX,NO SPACES) : ");
           fflush(stdin);
           for(i=0;i<10;i++)
                {
                   fflush(stdin);
                   trypassword[i]=getch();
                   printf("*");
                }
           if(strcmp(trypassword,"0")==0)
               {
                   return 0;
               }

           while(feof(fp)==0)
               {
                   fread(&A,sizeof(Admin),1,fp);

                   if(strcmp(A.email_id,tryemail)==0&&strcmp(A.password,trypassword)==0)
                       {
                            gotoxy(50,20);
                            textcolor(MAGENTA);
                            printf("VALIDATING CREDENTIALS.PLEASE WAIT.");

                            for(i=0;i<3;i++)
                                {
                                    gotoxy(84,20);
                                    for(int j=0;j<5;j++)
                                       {
                                          _sleep(200);
                                          printf(".");
                                       }
                                    gotoxy(84,20);
                                    printf("\t");


                                }

                            gotoxy(55,25);
                            textcolor(LIGHTGREEN);
                            printf("LOGIN SUCCESSFUL");

                            gotoxy(50,28);
                            printf("PRESS ANY KEY TO CONTINUE");
                            getch();
                            return 1;
                      }


              }
        gotoxy(45,28);
        textcolor(LIGHTRED);
        printf("ERROR!!! INCORRECT ID OR PASSWORD. ");
        rewind(fp);
        getch();



        }
        clrscr();
        screen_background();
        gotoxy(45,10);
        printf("TOO MANY ATTEMPTS.TRY AGAIN LATER");
        getch();
        fclose(fp);
        return 0;


}



int accept_ticket_no()
{
    int ticket_no;
    clrscr();
    screen_background();

   while(1)
   {
       gotoxy(100,6);
       textcolor(LIGHTRED);
       printf("Press 0 TO EXIT");

       gotoxy(50,10);
       textcolor(WHITE);
       printf("ENTER TICKET.NO : ");
       fflush(stdin);
       scanf("%d",&ticket_no);

       if(ticket_no==0)
              {
                 gotoxy(50,25);
                 textcolor(RED);
                 printf("CANCELLING INPUT");
                 gotoxy(50,28);
                 printf("PRESS ANY KEY TO CONTINUE");
                 getch();
                 return 0;
              }

       else if(ticket_no<0)
              {
                 gotoxy(50,25);
                 textcolor(RED);
                 printf("ERROR!!!INVALID TICKET.NO");
                 gotoxy(50,28);
                 printf("PRESS ANY KEY TO CONTINUE");
                 getch();
                 gotoxy(50,28);
                 printf("\t\t\t\t\t");

              }

       else
             {

                return ticket_no;
             }

   }
}



void view_ticket(int ticket_no)
{
   clrscr();
   screen_background();

   FILE*fp=fopen("bookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(50,15);
        printf("NO BOOKINGS DONE YET");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return ;
    }

    textcolor(YELLOW);
    gotoxy(3,8);
    printf("TRAIN.NO");
    gotoxy(12,8);
    printf("CLASS");
    gotoxy(19,8);
    printf("TICKET.NO");
    gotoxy(31,8);
    printf("NAME");
    gotoxy(54,8);
    printf("AGE");
    gotoxy(59,8);
    printf("GENDER");
    gotoxy(67,8);
    printf("ADDRESS");
    gotoxy(97,8);
    printf("CONTACT.NO\n");
    for(int i=0;i<120;i++)
    {
        printf("-");
    }

    Passenger P;
    int check=0;
    long int file_size;

    fseek(fp,0,SEEK_END);
    file_size=ftell(fp);
    rewind(fp);

    for(int i=0;i<file_size/sizeof(Passenger);i++)
         {


           fread(&P,sizeof(Passenger),1,fp);

           if(P.ticketno==ticket_no)
           {
               gotoxy(3,10);
               printf("%s",P.train_no);
               gotoxy(12,10);
               printf("%c",P.p_class);
               gotoxy(19,10);
               printf("%d",P.ticketno);
               gotoxy(31,10);
               printf("%.18s",P.p_name);
               gotoxy(54,10);
               printf("%.2d",P.age);
               gotoxy(59,10);
               printf("%c",P.gender);
               gotoxy(67,10);
               printf("%.28s",P.address);
               gotoxy(97,10);
               printf("%.10s",P.mob_no);
               check=1;

           }
         }

         if(check==0)
         {
             gotoxy(45,15);
             textcolor(RED);
             printf("NO DETAILS REGARDING TICKET.NO : %d FOUND",ticket_no);
             gotoxy(50,28);
             printf("PRESS ANY KEY TO CONTINUE");
             getch();
         }

         getch();
         fclose(fp);

}


char*accept_train_no()
{
    clrscr();
    screen_background();
    static char train_no[10];
    int check;

    gotoxy(100,6);
    textcolor(RED);
    printf("PRESS 0 TO EXIT");
    textcolor(WHITE);
     gotoxy(50,8);
     printf("ENTER TRAIN.NO : ");

     while(1)
     {
         fflush(stdin);
     fscanf(stdin,"%s",train_no);
     strcpy(train_no,strupr(train_no));

     if(strcmp(train_no,"0")==0)
     {
         gotoxy(50,25);
         textcolor(RED);
         printf("CANCELLING INPUT");
         gotoxy(46,28);
         printf("PRESS ANY KEY TO CONTINUE");
         getch();
         return NULL;
     }

    check=check_train_no(train_no);

    if(check==0)
    {
        gotoxy(40,15);
        textcolor(RED);
        printf("ERROR!!! INVALID TRAIN.NO .TRY AGAIN");
        gotoxy(67,8);
        printf("\t");
        gotoxy(67,8);
        textcolor(WHITE);
    }

    else if(check==1)
    {
        return train_no;
    }

     }



}





void view_train_bookings(char*train_no)
{
   clrscr();
   screen_background();

   FILE*fp=fopen("bookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(50,15);
        printf("NO BOOKINGS DONE YET");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return ;
    }


    gotoxy(48,6);
    textcolor(YELLOW);
    printf("TRAIN.NO %s BOOKING ",train_no);
    textcolor(YELLOW);
    gotoxy(3,8);
    printf("TRAIN.NO");
    gotoxy(12,8);
    printf("CLASS");
    gotoxy(19,8);
    printf("TICKET.NO");
    gotoxy(31,8);
    printf("NAME");
    gotoxy(54,8);
    printf("AGE");
    gotoxy(59,8);
    printf("GENDER");
    gotoxy(67,8);
    printf("ADDRESS");
    gotoxy(97,8);
    printf("CONTACT.NO\n");


    for(int i=0;i<120;i++)
    {
        printf("-");
    }

    Passenger P;
    int check=0,row=10;
    long int file_size;

    fseek(fp,0,SEEK_END);
    file_size=ftell(fp);
    rewind(fp);

    for(int i=0;i<file_size/sizeof(Passenger);i++)
         {

           fread(&P,sizeof(Passenger),1,fp);

           if(strcmp(P.train_no,train_no)==0)
           {
               gotoxy(3,row);
               printf("%s",P.train_no);
               gotoxy(12,row);
               printf("%c",P.p_class);
               gotoxy(19,row);
               printf("%d",P.ticketno);
               gotoxy(31,row);
               printf("%.18s",P.p_name);
               gotoxy(54,row);
               printf("%.2d",P.age);
               gotoxy(59,row);
               printf("%c",P.gender);
               gotoxy(67,row);
               printf("%.28s",P.address);
               gotoxy(97,row);
               printf("%.10s",P.mob_no);
               row++;
               check=1;

           }


         }

         if(check==0)
         {
             gotoxy(45,15);
             textcolor(RED);
             printf("NO BOOKING DETAILS REGARDING TRAIN.NO : %s FOUND",train_no);
             gotoxy(50,28);
             printf("PRESS ANY KEY TO CONTINUE");
             getch();
         }
         getch();
         fclose(fp);

}



void view_all_bookings()
{
    clrscr();
    screen_background();

    FILE*fp=fopen("bookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(50,15);
        printf("NO BOOKINGS DONE YET");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return ;
    }
    fseek(fp,0,SEEK_END);
    int filesize=ftell(fp);
    rewind(fp);

    if(filesize==0)
        {
        textcolor(LIGHTRED);
        gotoxy(50,15);
        printf("NO BOOKINGS DONE YET");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return ;
    }


    textcolor(YELLOW);
    gotoxy(3,8);
    printf("TRAIN.NO");
    gotoxy(12,8);
    printf("CLASS");
    gotoxy(19,8);
    printf("TICKET.NO");
    gotoxy(31,8);
    printf("NAME");
    gotoxy(54,8);
    printf("AGE");
    gotoxy(59,8);
    printf("GENDER");
    gotoxy(67,8);
    printf("ADDRESS");
    gotoxy(97,8);
    printf("CONTACT.NO\n");
    for(int i=0;i<120;i++)
    {
        printf("-");
    }

    Passenger P;
    int row=10;
    long int file_size;

    fseek(fp,-1,SEEK_END);
    file_size=ftell(fp);
    rewind(fp);

    for(int i=0;i<=file_size/sizeof(Passenger);i++)
    {


        fread(&P,sizeof(Passenger),1,fp);

         gotoxy(3,row);
         printf("%s",P.train_no);
         gotoxy(12,row);
         printf("%c",P.p_class);
         gotoxy(19,row);
         printf("%d",P.ticketno);
         gotoxy(31,row);
         printf("%.18s",P.p_name);
         gotoxy(54,row);
         printf("%.2d",P.age);
         gotoxy(59,row);
         printf("%c",P.gender);
         gotoxy(67,row);
         printf("%.28s",P.address);
         gotoxy(97,row);
         printf("%.10s",P.mob_no);
         row++;

    }
getch();

}



Passenger*get_passenger_details()
{
    clrscr();
    screen_background();



    static Passenger P;
    char *p;
    int check;

    gotoxy(100,6);
    textcolor(LIGHTRED);
    printf("PRESS 0 TO EXIT");


    gotoxy(50,8);
    textcolor(YELLOW);
    printf("ENTER BOOKING DETAILS\n");
    for(int i=0;i<120;i++)
    {
        printf("-");
    }

    gotoxy(50,10);
    textcolor(WHITE);
    printf("ENTER PASSENGER'S NAME : ");
    fflush(stdin);
    fgets(P.p_name,20,stdin);
    p=strchr(P.p_name,'\n');
    *p='\0';
    strcpy(P.p_name,strupr(P.p_name));
    if(strcmp(P.p_name,"0")==0)
    {
        return NULL;
    }



    gotoxy(50,11);
    printf("ENTER GENDER : ");
    while(1)
    {

        fflush(stdin);
        fscanf(stdin,"%c",&P.gender);

        if(P.gender==0)
        {
           return NULL;
        }

        else if(P.gender=='M'||P.gender=='m'||P.gender=='f'||P.gender=='F'||P.gender=='t'||P.gender=='T')
         {
             if(P.gender>97)
                P.gender=P.gender-32;
             break;
         }

        else
               {
                   gotoxy(30,28);
                   textcolor(RED);
                   printf("ERROR!!!INVALID INPUT.(GENDER CANNOT BE OTHER THAN M/F/T).TRY AGAIN");
                   gotoxy(65,11);
                   textcolor(WHITE);
                   printf("\t\t");
                   gotoxy(65,11);

               }


    }

     gotoxy(30,28);
     printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");



    gotoxy(50,12);
    printf("ENTER TRAIN.NO : ");
    while(1)
    {

        fflush(stdin);
        fscanf(stdin,"%s",P.train_no);
        strcpy(P.train_no,strupr(P.train_no));

        check=check_train_no(P.train_no);

        if(strcmp(P.train_no,"0")==0)
        {
           return NULL;
        }

        if(check==0)
        {
            gotoxy(50,28);
            textcolor(RED);
            printf("ERROR!!!INVALID TRAIN.NO .TRY AGAIN");
            gotoxy(67,12);
            textcolor(WHITE);
            printf("\t\t\t\t");
            gotoxy(67,12);
        }

        else if(check==1)
        {
            break;
        }
    }
     gotoxy(50,28);
     printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");



    gotoxy(50,13);
    printf("ENTER TRAVELLING CLASS (F/S) : ");
    while(1)
    {
        fflush(stdin);
        fscanf(stdin,"%c",&P.p_class);

        if(P.p_class==0)
        {
           return NULL;
        }

        else if(P.p_class=='F'||P.p_class=='f'||P.p_class=='S'||P.p_class=='s')
               {
                   if(P.p_class>97)
                    P.p_class=P.p_class-32;
                  break;
               }

        else
         {
            gotoxy(30,28);
            textcolor(RED);
            printf("ERROR!!!INVALID INPUT.(CLASS CANNOT BE OTHER THAN F/S/G).TRY AGAIN");
            gotoxy(81,13);
            textcolor(WHITE);
            printf("\t\t\t\t\t");
            gotoxy(81,13);

         }
    }


     gotoxy(30,28);
     printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");


    gotoxy(50,14);
    printf("ENTER AGE (IN YRS) : ");
    while(1)
    {
        fflush(stdin);
        fscanf(stdin,"%d",&P.age);

        if(P.age==0)
        {
           return NULL;
        }

        else if(P.age>70)
        {
            gotoxy(40,28);
            textcolor(RED);
            printf("SORRY.PEOPLE IN SENESCENCE ARE ADVISED TO AVOID TRAVELL");
            gotoxy(71,14);
            printf("\t\t");
            gotoxy(71,14);
            textcolor(WHITE);
        }

        else if(P.age<0)
        {
            gotoxy(50,28);
            textcolor(RED);
            printf("ERROR!!!INVALID AGE .AGE SHOULD BE POSITIVE.TRY AGAIN");
            textcolor(WHITE);
            gotoxy(71,14);
            printf("\t\t\t");
            gotoxy(71,14);
        }

        else
            {
                break;
            }

    }

     gotoxy(40,28);
     printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");



    gotoxy(50,15);
    printf("ENTER ADDRESS : ");
    while(1)
    {
        fflush(stdin);
        fgets(P.address,30,stdin);
        p=strchr(P.address,'\n');
        *p='\0';
       strcpy(P.address,strupr(P.address));
        if(strcmp(P.address,"0")==0)
        {
            return NULL;
        }

        else
            {
                break;
            }
    }


    gotoxy(50,16);
    printf("ENTER MOBILE.NO (10-DIGITS) : ");
    while(1)
    {
        fflush(stdin);
        fgets(P.mob_no,30,stdin);
        p=strchr(P.mob_no,'\n');
        *p='\0';

        if(strcmp(P.mob_no,"0")==0)
        {
            return NULL;
        }

        else if(strlen(P.mob_no)<10)
        {
            gotoxy(40,25);
            textcolor(RED);
            printf("ERROR!!!INVALID MOBILE.NO (CANNOT BE LESS THAN 10-DIGIT).TRY AGAIN");
            gotoxy(80,16);
            printf("\t\t\t\t\t\t\t");
            gotoxy(80,16);
            textcolor(WHITE);
            continue;
        }
        else
            {
                break;
            }
    }

    gotoxy(40,25);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t");


    return &P;





}



int check_train_no(char*train_no)
{
    FILE*fp=fopen("trainchart.dat","rb");
    if(fp==NULL)
    {

        return 0;
    }
     Train T;
    while(1)
    {
        if(feof(fp))
        {
            break;
        }

        fread(&T,sizeof(Train),1,fp);

        if(strcmp(T.train_no,train_no)==0)
        {
             fclose(fp);
            return 1;
        }

    }

     fclose(fp);
    return 0;

}





int booked_ticket_count(char*train_no,char p_class)
{

    FILE*fp=fopen("bookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(50,22);
        printf("NO BOOKINGS DONE YET");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return 0;
    }
    Passenger P;
    int count=0;
    long int file_size;

    fseek(fp,0,SEEK_END);
    file_size=ftell(fp);
    rewind(fp);

    for(int i=0;i<file_size/sizeof(Passenger);i++)
    {

        fread(&P,sizeof(Passenger),1,fp);

        if(P.p_class==p_class||strcmp(P.train_no,train_no)==0)
        {
           count++;
        }
    }
    fclose(fp);
    return count;

}


int last_ticket_no()
{


    FILE*fp=fopen("bookings.dat","rb");
    if(fp==NULL)
    {

        return 0 ;
    }

    Passenger P;


        fseek(fp,-1L*sizeof(Passenger),SEEK_END);
        fread(&P,sizeof(Passenger),1,fp);
      fclose(fp);
        return P.ticketno;

}

int book_ticket(Passenger P)
{
  FILE*fp=fopen("bookings.dat","ab");
  if(fp==NULL)
  {
      clrscr();
      gotoxy(45,15);
      textcolor(RED);
      printf("SORRY CANNOT CONNECT  TO RESOURCE FILE");
      getch();
      return 0;
  }

  int last_no=last_ticket_no();

  P.ticketno=last_no+1;


 if(fwrite(&P,sizeof(Passenger),1,fp)==1)
 {
     fclose(fp);
     return P.ticketno;
 }
 else
 {
     fclose(fp);
     return 0;
 }




}



int cancel_ticket(int ticket_no)
{
    clrscr();
    screen_background();

    FILE*fp1=fopen("bookings.dat","rb");
    if(fp1==NULL)
    {
        gotoxy(50,25);
        textcolor(RED);
        printf("UNABLE TO LOCATE RESOURE FILE.INCONVINIENCE IS REGRETTED");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return 0;
    }

    fseek(fp1,0,SEEK_END);
    long int filesize=ftell(fp1)/sizeof(Passenger);
    rewind(fp1);
    Passenger P[filesize];
    int found=0;

    if(filesize==0)
        return 0;

    for(int i=0;i<=filesize;i++)
    {
       fread(&P[i],sizeof(Passenger),1,fp1);

    }

    fclose(fp1);

    fp1=fopen("bookings.dat","wb");

    for(int i=0;i<filesize;i++)
    {
        if(P[i].ticketno!=ticket_no)
        {
            fwrite(&P[i],sizeof(Passenger),1,fp1);
        }
        else if(P[i].ticketno==ticket_no)
        {
            found=1;
        }
    }
    fclose(fp1);
return found;
}





int cancel_train(char*train_no)
{
    clrscr();
    screen_background();

    FILE*fp1=fopen("bookings.dat","rb");
    if(fp1==NULL)
    {
        gotoxy(50,25);
        textcolor(RED);
        printf("UNABLE TO LOCATE RESOURE FILE.INCONVINIENCE IS REGRETTED");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return 0;
    }

    fseek(fp1,0,SEEK_END);
    long int filesize=ftell(fp1)/sizeof(Passenger);
    rewind(fp1);
    Passenger P[filesize];
    int found=0;

    if(filesize==0)
        return 0;

    for(int i=0;i<=filesize;i++)
    {
       fread(&P[i],sizeof(Passenger),1,fp1);

    }

    fclose(fp1);

    fp1=fopen("bookings.dat","wb");

    for(int i=0;i<filesize;i++)
    {
        if(strcmp(P[i].train_no,train_no)!=0)
        {
            fwrite(&P[i],sizeof(Passenger),1,fp1);
        }
        else if(strcmp(P[i].train_no,train_no)==0)
        {
            found=1;
        }
    }
    fclose(fp1);
return found;
}




int check_mob_no(char*mob_no)
{
    FILE*fp=fopen("bookings.dat","rb");
    if(fp==NULL)
    {

        return 0;
    }
     Passenger P;
    while(1)
    {
        if(feof(fp))
        {
            break;
        }

        fread(&P,sizeof(Passenger),1,fp);

        if(strcmp(P.mob_no,mob_no)==0)
        {
             fclose(fp);
            return 1;
        }

    }

     fclose(fp);
    return 0;

}









char*accept_mob_no()
{
    clrscr();
    screen_background();
    static char mob_no[11];
    int check;

     gotoxy(100,6);
     textcolor(RED);
     printf("PRESS 0 TO EXIT");
     textcolor(WHITE);
     gotoxy(50,8);
     printf("ENTER MOBILE.NO : ");

     while(1)
     {
         fflush(stdin);
     fscanf(stdin,"%s",mob_no);
     strcpy(mob_no,strupr(mob_no));

     if(strcmp(mob_no,"0")==0)
     {
         gotoxy(50,25);
         textcolor(RED);
         printf("CANCELLING INPUT");
         gotoxy(46,28);
         printf("PRESS ANY KEY TO CONTINUE");
         getch();
         return NULL;
     }

     if(strlen(mob_no)!=10)
     {
        gotoxy(40,15);
        textcolor(RED);
        printf("ERROR!!!INVALID MOBILE.NO .TRY AGAIN");
        gotoxy(68,8);
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(68,8);
        textcolor(WHITE);
        continue;
    }

    check=check_mob_no(mob_no);

    if(check==0)
    {
        gotoxy(40,15);
        textcolor(RED);
        printf("NO BOOKINGS DONE FOR THIS MOBILE.NO .TRY AGAIN");
        gotoxy(68,8);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(68,8);
        textcolor(WHITE);
    }

    else if(check==1)
    {
        return mob_no;
    }

     }



}



void search_bookings(char*mob_no)
{
     clrscr();
   screen_background();

   FILE*fp=fopen("bookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(50,15);
        printf("NO BOOKINGS DONE YET");
        gotoxy(50,28);
        printf("PRESS ANY KEY TO CONTINUE");
        getch();
        return ;
    }


    gotoxy(45,6);
    textcolor(YELLOW);
    printf("BOOKINGS UNDER MOBILE.NO %s  ",mob_no);
    textcolor(YELLOW);
    gotoxy(3,8);
    printf("TRAIN.NO");
    gotoxy(12,8);
    printf("CLASS");
    gotoxy(19,8);
    printf("TICKET.NO");
    gotoxy(31,8);
    printf("NAME");
    gotoxy(54,8);
    printf("AGE");
    gotoxy(59,8);
    printf("GENDER");
    gotoxy(67,8);
    printf("ADDRESS");
    gotoxy(97,8);
    printf("CONTACT.NO\n");


    for(int i=0;i<120;i++)
    {
        printf("-");
    }

    Passenger P;
    int check=0,row=10;
    long int file_size;

    fseek(fp,0,SEEK_END);
    file_size=ftell(fp);
    rewind(fp);

    for(int i=0;i<file_size/sizeof(Passenger);i++)
         {

           fread(&P,sizeof(Passenger),1,fp);

           if(strcmp(P.mob_no,mob_no)==0)
           {
               gotoxy(3,row);
               printf("%s",P.train_no);
               gotoxy(12,row);
               printf("%c",P.p_class);
               gotoxy(19,row);
               printf("%d",P.ticketno);
               gotoxy(31,row);
               printf("%.18s",P.p_name);
               gotoxy(54,row);
               printf("%.2d",P.age);
               gotoxy(59,row);
               printf("%c",P.gender);
               gotoxy(67,row);
               printf("%.28s",P.address);
               gotoxy(97,row);
               printf("%.10s",P.mob_no);
               row++;
               check=1;

           }


         }

         if(check==0)
         {
             gotoxy(45,15);
             textcolor(RED);
             printf("NO BOOKING DETAILS REGARDING MOBILE.NO : %s FOUND",mob_no);
             gotoxy(50,28);
             printf("PRESS ANY KEY TO CONTINUE");
             getch();
         }
         getch();
         fclose(fp);

}



int check_train_no_repetition(char*train_no)
{
    FILE*fp=fopen("trainchart.dat","rb");

   fseek(fp,0,SEEK_END);
   int file_size=ftell(fp)/sizeof(Train);
   rewind(fp);

   Train T;

   for(int i=0;i<file_size;i++)
   {
       fread(&T,sizeof(Train),1,fp);

       if(strcmp(T.train_no,train_no)==0)
       {
           fclose(fp);
           return 1;
       }
   }
   fclose(fp);
   return 0;

}

