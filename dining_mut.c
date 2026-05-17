#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t fork1[5];

void *philosopher(void *num)
{
    int id = *(int *)num;

    while(1)
    {
        printf("Philosopher %d is Thinking\n", id);
        sleep(1);

        pthread_mutex_lock(&fork1[id]);
        pthread_mutex_lock(&fork1[(id+1)%5]);

        printf("Philosopher %d is Eating\n", id);
        sleep(1);

        pthread_mutex_unlock(&fork1[id]);
        pthread_mutex_unlock(&fork1[(id+1)%5]);

        printf("Philosopher %d finished Eating\n", id);
    }
}

int main()
{
    pthread_t p[5];
    int id[5];
    int i;

    for(i=0;i<5;i++)
        pthread_mutex_init(&fork1[i],NULL);

    for(i=0;i<5;i++)
    {
        id[i]=i;
        pthread_create(&p[i],NULL,philosopher,&id[i]);
    }

    for(i=0;i<5;i++)
        pthread_join(p[i],NULL);

    return 0;
}