#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
char buf1[] = "abc";
char buf2[] = "ABC";

int main(void) {
    int fd;

    if ((fd = creat("file.hold", FILESEC_MODE)) < 0) {
        printf("creat file failed.\n");
    }

//    if ((fd = open("file.hold", O_RDWR)) < 0) {
//        printf("open file failed.\n");
//    }


    if (write(fd, buf1, 3) != 3) {
        printf("wirte error.\n");
    }

    if (lseek(fd, 1117, SEEK_SET) == -1) {
        printf("lseek failed.\n");
    }

    if (write(fd, buf2, 3) != 3) {
        printf("wirte error.\n");
    }

    exit (0);
}
