#include<iostream>
using namespace std;
#include<vector>

void tripleSort(vector<int>& arr){
    int ones=0;
    int zeros=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==1){
            ones++;
        }
        else if(arr[i]==0){
            zeros++;
        }
    }
    int twos=arr.size()-ones-zeros;
    for(int i=0; i<arr.size(); i++){
        if(i<zeros){
            arr[i]=0;
        }
        else if(i<zeros+ones){
            arr[i]=1;
        }
        else{
            arr[i]=2;
        }
    }
}

int main(){
    vector<int> arr={0,0,1,0,2,1,1,2,2,0};
    tripleSort(arr);
    for(int i=0; i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
