NAME=hk
ARGS=-DDEBUG

CC=gcc
INFILES=$(wildcard src/*.c)
HEADERS=$(wildcard src/*.h)

$(NAME): 
	rm src/*~ src/\#* 2>/dev/null; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -c -fPIC $(INFILES) -o bin/$(NAME).o; \
	$(CC) -shared -o bin/lib$(NAME).so bin/$(NAME).o;

install:
	cp bin/lib$(NAME).so /usr/lib/lib$(NAME).so; \
	cp $(HEADERS) /usr/include/

clean:
	rm -rf bin;
