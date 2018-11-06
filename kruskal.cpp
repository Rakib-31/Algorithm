#include<bits/stdc++.h>
using namespace std;

int parent[2000];

struct krus{
    long long x,y,z;
};

vector <long long> vec;

bool comparetor(krus x, krus y){
    return x.z < y.z;
}

int findParent(int x){
    if(parent[x] == x)
        return x;
    return findParent(parent[x]);
}

bool isUnion(int a, int b){
    int x = findParent(a);
    int y = findParent(b);
    if(x != y) return true;
    return false;
}

void kruskal(krus ob[], int edge){
    sort(ob,ob+edge,comparetor);
    for(int i = 0; i < edge; i++){
        int a = ob[i].x;
        int b = ob[i].y;

        if(isUnion(a,b)){
            parent[b] = a;
            //vec.push_back(ob[i]);
        }
        else vec.push_back(ob[i].z);
    }
}

int main(){

    int node,edge;
    while(1){
        cin>>node>>edge;
        if(!node && !edge) break;
        krus ob[edge];

        for(int i = 0; i < edge; i++){
            cin>>ob[i].x>>ob[i].y>>ob[i].z;
            parent[ob[i].x] = ob[i].x;
            parent[ob[i].y] = ob[i].y;
        }

        kruskal(ob,edge);
        bool check = false;
        for(int i = 0; i < vec.size(); i++){
            if(check) cout<<" ";
            check = true;
            cout<<vec[i];
        }
        if(check) cout<<endl;
        else cout<<"forest"<<endl;
        vec.clear();
    }

    return 0;
}
