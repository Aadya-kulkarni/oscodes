#include <stdio.h>
#include <stdlib.h>

int main() {

    int rq[20], done[20]={0};
    int n, head, i, j, index, min, total=0;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter request queue: ");

    for(i=0;i<n;i++)
        scanf("%d",&rq[i]);

    printf("Enter head position: ");
    scanf("%d",&head);

    printf("Sequence: %d ", head);

    for(i=0;i<n;i++) {

        min = 9999;

        for(j=0;j<n;j++) {

            if(done[j]==0 && abs(rq[j]-head)<min) {

                min = abs(rq[j]-head);
                index = j;
            }
        }

        total += min;
        head = rq[index];

        done[index] = 1;

        printf("-> %d ", head);
    }

    printf("\nTotal Head Movement = %d", total);

    return 0;
}