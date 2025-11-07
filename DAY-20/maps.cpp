#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, string> student;
    student[1]="srikanta";
    student[2]="siddhartha";
    student[3]="abhinav";

    for(auto p : student){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}