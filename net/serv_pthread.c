#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <strings.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAXLINE 8192  // 8字节大小
#define SER_PORT 8000

struct s_info{ // 定义一个结构体，将客户端地址结构跟服务器与其进行通信的socket句柄cfd捆绑  
    struct sockaddr_in cliaddr;
    int connfd;
};


void *do_work(void *arg){
    int n,i;
    struct s_info *ts = (struct s_info *)arg;
    char buf[MAXLINE];
    char str[16];
    while(1){
        n = read(ts->connfd, &buf, MAXLINE);
        if(n == 0){
            printf("the client %d has closed\n", ts->connfd);
            break;
        }

        printf("received from %s at port %d\n",
                inet_ntop(AF_INET, &(*ts).cliaddr.sin_addr.s_addr,str, sizeof(str)),
                ntohs((*ts).cliaddr.sin_port)
            );

        for(i = 0; i<n; i++){
            buf[i] = toupper(buf[i]);
        }
        write((*ts).connfd, buf, n);
        write(STDOUT_FILENO, buf, n);
    }
    close(ts->connfd);
    return (void *)0; // 这里相当于pthread_exit()
}

int main(int argc, char *argv[]){

    int cfd, lfd, ret, i;
    pthread_t  tid;
    struct sockaddr_in ser_addr,client_addr;
    struct s_info ts[256];                      // 创建结构体数组
    bzero(&ser_addr, sizeof(ser_addr));
    socklen_t ser_addr_len = sizeof(ser_addr);
    socklen_t client_addr_len = sizeof(client_addr);

    lfd = socket(AF_INET, SOCK_STREAM, 0);

    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(SER_PORT);
    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ret = bind(lfd, (struct sockaddr *)&ser_addr, ser_addr_len);
    
    ret = listen(lfd, 128);

    printf("accepting client connet ...\n");

    while(1){
        cfd = accept(lfd, (struct sockaddr *)&client_addr, &client_addr_len);
        ts[i].cliaddr = client_addr;
        ts[i].connfd = cfd; 

        pthread_create(&tid, NULL, do_work, (void *)&ts[i]); // void * 8字节 ，只能地址传递(ts不会修改)，值传递容量不够会丢失数据
        pthread_detach(tid);            // 子线程分离，防止僵线程产生
        ++i;
    }


    return 0;
}