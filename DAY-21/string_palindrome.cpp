#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cout << "Enter the string to check for palindrome"<<endl;
    getline(cin, s);
    string sr=s;
    reverse(sr.begin(), sr.end());
    if(sr==s){
        cout << "The given string is a palindrome"<<endl;
    }
    else{
        cout << "The given string is not a palindrome"<<endl;
    }



    return 0;
}