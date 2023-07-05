#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>
#include <signal.h>
#include <error.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <ctype.h>

#define SERV_PORT 9999
#define BUF_SIZE 1024

void catch_child(int sigum){
   while(waitpid(0, NULL, WNOHANG) > 0);
   return;
}

int main(int argc, char *argv[]){

    int lfd, cfd, ret,pid, i;
    struct sockaddr_in serv_addr, client_addr;
    char buf[BUF_SIZE];
    socklen_t client_addr_len = sizeof(client_addr);

    lfd = socket(AF_INET, SOCK_STREAM, 0);
    
    // memset(&serv_addr, 0, sizeof(serv_addr));
    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ret = bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    listen(lfd, 128);

    while(1){

        cfd = accept(lfd, (struct sockaddr *)&client_addr, &client_addr_len);

        pid = fork();

        if(pid == 0){  // 子进程
            break;
        }else if(pid > 0){ // 父进程，每一次循环都要创建信号SIGCHLD捕捉函数是否有必要
            struct sigaction act;
            act.sa_handler = catch_child;
            sigemptyeset(&act.sa_mask);
            act.sa_flags = 0;
            ret = sigaction(SIGCHLD, &act, NULL);

            close(cfd);

            continue;
        }
    }

    if(pid == 0) {  // 子进程在循环中退出，执行该程序 块
        close(lfd);

        for(;;){

            ret = read(cfd, &buf, sizeof(buf));
            if(ret == 0){
                close(cfd);
                exit(1);
            }

            for(i = 0; i<ret; i++){
                buf[i] = toupper(buf[i]);
            }

            write(STDOUT_FILENO, &buf, ret);
            write(cfd, &buf, ret);
        }
    }

    return 0;
}
