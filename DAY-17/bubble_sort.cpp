#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr){
    int n = arr.size();
    while(n>1){
        for(int j=0; j<n-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
        n-1;
    }
}

int main(){
    vector<int> arr={4,1,5,2,3};
    bubbleSort(arr);

    for(int i=0; i<arr.size();i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}