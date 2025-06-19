class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int n=nums.size();
        // for(int i=n-1; i>=0; i--){             // insertion sort
        //     int j=0;
        //     while(j<i){
        //         if(nums[j]>nums[j+1]){swap(nums[j],nums[j+1]);}
        //         j++;
        //     }
        // }
        // for(auto it: nums){
        //     cout<<it<<" ";
        // }
        
        int n=nums.size();
        int low=0,mid=0,high=n-1;               //Dutch National Flag Algorithm
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++; low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};
