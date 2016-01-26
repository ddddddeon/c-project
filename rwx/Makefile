NAME=rwx
CC=gcc
OUTFILE=bin/$(NAME)
INFILES=$(wildcard src/*.c)
CFLAGS=-lhk -Wall

$(NAME): 
	rm src/*~ src/\#* 2>/dev/null; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o $(OUTFILE) $(INFILES) $(CFLAGS)

clean:
	@rm -rf bin;
