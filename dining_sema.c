#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t fork1[5];

void *philosopher(void *num)
{
    int id = *(int *)num;

    while(1)
    {
        printf("Philosopher %d is Thinking\n", id);
        sleep(1);

        sem_wait(&fork1[id]);
        sem_wait(&fork1[(id+1)%5]);

        printf("Philosopher %d is Eating\n", id);
        sleep(1);

        sem_post(&fork1[id]);
        sem_post(&fork1[(id+1)%5]);

        printf("Philosopher %d finished Eating\n", id);
    }
}

int main()
{
    pthread_t p[5];
    int id[5];
    int i;

    for(i=0;i<5;i++)
        sem_init(&fork1[i],0,1);

    for(i=0;i<5;i++)
    {
        id[i]=i;
        pthread_create(&p[i],NULL,philosopher,&id[i]);
    }

    for(i=0;i<5;i++)
        pthread_join(p[i],NULL);

    return 0;
}