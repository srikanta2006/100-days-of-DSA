//can be performed only on sorted arrays.
#include<iostream>
#include<vector>
using namespace std;


int search(vector<int> arr, int target){
    int str=0;
    int end=arr.size()-1;
    while(str<=end){
        int mid=(str+end)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            str=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main(){

    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12};
    int target1=12;
    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};
    int target2=0;

    int index1= search(arr1, target1);

    int index2= search(arr2, target2);

    if(index1!=-1){
        cout << target1 << " found at "<< index1+1<<endl;
    }
    else{
        cout << target1 << " not found" << endl;
    }

    if(index2!=-1){
        cout << target2 << " found at "<< index2+1<<endl;
    }
    else{
        cout << target2 << " not found" << endl;
    }
   
    return 0;
}


//optimization
//calculate (str+(end-str))/2 => no over flow when two max numbers are added in int