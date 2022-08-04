CC = gcc
CFLAGS = -Wall -g -std=c99 -pedantic -Werror 
LDFLAGS = -lm -lSDL2

SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

PROGRAM = uwu

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

$(PROGRAM): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(PROGRAM) $(LDFLAGS)

clean:
	rm -f $(PROGRAM) $(OBJ_FILES)

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./uwu

valgrindsdl:
	valgrind --suppressions=suppressions_20221_tp1.supp --leak-check=full ./uwu