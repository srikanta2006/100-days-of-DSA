#include<iostream>
using namespace std;

int n_fac(int n){
    if(n==0){
        return 1;
    }

    return (n*n_fac(n-1));
}

int main(){
    int n;
    cout << "Enter the value of N"<<endl;
    cin >> n;
    cout << n_fac(n) << endl;
    return 0;
}
