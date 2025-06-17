class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //hashing
        int n=nums.size();
        // vector<int> hash(n+1,0);
        // for(int i=0; i<n ; i++){
        //     hash[nums[i]]++;
        // }
        
        // for(int i=0; i<n+1;i++){
        //     if(hash[i]==0){return i;}
        // }
        // return -1;

        // formula
        int sum=0;
        for(int i=0; i<n ;i++){
            sum+=nums[i];
        }
        int miss=n*(n+1)/2 - sum;
        return miss;
    }

    
    
};
