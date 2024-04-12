#include "hw1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// You may define any helper functions you want. Place them in helpers.c/.h

char *input;

// Parse a number from the input
int number() {
    int result = 0;
    while (*input >= '0' && *input <= '9') {
        result = result * 10 + (*input - '0');
        input++;
    }
    return result;
}

// Parse a factor: either a number or a parenthesized expression
int factor() {
    while (*input == ' ') input++;  // Skip whitespace

    if (*input == '(') {
        input++;  // Skip '('
        int result = expression();
        while (*input == ' ') input++;  // Skip whitespace
        if (*input != ')') {
            printf("Error: Missing ')'.\n");
            exit(1);
        }
        input++;  // Skip ')'
        return result;
    } else {
        return number();
    }
}

// Parse a term which is a factor followed by zero or more * or / operations
int term() {
    int result = factor();
    while (1) {
        while (*input == ' ') input++;  // Skip whitespace

        if (*input == '*') {
            input++;  // Skip '*'
            result *= factor();
        } else if (*input == '/') {
            input++;  // Skip '/'
            int divisor = factor();
            if (divisor != 0) {
                result /= divisor;
            } else {
                printf("Error: Division by zero.\n");
                exit(1);
            }
        } else {
            break;
        }
    }
    return result;
}

// Parse an expression which is a term followed by zero or more + or - operations
int expression() {
    int result = term();
    while (1) {
        while (*input == ' ') input++;  // Skip whitespace

        if (*input == '+') {
            input++;  // Skip '+'
            result += term();
        } else if (*input == '-') {
            input++;  // Skip '-'
            result -= term();
        } else {
            break;
        }
    }
    return result;
}

// Main function to process expressions from command line arguments
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s '<expression>'.\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        input = argv[i];
        while(*input != '\0')
        {
            int result = expression();
            while (*input == ' ') input++;  // Skip whitespace
            if (*input != '.' && *input != '\0') {
                printf("Error: Expression must be deliminated with a period.\n");
                return 1;
            }
            else if (*input == '.')
                input++;
            printf("%d\n", result);
        }
    }
    return 0;
}
