#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int st, int end){
    int idx=st-1;
    int pivot = arr[end];
    for(int j=st; j<end; j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end){
    if(st<end){
        int pivotIdx= partition(arr, st, end);
        quickSort(arr, st, pivotIdx-1); //left partition
        quickSort(arr, pivotIdx+1, end); //right partition
    }
}

int main(){
    vector<int> arr ={12, 31, 35, 8, 32, 17};
    int n = arr.size();
    cout << "Before sorting"<< endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
    quickSort(arr, 0, n-1);
    cout << "After sorting"<< endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
    return 0;
}