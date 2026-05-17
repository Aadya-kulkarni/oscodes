#include<stdio.h>
#include<stdlib.h>

int main()
{
    int queue[100];
    int n,head,i;
    int total = 0;

    printf("Enter No. of requests");
    scanf("%d",&n);

    printf("Enter request queue:\n");

    for (i=0;i<n;i++)
    {
        scanf("%d",&queue[i]);
    }

    printf("Enter initial head position: ");

    scanf("%d", &head);

    printf("\nServicing Order:\n");

    for(i=0; i<n; i++)
    {
        printf("%d -> ", queue[i]);

        total = total + abs(queue[i] - head);

        head = queue[i];
    }

    printf("\nTotal Head Movement = %d", total);

    return 0;

}