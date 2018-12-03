#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    printf("number of process: ");
    scanf("%d",&n);
    printf("\n");
    int p[n],art[n],bt[n],wt[n],tat[n];
    double avgWt,avgTat;

    printf("process: ");
    for(int i = 0; i < n; i++)
        scanf("%d",&p[i]);
    printf("\n");


    printf("order: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&art[i]);
        p[i] = art[i];
        bt[p[i]] = bt[i+1];
    }
    printf("\n");

    printf("burst time: ");
    for(int i = 0; i < n; i++)
        scanf("%d",&bt[p[i]]);
    printf("\n");


    wt[p[0]] = 0;
    avgWt = 0;
    avgTat = 0;
    for(int i = 1 ; i < n; i++){
        wt[p[i]] = wt[p[i-1]] + bt[p[i-1]];
        avgWt += wt[p[i]];
    }
    avgWt /= n;

    printf("gantt chart:\n\n");
    for(int i = 0; i < n; i++){
        for(int j =0 ; j < wt[p[i]]; j++){
            printf("-");
        }
        printf("%d",p[i]);
    }

    printf("\n");

    for(int i = 0; i < n; i++){
        for(int j =0 ; j < wt[p[i]]; j++){
            printf(" ");
        }
        printf("%d",wt[p[i]]);
    }

    printf("\n\nwaiting time: \n\n");
    for(int i = 0 ; i < n; i++){
        printf("process %d: %d\n",i+1,wt[i+1]);
    }
    printf("\n");

    printf("average waiting time: %0.2lf\n\n",avgWt);

    for(int i = 0 ; i < n; i++){
        tat[p[i]] = wt[p[i]] + bt[p[i]];
        avgTat += tat[p[i]];
    }

    printf("turnaround time: ");
    for(int i = 0 ; i < n; i++){
        printf("process %d: %d\n",i+1,tat[i+1]);
    }
    printf("\n");

    avgTat /=n;
    printf("average turnaround time: %0.2lf\n",avgTat);

    return 0;
}
