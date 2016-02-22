#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int fd;
    char buf[BUFSIZE];

    if (argc != 2) {
        printf("usage: cat <file>\n");
        fd = STDIN_FILENO;

    } else {
        if (strlen(argv[1]) > BUFSIZE) {
            printf("pathname too long\n");
            return 1;
        }

        fd = open(argv[1], O_RDONLY);
        if (fd < 0) {
            printf("could not open %s\n", argv[1]);
            return 1;
        }
    }

    int n;
    while ((n = read(fd, buf, BUFSIZE)) > 0) {
        write(STDOUT_FILENO, buf, n);
    }
    
    close(fd);
    return 0;
}
