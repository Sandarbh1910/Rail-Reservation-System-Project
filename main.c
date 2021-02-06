#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"myrailres.h"
#include<string.h>

int main()
{
    int user,choice,i,ticket_no;
    Passenger *P;
    clrscr();
    screen_background();
    gotoxy(60,15);
    textcolor(LIGHTBLUE);
    printf("WELCOME");
    getch();

    FILE*fp1=fopen("trainchart.dat","rb");
    if(fp1==NULL)
        {
             gotoxy(50,8);
             printf("PREPARE CHART");
             prepare_chart();
        }

    else
        {
            gotoxy(52,15);
             textcolor(CYAN);
             printf("CHART ALREADY PREPARED");
             getch();
             clrscr();
        }

      while(1)//while loop 1
      {
         user=user_type();

        if(user==1)
         {
              while(1)//while loop 2
               {
                    char*p;
                    clrscr();
                    screen_background();
                    choice=passenger_menu();


                    switch(choice)
                          {
                             case 0:
                                  gotoxy(35,25);
                                  textcolor(GREEN);
                                  printf("THANK YOU FOR USING OUR SERVICE .PLEASE VISIT AGAIN");
                                  getch();
                             break;

                             case 1:
                                  view_train_chart();
                             break;

                             case 2:
                                  P=get_passenger_details();
                                  if(P!=NULL)
                                      {
                                          if(booked_ticket_count(P->train_no,P->p_class)<30)
                                                {
                                                     ticket_no=book_ticket(*P);
                                                     if(ticket_no==0)
                                                         {
                                                             clrscr();
                                                             gotoxy(50,15);
                                                             textcolor(RED);
                                                             printf("TICKET NOT BOOKED");
                                                             getch();
                                                         }

                                                      else
                                                         {
                                                             clrscr();
                                                             gotoxy(40,15);
                                                             textcolor(LIGHTGREEN);
                                                             printf("TICKET BOOKED SUCCESSFULLY .YOUR TICKET.NO IS : %d",ticket_no);
                                                             gotoxy(45,28);
                                                             printf("PRESS ANY KEY TO CONTINUE");
                                                             getch();
                                                             break;
                                                         }

                                                 }

                                            else
                                                 {
                                                      gotoxy(45,15);
                                                      textcolor(RED);
                                                      printf("SEATS FULL");
                                                      getch();
                                                      break;
                                                 }
                                    }

                             break;

                             case 3:
                                  ticket_no=accept_ticket_no();

                                  if(ticket_no!=0)
                                  {
                                     view_ticket(ticket_no);
                                  }

                                  gotoxy(50,28);
                                  printf("PRESS ANY KEY TO CONTINUE");
                                  getch();

                             break;

                             case 4:
                                    p=accept_mob_no();
                                    if(p!=NULL)
                                      {
                                          search_bookings(p);
                                      }
                             break;

                             case 5:
                                ticket_no=accept_ticket_no();
                                if(ticket_no!=0)
                                    {
                                        user=cancel_ticket(ticket_no);

                                        if(user==-1)
                                            {
                                                gotoxy(50,25);
                                                textcolor(RED);
                                                printf("NO SUCH BOOKING FOUND");
                                                gotoxy(50,28);
                                                printf("PRESS ANY KEY TO CONTINUE");
                                                getch();
                                            }

                                        else if(user==1)
                                            {
                                                gotoxy(45,15);
                                                textcolor(LIGHTGREEN);
                                                printf("CANCELLATION SUCCESSFUL .TICKET.NO : %d",ticket_no);
                                                gotoxy(50,28);
                                                printf("PRESS ANY KEY TO CONTINUE");
                                                getch();
                                            }
                                    }
                             break;

                             default:
                                  gotoxy(50,15);
                                  textcolor(LIGHTRED);
                                  printf("ERROR!!!INVALID SELECTION.TRY AGAIN");
                         }
                         if(choice==0)
                            break;

                  }//while loop 2 closing

           }

         else if(user==2)//Checking user type
           {
                   while(1)//while loop 3
                         {


                              choice=access_control();



                              if(choice==1)
                                         {
                                              while(1)//while loop 4
                                                     {
                                                         int log;
                                                         log=login();

                                                         if(log==1)
                                                                 {
                                                                     while(1)//while loop 5
                                                                          {
                                                                             int choice;
                                                                             char*p;
                                                                             clrscr();
                                                                             screen_background();
                                                                             choice=admin_menu();


                                                                             switch(choice)
                                                                                         {
                                                                                            case 0:
                                                                                                 gotoxy(25,25);
                                                                                                 textcolor(GREEN);
                                                                                                 printf("THANKING YOU FOR USING OUR SERVICE .PLEASE VISIT AGAIN");
                                                                                            break;

                                                                                            case 1:
                                                                                                 prepare_chart();
                                                                                            break;

                                                                                            case 2:
                                                                                                 addtrains();
                                                                                            break;

                                                                                            case 3:
                                                                                                 view_train_chart();
                                                                                            break;

                                                                                            case 4:
                                                                                                  P=get_passenger_details();
                                                                                                  if(P!=NULL)
                                                                                                        {
                                                                                                             if(booked_ticket_count(P->train_no,P->p_class)<30)
                                                                                                                       {
                                                                                                                             ticket_no=book_ticket(*P);
                                                                                                                             if(ticket_no==0)
                                                                                                                                       {
                                                                                                                                           clrscr();
                                                                                                                                           gotoxy(50,15);
                                                                                                                                           textcolor(RED);
                                                                                                                                           printf("TICKET NOT BOOKED");
                                                                                                                                           getch();
                                                                                                                                       }

                                                                                                                             else
                                                                                                                                       {
                                                                                                                                           clrscr();
                                                                                                                                           gotoxy(40,15);
                                                                                                                                           textcolor(LIGHTGREEN);
                                                                                                                                           printf("TICKET BOOKED SUCCESSFULLY .YOUR TICKET.NO IS : %d",ticket_no);
                                                                                                                                           gotoxy(45,28);
                                                                                                                                           printf("PRESS ANY KEY TO CONTINUE");
                                                                                                                                           getch();
                                                                                                                                           break;
                                                                                                                                       }

                                                                                                                      }

                                                                                                              else
                                                                                                                      {
                                                                                                                            clrscr();
                                                                                                                            screen_background();
                                                                                                                            gotoxy(45,15);
                                                                                                                            textcolor(RED);
                                                                                                                            printf("SEATS FULL IN THIS CATEGORY.PLEASE TRY IN OTHER ONES");
                                                                                                                            getch();
                                                                                                                            break;
                                                                                                                      }
                                                                                                         }


                                                                                            break;

                                                                                            case 5:
                                                                                               ticket_no=accept_ticket_no();
                                                                                               if(ticket_no!=0)
                                                                                                    {
                                                                                                       view_ticket(ticket_no);
                                                                                                    }

                                                                                               gotoxy(50,28);
                                                                                               printf("PRESS ANY KEY TO CONTINUE");
                                                                                               getch();
                                                                                            break;

                                                                                            case 6:

                                                                                                p=accept_train_no();
                                                                                                if(p!=NULL)
                                                                                                {
                                                                                                    view_train_bookings(p);
                                                                                                }
                                                                                            break;

                                                                                            case 7:
                                                                                                 p=accept_mob_no();
                                                                                                 if(p!=NULL)
                                                                                                 {
                                                                                                     search_bookings(p);
                                                                                                 }
                                                                                            break;

                                                                                            case 8:
                                                                                                  view_all_bookings();
                                                                                            break;

                                                                                            case 9:
                                                                                                  ticket_no=accept_ticket_no();
                                                                                                  if(ticket_no!=0)
                                                                                                  {
                                                                                                     user=cancel_ticket(ticket_no);

                                                                                                      if(user==0)
                                                                                                      {
                                                                                                          gotoxy(50,25);
                                                                                                          textcolor(RED);
                                                                                                          printf("NO SUCH BOOKING FOUND");
                                                                                                          gotoxy(50,28);
                                                                                                          printf("PRESS ANY KEY TO CONTINUE");
                                                                                                          getch();
                                                                                                      }

                                                                                                      else if(user==1)
                                                                                                      {
                                                                                                          gotoxy(45,15);
                                                                                                          textcolor(LIGHTGREEN);
                                                                                                          printf("CANCELLATION SUCCESSFUL .TICKET.NO : %d",ticket_no);
                                                                                                          gotoxy(50,28);
                                                                                                          printf("PRESS ANY KEY TO CONTINUE");
                                                                                                          getch();
                                                                                                      }
                                                                                                  }
                                                                                            break;

                                                                                            case 10:
                                                                                                  p=accept_train_no();
                                                                                                  if(p!=NULL)
                                                                                                  {
                                                                                                      user=cancel_train(p);
                                                                                                      if(user==1)
                                                                                                      {
                                                                                                          clrscr();
                                                                                                          gotoxy(38,15);
                                                                                                          textcolor(LIGHTMAGENTA);
                                                                                                          printf("BOOKINGS CANCELLED FOR THE TRAIN %s FOR THE DAY.",p);
                                                                                                          gotoxy(50,28);
                                                                                                          printf("PRESS ANY KEY TO CONTINUE");
                                                                                                          getch();
                                                                                                      }
                                                                                                  }
                                                                                            break;

                                                                                            case 11:
                                                                                                clrscr();
                                                                                                screen_background();

                                                                                                textcolor(RED);
                                                                                                for(i=5;i>0;i--)
                                                                                                {
                                                                                                    gotoxy(55,15);
                                                                                                    printf("SHUTING DOWN IN : %d",i);
                                                                                                    _sleep(500);
                                                                                                    gotoxy(72,15);
                                                                                                    printf("  ");
                                                                                                }
                                                                                                clrscr();
                                                                                                gotoxy(60,15);
                                                                                                textcolor(LIGHTCYAN);
                                                                                                printf("BYE BYE");
                                                                                                getch();
                                                                                                clrscr();
                                                                                                exit(0);
                                                                                            break;





                                                                                            default:
                                                                                                 gotoxy(50,15);
                                                                                                 textcolor(LIGHTRED);
                                                                                                 printf("ERROR!!!INVALID SELECTION.TRY AGAIN");
                                                                                        }
                                                                                    if(choice==0)
                                                                                        break;

                                                                          }//while loop 5 closing


                                                                  }
                                                     break;//break from while loop 4


                                                     }//while loop 4 closing
                                         }

                              else if(choice==2)
                                            {
                                                 sign_up();
                                                 break;
                                            }



                              else if(choice==0)
                                            {
                                                 break;//break from while loop 3
                                            }



                              else
                                            {
                                                 textcolor(LIGHTRED);
                                                 gotoxy(50,28);
                                                 printf("INVALID INPUT.TRY AGAIN ");
                                            }
                         }//while loop 3 closing



            }


          else
          {
              continue;
          }
      }//while loop 1 closing
}//main()
