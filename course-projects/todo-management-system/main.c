// necessary imports
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// contains all menu-work
#include "headers/menu.h"
// menu handler
#include "headers/menuhandler.h"
// for delay
#include "headers/delay.h"
// required for clear_screen function
#include "headers/clearscreen.h"


// operation delay in milli-seconds
#define DELAY 5000

// driver function
int main(){

    // SIDE NOTE: For color formatting
    // starting \033[32;1m will make the following text green bold
    // and ending with \033[0m will reset this setting
    // printf ("\033[32;1mOK\n\033[0m");
    // starting \033[31;1m will make the following text red bol
    // and ending with \033[0m will reset this setting
    // printf ("\033[31;1mDANGER\n\033[0m");



    // seed random number generator
    srand(time(NULL));
    // continue until user exists
    while (true) {
        // clear the console
        clear_screen();
        // print the menu
        print_main_menu();
        // read user's choice
        int choice; scanf("%d%*c", &choice);
        // stores the time to wait
        int time_to_wait = DELAY;
        // take action based on choice
        switch (choice) {
            case 0:
                // add a new todo
                add_todo();
                // stop further processing
                break;
            case 1:
                // display the todo
                show_todo();
                // stop further processing
                break;
            case 2:
                // all todos
                all_todos();
                // stop further processing
                break;
            case 3:
                // print today's todos
                today_todos();
                // stop further processing
                break;
            case 4:
                // print upcoming todos
                upcoming_todos();
                // stop further processing
                break;
            case 5:
                // past todos
                past_todos();
                // stop further processing
                break;
            case 6:
                // done todos
                done_todos();
                // stop further processing
                break;
            case 7:
                // not done todos
                not_done_todos();
                // stop further processing
                break;
            case 8:
                // mark this todo as done
                mark_done();
                // stop further processing
                break;
            case 9:
                // mark this todo as undone
                mark_todo();
                // stop further processing
                break;
            case 10:
                // perform the edit operation
                edit_todo();
                // stop further processing
                break;
            case 11:
                // delete the todo 
                delete_todo();
                // stop further processing
                break;
            case 12: 
                printf ("Bye Bye!\n");
                exit(EXIT_SUCCESS);
            // for any other choice just reprint the menu
            default:
                // do not wait- just reprint the menu 
                time_to_wait = 0;
        }
        // wait for sometime
        busy_wait(time_to_wait);
    }

    // return success to caller
    return 0;
}
