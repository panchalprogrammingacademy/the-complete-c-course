// define menuhandler.h if not defined already
#ifndef _MENUHANDLER_H
#define _MENUHANDLER_H

// include user.h
#include "user.h"
// include userio.h
#include "userio.h"
// for clearscreen
#include "clearscreen.h"
// for file processing
#include "banking.h"
// for list
#include "userlist.h"



// for new user registration
void new_user_registration() {
    // clear the console
    clear_screen();
    // print the header
    printf ("NEW USER REGISTRATION\n\n");
    // create a new user with empty details
    User user;
    // read username and validate
    if (!read_username(user.username))   return;
    // generate a random account number
    for (size_t i = 0; i < ACCOUNT_SIZE; ++i)
        user.account_no[i] = (rand() % 10) + '0';
    // append a null character at the end
    user.account_no[ACCOUNT_SIZE] = '\0';
    // print the account number
    printf ("Account number: %s\n", user.account_no);
    // prompt pin and validate
    if (!read_pin(user.pin)) return;


    // EXTENSION: You can validate the existence of account
    // with the randomly generated account number for sake of surity
    // here we expect that it's rare for generator of two same 
    // 10-digit numbers


    // store the new-user to the file
    if (write_to_file(user)) {
        printf ("\nNew user registered successfully.\nTransaction succeeded!\nYou will now be redirected to main menu!\n");
    } else {
        printf ("\nFailed to save new user.\nTransaction failed!\nYou will now be redirected to main menu!\n");
    }
}




// for balance-enquiry
void balance_enquiry() {
    // clear the console
    clear_screen();
    // header
    printf ("BALANCE ENQUIRY\n\n");
    // create a new user
    User user;
    // query user-details
    if (!query_user(&user)) return;
    // user details fetched successfully
    // read the user from file
    int location = read_user(&user);
    if(location == -1) {
        // failed to find user
        printf ("\nFailed to find a matching record.\nTransaction aborted!\nYou will now be redirected to main menu!\n");
    } else {
        // user found successfully - print the details
        user_to_string(&user);
        // transaction succeeded
        printf ("\nTransaction succeeded!\nYou will now be redirected to main menu!\n");
    }
}



// for cash withdrawl
void cash_withdrawl() {
    // clear the console
    clear_screen();
    // header
    printf ("CASH WITHDRAWL\n\n");
    // create a new user
    User user;
    // query user-details
    if (!query_user(&user)) return;
    // user details fetched successfully
    // read the user from file
    int location = read_user(&user);
    if(location == -1) {
        // failed to find user
        printf ("\nFailed to find a matching record.\nTransaction aborted!\nYou will now be redirected to main menu!\n");
    } else {
        // user found successfully - print the details
        user_to_string(&user);
        // prompt user for amount to be withdrawl
        double amount = 0.0; 
        printf ("Amount to withdraw: "); scanf ("%lf", &amount);
        // check if amount is correct
        if (amount <= 0) {
            // invalid amount
            printf ("Invalid withdrawl amount.\nTransaction failed!\nYou will now be redirected to main menu!\n");
        } else if (amount > user.balance) {
            // invalid amount
            printf ("Insufficient amount in your account.\nTransaction failed!\nYou will now be redirected to main menu!\n");
        } else {
            // update the amount
            user.balance -= amount;
            // save the user
            if(!save_user(user)) {
                // failed to save user
                printf ("Failed to withdraw cash.\nTransaction failed!\nYou will now be redirected to main menu!\n");
            } else {
                // cash withdrawl successful
                printf ("Please collect your cash.\nTransaction succeeded!\nYou will now be redirected to main menu!\n");
            }
        }
    }
}

// for cash deposit
void cash_deposit() {
    // clear the console
    clear_screen();
    // header
    printf ("CASH DEPOSIT\n\n");
    // create a new user
    User user;
    // query user-details
    if (!query_user(&user)) return;
    // user details fetched successfully
    // read the user from file
    int location = read_user(&user);
    if(location == -1) {
        // failed to find user
        printf ("\nFailed to find a matching record.\nTransaction aborted!\nYou will now be redirected to main menu!\n");
    } else {
        // user found successfully - print the details
        user_to_string(&user);
        // prompt user for amount to be deposit
        double amount = 0.0; 
        printf ("Amount to deposit: "); scanf ("%lf", &amount);
        // check if amount is correct
        if (amount <= 0) {
            // invalid amount
            printf ("Invalid deposit amount.\nTransaction failed!\nYou will now be redirected to main menu!\n");
        } else {
            // update the amount
            user.balance += amount;
            // save the user
            if(!save_user(user)) {
                // failed to save user
                printf ("Failed to deposit cash, please collect your cash.\nTransaction failed!\nYou will now be redirected to main menu!\n");
            } else {
                // cash withdrawl successful
                printf ("Your cash was deposited successfully.\nTransaction succeeded!\nYou will now be redirected to main menu!\n");
            }
        }
    }
}



// for account details update
void update_account_details() {
    // clear the console
    clear_screen();
    // header
    printf ("UPDATE ACCOUNT DETAILS\n\n");
    // create a new user
    User user;
    // query user-details
    if (!query_user(&user)) return;
    // user details fetched successfully
    // read the user from file
    int location = read_user(&user);
    if(location == -1) {
        // failed to find user
        printf ("\nFailed to find a matching record.\nTransaction aborted!\nYou will now be redirected to main menu!\n");
    } else {
        // user found successfully - print the details
        user_to_string(&user);
        // read username
        if (!read_username(user.username))  return;
        // read pin
        if (!read_pin(user.pin))    return;
        // save the user
        if(!save_user(user)) {
            // failed to save user
            printf ("Failed to update your account details.\nTransaction failed!\nYou will now be redirected to main menu!\n");
        } else {
            // update successful
            printf ("Your account was updated successfully.\nTransaction succeeded!\nYou will now be redirected to main menu!\n");
        }
    }
}

// for deregistering the user
void deregister_user() {
    // clear the console
    clear_screen();
    // header
    printf ("USER DEREGISTRATION\n\n");
    // create a new user
    User user;
    // query user-details
    if (!query_user(&user)) return;
    // user details fetched successfully
    // read the user from file
    int location = read_user(&user);
    if(location == -1) {
        // failed to find user
        printf ("\nFailed to find a matching record.\nTransaction aborted!\nYou will now be redirected to main menu!\n");
    } else {
        // user found successfully - print the details
        user_to_string(&user);
        // delete the user
        if (!delete_user(user)) {
            // failed to delete user
            printf ("Failed to de-register your account.\nTransaction failed!\nYou will now be redirected to main menu!\n");
        } else {
            // user deleted successfully
            printf ("Your account was de-registered.\n");
            // if user has a balance then return it
            if (user.balance > 0) printf ("Please collect your cash of %.2lf\n", user.balance);
            // success
            printf ("We're are sorry to see you go!\nTransaction succeeded!\nYou will now be redirected to main menu!\n");
        }
    }    
}


// fetches the list of all users
void list_all_users() {
    // clear the console
    clear_screen();
    // print the header
    printf ("%-20s%-15s%-10s%-10s\n", "Username", "Account number", "PIN", "Balance");

    // read the list of all users
    UserList* list = read_all();
    // validate list
    if (list == NULL) {
        printf ("Failed to fetch list of users.\nTransaction failed!\nYou will now be redirected to main menu!");
    } else {
        // check the size of list
        if (list->size == 0) {
            printf ("No records found\n\n");
        } else {
            // iterate through all records
            UserListNode* temp = list->head;
            while (temp != NULL) {
                // fetch the user
                User user = temp->user;
                // fetch the next user
                temp = temp->next;
                // print the details
                printf ("%-20s%-15s%-10s%-10.2lf\n", user.username, user.account_no, user.pin, user.balance);
            }
            // print the total number of records
            printf ("\nFound %ld record(s)\n", list->size);
        }

        // free memory allocated to user list
        free_user_list(list);
        // print finishing message
        printf ("Transaction succeeded\nYou will now be redirected to main menu!\n");
    }
}


#endif