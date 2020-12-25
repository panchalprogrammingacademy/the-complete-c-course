// define todo.h if not defined already
#ifndef _TODO_H
#define _TODO_H


// for boolean type
#include <stdbool.h>

// fix the sizes
#define TITLE_SIZE 100
#define DESCRIPTION_SIZE 1000
#define DEADLINE_SIZE 10
#define ID_SIZE 10
// max. input size for strings
#define MAX_STRING_SIZE 10000

// definition for todo type
typedef struct Todo{
    // each todo has title
    char title[TITLE_SIZE + 1];
    // each todo has description
    char description[DESCRIPTION_SIZE + 1];
    // each todo has a deadline
    char deadline[DEADLINE_SIZE + 1];
    // each todo has a status
    bool finished;
    // each todo has a unique id
    char todoId[ID_SIZE + 1];
}Todo;

#endif