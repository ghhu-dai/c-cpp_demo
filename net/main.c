#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <ctype.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERV_PORT 9527
#define BUF_SIZE 1024

void sys_err(int ret, char *str){
    perror(str);
    exit(1);
}

int main(int argc, char *argvp[]){

    int serv_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(serv_fd == -1){
        sys_err(serv_fd, "socket error");
    }

    struct sockaddr_in serv_addr, client_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    int ret = bind(serv_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if(ret != 0){
        sys_err(ret, "bind_error");
    }

    ret = listen(serv_fd, 5);
    if(ret != 0){
        sys_err(ret, "lister error");
    }

    socklen_t client_addr_len = sizeof(client_addr); // 该参数是传入传出参数，需要有初始值
    int serv_cfd = accept(serv_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if(serv_cfd == -1){
        sys_err(ret, "accept error");
    }


    char buf[BUF_SIZE], client_ip[BUF_SIZE], client_port[BUF_SIZE];

    printf("client ip: %s\t client port: %d\n",
            inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, client_ip, (socklen_t)(sizeof(client_ip)) ),
            ntohs(client_addr.sin_port)
    );
    
    while(1){

        ret = read(serv_cfd, buf, sizeof(buf)); // ret 是read读到的字节数

        write(STDOUT_FILENO, buf, ret);

        for(int i = 0; i<ret; ++i){
            buf[i] = toupper(buf[i]);
        }

        write(serv_cfd, buf, ret);
    }

    close(serv_fd);
    close(serv_cfd);

    return 0;
}