#include "postfix_eval.h"
#include <stdio.h>
#include <stdlib.h>

// Pushes a new operand value onto the stack.
void push(Operand **stack, double value) {
    Operand *new_node = (Operand *)malloc(sizeof(Operand));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

// Pops the top operand from the stack.
double pop(Operand **stack) {
    if (*stack == NULL) {
        printf("Error: Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    Operand *temp = *stack;
    double popped_value = temp->value;
    *stack = (*stack)->next;
    free(temp);
    return popped_value;
}

// Prints the stack contents from top to bottom.
void print(Operand *stack) {
    Operand *current = stack;
    printf("Stack (top to bottom):\n");
    while (current != NULL) {
        printf("%.2f\n", current->value);
        current = current->next;
    }
}

// Returns true if the character is a digit (0-9).
bool is_operand(char ch) {
    return (ch >= '0' && ch <= '9');
}

// Returns true if the character is a valid operator.
bool is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Performs the arithmetic operation specified by 'operator' on op1 and op2.
double perform_operation(char operator, double op1, double op2) {
    switch (operator) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/':
            if (op2 == 0) {
                printf("Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
            return op1 / op2;
        default:
            printf("Error: Invalid operator.\n");
            exit(EXIT_FAILURE);
    }
}

// Evaluates a postfix expression and returns the result.
double evaluate_postfix(Operand **stack, char *expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (is_operand(expression[i])) {
            push(stack, (double)(expression[i] - '0'));
        } else if (is_operator(expression[i])) {
            if (*stack == NULL) {
                printf("Error: Invalid expression.\n");
                exit(EXIT_FAILURE);
            }
            double op2 = pop(stack);
            if (*stack == NULL) {
                printf("Error: Invalid expression.\n");
                exit(EXIT_FAILURE);
            }
            double op1 = pop(stack);
            double result = perform_operation(expression[i], op1, op2);
            push(stack, result);
        } else {
            printf("Error: Invalid character in expression.\n");
            exit(EXIT_FAILURE);
        }
    }
    double result = pop(stack);
    if (*stack != NULL) {
        printf("Error: Invalid expression.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
