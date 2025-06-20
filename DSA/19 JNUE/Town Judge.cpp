class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int siz=trust.size();
        vector<int> count(n+1);
        for(auto person: trust){
            count[person[0]]--;
            count[person[1]]++;
        }
        for(int i=1; i< n+1; i++){
            if(count[i]==n-1) return i;
        }
        return -1;
    }
};
