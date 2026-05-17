#include <stdio.h>

int main() {

    int n, r, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10] = {0};

    // Allocation Matrix
    printf("Enter Allocation Matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d", &alloc[i][j]);

    // Max Matrix
    printf("Enter Max Matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d", &max[i][j]);

    // Available Resources
    printf("Enter Available Resources:\n");

    for(j=0;j<r;j++)
        scanf("%d", &avail[j]);

    // NEED = MAX - ALLOC
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int count = 0;

    printf("\nSafe Sequence: ");

    while(count < n) {

        for(i=0;i<n;i++) {

            if(finish[i] == 0) {

                int flag = 1;

                // Check need <= avail
                for(j=0;j<r;j++) {

                    if(need[i][j] > avail[j]) {

                        flag = 0;
                        break;
                    }
                }

                // If process can run
                if(flag == 1) {

                    printf("P%d ", i);

                    // Release resources
                    for(j=0;j<r;j++)
                        avail[j] += alloc[i][j];

                    finish[i] = 1;

                    count++;
                }
            }
        }
    }

    return 0;
}