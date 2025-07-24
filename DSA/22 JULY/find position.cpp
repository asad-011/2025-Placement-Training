class Solution {
private:
    int findfirst(vector<int> nums, int target){
        int low=0, high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target) ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    int findlast(vector<int> nums, int target){
        int low=0, high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<=target){
                if(nums[mid]==target) ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans(2,-1);
        ans[0]=findfirst(nums,target);
        ans[1]=findlast(nums,target);
        return ans;
    }
};
