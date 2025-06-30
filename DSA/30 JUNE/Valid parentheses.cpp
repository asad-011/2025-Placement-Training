class Solution {
public:
    bool isValid(string s) {
        stack<char> stt;
        for(int i=0; i<s.size(); i++){
            char ch=s[i];
            if(ch=='('||ch=='['||ch=='{'){
                stt.push(ch);
            }
            else if(!stt.empty()){
                if(ch==')'){
                    if(stt.top()!='(') return false;
                    else stt.pop();
                }
                if(ch=='}'){
                    if(stt.top()!='{') return false;
                    else stt.pop();
                }
                if(ch==']'){
                    if(stt.top()!='[') return false;
                    else {
                        stt.pop();
                    }
                }
            }
            else return false;
        }
        if(!stt.empty()) return false;
        return true;
    }
};
