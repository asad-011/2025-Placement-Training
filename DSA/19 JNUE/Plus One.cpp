class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int n=digits.size();
        int c=1;
        for(int i=n-1; i>=0 ; i--){
            digits[i]=digits[i]+c;
            c=digits[i]/10;
            digits[i]=digits[i]%10;
        }
        if(c==1){
            result.emplace_back(1);
        }
        for(auto it:digits){
            result.emplace_back(it);
        }
        return result;
    }
};
