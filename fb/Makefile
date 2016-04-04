NAME=fb
LIBS=-lhk
CFLAGS=-Wall $(LIBS) #-DDEBUG

CC=gcc
OUTFILE=bin/$(NAME)
INFILES=$(wildcard src/*.c)

$(NAME): 
	@set -e; \
	rm src/*~ src/\#* 2>/dev/null || true; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o $(OUTFILE) $(INFILES) $(CFLAGS); \
	sudo chown root:root bin/fb; \
	sudo chmod u+s bin/fb;

clean:	findBin
	@rm -rf bin;

findBin:
	@[ -d bin ];

indent:
	@indent -kr --no-tabs $(wildcard src/*.c src/*.h)

install:
	@mv bin/$(NAME) /usr/bin/$(NAME); \
	chmod a+x /usr/bin/$(NAME); \
	echo "[OK] installed to /usr/bin/$(NAME)";

all: $(NAME) findBin install

rebuild: clean $(NAME) install
