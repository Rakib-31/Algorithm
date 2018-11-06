#include<bits/stdc++.h>
using namespace std;

int dp[100];

int fib(int n){
    if(dp[n] == -1){
        if(n <= 1) dp[n] = n;
        else {
            dp[n] =  fib(n-1) + fib(n-2);
            cout<<dp[n]<<" ";
        }
    }
    cout<<endl;
    return dp[n];
}

int main(){
    int n;

    cin>>n;

    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }

    cout<<fib(n)<<endl;

    return 0;
}
