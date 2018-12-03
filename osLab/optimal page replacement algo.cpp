#include<bits/stdc++.h>
using namespace std;

vector <int> vec;
vector <int> :: iterator it;
bool check[100];

int discard(int siz[],int frame,int a, int n){
    int big  = -5,con;
    for(int i = 0; i < frame; i++){
        it = find(vec.begin()+a,vec.end(),siz[i]);
        if(it != vec.end()){
            int x = distance(vec.begin(),it);
            if(x>big){
               big = x;
               con = i;
            }
        }
        else return i;
    }
    return con;
}

int main(){

    int n,data,frame,need = 0,coun=0,finalRes[100];
    char finalChar[100];
    cin>>n>>frame;



    for(int i = 0; i < n;i++){
        cin>>data;
        vec.push_back(data);
    }

    int siz[frame];

    for(int i = 0; i < n; i++){
            bool fault = false;
        if(!check[vec[i]]){
            check[vec[i]] = true;
            fault = true;
            need++;
            finalRes[i] = vec[i];
            finalChar[i] = 'p';

            if(coun < frame){
                siz[coun++] = vec[i];
            }
            else{
                int get = discard(siz,frame,i+1,n);

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
        if(fault) cout<<" p";
        cout<<endl;
    }

    cout<<endl<<"Page fault:"<<endl<<endl;
    for(int i = 0; i < n; i++){
        cout<<finalRes[i]<<" "<<finalChar[i]<<endl;
    }

    cout<<endl<<"Number of page fault: "<<need<<endl;

    return 0;
}

