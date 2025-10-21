/*
question:
given n stalls, c cows, and an array named arr of size n, distance of ith stall from origin is given by arr[i]
we need to return the largest value of the min distance between cows such that
i)all cows are placed
ii)the min distance between any two cows is possible max
*/

/*
approach:
determine the range for the answer first
min=1
max=largest num in arr - smallest number in arr
now binary search in this range
case1: if mid is a possible answer check right after saving the present
case2:if mid not possible answer check left for more smaller value

possibility check
1) sort the array
2)place first cow at 1st pos
3)place next cow at a position where distance greater than or equal to mid
4)if all cows placed with this condition that mid value is possible or else no
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool possible(vector<int>& arr, int mid, int n, int c){
    int cows=1;
    int current_pos=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]-current_pos>=mid){
            cows++;
            current_pos=arr[i];
        }
        if(cows==c){
            return true;
        }
    }
    return false;
}


int getDistance(vector<int>& arr, int n, int c){
    int st=1;
    int end=arr[n-1]-arr[0];
    int ans=-1;
    while(st<=end){
        int mid=st + (end-st)/2;
        if(possible(arr, mid, n, c)){
            ans=mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

int main(){

    int n=5;
    int c=3;
    vector<int> arr ={1,2,8,4,9};
    sort(arr.begin(), arr.end());
    cout << getDistance(arr, n, c)<<endl;
    return 0;
}