#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <netinet/in.h>

int ftp_start();

int main() {

    ftp_start();
//    while(1) {
//        ftp_listen();
//        ftp_download();
//        ftp_upload();
//        ftp_list();
//        ftp_delete();
//        ftp_login();
//        ftp_logout();
//    }
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

        printf("Recive [%s] \n", commd);

        if(write(cli_sockfd, commd, 50) < 0) {
            printf("Write Error!\n");
            exit(1);
        }

        close(cli_sockfd);
   }

    return 0;
}

int ftp_download(char *path, char *filename) {
    return 0;
}
