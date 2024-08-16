CC=gcc
DEBUG=yes
# -W which warns about a selection of common programming errors, 
# such as functions which can return without a value 
# -g for debug
# -Wall to get all the possible warnings
# -ansi -pendantic to get portable code
# -Werror Make all warnings into errors. 
# -Wextra This enables some extra warning flags that are not enabled by -Wall.
ifeq ($(DEBUG),yes)
    CFLAGS=-W -Wall -Wconversion -Wshadow -Wcast-qual -Wwrite-strings -Werror -Wextra -ansi -pedantic-errors -g -std=c11
    LDFLAGS= -Wall -lm
else
    CFLAGS=-W -Wall -Wconversion -Wshadow -Wcast-qual -Wwrite-strings -Werror -Wextra -ansi -pedantic-errors -std=c11
    LDFLAGS= -Wall -lm
endif

main: main.o 
	$(CC) $(LDFLAGS) main.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o


clean:
	rm -f main main.o  	# Remove the executable file

