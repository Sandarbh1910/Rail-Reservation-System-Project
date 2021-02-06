#ifndef MYRAILRES_H_INCLUDED
#define MYRAILRES_H_INCLUDED

typedef struct Train
{
     char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
    int distance;
    float time;
}Train;


typedef struct Passenger
{
    char p_name[20];
    char gender;
    char train_no[10];
    char p_class;
    char address[30];
    int age;
    int ticketno;
    char mob_no[11];

}Passenger;


typedef struct Admin
{
    char name[20];
    char email_id[30];
    char mob[11];
    int age;
    char gender;
    char password[10];
}Admin;


void screen_background();
int passenger_menu();
int admin_menu();
void prepare_chart();
void view_train_chart();
int user_type();
void addtrains();
int access_control();
void sign_up();
int login();
int accept_ticket_no();
void view_ticket(int);
char*accept_train_no();
void view_train_bookings(char*);
void view_all_bookings();
Passenger* get_passenger_details();
int check_train_no(char*);
int booked_ticket_count(char*,char);
int last_ticket_no();
int book_ticket(Passenger);
int cancel_ticket(int);
int cancel_train(char*);
char*accept_mob_no();
int check_mob_no(char*);
void search_bookings(char*);
int check_train_no_repetition(char*);

#endif // MYRAILRES_H_INCLUDED
