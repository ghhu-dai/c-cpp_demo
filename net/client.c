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


void sys_error(char *str){
    perror(str);
    exit(1);
}

int main(int argc, char *argv[]){

    
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(client_fd == -1){
        sys_error("socket error");
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9527);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr.s_addr);
    int ret = connect(client_fd, (struct sockaddr *)&serv_addr,  sizeof(serv_addr));
    if(ret  != 0){
        sys_error("connect error");
    }

    int count = 10;
    char buf[1024];
    while(count--){
        write(client_fd, "hello\n", 6);
        ret = read(client_fd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, ret);
        sleep(1);

    }

    close(client_fd);

    return 0;
}