NAME=cat
LIBS=-lhk
CFLAGS=-Wall $(LIBS) #-DDEBUG

CC=gcc

all: clean ls cat

clean: 	
	@set -e; \
	rm src/*~ src/\#* 2>/dev/null || true; \
	if [ ! -d bin ]; then mkdir bin; fi;
ls: 	
	$(CC) -o bin/ls src/ls.c $(CFLAGS)

cat: 
	$(CC) -o bin/cat src/cat.c $(CFLAGS)

