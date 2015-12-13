#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 4096   /* max line length */

int main(void) {
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    if (pipe(fd) < 0) {
        printf("pipe_error");
    }
    if ((pid = fork()) < 0) {
        printf("fork error");
    } else if (pid > 0) {
        close(fd[0]);
        write(fd[1], "hello pipe.\n", 12);
    } else {
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
    }
    exit (0);
}

