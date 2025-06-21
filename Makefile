##
# Contact Book
#
# @file main.c
# @brief This file compiles the contact book CLI
#
# @author Connor Akey
# @date 2025-06-21
# @version 1.0
#
# @details
#	This file has two different compilation methods, gcc (for linux) and clang (for mac)
#	If you want to use clang on linux or gcc on mac it should work perfectly fine.
#	To compile for windows you should manually input gcc -o main main.c and not use make since windows doesn't come with make builtin
#	If you can get make to somehow work on windows building with gcc is recommended for windows (idk about arm tbh)
#	If you are finished with the program feel free to do make clean
##

CC_GCC = gcc
CC_CLANG = clang
CFLAGS = -O2 -Wall -Wextra -Wpedantic -std=c11

all: main

main: main.c
	$(CC_GCC) $(CFLAGS) -o main main.c

clang: main.c
	$(CC_CLANG) $(CFLAGS) -o main main.c

clean:
	rm -f main
