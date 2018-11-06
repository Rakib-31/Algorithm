#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int parent[MAX];
vector<pair<int, pair<int, int> > >Edges;
vector<pair<int, int> >resultEdge;

bool cmp(const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b){
    return a.second.second<b.second.second;
}

void reset(int n){
    for(int i=0; i<n; i++)
        parent[i] = i;
    return;
}

int findParent(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

bool isUnion(int u, int v){
    int x = findParent(u), y = findParent(v);

    if(x!=y){
        parent[y] = x;
        return false;
    }

    return true;
}

int callKruskal(){
    int cost = 0;
    sort(Edges.begin(), Edges.end(), cmp);

    for(int i=0; i<Edges.size(); i++){
        int u = Edges[i].first, v = Edges[i].second.first;
        if(isUnion(u,v) == false){
            resultEdge.push_back(make_pair(u,v));
            cost+=Edges[i].second.second;
        }
    }

    return cost;
}

int main(){
    ifstream inputStream("inputStreamKruskal.txt");
    ofstream outputStream("outputStream.txt");

    string x,y;
    int w;
    int index = 0;
    map<string, int>indexOf;
    map<int, string>data;

    while(inputStream>>x>>y>>w){
        int u,v;
        if(indexOf.find(x) == indexOf.end())
            indexOf[x] = index++, data[index-1] = x;
        if(indexOf.find(y) == indexOf.end())
            indexOf[y] = index++, data[index-1] = y;

        u = indexOf[x];
        v = indexOf[y];

        Edges.push_back(make_pair(u, make_pair(v,w)));
    }

    reset(index);
    int cost = callKruskal();
    outputStream<<cost<<endl;

    for(int i=0; i<resultEdge.size(); i++){
        int a = resultEdge[i].first, b = resultEdge[i].second;
        outputStream<<data[a]<<" "<<data[b]<<endl;
    }

    return 0;
}
