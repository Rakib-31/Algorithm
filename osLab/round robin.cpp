#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int n, q;
double avgWaiting, avgTurnaround;

struct Process{
    int burst, arrival, waiting = 0, turnaround = 0, id;
}p[MAX];

int order[MAX];

void GanttChart(){
    puts("");

    vector<Process>v;
    vector<int>hold;

    for(int i=0; i<n; i++)
        v.push_back(p[order[i]-1]);

    int t = 0, i = -1;

    while(!v.empty()){
        i = (i+1)%(int)v.size();

        int burst = min(v[i].burst, q);
        int waiting = t - v[i].arrival;
        int curr = v[i].id-1;

        p[curr].waiting += waiting;
        t+=burst;
        v[i].burst-=burst;
        v[i].arrival = t;

        hold.push_back(burst);

        printf("p%d",curr+1);
        while(burst--)
            printf("_");

        if(!v[i].burst)
            v.erase(v.begin()+i), i--;
    }

    puts("//");

    t = 0;
    for(int i=0; i<hold.size(); i++){
        printf("%02d", t);
        t+=hold[i];
        while(hold[i]-- && i!=hold.size())
            printf(" ");
    }
    printf("%02d", t);

    puts("\n");

    return;
}

void scan(){
    printf("Enter the quantum amount: ");
    scanf("%d", &q);

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    puts("");
    printf("Enter the arrival time of each process:\n");
    for(int i=0; i<n; i++){
        printf("P[%d] = ", i+1);
        scanf("%d",&p[i].arrival);
        p[i].id = i+1;
    }

    puts("");
    printf("Enter the burst time of each process:\n");
    for(int i=0; i<n; i++){
        printf("P[%d] = ", i+1);
        scanf("%d",&p[i].burst);
    }

    puts("");
    printf("Enter the process order:\n");
    for(int i=0; i<n; i++){
        scanf("%d",&order[i]);
    }
}

void calculate(){
    int waiting = 0, turnaround = 0;

    for(int i=0; i<n; i++){
        int curr = order[i] - 1;
        printf("Waiting time for process %d: %d\n", curr+1, p[curr].waiting);
        waiting += p[curr].waiting;
        turnaround += p[curr].waiting + p[curr].burst;
    }

    avgWaiting = (double)waiting/n;
    avgTurnaround = (double)turnaround/n;
}

void print(){
    printf("Average waiting time: %0.3lf\n", avgWaiting);
    printf("Average turnaround time: %0.3lf\n", avgTurnaround);
}

int main(){
    scan();
    GanttChart();
    calculate();
    print();
}
