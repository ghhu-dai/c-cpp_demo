#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int fd1, fd2,n;
    char buf[4096];
    
    // fd1 = open(argv[1],O_RDWR);
    fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1){
        perror("open argv[1] error");
        exit(1);
    }

//
    fd2 = open(argv[2], O_RDWR | O_CREAT |O_TRUNC, 0644);
    if(fd2 == -1){
        perror("open argv2 error");
        exit(1);
    }

//
    while((n = read(fd1,buf, 4096)) != 0){
        if(n < 0){
            perror("read error");
            break;;
        }
        write(fd2, buf, n);
    }

    close(fd1);
    close(fd2);


    return 0;
}