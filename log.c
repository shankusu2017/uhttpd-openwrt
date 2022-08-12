#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "uhttpd.h"


static int xlog_fd = -1;

int xlog_init(char *path)
{
    int fd = open(path, O_CREAT | O_APPEND | O_RDWR);
    if (fd <= 0) {
        return fd;
    }
    xlog_fd = fd;

    return 0;
}

void xlog(char *format, ...)
{
    if (xlog_fd < 0) {
        return;
    }
    return;

    va_list args;

    va_start(args, format);
    vdprintf(xlog_fd, format, args);
    va_end(args);

    return;
}