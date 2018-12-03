#include<bits/stdc++.h>
using namespace std;

int process[100],num;
vector <int> leftVec,rightVec;

int binSearch(int first,int start,int ends){
    if(ends >= start){
        int mid = (start+ends) / 2;
        if(process[mid] == first) return mid;
        else if(process[mid] > first)
            return binSearch(first,0,mid);
        return binSearch(first,mid+1,ends);
    }
}

int calculateLeftSerial(int index){
    int leftSum = 0;
    for(int i = index; i > 0; i--){
        leftVec.push_back(process[i]);
        leftSum += process[i] - process[i-1];
    }
    leftSum += process[num+2] - process[0];
    for(int i = num+1; i > index; i--){
        leftVec.push_back(process[i]);
        leftSum += process[i] - process[i-1];
    }
    return leftSum;
}

int calculateRightSerial(int index){
    int rightSum = 0;
    for(int i = index; i < num+2; i++){
        rightVec.push_back(process[i]);
        rightSum += process[i+1] - process[i];
    }
    rightSum += process[num+2] - process[0];
    for(int i = 1; i < index; i++){
        rightVec.push_back(process[i]);
        rightSum += process[i] - process[i-1];
    }
    return rightSum;
}

int main(){

    int first,last,start;
    cin>>num;
    for(int i = 0; i < num; i++){
        cin>>process[i];
    }
    cin>>first;
    cout<<"Range: ";
    cin>>start>>last;
    cout<<endl;
    process[num] = first;
    process[num+1] = start;
    process[num+2] = last;
    sort(process,process+num+3);

    int index = binSearch(first,0,num+2);
    int left = calculateLeftSerial(index);

    cout<<"Left First Final Serial: ";
    for(int i = 0; i < leftVec.size(); i++){
        cout<<leftVec[i]<<" ";
    }
    cout<<endl;
    cout<<"Total cost: "<<left<<endl;

    int right = calculateRightSerial(index);

    cout<<"Right First Final Serial: ";
    for(int i = 0; i < rightVec.size(); i++){
        cout<<rightVec[i]<<" ";
    }
    cout<<endl;
    cout<<"Total cost: "<<right<<endl;

    return 0;
}


