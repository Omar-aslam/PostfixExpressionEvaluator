#ifndef POSTFIX_EVAL_H
#define POSTFIX_EVAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * A linked list-based stack structure used to evaluate 
 * postfix expressions (Reverse Polish Notation). Each node represents an operand.
 */
typedef struct operand {
    double value;         // The numeric value (operand)
    struct operand *next; // Pointer to the next stack node
} Operand;

/* Stack Operation Function Prototypes */

// Pushes a new operand onto the stack.
void push(Operand **stack, double value);

// Pops the top operand from the stack and returns its value.
double pop(Operand **stack);

// Prints all elements of the stack.
void print(Operand *stack);

/* Postfix Expression Evaluation Function Prototypes */

// Checks if a given character is a valid operator (+, -, *, /).
bool is_operator(char ch);

// Checks if a given character is a digit (operand).
bool is_operand(char ch);

// Performs the specified arithmetic operation on two operands.
// Exits the program if division by zero is attempted.
double perform_operation(char operator, double op1, double op2);

// Evaluates the given postfix expression and returns the result.
double evaluate_postfix(Operand **stack, char *expression);

#endif
