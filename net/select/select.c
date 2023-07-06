#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <strings.h>
#include <sys/select.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>


#define SERP_PORT 8999
#define MAX_SIZE 1024

int main(int argc, char *argv[]){

    int ret, cfd, lfd, n, i;
    struct sockaddr_in ser_addr, cli_addr;
    char buf[MAX_SIZE];
    socklen_t cli_addr_len = sizeof(cli_addr);
    bzero(&ser_addr, sizeof(ser_addr));
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    ret = setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(SERP_PORT);
    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ret = bind(lfd, (struct sockaddr *)&ser_addr, sizeof(ser_addr));
    ret = listen(lfd, 128);




    fd_set rset, allset;
    int maxfd = lfd, nready;
    FD_ZERO(&allset);
    FD_SET(lfd, &allset);

    while(1){
        rset = allset;
        nready = select(maxfd+1, &rset, NULL, NULL, NULL);
        if(nready < 0){
            perror("select error");
            exit(1);
        }

        if(FD_ISSET(lfd, &rset)){
            cfd = accept(lfd, (struct sockaddr *)&cli_addr, &cli_addr_len);
            FD_SET(cfd, &allset);
            if(maxfd < cfd) maxfd = cfd;
            if(nready == 1){
                continue;
            }
        }

        // 判断读事件在哪一个文件描述符
        for(i = lfd+1; i < maxfd+1; i++){ // 如果指定监听5，6，1023，这一步可以通过自定义数组优化
            if(FD_ISSET(i, &rset)){

                n = read(i, buf, sizeof(buf));
                if(n == 0){
                    close(i);
                    FD_CLR(i, &allset);  // 移除关闭的文件描述符
                }

                for(int j = 0; j < n; j++){
                    buf[j] = toupper(buf[j]);
                }
                write(i, buf, n);
                write(STDOUT_FILENO, buf, n);

                if(nready == 1) break;  // 跳出for，节省时间 》》》》》》
            }
        }

    }



    close(lfd);
    return 0;
}