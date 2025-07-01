class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // int n=nums1.size();
        // int m=nums2.size();
        // for(int i=0 ; i<n ;i++){
        //     int j=0;
        //     int maxnext=nums1[i];
        //     while(j<m){
        //         if(nums2[j]==maxnext){
        //             if(j==m-1){
        //                 nums1[i]=-1;
        //             }
        //             while(j<m){
        //                 if(maxnext<nums2[j]) {nums1[i]=nums2[j];
        //                 break;}
        //                 else if(j==m-1)  nums1[i]=-1;
        //                 j++;
        //             }
        //         }
        //         j++;
        //     }
        // }
        // return nums1;

        stack<int> st;
        map<int, int> hash;
        for(int i=nums2.size()-1;i>=0; i--){
            while(!st.empty() && st.top()<nums2[i]) st.pop();
            if(st.empty()) hash[nums2[i]]=-1;
            else hash[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(int i=0; i<nums1.size();i++){
            nums1[i]=hash[nums1[i]];
        }
        return nums1;
    }
};
