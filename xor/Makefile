CC=gcc
NAME=xor
OUTFILE=bin/$(NAME)
INFILES=$(wildcard src/*.c)
LIBS=-lhk

xor: 
	rm src/*~ src/\#* 2>/dev/null; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o $(OUTFILE) $(INFILES) $(LIBS)

clean:
	@rm -rf bin;
