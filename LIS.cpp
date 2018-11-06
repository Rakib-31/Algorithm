#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,a[100],lis[100];

    for(int i = 0; i < 100; i++)
        lis[i] = 1;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" "<<lis[i]<<endl;

    return 0;
}
