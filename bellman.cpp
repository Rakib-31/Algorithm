#include<bits/stdc++.h>

using namespace std;

#define INF 1000000

struct edges
{
    int u, v, w;
    void set(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }

};

vector<edges> g;
int dist[100], n;

bool bellmanFord(int s)
{
    dist[s] = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j=0;j<g.size();j++)
        {
            edges e = g[j];
            if(dist[e.v] > dist[e.u] + e.w)
            {
                dist[e.v] = dist[e.u] + e.w ;
            }
        }
    }

    for(int j=0;j<g.size();j++)
    {
        edges e = g[j];
        if(dist[e.v] > dist[e.u] + e.w)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    for(int i=1 ; i < 100 ; i++)
        dist[i] = INF;
    char a, b;
    int x, y, c;
    edges edge;
    set<char> st;
    set<char> :: iterator i;
    cout << "Enter number of virtics : ";
    cin >> n;
    cout << "Enter number of Edge : " ;
    int e;
    cin >> e;
    cout << "Enter Edge: " << endl;

    for(int j=0; j<e;j++)
    {
        cin >> a >> b >> c;
        x = a - 96;
        y = b - 96;
        edge.set(x, y, c);
        g.push_back(edge);
        st.insert(a);
        st.insert(b);
    }

    char src;
    cout << "Enter source : " ;
    cin >> src;
    bool flag = bellmanFord(src-96);

    if(!flag)
        cout << "No solution" << endl;

    else
    {
        cout << src << " " << dist[src - 96] << endl;
        for(i = st.begin(); i!=st.end(); i++)
        {
            if(*i == src)
                continue;
            cout << *i << " " << dist[*i - 96] << endl;
        }
    }
    return 0;
}
