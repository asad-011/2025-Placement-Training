class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxsum=INT_MIN;
        // for(int i=0 ; i<n ; i++){
        //     int sum=0;                   //Brute
        //     for(int j=i ; j<n ; j++){
        //         sum+=nums[j];
        //         maxsum=max(maxsum,sum); 
        //     }     
        // }
        // return maxsum;

        //kadane's algo
        int sum=0;
        for(int i=0; i<n ; i++){
            sum+=nums[i];
            if(maxsum<sum) maxsum=sum;
            if(sum<=0) sum=0;
        }
        return maxsum;
    }
};
