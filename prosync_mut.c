#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t m;

void *process1()
{
    pthread_mutex_lock(&m);

    printf("Process 1 is in Critical Section\n");
    sleep(2);

    printf("Process 1 Exit\n");

    pthread_mutex_unlock(&m);
}

void *process2()
{
    pthread_mutex_lock(&m);

    printf("Process 2 is in Critical Section\n");
    sleep(2);

    printf("Process 2 Exit\n");

    pthread_mutex_unlock(&m);
}

int main()
{
    pthread_t t1, t2;

    pthread_mutex_init(&m, NULL);

    pthread_create(&t1, NULL, process1, NULL);
    pthread_create(&t2, NULL, process2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}