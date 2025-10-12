//can be performed only on sorted arrays.
//recursive approach
#include<iostream>
#include<vector>
using namespace std;


int search(vector<int> arr1, int target, int str, int end){
if(str<=end){
   int mid=str + (end - str)/2;
   if(arr1[mid]==target){
    return mid;
   }
   else if(arr1[mid]>target){
    return search(arr1, target, str, mid-1);
   }
   else{
    return search(arr1, target, mid+1, end);
   }
}
else{
    return -1;
}
}

int main(){

    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12};
    int target1=12;
    int str=0;
    int end=arr1.size()-1;
    

    int index1= search(arr1, target1, str, end);


    if(index1!=-1){
        cout << target1 << " found at "<< index1+1<<endl;
    }
    else{
        cout << target1 << " not found" << endl;
    }
    return 0;
}