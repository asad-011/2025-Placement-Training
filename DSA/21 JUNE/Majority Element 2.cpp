class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int req = n / 3 + 1;
        map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        vector<int> ans;
        for (auto it : mpp) {
            if (it.second >= req)
                ans.emplace_back(it.first);
        }
        return ans;
        
    }
};
