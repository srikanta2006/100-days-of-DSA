#include<iostream>
using namespace std;

int main(){

    int arr[]={10,20,30,40};
    int* ptr = arr;  // arr is a pointer that points to arr[0];

    cout << *(ptr+1)<<endl; //20
    cout << *(ptr+3)<<endl; //40
    ptr++;
    cout <<*ptr<<endl; //20

    return 0;
}
