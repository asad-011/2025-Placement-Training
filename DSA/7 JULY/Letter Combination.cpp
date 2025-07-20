class Solution {
private:
    void solve(string digits, string output, int index, vector<string> &ans, vector<string> hash){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        int number=digits[index]-'0';
        string value=hash[number];
        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits, output, index+1 , ans, hash);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        vector<string> hash={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output;
        solve(digits, output, 0, ans, hash);
        return ans;
    }
};
