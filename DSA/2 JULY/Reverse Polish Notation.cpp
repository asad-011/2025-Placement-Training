#include <cstdlib>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans;
        stack<int> st;
        for(int i=0 ; i<tokens.size() ; i++){
            string operators=tokens[i];
            if(operators==  "+" || operators=="-"||operators=="*"||operators=="/"){
                int num2=st.top(); st.pop();
                int num1=st.top(); st.pop();
                if(operators=="+") st.push(num1+num2);
                if(operators=="-") st.push(num1-num2);
                if(operators=="*") st.push(num1*num2);
                if(operators=="/") st.push(num1/num2);
                  
            }
            else   st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
