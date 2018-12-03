
#include <bits/stdc++.h>
using namespace std;

#define MAXN 20

int p, r;
int MAX[MAXN][MAXN], ALLOCATION[MAXN][MAXN], NEED[MAXN][MAXN], WORK[MAXN], AVAILABLE[MAXN];
bool FINISH[MAXN];
vector<int>seq;

void scan(){
    printf("Enter the number of processes: ");
    scanf("%d",&p);

    printf("Enter the number of resources: ");
    scanf("%d",&r);
    puts("");

    printf("Enter the number of allocated instances for each resource:\n ");
    for(int i=0; i<r; i++) printf(" R%d",i+1);
    puts("");
    for(int i=0; i<p; i++){
        printf("P%d ",i+1);
        for(int j=0; j<r; j++){
            scanf("%d",&ALLOCATION[i][j]);
        }
    }

    printf("Enter maximum number of instances each resource can have:\n ");
    for(int i=0; i<r; i++) printf(" R%d",i+1);
    puts("");
    for(int i=0; i<p; i++){
        printf("P%d ",i+1);
        for(int j=0; j<r; j++){
            scanf("%d",&MAX[i][j]);
            NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
        }
    }

    printf("Enter the number of available instances each resource:\n");
    for(int i=0; i<r; i++){
        printf("AVAILABLE[R%d] = ",i+1);
        scanf("%d", &AVAILABLE[i]);
    }
}

void calculate(){
    for(int i=0; i<r; i++)
        WORK[i] = AVAILABLE[i];

    int finished = 0;

    while(seq.size() < p){
        bool found = false;

        for(int i=0; i<p; i++){
            if(!FINISH[i]){
                bool satisfied = true;
                for(int j=0; j<r; j++){
                    if(NEED[i][j] > WORK[j]){
                        satisfied = false;
                        break;
                    }
                }

                if(satisfied){
                    for(int j=0; j<r; j++){
                        WORK[j] += ALLOCATION[i][j];
                    }
                    seq.push_back(i+1);
                    FINISH[i] = found = true;
                }
            }
        }

        if(!found){
            printf("Unsafe\n");
            break;
        }
    }

    if(seq.size()==p){
        printf("The safe sequence:\n");
        for(int i=0; i<seq.size(); i++)
            printf("%d ",seq[i]);
        puts("");
    }
}

int main(){
    scan();
    calculate();
}
