#include<bits/stdc++.h>
using namespace std;

vector <int> vec;
vector <int> :: iterator it;
int mp[100];
bool check[100];

int discard(int siz[],int frame, int n){
    int big  = 100000,con;
    for(int i = 0; i < frame; i++){
        if(mp[siz[i]] < big){
            big = mp[siz[i]];
            con = i;
        }
    }
    return con;
}

int main(){

    int n,data,frame,need = 0,coun=0,count = 1,finalRes[100];
    char finalChar[100];

    cin>>n>>frame;



    for(int i = 0; i < n;i++){
        cin>>data;
        vec.push_back(data);
    }

    int siz[frame];

    for(int i = 0; i < n; i++){
            bool fault = false;
        count++;
        mp[vec[i]] = count;
        if(!check[vec[i]]){
            fault = true;
            check[vec[i]] = true;
            need++;
            finalRes[i] = vec[i];
            finalChar[i] = 'p';
            if(coun < frame){
                siz[coun++] = vec[i];
            }
            else{
                int get = discard(siz,frame,n);

                check[siz[get]] = false;
                siz[get] = vec[i];
            }
        }
        else{
            finalRes[i] = vec[i];
            finalChar[i] = ' ';
        }
        cout<<"New Frame: ";
        for(int j = 0; j < coun; j++){
            cout<<siz[j]<<" ";
        }
        if(fault) cout<<" "<<"p";
        cout<<endl;
    }
    cout<<endl<<"Page fault:"<<endl<<endl;
    for(int i = 0; i < n; i++){
        cout<<finalRes[i]<<" "<<finalChar[i]<<endl;
    }
    cout<<endl<<"Number of page fault: "<<need<<endl;

    return 0;
}


