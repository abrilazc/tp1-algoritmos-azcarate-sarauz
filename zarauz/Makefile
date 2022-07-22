CC = gcc
CFLAGS = -Wall -g -std=c99 -pedantic -Werror 
LDFLAGS = -lm

SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

PROGRAM = carga_puntos

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

$(PROGRAM): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(PROGRAM) $(LDFLAGS)

clean:
	rm -f $(PROGRAM) $(OBJ_FILES) puntos.txt

valgrind:
	valgrind --suppressions=suppressions_20221_tp1.supp --leak-check=full ./gravitar