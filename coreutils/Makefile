NAME=cat
LIBS=-lhk
CFLAGS=-Wall $(LIBS) #-DDEBUG

CC=gcc

all: ls cat

ls: 
	set -e; \
	rm src/*~ src/\#* 2>/dev/null || true; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o bin/ls src/ls.c $(CFLAGS)

cat: 
	set -e; \
	rm src/*~ src/\#* 2>/dev/null || true; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o bin/cat src/cat.c $(CFLAGS)

