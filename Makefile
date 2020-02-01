CC=gcc
CFLAGS=-I.

all:
	$(CC) -o three_dice_monty three_dice_monty.c

clean:
	rm -f three_dice_monty
