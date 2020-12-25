// define todoio.h if not defined already
#ifndef _USERIO_H
#define _USERIO_H

// required for console IO
#include <stdio.h>
// for booleans
#include <stdbool.h>
// for character type
#include <ctype.h>
// for time
#include <time.h>
// include the todo header
#include "todo.h"
// for string operations
#include "strutil.h"
// for todolist
#include "todolist.h"
// for clear screen
#include "clearscreen.h"

// type of filter to be applied
// defines the constants with values 0, 1, 2, 3
typedef enum FILTER_TYPE{ALL, BEFORE, TODAY, AFTER, DONE, NOT_DONE}FILTER_TYPE;


// prints count many occurrences of symbol followed by newline
void print_header(int count, char symbol, char* title){
    for (int i = 0; i < count; ++i) printf("%c", symbol);
    printf ("\n%s\n", title);
    for (int i = 0; i < count; ++i) printf("%c", symbol);
    printf ("\n");
}


// returns true if a date is valid; false otherwise
// assumes that day, month and year are non-negative
bool is_valid_date(int day, int month, int year) {
    // number of days in month
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // check for leap year
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))  days_in_month[1] = 29;
    // check for year
    if (year < 1000 || year > 9999) return false;
    // check for month
    if (month < 1 || month > 12)    return false;
    // check if days
    if (day < 1 || day > days_in_month[month - 1])  return false;
    // all test cases passed so date is valid
    return true;
}

// gets the today's date
void today_date(int* day, int* month, int* year) {
    time_t t = time(NULL);
    struct tm *curr_tm = localtime(&t);
    *day = curr_tm->tm_mday;
    *month = curr_tm->tm_mon + 1;
    *year = curr_tm->tm_year + 1900;
}


// compares the dates
// returns -1, 0 or +1 according to date1 <, = or > date2
int compare_date(int d1, int m1, int y1, int d2, int m2, int y2) {
    // first compare years
    if (y1 < y2)        return -1;
    if (y1 > y2)        return +1;
    // year are same - compare months
    if (m1 < m2)        return -1;
    if (m1 > m2)        return +1;
    // months are also same -compare days
    if (d1 < d2)        return -1;
    if (d1 > d2)        return +1;

    // both the dates are same
    return 0;
}

// reads and validates the title
// if succeeds then updates the string and returns true
// otherwise returns false
bool read_title(char* string) {
    // stores the value for the title
    char title[MAX_STRING_SIZE];
    // prompt the user for title
    printf ("Title: ");
    // accept everything till a new-line
    // %*c will catch the new-line and throw it away
    scanf ("%[^\n]%*c", title);
    // remove the leading and trailing white-spaces
    trim(title);
    // get the length of trimmed content
    size_t length = len(title);
    // validate length
    if (length == 0) {
        // invalid input
        printf ("\033[31;1mTitle cannot be empty.\nOperation aborted!\nYou will now be redirected to main menu!\n\033[0m");
        // failure
        return false;
    } else if (length > TITLE_SIZE) {
        // max. size exceeded
        printf ("\033[31;1mMax. size exceeded for title.\nOperation aborted!\nYou will now be redirected to main menu!\n\033[0m");
        // invalid input
        return false;
    }
    // copy the value 
    string_copy(title, string);
    // success
    return true;
}


// reads and validates the deadline
// stores the deadline in passed string if succeeds and returns true
// otherwise returns false
bool read_deadline(char* string) {
    // stores the deadline
    char deadline[MAX_STRING_SIZE];
    // prompt for the deadline
    printf ("Deadline (dd/mm/yyyy): ");
    // scan the input
    scanf ("%[^\n]s%*c", deadline);
    // get the length of the input
    size_t length = len(deadline);
    // validate the length
    if (length != DEADLINE_SIZE) {
        // invalid length
        printf ("\033[31;1mInvalid deadline.\nOperation aborted!\nYou will now be redirected to main menu!\n\033[0m");
        // failure
        return false;
    } else {
        // validate the pattern
        bool isValidPattern = (isdigit(deadline[0]) && isdigit(deadline[1]) 
                                && isdigit(deadline[3]) && isdigit(deadline[4]) 
                                && isdigit(deadline[6]) && isdigit(deadline[7]) 
                                && isdigit(deadline[8]) && isdigit(deadline[9])
                                && deadline[2] == '/' && deadline[5] == '/');
        // get the day, month and year
        int day, month, year;
        sscanf(deadline, "%d%*c%d%*c%d", &day, &month, &year);
        // validate deadline
        if (!isValidPattern || !is_valid_date(day, month, year)) {
            // invalid deadline
            printf ("\033[31;1mInvalid deadline.\nOperation aborted!\nYou will now be redirected to main menu!\n\033[0m");
            // failure 
            return false;
        } else {
            // get today's date
            int tday, tmonth, tyear;
            today_date(&tday, &tmonth, &tyear);
            // check if deadline is before today
            if (compare_date(day, month, year, tday, tmonth, tyear) < 0) {
                // deadline has to be at least today
                printf ("\033[31;1mDeadline has to be at least today i.e. %02d/%02d/%04d.\nOperation aborted!\nYou will  now be redirected to main menu!\n\033[0m", tday, tmonth, tyear);
                // failure
                return false;
            }
            // copy the deadline
            string_copy(deadline, string);
            // success
            return true;
        }
    }
}


// reads and stores the description in string
void read_description(char* string) {
    // prompt the user for description
    printf ("Description (Ctrl + D to finish): ");
    // stores the index
    size_t index = 0;
    // stores the character
    char character;
    // iterate till end of file
    while ( (character = getchar()) != EOF) {
        // add this character to string
        string[index++] = character;
        // check if reached to end 
        if (index == DESCRIPTION_SIZE) {
            // max. size exceeded
            printf ("\033[31;1m\nMax. size exceeded for description\n\033[0m");
            // stop further input
            break;
        }
    }
    // append a null character at the end
    string[index] = '\0';
}



// reads the todoId
bool read_todoId(char* string) {
    // stores the value for the todoId
    char todoId[MAX_STRING_SIZE];
    // prompt the user for todoId
    printf ("TodoId: ");
    // accept everything till a new-line
    // %*c will catch the new-line and throw it away
    scanf ("%[^\n]%*c", todoId);
    // get the length of trimmed content
    size_t length = len(todoId);
    // validate length
    if (length != ID_SIZE) {
        // invalid input
        printf ("\033[31;1mTodoId must be of size %d.\nOperation aborted!\nYou will now be redirected to main menu!\n\033[0m", ID_SIZE);
        // failure
        return false;
    } else if (!is_numeric(todoId)){
        // invalid todoId
        printf ("\033[31;1mTodoId has to be numeric.\nOperation aborted!\nYou will now be redirected to main menu!\n\033[0m");
        // invalid input
        return false;
    }
    // copy the value 
    string_copy(todoId, string);
    // success
    return true;
}

// query the todo and validates
// stores in the pased variable if succeeds and return true
// otherwise returns false
bool query_todo(Todo* todo) {
    // query the title
    if (!read_title(todo->title))    return false;
    // query the deadline
    if (!read_deadline(todo->deadline))   return false;
    // query the description
    read_description(todo->description);
    // read everything
    return true;
}

// prints the todo with optional coloring
void todo_to_colored_string(Todo* todo, bool isColored) {
    // check if coloring is to be done
    if (isColored) {
        // check if this todo is done
        if (todo->finished) {
            // finished todos in gray
            printf ("\033[37;1m");
        } else {
            // check if this todo is passed
            int day, month, year;
            sscanf(todo->deadline, "%d/%d/%d", &day, &month, &year);
            // get today's date, month and year
            int tday, tmonth, tyear;
            today_date(&tday, &tmonth, &tyear);
            // compare dates
            int cmp = compare_date(day, month, year, tday, tmonth, tyear);
            // check if this todo has passed
            if (cmp < 0) {
                // missed todos in red
                // this todo is passed but not yet finished
                printf ("\033[31;1m");
            } else if (cmp == 0) {
                // today's todo in magenta
                printf ("\033[35;1m");
            } else {
                // upcoming todos in blue
                printf ("\033[34;1m");
            }
        }
    }  
    // print the id
    printf ("TodoId: %s\n", todo->todoId);
    // print the todo title
    printf ("Title: %s\n", todo->title);
    // print the status
    printf ("Status: %s\n", (todo->finished ? "DONE" : "NOT DONE"));
    // print the deadline
    printf ("Deadline: %s\n", todo->deadline);
    // print the description
    printf ("Description: %s\n", todo->description);
    // reset the coloring
    printf ("\033[0m");
}
// string representation of string
void uncolored_todo(Todo* todo) {
    todo_to_colored_string(todo, false);
}
// string representation of string
void colored_todo(Todo* todo) {
    todo_to_colored_string(todo, true);
}

// prints the color codes
void color_codes(){
    printf ("\033[0mCOLOR CODES:\n");
    printf ("\033[37;1m%-10s\t", "○ Done");
    printf ("\033[31;1m%-10s\t", "○ Missed");
    printf ("\033[35;1m%-10s\t", "○ Today");
    printf ("\033[34;1m%-10s\t", "○ Upcoming");
    printf ("\033[0m\n");
}



// print the list of todos according to filter type
void list_filter_todos(TodoList* list, FILTER_TYPE type) {
    // clear the console
    clear_screen();
    // get the header based on filter type
    char* header = (type == ALL ? "ALL TODO" : 
                    type == BEFORE ? "PAST TODO" : 
                    type == TODAY ? "TODAY TODO" : 
                    type == AFTER ? "UPCOMING TODO" :
                    type == DONE ? "DONE TODO" : 
                    type == NOT_DONE ? "NOT DONE TODO" : 
                    "");
    // header
    print_header(50, '=', header);
    // stores the number of items printed
    int count = 0;
    // get today's date
    int tday, tmonth, tyear; today_date(&tday, &tmonth, &tyear);
    // iterate through all records
    TodoListNode* temp = list->head;
    while (temp != NULL) {
        // fetch the todo
        Todo todo = temp->todo;
        // fetch the next user
        temp = temp->next;
        // get the deadline of this todo
        int day, month, year;
        sscanf(todo.deadline, "%d/%d/%d", &day, &month, &year);
        // compare the dates
        int cmp = compare_date(day, month, year, tday, tmonth, tyear);
        // check if this todo is to be printed
        if ( (type == ALL) || (type == BEFORE && cmp < 0)) {
            // print the details
            colored_todo(&todo);
            // increase the count
            count++;
        } else if ((type == TODAY && cmp == 0) ||  (type == AFTER && cmp > 0)) {
            // print the details
            uncolored_todo(&todo);
            // increse the count
            count++;
        } else if ((type == DONE && todo.finished) || (type == NOT_DONE && !todo.finished)) {
            // print the details
            colored_todo(&todo);
            // increse the count
            count++;
        }
    }
    // validate count
    if (count == 0) {
        // no records for given filter found
        printf ("No records found\n\n");
    } else {
        // print color codes if required
        if (type != TODAY && type != AFTER && type != DONE) color_codes();
        // print the total number of records
        printf ("\n\033[32;1mFound %d record(s)\n\033[0m", count);
    }
    // free memory allocated to todo list
    free_todo_list(list);
    // wait for user to press any key
    printf ("Press any key to continue..."); getchar();
    // print finishing message
    printf ("\033[32;1mOperation succeeded\nYou will now be redirected to main menu!\n\033[0m");
}


#endif