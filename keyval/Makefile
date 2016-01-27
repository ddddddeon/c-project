CC=gcc
INFILES=$(wildcard src/*.c)
OUTFILE=./bin/keyval
LIBS=-lhk

keyval:
	rm src/*~ src/\#* 2>/dev/null; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o $(OUTFILE) $(INFILES) $(LIBS)

clean:
	@rm -rf bin;
