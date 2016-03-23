NAME=red
LIBS=-lhk -lhiredis
CFLAGS=-Wall $(LIBS) #-DDEBUG

CC=gcc
OUTFILE=bin/$(NAME)
INFILES=$(wildcard src/*.c)

$(NAME): 
	set -e; \
	rm src/*~ src/\#* 2>/dev/null || true; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o $(OUTFILE) $(INFILES) $(CFLAGS)

clean:	findBin
	@rm -rf bin;

findBin:
	@[ -d bin ];

install:
	@mv bin/$(NAME) /usr/bin/$(NAME); \
	chmod a+x /usr/bin/$(NAME); \
	echo "[OK] installed to /usr/bin/$(NAME)";

all: $(NAME) findBin install

rebuild: clean $(NAME) install
