#include<bits/stdc++.h>
using namespace std;

void insertst(stack<int> st, int x){
    if( st.empty() || st.top()<=x ){
        st.push(x);
        return;
    }
    int temp=st.top();
    st.pop();
    insertst(st,x);
    insertst(st,temp);
}
void sortstt(stack<int> st){
    if(st.empty()){
        return ;
    }
    int x=st.top();
    st.pop();
    sortstt(st);
    insertst(st,x);
}

int main(){
    stack<int> stt;
    stt.push(5);
    stt.push(4);
    stt.push(3);
    stt.push(2);
    stt.push(1);

    sortstt(stt);
    while(!stt.empty()){
        cout<<stt.top()<<" ";
        stt.pop();
    }
}