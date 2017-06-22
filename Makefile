CC = gcc
DIR = /usr/bin/

all: 
	@echo "Compiling..."
	$(CC) command.c -o dictcc_REPL

install:
	$(all)
	cp dictcc_REPL $(DIR) 
