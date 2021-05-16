##
## EPITECH PROJECT, 2020
## B-PSU-101-MPL-1-1-minishell1-guillaume.boudaille
## File description:
## Makefile
##

CC	=	gcc

SRC	=	$(wildcard *.c)

LIB	=	mysh

all:	$(LIB)

$(LIB):	$(SRC)
	$(CC) $(SRC) -o $(LIB)

clean:
	rm -f $(LIB)

re:
	rm -f $(LIB)
	$(CC) $(SRC) -o $(LIB)