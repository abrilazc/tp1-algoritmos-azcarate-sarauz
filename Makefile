CC = gcc
CFLAGS = -Wall -g -std=c99 -pedantic -Werror 
LDFLAGS = -lm

SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

PROGRAM = E4_99465

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

$(PROGRAM): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(PROGRAM) $(LDFLAGS)

clean:
	rm -f $(PROGRAM) $(OBJ_FILES)