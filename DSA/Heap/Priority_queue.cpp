#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    priority_queue<int, vector<int>, greater<int>> p;
    p.push(10);
    p.push(10);
    p.push(5);
    p.push(19);
    p.push(1);
    p.push(100);
    while(p.size()){
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;


    // priority_queue<int> p; //maxHeap;
    // p.push(10);
    // p.push(1);
    // p.push(50);
    // p.push(11);
    // p.push(100);
    // cout<<p.top();
    // while(p.size()){
    //     cout<<p.top()<<" ";
    //     p.pop();
    // }
    // cout<<endl;
}
