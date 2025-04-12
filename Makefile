CC = gcc
CFLAGS = -Wall -std=c99 -pedantic

SRC = postfix_main.c postfix_eval_functions.c
OBJ = $(SRC:.c=.o)
EXEC = postfix_eval

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXEC)
