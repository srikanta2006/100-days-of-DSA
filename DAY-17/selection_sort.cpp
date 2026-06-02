#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr){
    int n=arr.size();
   for(int i=0; i<n; i++){
    int smallest = i;
    for(int j=i; j<n; j++){
        if(arr[j]<arr[smallest]){
            smallest = j;
        }
    }
    swap(arr[smallest], arr[i]);
   }
}


int main(){
    vector<int> arr={4,1,5,2,3};
    selectionSort(arr);

    for(int i=0; i<arr.size();i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}