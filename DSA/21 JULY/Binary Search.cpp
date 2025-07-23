#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> nums,int target){
    int low=0, high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int binarySearchRecursive(vector<int> nums, int low, int high, int target){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]<target) return binarySearchRecursive(nums, mid+1, high,target);
    else return binarySearchRecursive(nums, low, mid-1,target);
}
int main(){
    binarySearch(nums,target);
    binarySearchRecursive(nums,0,nums.size()-1,target);
}
