#include<bits/stdc++.h>
using namespace std;

int main(){

    vector <int> v[100],v1[100];

    int n,m,k,value1,value2;
    string str[100],res[100],middle;
    char first,last;

    cout<<"Number of process: ";
    scanf("%d",&m);
    cout<<endl;
    cout<<"Number of resource: ";
    scanf("%d",&k);
    cout<<endl;
    cout<<"Number of edges: ";
    scanf("%d",&n);
    cout<<endl;
    getchar();

    for(int i = 0; i < n; i++){
        cin>>first>>value1>>middle>>last>>value2;
        //cout<<first<<middle<<last<<endl;
        if(first == 'p'){
            v[value1].push_back(value2);
        }
        if(last == 'p'){
            v1[value2].push_back(value1);
        }
    }

    for(int i = 1; i <= n; i++){
        bool flag = true;
        if(v1[i].size()){
            cout<<"process p"<<i<< " is holding for an instance of resource type";
            for(int j = 0; j < v1[i].size(); j++){
                cout<<" r"<<v1[i][j];
            }
            if(v[i].size()){
                flag = false;
                cout<<" and is waiting for an instance of resource type";
                for(int j = 0; j < v[i].size(); j++){
                    cout<<" r"<<v[i][j];
                }
                cout<<endl;
            }
        }
        if(flag){
            if(v[i].size()){
                cout<<"process p"<<i<< " is waiting for an instance of resource type";
                for(int j = 0; j < v[i].size(); j++){
                    cout<<" r"<<v[i][j];
                }
                cout<<endl;
            }
        }
        cout<<endl;

    }

    return 0;
}
