NAME=sr
ARGS=-lcurl -DDEBUG

CC=gcc
OUTFILE=bin/$(NAME)
INFILES=$(wildcard src/*.c) $(wildcard src/lib/*.c)

$(NAME): 
	rm src/*~ src/\#* 2>/dev/null; \
	$(CC) -o $(OUTFILE) $(INFILES) $(ARGS)
