// define menu.h if not already defined
#ifndef _MENU_H
#define _MENU_H

// necessary imports
#include <stdio.h>

// prints count many occurrences of symbol followed by newline
void print_separator(int count, char symbol){
    for (int i = 0; i < count; ++i) printf("%c", symbol);
    printf ("\n");
}


// prints the separator on the console
void print_main_menu(){
    // print the menu
    print_separator(50, '=');
    printf ("MAIN MENU\n");
    print_separator(50, '=');
    printf ("1. New user registration\n");
    printf ("2. Balance enquiry\n");
    printf ("3. Cash withdrawl\n");
    printf ("4. Cash deposit\n");
    printf ("5. Update account details\n");
    printf ("6. Deregister\n");
    printf ("7. List all users\n");
    printf ("8. Exit\n");
    printf ("Please enter your choice: ");
}

#endif