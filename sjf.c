#include <stdio.h>

int main() {
    int n, bt[10], wt[10], tat[10], i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        printf("BT of P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // Sorting burst times
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];

    printf("\nBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\n", bt[i], wt[i], tat[i]);

    return 0;
}