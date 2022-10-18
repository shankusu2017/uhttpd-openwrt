#ifndef UBUSLOG_H_20221018
#define UBUSLOG_H_20221018

#define XP_DEBUG 

void ubuslog(char *format, ...);


#define ulog(format, ...) \
        ubuslog("[%s:%d->%s] "format, __FILE__, __LINE__, __func__, ##__VA_ARGS__)


#endif 