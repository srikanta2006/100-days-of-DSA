/*

I]given:
1)n -> number of books
2)arr vector -> where arr[i] indicates number of pages in ith book
3)m -> number of students

II]required to return(ROR):
min possible value of pages at a student who has max number of pages amongst all other after allocation.

III]conditions:
1]each student should atleast get one book
2]each book must be given to a student
3]allocation must happen in contigious manner.

**approach and psedou code written in 17th october DSA notes**

*/
#include<iostream>
#include<vector>
using namespace std;


bool isValid(vector<int>& arr, int n, int m, int mid){
    int student=1; 
    int pages=0;
    for(int i=0; i<n; i++){
        if(arr[i]>mid){
            return false;
        }
        if(pages+arr[i]<=mid){
            pages=pages+arr[i];
        }
        else{
            student++;
            pages=arr[i];
        }
    }
    if(student<=m){
        return true;
    }

    return false; 
}

int sum(vector<int>& arr, int n){
    int total=0;
    for(int i=0; i<n; i++){
        total = total+arr[i];
    }
    return total;
}

int allocateBooks(vector<int>& arr, int n, int m){
    int st = 0;
    int end = sum(arr,n);
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isValid(arr, n, m, mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return ans;
}
int main(){

    vector<int> arr ={15,17,20};
    int n=arr.size(), m=2;
    cout << allocateBooks(arr,n,m) << endl;


    return 0;
}