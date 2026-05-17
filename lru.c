#include <stdio.h>

int main() {

    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = 12, f = 3;

    int frame[10], time[10];
    int i, j, pos, fault = 0, cnt = 0, found, min;

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {

        found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                cnt++;
                time[j] = cnt;
                break;
            }
        }

        if(!found) {

            min = time[0];
            pos = 0;

            for(j = 1; j < f; j++) {
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            cnt++;
            frame[pos] = pages[i];
            time[pos] = cnt;
            fault++;
        }
    }

    printf("Page Faults = %d", fault);

    return 0;
}