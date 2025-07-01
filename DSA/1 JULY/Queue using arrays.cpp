#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class arrayqueue{
    private:
        vector<int> qu;
    public:
        void front(){
            if(qu.empty()) cout<<"QUEUE Empty!"<<endl;
            else cout<<qu[0];
        }
        void enqueue(int n){
            qu.emplace_back(n);
        }
        void isEmpty(){
            if(qu.size()==0) cout<<"Empty!"<<endl;
            else cout<<"~Empty"<<endl;
        }
        void size(){
            cout<<qu.size()<<endl;
        }
        void dequeue(){
            if(qu.size()==0){ 
                cout<<"Empty! cant dequeue"<<endl;
                return; 
            }
            vector<int> temp;
            for(int i=qu.size()-1; i>=0;i--){
                temp.emplace_back(qu[i]);
            }
            temp.resize(temp.size()-1);
            qu.resize(qu.size()-1);
            int n=qu.size();
            for(int i=temp.size()-1; i>=0;i--){
                qu[n-i]=temp[i];
            }

            //Alternative
            // qu.erase(qu.begin());
        }
};
int main(){
    arrayqueue q1;
    // q1.size();
    // q1.isEmpty();
    // q1.dequeue();
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.size();
    q1.isEmpty();
    q1.dequeue();
    q1.dequeue();
    q1.size();
}
