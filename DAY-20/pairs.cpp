#include<iostream>
using namespace std;
int main(){
    pair<int, string> p = {2006, "Srikanta"};
    cout << "year of birth of "<< p.second << " is " << p.first<<endl;
    return 0;
}