#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Brute
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      //brute  
        // int n=nums.size();
        // for(int i=0; i<n; i++){
        //     if(nums[i]==target) return i;
        //     if(nums[i]>target) return i;  
        // }
        // return n;
      
    //optimal binary search method
        int n=nums.size();
        int low=0;
        int high=n-1;
        if(target<nums[low]) return 0;
        if(target>nums[high]) return n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(target>nums[mid]) low=mid+1;
            else high=mid-1;
        }
        return low;
    
    }
};


