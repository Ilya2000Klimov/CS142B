#ifndef HW_1_H
#define HW_1_H

#include <stdio.h>
#include <stdlib.h>
#include "helpers1.h"

// Parses an integer number from the current position of the input string.
int number();

// Parses a factor, which is either a simple number or a nested expression
// enclosed in parentheses.
int factor();

// Parses a term, which is a factor potentially followed by multiplication
// or division operations.
int term();

// Parses an expression, which is a term potentially followed by addition
// or subtraction operations.
int expression();


#define USAGE "digit = \"0\" | \"1\" | ... | \"9\"\n\
                number = digit {digit}.\
                factor = number | \"(\" expression \")\".\
                term = factor { (\"*»|\"/\") factor}.\
                expression = term {(\"+\" | \"-\") term}.\
                computation = expression \" \""

// // Usage statement
// #define USAGE "usage:\n\
//                53markdown -h | -O | -H NUM\n\
//                53markdown -E | -K KEYWORD [-c]\n"

// // MACRO for KEYWORD highlighting, BOLD with Red foreground and White Background
// #define COLOR_START "\e[1;31;47m"
// #define COLOR_RESET "\e[0m"

#endif
