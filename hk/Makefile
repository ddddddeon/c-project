NAME=hk
CFLAGS=-Wall -Werror #-DDEBUG

CC=gcc
INFILES=$(wildcard src/*.c)
TESTFILES=$(wildcard test/*.c)
HEADERS=$(wildcard src/*.h)

shared: $(NAME)
	@set -e; \
	$(CC) -shared -o bin/lib$(NAME).so $(wildcard bin/*.o); \
	echo "[OK] created shared object in ./bin/";

$(NAME): 
	@set -e; \
	echo "[*] compiling..."; \
	rm src/*~ src/\#* test/*~ test/\#* 2>/dev/null || true; \
	[ -d bin ] || mkdir bin; \
	for file in $(INFILES); do \
	  $(CC) $(CFLAGS) -c -fPIC $$file -o bin/$$(basename $${file%%.*}).o; \
	done; \
	echo "[OK] created object file(s) in ./bin/"; 

install: 
	@set -e; \
	echo "[*] installing..."; \
	[ -d bin ]; \
	[ -d /usr/include/hk ] || mkdir /usr/include/hk; \
	cp bin/lib$(NAME).so /usr/lib/lib$(NAME).so; \
	echo "[OK] shared libraries installed to /usr/lib/"; \
	cp $(HEADERS) /usr/include/hk/; \
	echo "[OK] headers installed to /usr/include/hk/";

uninstall:
	@set -e; \
	REMOVED=false; \
	[ ! -e /usr/lib/libhk.so ] || rm /usr/lib/libhk.so &&  REMOVED=true; \
	[ ! -d /usr/include/hk ] ||  rm -rf /usr/include/hk && REMOVED=true; \
	[ $$REMOVED = false ] || echo "[OK] uninstalled /usr/lib/libhk.so and /usr/include/hk";

clean:
	@( [ -d bin ] && rm -rf bin ) || true;

tests:
	@echo "[*] compiling tests..."; \
	rm test/*~ test/\#* 2>/dev/null || true; \
	$(CC) -o tests $(TESTFILES) -lhk; \
	echo "[*] running tests...\n"; \
	( ./tests && echo "[OK] all tests passed!" ) || \
	echo "[ERR] some tests failing...!"; \
	rm tests;

all: $(NAME) shared install tests clean

