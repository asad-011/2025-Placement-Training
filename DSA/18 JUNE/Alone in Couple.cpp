// User function Template for C++

class Solution {
  public:
    int findSingle(vector<int> &arr) {
        int n=arr.size(); 
        // map<int, int> mpp;
                                          //hashing
        // for(int i=0; i<n ;i++){
        //     mpp[arr[i]]++;
            
        // }
        // for(auto it: mpp){
        //     if(it.second%2!=0) return it.first;
        // }
        // return 0;
        
        int rem=arr[0];
        for(int i=1; i<n;i++){
            rem=rem^arr[i];             //XOR
        }
        return rem;
    }
};
