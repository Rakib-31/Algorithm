#include<bits/stdc++.h>
using namespace std;

int process[100],num,arr[100];
vector <int> leftVec,rightVec,vec;

int binSearch(int first,int start,int ends){
    if(ends >= start){
        int mid = (start+ends) / 2;
        if(process[mid] == first) return mid;
        else if(process[mid] > first)
            return binSearch(first,0,mid);
        return binSearch(first,mid+1,ends);
    }
}

int binSearchSSTF(int first,int start,int ends){
    if(ends >= start){
        int mid = (start+ends) / 2;
        if(arr[mid] == first) return mid;
        else if(arr[mid] > first)
            return binSearchSSTF(first,0,mid);
        return binSearchSSTF(first,mid+1,ends);
    }
}

int calculateScanLeftSerial(int index){
    int leftSum = 0;
    for(int i = index; i > 0; i--){
        leftVec.push_back(process[i]);
        leftSum += process[i] - process[i-1];
    }
    leftVec.push_back(process[0]);
    if(index+1<num+2) leftSum += process[index+1] - process[0];
    for(int i = index+1; i < num+2; i++){
        leftVec.push_back(process[i]);
        leftSum += process[i+1] - process[i];
    }
    leftVec.push_back(process[num+2]);
    return leftSum;
}

int calculateScanRightSerial(int index){
    int rightSum = 0;
    for(int i = index; i < num+2; i++){
        rightVec.push_back(process[i]);
        rightSum += process[i+1] - process[i];
    }
    rightVec.push_back(process[num+2]);
    if(index-1>0) rightSum += process[num+2] - process[index-1];
    for(int i = index-1; i > 0; i--){
        rightVec.push_back(process[i]);
        rightSum += process[i] - process[i-1];
    }
    rightVec.push_back(process[0]);
    return rightSum;
}

int calculateCscanLeftSerial(int index){
    int leftSum;
    for(int i = index; i >= 0; i--)
        leftVec.push_back(process[i]);
    for(int i = num+2; i > index; i--)
        leftVec.push_back(process[i]);
    leftSum = process[index] - 2*process[0] + 2*process[num+2] - process[index+1];
    return leftSum;
}

int calculateCscanRightSerial(int index){
    int rightSum;
    for(int i = index; i <= num+2; i++)
        rightVec.push_back(process[i]);
    for(int i = 0; i < index; i++)
        rightVec.push_back(process[i]);
    rightSum = 2*process[num+2] - process[index] + process[index-1] - 2*process[0];
    return rightSum;
}

void removeElement(int index){
    for(int i = index; i < num; i++){
        arr[i] = arr[i+1];
    }
    num--;
}

void calculateSerial(int index){
    vec.push_back(arr[index]);
    int temp = index;
    int left = index-1;
    int right = index+1;
    if(left < 0 && right > num)
        return;
    if(left > -1 && right < num+1){
        index = (abs(arr[left] - arr[index]) < abs(arr[right] - arr[index])) ? left : right;
    }
    else if(left > -1 && right > num){
        index = left;
    }
    else index = right;
    removeElement(temp);
    if(index>temp) index--;

    calculateSerial(index);
}

int calculateLookLeftSerial(int index){
    int leftSum = 0;
    for(int i = index; i > 0; i--){
        leftVec.push_back(process[i]);
        if(i-1>0)
            leftSum += process[i] - process[i-1];
    }
    if(index+1<num+2) leftSum += process[index+1] - process[1];

    for(int i = index+1; i < num+2; i++){
        leftVec.push_back(process[i]);
        if(i+1<num+2)
            leftSum += process[i+1] - process[i];
    }
    return leftSum;
}

int calculateLookRightSerial(int index){
    int rightSum = 0;
    for(int i = index; i < num+2; i++){
        rightVec.push_back(process[i]);
        if(i+1<num+2)
            rightSum += process[i+1] - process[i];
    }
    if(index-1>0) rightSum += process[num+1] - process[index-1];
    for(int i = index-1; i > 0; i--){
        rightVec.push_back(process[i]);
        if(i-1>0)
            rightSum += process[i] - process[i-1];
    }
    return rightSum;
}

int calculateCLookLeftSerial(int index){
    int leftSum = 0;
    for(int i = index; i > 0; i--){
        leftVec.push_back(process[i]);
        if(i-1>0)
            leftSum += process[i] - process[i-1];
    }
    leftSum += process[num+1] - process[1];
    for(int i = num+1; i > index; i--){
        leftVec.push_back(process[i]);
        if(i-1>index)
            leftSum += process[i] - process[i-1];
    }
    return leftSum;
}

int calculateCLookRightSerial(int index){
    int rightSum = 0;
    for(int i = index; i < num+2; i++){
        rightVec.push_back(process[i]);
        if(i+1<num+2)
            rightSum += process[i+1] - process[i];
    }
    rightSum += process[num+1] - process[1];
    for(int i = 1; i < index; i++){
        rightVec.push_back(process[i]);
        if(i+1<index)
            rightSum += process[i+1] - process[i];
    }
    return rightSum;
}

void output(int left, int right){
    cout<<"Left First Final Serial: ";
    for(int i = 1; i < leftVec.size(); i++){
        cout<<leftVec[i]<<" ";
    }
    cout<<endl;
    cout<<"Total cost: "<<left<<endl;

    cout<<"Right First Final Serial: ";
    for(int i = 1; i < rightVec.size(); i++){
        cout<<rightVec[i]<<" ";
    }
    cout<<endl;
    cout<<"Total cost: "<<right<<endl;
}

void fcfs(){
    cout<<endl<<"FCFS:"<<endl<<endl;
    int time = 0;
    for(int i = 0; i < num; i++){
        cout<<process[i]<<" ";
        if(i+1<num)
            time += abs(process[i+1] - process[i]);
    }
    cout<<endl;
    cout<<"Cost: "<<time<<endl<<endl;
}

int main(){

    int last,start,first;
    cin>>num;
    for(int i = 0; i < num; i++){
        cin>>process[i];
        arr[i] = process[i];
    }
    cin>>first;
    cout<<"Range: ";
    cin>>start>>last;
    cout<<endl;

    fcfs();

    process[num] = first;
    arr[num] = first;
    process[num+1] = start;
    process[num+2] = last;
    sort(process,process+num+3);

    int index = binSearch(first,0,num+2);
    int left = calculateScanLeftSerial(index);
    int right = calculateScanRightSerial(index);

    cout<<endl<<"Scan: "<<endl<<endl;
    output(left,right);


    leftVec.clear();
    rightVec.clear();

    left = calculateCscanLeftSerial(index);
    right = calculateCscanRightSerial(index);

    cout<<endl<<"Cscan: "<<endl<<endl;
    output(left,right);

    leftVec.clear();
    rightVec.clear();

    left = calculateLookLeftSerial(index);
    right = calculateLookRightSerial(index);

    cout<<endl<<"Look: "<<endl<<endl;
    output(left,right);

    leftVec.clear();
    rightVec.clear();

    left = calculateCLookLeftSerial(index);
    right = calculateCLookRightSerial(index);

    cout<<endl<<"CLook: "<<endl<<endl;
    output(left,right);


    cout<<endl<<"SSTF:"<<endl<<endl;
    sort(arr,arr+num+1);
    index = binSearchSSTF(first,0,num);

    calculateSerial(index);
    cout<<"Final Serial: ";
    for(int i = 1; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    int time = 0;
    //cout<<vec.size()<<endl;
    for(int i = 1; i < vec.size(); i++){
        time += abs(vec[i] - vec[i-1]);
    }

    cout<<"Total cost: "<<time<<endl;


    return 0;
}


