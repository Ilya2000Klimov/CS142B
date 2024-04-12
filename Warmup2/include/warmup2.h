#ifndef WARMUP2
#define WARMUP2

#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

// Parses an integer number from the current position of the input string and updates the pointer.
int number(char **input);

// Parses a factor, either a number or a nested expression in parentheses, and updates the pointer.
int factor(char **input);

// Parses a term, potentially followed by multiplication or division operations, and updates the pointer.
int term(char **input);

// Parses an expression, potentially followed by addition or subtraction operations, and updates the pointer.
int expression(char **input);


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
