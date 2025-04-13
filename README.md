# Postfix Expression Evaluator

## Project Overview

This project implements a postfix (Reverse Polish Notation) expression evaluator in C. Using a linked list-based stack, the program parses and evaluates an expression provided via the command line. 
It is built with a modular design to promote maintainability, and it employs robust error handling to manage invalid input and runtime exceptions such as division by zero.


## Steps to Run in VS Code

### Prerequisites

- **Visual Studio Code**: Install from [here](https://code.visualstudio.com/).
- **C/C++ Extension by Microsoft**: Available in the VS Code Extensions Marketplace.
- **GCC Compiler**: Ensure you have GCC installed on your system (e.g., via MinGW on Windows or using a package manager on Linux/Mac).

Technical Explanation
Stack-Based Evaluation:
The evaluator uses a linked list to implement a stack. Each node (an Operand) stores a double value and a pointer to the next node.

Push/Pop Operations: These functions add or remove values from the stack.

Printing: The stack’s contents can be printed for debugging purposes.

Parsing and Evaluation:

Operands: The program treats characters '0'-'9' as operands and converts them to numeric values.

Operators: When an operator (+, -, *, /) is encountered, it pops two operands, applies the operation, and pushes the result back.

Error Handling: Checks for invalid characters, insufficient operands, and division by zero ensure robust execution.

Modular Design:
The project is divided into:

postfix_main.c: Handles command-line parsing and program control.

postfix_eval.h: Provides declarations and data structures for the evaluator.

postfix_eval_functions.c: Contains all the core logic for operations and evaluation. This separation makes the code easier to understand, maintain, and extend.

Compilation Flags:
The Makefile uses -Wall -std=c99 -pedantic to enforce strict compilation rules, which helps catch common errors and ensures compliance with the C99 standard.



