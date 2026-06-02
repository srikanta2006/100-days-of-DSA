#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=1; i<n; i++){
        int key = arr[i]; // left most section of unsorted part
        int j = i-1; //index of right most section of sorted part
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}


int main(){
    vector<int> arr={4,1,5,2,3};
    insertionSort(arr);

    for(int i=0; i<arr.size();i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}