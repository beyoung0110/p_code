#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
    int fd[2];
    int n;
    pid_t pid;
    char line[20];

    if(pipe(fd) < 0)
        printf("pipe error");

    pid = fork();
    if(pid < 0) {
        printf("fork error");
    } else if (pid > 0) {
        close(fd[0]);
        write(fd[1], "hello this word.", 20);
    } else {
        close(fd[1]);
        n = read(fd[0], line, 20);
        write(STDOUT_FILENO, line ,20);
    }
    exit(0);
}
