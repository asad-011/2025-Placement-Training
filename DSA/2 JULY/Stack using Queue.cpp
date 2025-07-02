class MyStack {
    queue<int> qt;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        qt.push(x);
    }
    
    int pop() {
        if(qt.empty()) return -1;
        int n=qt.size();
        for(int i=0; i<n-1; i++){
            qt.push(qt.front());
            qt.pop();
        }
        int pop=qt.front();
        qt.pop();
        return pop;
    }
    
    int top() {
        return qt.back();
    }
    
    bool empty() {
        return qt.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
