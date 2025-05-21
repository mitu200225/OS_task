#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rem_bt[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        printf("Burst time for P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
        wt[i] = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > tq) {
                    t += tq;
                    rem_bt[i] -= tq;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) break;
    }

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P[%d]\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    return 0;
}