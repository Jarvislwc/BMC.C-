#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t semaphore;
int count = 0;

void *child(){
    for(int i = 0;i < 10;i++){
        sem_wait(&semaphore);
        printf("Counter = %d\n",++count);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(){

    sem_init(&semaphore,0,0);

    pthread_t t;
    pthread_create(&t,NULL,child,NULL);

    printf("Post 2 jobs\n");
    sem_post(&semaphore);
    sem_post(&semaphore);
    
    sleep(3);
    printf("Wait\n");

    int i;
    for(i = 0; i<10; i++){
       sem_post(&semaphore);   
    }

    printf("Post %d jobs\n",i);
    pthread_join(t,NULL);    

    return 0;

}