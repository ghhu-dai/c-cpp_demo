#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>
#include <sys/stat.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM 5

int queue[NUM];                      // 全局数组实现环形队列 
sem_t blank_number, product_number; // 空格子信号量，产品信号量

void *producer(void *arg){
    int i = 0;
    while(1){
        sem_wait(&blank_number);
        queue[i] = rand()%1000 + 1;
        printf("__prodeuc\t%d\n", queue[i]);
        sem_post(&product_number);

        i = (i+1) % NUM;
        sleep(rand()%1); 
    }

}

void *consumer(void *arg){

    srand(time(NULL));
    int i = 0;
    while(1){
        sem_wait(&product_number);      // 若product_number为0，阻塞等待生产者生产
        printf("consumer %d\n", queue[i]);
        queue[i] = 0;                   //  模拟消费
        sem_post(&blank_number);
        i = (i+1) % NUM;
        sleep(rand()%3);

    }

}

int main(int argc, char *argv[]){

    pthread_t pid, cid;

    sem_init(&blank_number, 0, NUM);
    sem_init(&product_number, 0, 0); // 为什么是两个信号量

    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(pid,NULL);
    pthread_join(cid, NULL);        // 回收两个线程

    sem_destroy(&blank_number);
    sem_destroy(&product_number);   // 释放信号量所占资源

    return 0;
}