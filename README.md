# Rail-Reservation-System-Project
This is a beginner project which I created in 1st year of college, so as to test my knowledge and perform a practical of whatever I learned so far in C programming language.In this I have used simple C language concepts , pre-defined library functions and file handling stuff.

FEATURES:-

1)In this I have tried to provide seperate user console-interfaces for customer and admin so as to ensure their is no interference in doing respective tasks .

2)Unlike the customer interface which is open to every user ,admin side is password protected for this login and sign-up options(sign-up is too, access code protected i.e a random guy is not allowed to sign-up and use admin's powers) are provided.

3)On customer side there is a list of tasks which a customer can perform (like viewing train chart,booking a ticket,viewing a ticket,searching a ticket with the help of mobile number and cancelling a ticket)with proper validations and restrictions applied at suitable places.

4)Similarly ,on the admin side there are some powers and responsibilities listed in form of a menu like preparing a train chart ,adding trains to existing chart,view all customers bookings,cancel a train and to shut down the program(random guy is not allow to end the program) etc.

5)At any step ,the option to exit the current task is provided wherever possible .So as to give an ease to the user to exit with his/her will.

6)Efforts to make the console-interface less boring , more informative and attractive to an extent are made wherever possible.

7)Attempts to make use of pre-defined function so as to make the code easily traceable for readers have been made , but at some points there were some issues while using them(functions like remove() and rename() were producing error while cancelling ticket and cancelling train ,maybe be due to human error or some other issues ) , so some logics were implemented inorder to bring the program in workable conditions with zero error(this is not a matter to concern as the code written has pure logics applied with the help of arrays and some other functions in place of both the functions ).

8)Colored text , alignment and little creativity have been used wherever possible to make the console-interface somewhat less black n white and boring .

NOTE:-

This program was developed on Code Blocks IDE version 20.03 with mingw compiler which does not support the <conio.h> header file unlike the turbo compiler in turbo c++ , so to solve this issue , the code/support of already developed header file "conio2.h" was downloaded from a site.
