#include "fb.h"

int main(int argc, char *argv[])
{
    signal(SIGINT, sig_handler);

    int ttyfd = open("/dev/tty0", O_RDWR);
    void bye() {
        ioctl(ttyfd, KDSETMODE, KD_TEXT);
    }
    atexit(bye);

    ioctl(ttyfd, KDSETMODE, KD_GRAPHICS);


    if (argc < 4) {
        printf("must supply r, g, b\n");
        exit(1);
    }
    unsigned int r = atoi(argv[1]);
    unsigned int g = atoi(argv[2]);
    unsigned int b = atoi(argv[3]);
    int c = 0;

    screen_writer *sw = new_screen_writer();
    setup_framebuffer(sw);

    for (;;) {
        for (c = 0; c <= 200; c++) {
            draw(sw, r, g, b);
            r = (r + 1) % 200;
            g = (g + 1) % 200;
            b = (b + 1) % 200;
            usleep(1000);
        }

        for (c = 200; c >= 0; c--) {
            draw(sw, r, g, b);
            r = (r - 1) % 200;
            g = (g - 1) % 200;
            b = (b - 1) % 200;
            usleep(1000);
        }
    }

    munmap((void *) sw->fbp, sw->screensize);
    close(sw->fbfd);
    return 0;
}
