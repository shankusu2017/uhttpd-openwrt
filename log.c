#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int log_init(char *path);
void xlog(char *format, ...);

int log_init(char *path)
{
    int fd = open(path, O_CREAT | O_APPEND | O_RDWR);
    return fd;
}

void xlog(char *format, ...)
{
    int fd = log_init("/tmp/uhttpd.log");
    if (fd < 0) {
        return;
    }

    time_t tt = time(0);
    char buf[32] = {0};
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&tt));
    dprintf(fd, "%-6.6s %-7.7d  %s ", "uhttpd", getpid(),  buf);

	va_list args;
	va_start(args, format);
	vdprintf(fd, format, args);
	va_end(args);

    close(fd);

	return;
}