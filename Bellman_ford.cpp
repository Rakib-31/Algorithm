#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pair<pii,int> > v[100];
int distan[100];

bool bellman_ford(int src,int V,int E)
{
    memset(distan,INT_MAX,sizeof(distan));
    distan[src] =  0;

    for(int i = 1; i<=V-1;i++)
    {
        for(int j = 0;j<E;j++)
        {
            vector<pair<pii,int> > ::iterator it;
            it = v[j].begin();
            int src = (*it).first.first;
            int dist = (*it).first.second;
            int weight = (*it).second;
            cout<<src<<" "<<dist<<" "<<weight<<endl;
            if(distan[src]!=INT_MAX && distan[src] + weight < distan[dist])
            {
                distan[dist] = distan[src] + weight;
            }
        }
    }


    for(int i = 0; i < E ;i++)
    {
            vector<pair<pii,int> > ::iterator it;
            it = v[i].begin();
            int src = (*it).first.first;
            int dist = (*it).first.second;
            int weight = (*it).second;

            if(distan[src]!=INT_MAX && distan[src] + weight < distan[dist])
            {
                printf("Negative cycle detected\n");
                return true;
            }
    }

    return false;
}

int main()
{

  int a,b,c,V;
  int edge = 0;

  cin >> V;

  while(cin >> a >> b >> c)
  {

      v[edge++].push_back(make_pair(pii(a,b),c));
  }

  if(!bellman_ford(0,V,edge))
  {
      cout<<distan[3]<<endl;
  }

  return 0;
}
