#include<bits/stdc++.h>
using namespace std;

int main(){

    int p[100],t[100],t1[100],order[100],wt[100],tat[100],n,temp;
    double avgWt,avgTat;
    cout<<"Number of process: ";
    cin>>n;
    cout<<"process: ";

    for(int i = 0; i < n; i++){
        cin>>p[i];
    }
    cout<<"burst time: ";
    for(int i = 0; i < n; i++){
        cin>>t[i];
        t1[i] = t[i];
    }
    cout<<"order: ";
    for(int i = 0; i < n; i++){
        cin>>order[i];
        p[i] = order[i];
        t[i] = t1[order[i] - 1];
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(t[j]<t[i]){
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[p[0]] = 0;
    avgWt = 0;
    avgTat = 0;

    for(int i = 1 ; i < n; i++){
        wt[p[i]] = wt[p[i-1]] + t[i-1];
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
        tat[p[i]] = wt[p[i]] + t[i];
        avgTat += tat[p[i]];
    }

    printf("turnaround time: \n");
    for(int i = 0 ; i < n; i++){
        printf("process %d: %d\n",i+1,tat[i+1]);
    }
    printf("\n");

    avgTat /=n;
    printf("average turnaround time: %0.2lf\n",avgTat);

    return 0;
}
