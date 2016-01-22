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

test: findBin
	bin/sr programmerhumor 1; \
	bin/sr programmerhumorasdfasdfasdflkajshdflkjashdlkfjhasldkjfhalskdjfhlaskdjfhlaksdjfhlaksjdhflakjsdhflaksjdhflaksjdhflkajsdhflkajsdhflkjasdhflkajsdhflkjasdhflkjasdhflkjasdhflkjasdhflkjashdflkjasdhflkjasdhflkajsdhflkajsdhflkajsdhflkajsdhflkjashdflkjashdflkjahsdflkjhasdlfkjhasdlkfjhasdlkfjhaslkdjfhlaksdjfhlkasdjfhlkasjdhflkasjdhflkasjdfhlkasjdhflkasdjhflkajsdhf 1 || true;

all: clean $(NAME) findBin test

rebuild: clean $(NAME)
