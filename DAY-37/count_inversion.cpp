#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int> &arr, int st, int mid, int end){
    int invoCount=0;
    vector<int> temp;
    int i=st;
    int j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            invoCount+=(mid-st)+1;
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0; idx<temp.size(); idx++){
        arr[idx+st] = temp[idx];
    }
    return invoCount;
}

int mergeSort(vector<int> &arr, int st, int end){
    if(st<end){
        int mid = st + (end-st)/2;
        int leftCount= mergeSort(arr, st, mid);
        int rightCount= mergeSort(arr, mid+1, end);

        int count= merge(arr, st, mid, end);

        return leftCount+rightCount+count;
    }
    return 0;

}


int main(){
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    for(int i=0; i<arr.size(); i++){
        cout <<arr[i] << " ";
    }
    cout<<endl;
    int ans= mergeSort(arr, 0, arr.size()-1);
    cout<<"invertion count: " << ans;
    cout<<endl;

    return 0;
}