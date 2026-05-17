#include <stdio.h>
#include <stdlib.h>

int main() {

    int rq[20], n, head, total=0, i, temp;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter requests: ");

    for(i=0;i<n;i++)
        scanf("%d",&rq[i]);

    printf("Enter head position: ");
    scanf("%d",&head);

    // Sort
    for(i=0;i<n-1;i++) {

        for(int j=i+1;j<n;j++) {

            if(rq[i]>rq[j]) {

                temp=rq[i];
                rq[i]=rq[j];
                rq[j]=temp;
            }
        }
    }

    printf("Sequence: ");

    for(i=0;i<n;i++) {

        total += abs(rq[i]-head);

        head = rq[i];

        printf("%d ", head);
    }

    printf("\nTotal Head Movement = %d", total);

    return 0;
}