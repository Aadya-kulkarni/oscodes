#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t s;

void *process1()
{
    sem_wait(&s);

    printf("Process 1 is in Critical Section\n");
    sleep(2);

    printf("Process 1 Exit\n");

    sem_post(&s);
}

void *process2()
{
    sem_wait(&s);

    printf("Process 2 is in Critical Section\n");
    sleep(2);

    printf("Process 2 Exit\n");

    sem_post(&s);
}

int main()
{
    pthread_t t1, t2;

    sem_init(&s, 0, 1);

    pthread_create(&t1, NULL, process1, NULL);
    pthread_create(&t2, NULL, process2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}