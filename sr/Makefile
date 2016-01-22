NAME=sr
ARGS=-lcurl -lhk -DDEBUG

CC=gcc
OUTFILE=bin/$(NAME)
INFILES=$(wildcard src/*.c) $(wildcard src/lib/*.c)

$(NAME): 
	rm src/*~ src/\#* 2>/dev/null; \
	if [ ! -d bin ]; then mkdir bin; fi; \
	$(CC) -o $(OUTFILE) $(INFILES) $(ARGS)

clean:
	@rm -rf bin;
