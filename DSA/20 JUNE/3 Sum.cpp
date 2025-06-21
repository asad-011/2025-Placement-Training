class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //brute o(n^3);
        // vector<vector<int>> result;
        set<vector<int>> stt;
        int n=nums.size();
        // for(int i=0; i<n ; i++){
        //     for(int j=i+1; j<n;j++){
        //         for(int k=j+1; k<n ; k++){
        //             vector<int> triplet;
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 triplet.emplace_back(nums[i]);
        //                 triplet.emplace_back(nums[j]);
        //                 triplet.emplace_back(nums[k]);
        //                 sort(triplet.begin(),triplet.end());
        //                 stt.insert(triplet);
        //             }
        //         }
        //     }
        // }
        // for(auto it: stt){
        //     result.emplace_back(it);
        // }
        // return result;

        //Better
        // for(int i=0; i<n;i++){
        //     set<int> hash;
        //     for(int j=i+1;j<n;j++){
        //         int req=-(nums[i]+nums[j]);
        //         if(hash.find(req)!=hash.end()){
        //             vector<int> triplet={nums[i],nums[j],req};
        //             sort(triplet.begin(),triplet.end());
        //             stt.insert(triplet);
        //         }
        //         hash.insert(nums[j]);
        //     }
        // }
        // for(auto it: stt){
        //     result.emplace_back(it);
        // }
        // return result;

        //optimal
        sort(nums.begin(),nums.end());
        for(int i=0; i<n ; i++){
            if( i!=0 && nums[i]==nums[i-1]){continue;}
            int j=i+1;
            int k=n-1;
            while(k>j){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    stt.insert(temp);
                    j++; k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        vector<vector<int>> result(stt.begin(),stt.end());
        return result;
    }
};
