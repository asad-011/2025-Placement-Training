#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class arraystack{
    private:
        vector<int> stt;
    public:
        void push(int n){ stt.emplace_back(n); }
        void top(){
            if(stt.empty()){
                cout << "Stack is empty" << endl;
                return;
            }
            cout<<stt[stt.size()-1];
        }
        void pop(){
            if(stt.empty()){
                cout << "Stack is empty" << endl;
                return;
            }
            stt.resize(stt.size()-1);
        }
        void peep(int i = 0 ){
            if(i < 0 || i >= stt.size()) {
                cout << "Index out of bounds" << endl;
                return;
            }
            cout << stt[stt.size() - 1 - i] << endl;
        }
};

int main(){
    arraystack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    cout << "Top element: ";
    st.top();
    cout << endl;

    cout << "Peeping at index 0: ";
    st.peep(0);
    
    cout << "Peeping at index 2: ";
    st.peep(2);

    cout << "Peeping at index 5 (out of bounds): ";
    st.peep(5);

    cout << "Popping top element." << endl;
    st.pop();
    
    cout << "Top element after pop: ";
    st.top();
    
    return 0;
}
