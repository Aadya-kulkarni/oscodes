#include <stdio.h>

int main() {

    int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,2};
    int n = 13, f = 3;

    int frame[10];
    int i, j, k, pos, farthest, found, fault = 0;

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

            pos = -1;
            farthest = i;

            for(j = 0; j < f; j++) {

                for(k = i + 1; k < n; k++) {
                    if(frame[j] == pages[k])
                        break;
                }

                if(k == n) {
                    pos = j;
                    break;
                }

                if(k > farthest) {
                    farthest = k;
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            fault++;
        }
    }

    printf("Page Faults = %d", fault);

    return 0;
}
