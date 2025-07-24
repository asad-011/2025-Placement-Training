#include<bits/stdc++.h>
using namespace std;

int numberOfRotation(vector<int> nums){
    for(int i=1; i<nums.size();i++){
        if(nums[i]<nums[i-1]) return i;
    }
    return 0;
}
int numberOfRotationBST(vector<int> nums){
    int low=0,high=nums.size()-1;
    int ans=INT_MAX;
    int index=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[low]<=nums[high]) return low;
        if(nums[low]<=nums[mid]){
            if(nums[low]<ans){
                ans=nums[low];
                index=low;
                low=mid+1;
            }
            else low=mid+1    
        }
        else{
            if(nums[mid]<ans){
                ans=nums[mid];
                index=mid;
                high=mid-1;
            }
        }
    }
    return index;
}
int main(){
    cout<<numberOfRotation(nums);
    cout<<numberOfRotationBST(nums);
}
