#include<bits/stdc++.h>
using namespace std;

void insertst(stack<int> st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int temp=st.top();
    st.pop();
    insertst(st,x);
}

void reversest(stack<int> st){
    if(st.empty()){
        return ;
    }
    int x=st.top();
    st.pop();
    reversest(st);
    insertst(st,x);
}

int main(){
    stack<int> stt;
    stt.push(5);
    stt.push(4);
    stt.push(3);
    stt.push(2);
    stt.push(1);

    reversest(stt);
    while(!stt.empty()){
        cout<<stt.top()<<" ";
        stt.pop();
    }
}