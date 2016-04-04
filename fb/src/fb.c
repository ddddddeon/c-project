#include "fb.h"

void sig_handler(int signo)
{
    exit(0);
}

screen_writer *new_screen_writer()
{
    screen_writer *new = malloc(sizeof(screen_writer));

    int fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    new->fbfd = fbfd;

    return new;
};

void draw(screen_writer * sw, unsigned int r, unsigned int g,
          unsigned int b)
{
    struct fb_var_screeninfo vinfo = sw->vinfo;
    struct fb_fix_screeninfo finfo = sw->finfo;
    char *fbp = sw->fbp;

    int location;
    int x = 0;
    int y = 0;

    for (y = 0; y < XSIZE; y++) {
        for (x = 0; x < YSIZE; x++) {
            location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8)
                + (y + vinfo.yoffset)
                * finfo.line_length;

            if (vinfo.bits_per_pixel == 32) {
                *(fbp + location) = b;
                *(fbp + location + 1) = g;
                *(fbp + location + 2) = r;
                *(fbp + location + 3) = 0;
            } else {
                perror("Not 32 bytes per pixel :(");
                exit(1);
            }

        }
    }
}

void setup_framebuffer(screen_writer * sw)
{
    sw->fbp = 0;

    if (ioctl(sw->fbfd, FBIOGET_FSCREENINFO, &sw->finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    if (ioctl(sw->fbfd, FBIOGET_VSCREENINFO, &sw->vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    sw->screensize =
        sw->vinfo.xres * sw->vinfo.yres * sw->vinfo.bits_per_pixel / 8;

    sw->fbp = (char *) mmap(0, sw->screensize, PROT_READ | PROT_WRITE,
                            MAP_SHARED, sw->fbfd, 0);

    if ((long int) sw->fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
}
