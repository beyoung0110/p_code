#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

void commd_ls();

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

        commd_ls(addr, commd);
    }
}

void commd_ls(struct sockaddr_in addr, char *commd)
{
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
        printf(" %s ",commd);
    }

    printf("\n");
    close(sockfd);
    return ;
}
