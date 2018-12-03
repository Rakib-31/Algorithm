#include<bits/stdc++.h>
using namespace std;

map <char,bool> check;

int main(){

    int n,frame,need = 1,coun=1;
    cin>>n>>frame;
    string s;
    getchar();
    getline(cin,s);
    queue <char> q;
    q.push(s[0]);
    check[s[0]] = true;
    cout<<s[0]<<" "<<"p"<<endl;

    for(int i = 1; i < s.size(); i++){
        if(s[i] != ' '){
            if(coun < frame){
                if(!check[s[i]]){
                    check[s[i]] = true;
                    q.push(s[i]);
                    need++;
                    coun++;
                    cout<<s[i]<<" "<<"p"<<endl;
                }
            }
            else{
                if(!check[s[i]]){
                    check[s[i]] = true;
                    check[q.front()] = false;
                    q.pop();
                    need++;
                    q.push(s[i]);
                    cout<<s[i]<<" p"<<endl;
                }
                else cout<<s[i]<<endl;
            }
        }
    }
    cout<<need<<endl;

    return 0;
}
