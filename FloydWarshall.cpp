#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long x[100][100];
    int nodenumber,u,v,cost,src,dist;

    cout<<"Enter the number of nodes : ";
    cin >> nodenumber;

    for(int i = 0; i < nodenumber ; i++){
      for(int j = 0; j < nodenumber ; j++){

          if(i == j)
            x[i][j] = 0;
          else
            x[i][j] = INT_MAX;
      }
   }

    while(scanf("%d %d",&u,&v)!=EOF)
    {
        cin >> cost;
        x[u][v] = cost;
    }

    for(int k = 0; k < nodenumber ; k++){
      for(int i = 0; i < nodenumber ; i++){
        for(int j = 0; j < nodenumber ; j++){
           x[i][j] = min(x[i][j],x[i][k]+x[k][j]);
        }
      }
    }

    while(scanf("%d%d",&src,&dist)!=EOF)
    {
        printf("%d - > %d : %d\n",src,dist,x[src][dist]);
    }

    return 0;
}
