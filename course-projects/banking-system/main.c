// necessary imports
#include <stdio.h>
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
        // take action based on choice
        switch (choice) {

            // for registration operation
            case 1:
                // perform the new-use-registration
                new_user_registration();
                // busy-wait 
                busy_wait(DELAY);
                // stop further processing
                break;
            case 2:
                // perform balance enquiry
                balance_enquiry();
                // busy-wait 
                busy_wait(DELAY);
                // stop further processing
                break;
            case 3:
                // perform cash withdrawl
                cash_withdrawl(); 
                // busy-wait 
                busy_wait(DELAY);
                // stop further processing
                break;
            case 4:
                // perform cash deposit
                cash_deposit(); 
                // busy-wait 
                busy_wait(DELAY);
                // stop further processing
                break;
            case 5:
                // update the account details
                update_account_details();
                // busy-wait 
                busy_wait(DELAY);
                // stop further processing
                break;
            case 6:
                // deregister user
                deregister_user();
                // busy-wait 
                busy_wait(DELAY);
                // stop further processing
                break;
            case 7:
                // list all users
                list_all_users();
                // busy-wait 
                busy_wait(DELAY);
                // stop further processing
                break;
            case 8: 
                printf ("Bye Bye!\n");
                exit(EXIT_SUCCESS);
            // for any other choice just reprint the menu
        }
    }

    // return success to caller
    return 0;
}
