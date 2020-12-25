// define clearscreen.h if it is not already defined
#ifndef _CLEARSCREEN_H
#define _CLEARSCREEN_H

// necessary imports
#include <stdbool.h>
#include <stdlib.h>

// clear the console based on OS
void clear_screen(){
    // set it to true for windows environment
    bool isWindows = false;
    // on windows cls is used to clear console
    // on Linux/Mac clear is used to clear console
    if (isWindows)  system("cls");
    else            system("clear");
}


#endif