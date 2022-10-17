#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int log_fd = -1;

int log_init(char *path)
{
    int fd = open(path, O_CREAT | O_APPEND | O_RDWR);
    if (fd <= 0) {
        return fd;
    }
    log_fd = fd;

    return 0;
}

void log(char *buf)
{
    if (log_fd < 0) {
        return;
    }

    int count = strlen(buf);

    write(log_fd, buf, count);
    return;
}