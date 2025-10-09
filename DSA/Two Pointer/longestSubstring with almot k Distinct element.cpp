#include<bits/stdc++.h>
using namespace std;


int longestKSubstr(string &s, int k) {
        // code here
        int count=-1;
        int l=0, r=0;
        vector<int> freq(26,0);
        int distinct=0;
        while(r<s.size()){
            if(freq[s[r]-'a']==0) distinct++;
            freq[s[r]-'a']++;
            if(distinct<=k) count=max(count,r-l+1);
            while(distinct>k && l<=r){
                freq[s[l]-'a']--;
                if(freq[s[l]-'a']==0) distinct--;
                l++;
            }
            r++;
        }
        return count;
};
int main(){
    string s="abcddefg";
    cout<<longestKSubstr(s,2);
}