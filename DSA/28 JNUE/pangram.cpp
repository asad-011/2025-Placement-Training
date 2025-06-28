class Solution {
public:
    bool checkIfPangram(string sentence) {
    // vector<char> hash(27,0);
    // for(int i=0; i<sentence.size(); i++){
    //     int pos=sentence[i]-'a';
    //     hash[pos]++;
    // }
    // for(int i=0; i<26 ; i++){
    //     if(hash[i]==0) return false;
    // }
    // return true;
        set<char> history;
        int n=sentence.size();
        if(n<26) return false;
        int count=0;
        for(auto it: sentence){
            if(history.find(it)==history.end()) {
                count++;
                history.insert(it);
            }
        }
        return count==26 ? true : false;
    }

};
