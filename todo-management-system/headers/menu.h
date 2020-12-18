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
    printf ("0. Add Todo\n");
    printf ("1. Show Todo\n");
    printf ("2. All Todos\n");
    printf ("3. Today's Todos\n");
    printf ("4. Upcoming Todos\n");
    printf ("5. Past Todos\n");
    printf ("6. Done Todos\n");
    printf ("7. Not done Todos\n");
    printf ("8. Mark as done\n");
    printf ("9. Mark as todo\n");
    printf ("10. Edit Todo\n");
    printf ("11. Delete Todo\n");
    printf ("12. Exit\n");
    printf ("Please enter your choice: ");
}

#endif