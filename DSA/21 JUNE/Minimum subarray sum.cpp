class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int minL = n+1;
        int sum = 0;
        while (r < n ) {
            sum += nums[r];
            while (l<=r && sum >= target) {
                minL = min(minL , r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        
        return minL==n+1 ? 0 : minL;
    }
};
