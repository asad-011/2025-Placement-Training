class Solution {
public:
    int magicalString(int n) {
        if(n<=3) return 1;
        int count=1;
        int index=2;
        string s="122";
        int y=s.size();
        while(y<n){
            if(s.back()=='2'){
                s+='1'; 
                count++;
                if(s[index]=='2'){
                    s+='1'; count++;
                }
            }
            else {
                s+='2';
                if(s[index]=='2'){
                    s+='2';
                }
            }
            index++;
            y=s.size();
        }
        if(s.size()==n) return count;
        if(s.back()=='1') return count-1;
        return count;
    }
};
