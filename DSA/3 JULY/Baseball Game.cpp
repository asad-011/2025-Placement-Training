
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> score;
        for(int i=0; i<operations.size(); i++){
                if(operations[i]=="+"){
                    int num2=score.top(); 
                    score.pop();
                    int num1=score.top();
                    score.push(num2);
                    score.push(num1+num2);
                }
                else if(operations[i]=="C") score.pop();
                else if (operations[i]=="D")  score.push(score.top()*2);
                else {
                    int num=stoi(operations[i]);
                    score.push(num);
                }
        }

        int ans=0;
        while(score.size()!=0){
            ans+=score.top();
            score.pop();
        }
        return ans;
    }
};
