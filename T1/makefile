# makefile para exercicios da aula de revisão SPDis 17-18

CC = gcc 
CFLAGS = -Wall -std=gnu99 
LDFLAGS = -lm

SRC2 = hello.c
SRC3 = p2.6.c

all: hello args
.PHONY: all

hello:  $(SRC2) makefile
    $(CC) $(CFLAGS) $(SRC2) $(LDFLAGS) -o $@ 

args:   $(SRC3) makefile
    $(CC) $(CFLAGS) $(SRC3) $(LDFLAGS) -o $@ 

