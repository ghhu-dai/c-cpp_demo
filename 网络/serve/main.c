// File Path: ~/网络/serve/main.cpp
// File Name: main.cpp
// Directory: ~/网络/serve
// Date: 2023-06-24

#include <stdio.h>
#include <sys/socket.h> 
#include <netinet/in.h> 

int main(){

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd == -1) return -1;
    
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY ：0.0.0.0

    return 0;
}
