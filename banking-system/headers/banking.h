// define banking.h if not defined already
#ifndef _BANKING_H
#define _BANKING_H

// This file is responsible for handling all the banking operations
// And all the data is read and written to file

// for file IO
#include <stdio.h>
// for boolean operations
#include <stdbool.h>
// for user operations
#include "user.h"
// for user list
#include "userlist.h"

// stores the filename
const char* filename = "user-data/user_details.dat";
const char* tempfilename = "user-data/temp_user_details.dat";

// writes the user to file
// returns true if operation succeeds
// otherwise returns false
bool write_to_file(User user) {
    // open the file for append mode
    FILE* fptr = fopen(filename, "ab");
    // validate file pointer
    if (fptr == NULL)   return false;
    // write the object to file
    fwrite(&user, sizeof(User), 1, fptr);
    // close the file
    fclose(fptr);
    // success
    return true;
}


// reads the user with given details
// and returns the location where record is found
// if fails to find then returns -1
int read_user(User* user) {
    // open file for reading
    FILE* fptr = fopen(filename, "rb");
    // validate file
    if (fptr == NULL)   return false;
    // stores the details of the user
    User tempUser;
    // iterate through file and read documents
    while (fread(&tempUser, sizeof(User), 1, fptr) == 1) {
        // check if user matches
        if (string_equal(user->account_no, tempUser.account_no) 
                && string_equal(user->pin, tempUser.pin)) {
            // found user - update details
            *user = tempUser;
            // return the location
            return ftell(fptr) - 1*sizeof(User);
        }
    }
    // close the file
    fclose(fptr);
    // failed to find user
    return -1;
}


// replaces the user with given details (if exist)
// for update we over-write
// for delete we drop 
bool replace_user(User* user, bool dropUser) {
    // open file for reading
    FILE* fptr = fopen(filename, "rb");
    // validate file
    if (fptr == NULL)   return false;
    // open another file for writing
    FILE* tempPtr = fopen(tempfilename, "wb");
    // validate file
    if (tempPtr == NULL)    return false;
    // stores the details of the user
    User tempUser;
    // iterate through file and read documents
    while (fread(&tempUser, sizeof(User), 1, fptr) == 1) {
        // check if this user matches
        if (string_equal(user->account_no, tempUser.account_no)) {
            // check if we need to write another user
            if (!dropUser)   fwrite(user, sizeof(User), 1, tempPtr);
        } else {
            // write object to file
            fwrite(&tempUser, sizeof(User), 1, tempPtr);
        }
    }
    // close both the files
    fclose(fptr); fclose(tempPtr);
    // delete the actual file
    if (remove(filename) != 0)  return false;
    // rename and validate
    if (rename(tempfilename, filename) != 0) return false;
    // success 
    return true;
}

// saves the user with given details
bool save_user(User user) {
    // replace the user with new details
    return replace_user(&user, false);
}

// delets the user
bool delete_user(User user) {
    // replace the user with null
    return replace_user(&user, true);
}

// reads and returns the 
// list of users available
UserList* read_all() {
    // create a new empty list
    UserList* list = new_user_list();
    // validate list
    if (list == NULL)   return list;
    // open file for reading
    FILE* fptr = fopen(filename, "rb");
    // validate file
    if (fptr == NULL)   return list;
    // stores the details of the user
    User user;
    // iterate through file and read documents
    while (fread(&user, sizeof(User), 1, fptr) == 1) {
        // add the item to list
        add_to_list(list, user);
    }
    // close the file
    fclose(fptr);
    // return the newly created list
    return list;
}

#endif