#include<bits/stdc++.h>
using namespace std;

int process[100],num;
vector <int> vec;

int binSearch(int first,int start,int ends){
    if(ends >= start){
        int mid = (start+ends) / 2;
        if(process[mid] == first) return mid;
        else if(process[mid] > first)
            return binSearch(first,0,mid);
        return binSearch(first,mid+1,ends);
    }
}

void removeElement(int index){
    for(int i = index; i < num; i++){
        process[i] = process[i+1];
    }
    num--;
}

void calculateSerial(int index){
    vec.push_back(process[index]);
    int temp = index;
    int left = index-1;
    int right = index+1;
    if(left < 0 && right > num)
        return;
    if(left > -1 && right < num+1){
        index = (abs(process[left] - process[index]) < abs(process[right] - process[index])) ? left : right;
    }
    else if(left > -1 && right > num){
        index = left;
    }
    else index = right;
    removeElement(temp);
    if(index>temp) index--;

    calculateSerial(index);
}

int main(){

    int first;
    cin>>num;
    for(int i = 0; i < num; i++){
        cin>>process[i];
    }
    cin>>first;
    process[num] = first;
    sort(process,process+num+1);

    int index = binSearch(first,0,num);
    calculateSerial(index);

    cout<<"Final Serial: ";
    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    int time = 0;
    for(int i = 1; i < vec.size(); i++){
        time += abs(vec[i] - vec[i-1]);
    }

    cout<<"Total cost: "<<time<<endl;

    return 0;
}
