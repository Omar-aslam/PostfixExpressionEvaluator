#include "postfix_eval.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // Ensure exactly one argument (the postfix expression) is provided.
    if (argc != 2) {
        printf("Usage: %s <postfix_expression>\n", argv[0]);
        return 1;
    }

    Operand *stack = NULL;

    // Evaluate the postfix expression passed as command-line argument.
    double result = evaluate_postfix(&stack, argv[1]);

    // Print the result formatted to 2 decimal places.
    printf("Result: %.2f\n", result);
    return 0;
}
