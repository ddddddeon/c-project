CC=gcc
NAME=xor
CFLAGS=#-DDEBUG
LIBS=-lhk
OUTFILE=bin/$(NAME)
INFILES=$(wildcard src/*.c)


xor: 
	rm src/*~ src/\#* 2>/dev/null; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o $(OUTFILE) $(INFILES) $(LIBS) $(CFLAGS)

clean:
	@rm -rf bin;
