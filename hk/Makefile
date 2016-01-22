NAME=hk
CFLAGS=-DDEBUG -Wall -Werror

CC=gcc
INFILES=$(wildcard src/*.c)
TESTFILES=$(wildcard test/*.c)
HEADERS=$(wildcard src/*.h)

$(NAME): 
	@set -e; \
	rm src/*~ src/\#* test/*~ test/\#* 2>/dev/null || true; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) $(CFLAGS) -c -fPIC $(INFILES) -o bin/$(NAME).o; \
	echo "[OK] created object file"; \
	$(CC) -shared -o bin/lib$(NAME).so bin/$(NAME).o; \
	echo "[OK] created shared object";
install: 
	@set -e; \
	[ -d bin ]; \
	[ -d /usr/include/hk ] || mkdir /usr/include/hk; \
	cp bin/lib$(NAME).so /usr/lib/lib$(NAME).so; \
	echo "[OK] shared libraries installed to /usr/lib/"; \
	cp $(HEADERS) /usr/include/hk/; \
	echo "[OK] headers installed to /usr/include/hk";

clean:
	@( [ -d bin ] && rm -rf bin ) || true;

tests:
	@echo "[*] running tests..."; \
	$(CC) -o tests $(TESTFILES) -lhk; \
	./tests && \
	echo "[OK] all tests passed!"; \
	rm tests;

all: $(NAME) install tests clean

