class Solution {
  public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool anti(string s1, string s2){
        int n=s1.size();
        int k=2;
        while(k>0){
            for(int i=0; i<n-1; i++){
                swap(s1[i],s1[i+1]);
            }
            k--;
        }
        return s1==s2 ? true: false;
    }
    bool clock1(string s1, string s2){
        int n=s1.size();
        int k=2;
        while(k>0){
            for(int i=n-1; i>0; i--){
                swap(s1[i],s1[i-1]);
            }
            k--;
        }
        return s1==s2 ? true: false;
    }
    bool isRotated(string& s1, string& s2) {
        // Your code here
        if(clock1(s1,s2)) return true;
        if(anti(s1,s2)) return true;
        return false;
    }
};
