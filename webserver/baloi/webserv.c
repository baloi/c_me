#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>


#define BUFSIZE 8096
#define ERROR   42
#define LOG     44
#define FORBIDDEN 403
#define NOTFOUND  404

/*******************************************************************************
 *                                                                             *
 * Simple webserver in C                                                       *
 *                                                                             *
 ******************************************************************************/

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
    const char *forbidden_msg = "HTTP/1.1 403 Forbidden\nContent-Length: 185\n"
        "Connection: close\nContent-Type: text/html\n\n"
        "<html>head>\n<title>403 Forbidden</title>\n</head>"
        "<body>\n<h1>Forbidden</h1>\n"
        "The requested URL, file type or operation is not allowed in this"
        " simple static file webserver.\n</body></html>\n";

    switch (type) {
        case ERROR:
            (void)sprintf(logbuffer, "ERROR: %s:%s Errno=%d exiting pid=%d",
                s1, s2, errno, getpid());
            break;
        case FORBIDDEN:
            /*
             * #include <fcntl.h>
             * int write( int handle, void *buffer, int nbyte);
             *
             * The write function attempts to write nbytes from buffer to the
             * file associated with the handle. On text files, it expands each
             * LF to CR/LF.
             *
             * The function returns the number of bytes written to the file. A 
             * return value of -1 indicates an error, with errno set 
             * appropriately.
             */
            printf("\nwriting forbidden statement to socket_fd\n");
            (void)write(socket_fd, forbidden_msg, 270);
            break;

    }
}

void test_logger() {
    printf("\nTesting logger -- START\n");
   
    int fd;
    

    //TODO: create fd(file or dummy)
    //void logger(int type, char *s1, char *s2, int socket_fd) {
    printf("\nForbidden...\n");
     
    if( (fd = open("./test.txt", O_CREAT | O_RDWR | O_APPEND, 0644)) == -1) {
        perror("\nCannot open test.txt\n");
        exit(1);
    }

    logger(FORBIDDEN, "failed to read browser request", "", fd);

    if (close(fd) == 0) {
        printf("\nclosed fd successfully\n");
    } else {
        perror("\nproblem closing fd\n");
        exit(1);
    }

    printf("\nTesting logger -- END\n");
}

void run_tests() {
    test_logger();
}

int main(int argc, char **argv) {
    int i, port, pid, listenfd, socketfd, hit;

    //printf("\nargv[1] = >>%s<<\n", argv[1]);
    if (argc > 1) {
        if (strcmp("test", argv[1]) == 0) {
            printf("Running tests...\n");
            run_tests();
            return 0;
        }
    } else {
        printf("\nargc <= 1\n"); 
    }

    return 0;
}
