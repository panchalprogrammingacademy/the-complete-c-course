// define the strutil.h if not alread defined
#ifndef _STRUTIL_H
#define _STRUTIL_H

// necessary imports
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#include <stdio.h>

// define methods in strings
size_t len(char* string) {
    // assert that string is not null
    assert (string != NULL);
    // compute the length of the string
    size_t size = 0;
    while (string[size] != '\0')    size++;
    // return the computed size
    return size;
}

// trims the string i.e. 
// removes the leading and trailing whitespaces
void trim(char* string) {
    // assert that string is not null
    assert (string != NULL);
    // get the length of the string
    size_t length = len(string);
    // if length of the string is zero we need not to do anything
    if (length == 0)    return;
    // stores the index of first non-whitespace character from start
    int startIndex = 0;
    // stores the index of first non-whitespace character from end
    int endIndex = len(string) - 1;
    // search from begin
    while (startIndex < length && isspace(string[startIndex]))  startIndex++;
    // search from the end
    while (-1 < endIndex && isspace(string[endIndex])) endIndex--;
    // validate start and end indices
    if (startIndex < length && -1 < endIndex) {
        // string contains some non-space characters
        // modify the content of string
        // stores the index
        size_t index = 0;
        for (size_t j = startIndex; j <= endIndex;  ++j)
            string[index++] = string[j];
        // update the last index
        string[index] = '\0';
    } else {
        // string is empty
        string[0] = '\0';
    }
}


// copies the source string to destination
void string_copy(char* source, char* destination){
    // assert that source is not null
    assert (source != NULL);
    // assert that destination is not null
    assert (destination != NULL);
    // get the length of source
    size_t length = len(source);
    // copy the content to destination
    for (size_t i = 0; i < length; ++i) destination[i] = source[i];
    // update the end character
    destination[length] = '\0';
}


// checks if a string is numeric
bool is_numeric(char* string) {
    // assert that string is not null
    assert (string != NULL);
    // iterate through all characters and verify
    // that they are numeric/digit
    for (size_t i = 0; string[i] != '\0'; ++i)
        // validate ith character
        if (string[i] < '0' || string[i] > '9') return false;
    // if all the characters are digits then it is numeric
    return true;
}


// compares the strings
bool string_equal(char* string1, char* string2) {
    // get the lengths of string1 and string2
    size_t length1 = len(string1), length2 = len(string2);
    // compare lengths
    if (length1 != length2) return false;
    // iterate and compare characters
    for (size_t i = 0; i < length1; ++i)
        // compare ith character
        if (string1[i] != string2[i])   return false;
    // both strings matched
    return true;
}

#endif