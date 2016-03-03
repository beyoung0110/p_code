#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <fcntl.h>

void commd_ls(struct sockaddr_in addr, char *commd);
void commd_put(struct sockaddr_in addr, char *commd);

int main() {
    struct sockaddr_in addr;
    char commd [50];

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(8989);

    while(1) {
        bzero(commd, 50);
        if(fgets(commd, 50, stdin) == NULL) {
            printf("Command gets error!");
            return -1;
        }

        commd[strlen(commd)-1]='\0';
        printf("Input Command Is [ %s ]\n",commd);
      
        if(strncmp(commd, "ls", 2) == 0) {
            commd_ls(addr, commd);
        } else if(strncmp(commd, "put", 3) == 0) {
            commd_put(addr, commd);
        }
    }
}

void commd_ls(struct sockaddr_in addr, char *commd) {
    int sockfd;

    if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket Error!\n");
        exit(1);
    }    
    
    if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Connect Error!\n");
        exit(1);
    }
                    
    if(write(sockfd, commd, 50) < 0) {
        printf("Write Error!\n");
        exit(1);
    }

    while(read(sockfd, commd, 50) > 0) {
        printf("Server reply is [ %s ] \n",commd);
    }

    close(sockfd);
    return ;
}

void commd_put(struct sockaddr_in addr, char *commd) {
    int fd;
    int sockfd;
    char buffer[50];
    int nbytes;

    if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
            printf("Socket Error!\n");
            exit(1);
    }

    if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
            printf("Connect Error!\n");
            exit(1);
    }
    
    if(write(sockfd, commd, 50)<0)
    {
            printf("Wrtie Error!At commd_put 1\n");
            exit(1);
    }

    if((fd=open(commd+4, O_RDONLY)) < 0)
    {
            printf("Open Error!\n");
            exit(1);
    }

    while((nbytes=read(fd, buffer, 50)) > 0)
    {
            if(write(sockfd, buffer, nbytes) < 0)
            {
                printf("Write Error!At commd_put 2");
            }
    }

    close(fd);
    close(sockfd);

    return ;
}
