class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookies=0;
        int child=0;
        int n=g.size();
        int m=s.size();
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        while(child< n && cookies <m){
            if(s[cookies]>=g[child]){
                child++;
            }
            cookies++;
        }
        return child;
    }
};
