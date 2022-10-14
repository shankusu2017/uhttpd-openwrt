#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include "uhttpd.h"

// static int log_fd = -1;

// int log_init(char *path)
// {
//     int fd = open(path, O_CREAT | O_APPEND | O_RDWR);
//     if (fd <= 0) {
//         return fd;
//     }
//     log_fd = fd;

//     return 0;
// }


// void xlog(char *format, ...)
// {
//     return;
// 	va_list args;

// 	va_start(args, format);

// 	vdprintf(log_fd, format, args);

// 	va_end(args);

// 	return;
// }