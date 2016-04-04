#ifndef FB_H
#define FB_H

#define XSIZE 1080
#define YSIZE 1920

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include <signal.h>
#include <malloc.h>

typedef struct {
    int fbfd;
    char *fbp;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    int screensize;

} screen_writer;

void sig_handler(int signo);
void draw(screen_writer * sw, unsigned int r, unsigned int g,
          unsigned int b);
screen_writer *new_screen_writer();
void setup_framebuffer(screen_writer * sw);

#endif                          /* !FB_H */
