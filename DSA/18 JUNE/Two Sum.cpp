class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> result;
        int n=nums.size();
        // for(int i=0; i<n;i++){
        //     for(int j=i+1; j<n;j++){              //Brute
        //         if(nums[i]+nums[j]==target){
        //             result.emplace_back(i);
        //             result.emplace_back(j);
        //             return result;
        //         }
        //     }
        // }
        // return result;

        map<int,int> mpp;
        for(int i=0; i<n ;i++){
            int req=target-nums[i];
            if(mpp.find(req)!=mpp.end()){
                return {mpp[req],i};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};
