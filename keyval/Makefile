CC=gcc
INFILES=$(wildcard src/*.c)
OUTFILE=./bin/keyval
LIBS=

keyval:
	rm src/*~ src/\#* 2>/dev/null; \
	$(CC) -o $(OUTFILE) $(INFILES) $(LIBS)
