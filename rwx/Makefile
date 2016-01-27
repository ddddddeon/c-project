NAME=rwx
CC=gcc
OUTFILE=bin/$(NAME)
INFILES=$(wildcard src/*.c)
LIBS=-lhk
CFLAGS=-Wall $(LIBS) #-DDEBUG

$(NAME): 
	rm src/*~ src/\#* 2>/dev/null; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o $(OUTFILE) $(INFILES) $(CFLAGS)

install:
	@mv bin/$(NAME) /usr/bin/$(NAME); \
	chmod a+x /usr/bin/$(NAME); \
	echo "[OK] installed to /usr/bin/$(NAME)";

clean:
	@rm -rf bin/*;

all: clean $(NAME) install

