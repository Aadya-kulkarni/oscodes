#include <stdio.h>

int main() {
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = 12, f = 3;

    int frame[10], i, j, k = 0, fault = 0, found;

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++) {

        found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frame[k] = pages[i];
            k = (k + 1) % f;
            fault++;
        }
    }

    printf("Page Faults = %d", fault);

    return 0;
}