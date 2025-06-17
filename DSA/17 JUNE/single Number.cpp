class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // map<int,int> mpp;
        int n=nums.size();
        // for(int i=0; i<n ;i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto it: mpp){
        //     if (it.second == 1) return it.first;
        // }
        // return 0;

        set<int> st;
        int sum=0;
        int stsum=0;
        for(int i=0; i<n;i++){
            if(!st.contains(nums[i])){   //doubt- st.contains(nums[i]) error in VScode
                st.insert(nums[i]);
                stsum+=nums[i];
            }
            sum+=nums[i];
        }
        return (2*stsum-sum);

        // int result=0;
        // for(int i=0 ; i<n ; i++){
        //     result=result^nums[i];
        // }
        // return result;
    }
};
