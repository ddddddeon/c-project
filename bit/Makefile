NAME=bit
CC=gcc
OUTFILE=bin/$(NAME)
INFILES=$(wildcard src/*.c)

xor: 
	rm src/*~ src/\#* 2>/dev/null; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o $(OUTFILE) $(INFILES)

clean:
	@rm -rf bin;
