#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


#define BUFSIZE 8096
#define ERROR   42
#define LOG     44
#define FORBIDDEN 403
#define NOTFOUND  404

struct {
    char *ext;
    char *filetype;
} extensions [] = {
    {"gif", "image/gif"},
    {"jpg", "image/jpg"},
    {"jpeg", "image/jpeg"},
    {"png", "image/png"},
    {"ico", "image/ico"},
    {"zip", "image/zip"},
    {"gz", "image/gz"},
    {"tar", "image/tar"},
    {"htm", "text/htm"},
    {"html", "text/html"},
    {"0", "0"},
};

void logger(int type, char *s1, char *s2, int socket_fd) {
    int fd;
    char logbuffer[BUFSIZE*2];

    switch (type) {
        case ERROR:
            (void)sprintf(logbuffer, "ERROR: %s:%s Errno=%d exiting pid=%d",
                s1, s2, errno, getpid());
            break;
        case FORBIDDEN:
            (void)write(socket_fd, "");
            break;

    }
}
