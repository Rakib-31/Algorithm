#include<bits/stdc++.h>
using namespace std;

int distan[100];
typedef pair <int,int> pi;
vector <pi> v[100];
priority_queue < pi,vector<pi>,greater<pi> > pq;

void dijkstra(int src){
    distan[src] = 0;
    pq.push(make_pair(0,src));

    while(!pq.empty()){
        pi t = pq.top();
        pq.pop();
        int u = t.second;
        vector <pi>:: iterator it;

        for(it = v[u].begin();it!=v[u].end();it++){
            int a = (*it).first;
            int b = (*it).second;

            if(distan[u] + a < distan[b]){
                distan[b] = distan[u] + a;
                pq.push(make_pair(distan[b],b));
            }
        }
    }
}

int main(){
    freopen("inputfile.txt","r",stdin);
    freopen("outputfile.txt","w",stdout);
    int x,y,z;
    int n,e;
    scanf("%d%d",&n,&e);

    for(int i = 0;i < e; i++){
        scanf("%d%d%d",&x,&y,&z);
        distan[x] = 100;
        distan[y] = 100;
        v[x].push_back(make_pair(z,y));
    }

    dijkstra(0);

    for(int i = 0;i < n;i++)
        cout<<"distance from 0 to "<<i<< "is "<<distan[i]<<endl;

    return 0;
}
