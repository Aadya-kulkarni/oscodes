#include <stdio.h>
#include <stdlib.h>

int main() {

    int rq[20], n, head, total=0, i;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter requests: ");

    for(i=0;i<n;i++)
        scanf("%d",&rq[i]);

    printf("Enter head: ");
    scanf("%d",&head);

    printf("Sequence: %d ", head);

    for(i=0;i<n;i++) {

        total += abs(rq[i]-head);

        head = rq[i];

        printf("-> %d ", head);
    }

    // Jump to first request
    total += abs(head-rq[0]);

    printf("-> %d", rq[0]);

    printf("\nTotal Head Movement = %d", total);

    return 0;
}