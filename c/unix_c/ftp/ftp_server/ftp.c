#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <netinet/in.h>
#include <dirent.h>
#include <fcntl.h>

int ftp_start();
void commd_ls(int sockfd);
void commd_put(int sockfd, char *filename);

int main() {
    ftp_start();
    return 0;
}

int ftp_start() {
    /*
     * struct sockaddr_in {
     *  short sin_family;
     *  unsigned short sin_port;
     *  struct in_addr sin_addr;
     *  unsigned char sin_zero[8];
     * }
     *
     */
    struct sockaddr_in ser_addr, cli_addr;
    int ser_sockfd, cli_sockfd;
    int ser_len, cli_len;
    char commd [50];
    bzero(commd, 50);

    // using socket(domain, type, protocol) to create a socket_fd
    if((ser_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket Error!\n");
        return -1;
    }

    // fill sockaddr_in
    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ser_addr.sin_port = htons(8989);
    ser_len = sizeof(ser_addr);
    
    // bind socket_fd with sockaddr_in
    if((bind(ser_sockfd, (struct sockaddr *)&ser_addr, ser_len)) < 0) {
        printf("Bind Error!\n");
        return -1;
    }
    
    if(listen(ser_sockfd, 5) < 0) {
        printf("Linsten Error!\n");
        return -1;
    }

    bzero(&cli_addr, sizeof(cli_addr));
    cli_len = sizeof(cli_addr);
    
    while(1) {
        printf("begins.\n");

        if((cli_sockfd = accept(ser_sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&cli_len)) < 0) {
            printf("Client Accept Error!\n");
            exit(1);
        }

        if(read(cli_sockfd, commd, 50) < 0) {
            printf("Read Command Error!\n");
            exit(1);
        }
        printf("Recive [%s]\n", commd);

        if(strncmp(commd, "ls", 2) == 0) {
            commd_ls(cli_sockfd);
        } else if(strncmp(commd, "put", 3) == 0) {
            commd_put(cli_sockfd, commd + 4);
        }

/*        if(write(cli_sockfd, commd, 50) < 0) {
            printf("Write Error!\n");
            exit(1);
        }
        close(cli_sockfd);
*/
   }

    return 0;
}

void commd_ls(int sockfd) {
    DIR *mydir =NULL;
    struct dirent *myitem = NULL;
    char commd[50] ;
    bzero(commd, 50);

    if((mydir=opendir(".")) == NULL)
    {
        printf("OpenDir Error!\n");
        exit(1);
    }

    while((myitem = readdir(mydir)) != NULL)
    {
        if(sprintf(commd, myitem->d_name, 50) < 0)
        {
            printf("Sprintf Error!\n");
            exit(1);
        }
        if(write(sockfd, commd, 50) < 0 )
        {
            printf("Write Error!\n");
            exit(1);
        }
    }
    closedir(mydir);
    close(sockfd);
    return ;
}

void commd_put(int sockfd, char *filename) {
    int fd, nbytes;
    char buffer[50];
    bzero(buffer, 50);    

    printf("get filename : [ %s ]\n", filename);
    if((fd=open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0644)) < 0)
    {
        printf("Open file Error!\n");
        return ;
    }
    while((nbytes=read(sockfd, buffer, 50)) > 0)
    {
        if(write(fd, buffer, nbytes) < 0)
        {
            printf("Write Error! At commd_put 1!\n");
            close(fd);
            exit(1);
        }
    }
    close(fd);
    close(sockfd);
    return ;
}
