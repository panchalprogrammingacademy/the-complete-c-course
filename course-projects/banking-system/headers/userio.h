// define userio.h if not defined already
#ifndef _USERIO_H
#define _USERIO_H

// required for console IO
#include <stdio.h>
// for booleans
#include <stdbool.h>
// include the user header
#include "user.h"
// for string operations
#include "strutil.h"



// reads the username from console
// returns true if username is correct
// otherwise returns false
bool read_username(char* string) {
    // stores the values for the user
    char username[MAX_STRING_SIZE];
        // prompt for user-name
    printf ("Username: ");
    // get all character until a next-line
    // %*c captures the next-line and throws it away
    scanf("%[^\n]%*c", username);

    // remove leading and trailing whitespaces
    trim(username);
    // get the new length
    size_t length = len(username);
    // verify the length
    if (length == 0) {
        // transaction aborted
        printf ("Username cannot be empty.\nTransaction aborted!\nYou will now be redirected to main menu!\n");
        // return error
        return false;
    } else if (length > USERNAME_SIZE) {
        // transaction aborted
        printf ("Max. length exceeded for username.\nTransaction aborted!\nYou will now be redirected to main menu!\n");
        // error
        return false;
    }
    // update the username
    string_copy(username, string);
    // success
    return true;
}

// reads the pin and returns true
// if pin is validated otherwise returns false
bool read_pin(char* string) {
    // stores the values for the user
    char pin[MAX_STRING_SIZE];
    // prompt for pin
    printf ("PIN: ");
    // get all character until a next-line
    // %*c captures the next-line and throws it away
    scanf("%[^\n]%*c", pin);
    // trim the pin
    trim(pin);
    // validate the length of the pin
    size_t pLen = len(pin);
    if (pLen != PIN_SIZE) {
        // invalid pin
        printf ("PIN size must be %d\nTransaction aborted!\nYou will now be redirected to main menu!\n", PIN_SIZE);
        // error
        return false;
    }
    // check if string is numeric
    if (!is_numeric(pin)) {
        // invalid pin
        printf ("PIN must be numeric\nTransaction aborted!\nYou will now be redirected to main menu!\n");
        // error 
        return false;
    }
    // copy the pin
    string_copy(pin, string);
    // success
    return true;
}

// reads the account number and 
// returns true if validated
// false otherwise
bool read_account_no(char* string) {
    // stores the values for the user
    char account_no[MAX_STRING_SIZE];
    // prompt for account number
    printf ("Account number: ");
    // get all character until a next-line
    // %*c captures the next-line and throws it away
    scanf("%[^\n]%*c", account_no);
    // trim the account_no
    trim(account_no);
    // validate the length of the account_no
    size_t aLen = len(account_no);
    if (aLen != ACCOUNT_SIZE) {
        // invalid account_no
        printf ("Account number size must be %d\nTransaction aborted!\nYou will now be redirected to main menu!\n", ACCOUNT_SIZE);
        // error
        return false;
    }
    // check if string is numeric
    if (!is_numeric(account_no)) {
        // invalid account_no
        printf ("Account number must be numeric\nTransaction aborted!\nYou will now be redirected to main menu!\n");
        // error 
        return false;
    }
    // copy the account_no
    string_copy(account_no, string);
    // success
    return true;
}




// query the user for account_no and PIN
// returns true if succeds 
// otherwise returns false
bool query_user(User* user) {
    // prompt for account number
    if (!read_account_no(user->account_no)) return false;
    // prompt for pin
    if (!read_pin(user->pin))   return false;
    // sucess
    return true;
}


// string representation of string
void user_to_string(User* user) {
    // print the username
    printf ("Username: %s\n", user->username);
    // print the account number
    printf ("Account number: %s\n", user->account_no);
    // pirnt the pin
    printf ("PIN: %s\n", user->pin);
    // print the balance
    printf ("Balance: %.2lf\n", user->balance);
}
#endif