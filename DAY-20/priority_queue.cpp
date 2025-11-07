#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(5);
    pq.push(4);
    pq.push(6);
    pq.push(2);
    pq.push(8);
    pq.push(3);
    pq.push(1);

    while(!pq.empty()){
        cout<<pq.top() << endl;
        pq.pop();
    }

    return 0;
}