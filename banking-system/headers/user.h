// define user.h if not defined already
#ifndef _USER_H
#define _USER_H

// This file is responsible for all the user-related working
// This file do not handle any file operations

// fix the size of username and pin
#define USERNAME_SIZE 100
#define PIN_SIZE 4
#define ACCOUNT_SIZE 10
// max. input size for strings
#define MAX_STRING_SIZE 10000

// definition for user type
typedef struct User{
    // each user has name
    char username[USERNAME_SIZE + 1];
    // each user has 10-digit account number
    char account_no[ACCOUNT_SIZE + 1];
    // each user has a 4-digit pin
    char pin[PIN_SIZE + 1];
    // each user has bank-balance
    double balance;
}User;

#endif