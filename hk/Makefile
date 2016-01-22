NAME=hk
CFLAGS=-DDEBUG -Wall -Werror

CC=gcc
INFILES=$(wildcard src/*.c)
TESTFILES=$(wildcard test/*.c)
HEADERS=$(wildcard src/*.h)

$(NAME): 
	set -e; \
	rm src/*~ src/\#* test/*~ test/\#* 2>/dev/null || true; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) $(CFLAGS) -c -fPIC $(INFILES) -o bin/$(NAME).o; \
	$(CC) -shared -o bin/lib$(NAME).so bin/$(NAME).o; \

install: 
	set -e; \
	[ -d bin ];
	[ -d /usr/include/hk ] || mkdir /usr/include/hk; \
	cp bin/lib$(NAME).so /usr/lib/lib$(NAME).so; \
	cp $(HEADERS) /usr/include/hk/

clean:
	@( [ -d bin ] && rm -rf bin ) || true;

tests:
	$(CC) -o tests $(TESTFILES) -lhk; \
	./tests && \
	echo "[OK] all tests passed!"; \
	rm tests;

all: clean $(NAME) install tests

