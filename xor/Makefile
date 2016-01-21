CC=gcc
OUTFILE=bin/xor
INFILES=$(wildcard src/*.c)

xor: 
	rm src/*~ src/\#* 2>/dev/null; \
	$(CC) -o $(OUTFILE) $(INFILES)
