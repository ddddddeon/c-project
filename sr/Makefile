NAME=sr
LIBS=-lcurl -lhk
CFLAGS=-DDEBUG -Wall -Werror $(LIBS)

CC=gcc
OUTFILE=bin/$(NAME)
INFILES=$(wildcard src/*.c) $(wildcard src/lib/*.c)

$(NAME): 
	set -e; \
	rm src/*~ src/\#* 2>/dev/null || true; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o $(OUTFILE) $(INFILES) $(CFLAGS)

clean:	findBin
	@rm -rf bin;

findBin:
	@[ -d bin ];

tests: findBin
	bin/sr programmerhumor 1; \
	bin/sr programmerhumorasdfasdfasdflkajshdflkjashdlkfjhasldkjfhalskdjfhlaskdj 1 || true;

install:
	@mv bin/$(NAME) /usr/bin/$(NAME); \
	chmod a+x /usr/bin/$(NAME); \
	echo "[OK] installed to /usr/bin/$(NAME)";

all: $(NAME) findBin tests install

rebuild: clean $(NAME) install
