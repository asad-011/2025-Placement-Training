#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &nums){
    int n=nums.size();
    for(int i=n-1; i>=0 ; i--){
        int j=0;
        for(j; j<i ; j++){
            if(nums[j]>nums[j+1]) swap(nums[j],nums[j+1]);
        }
    }
}

void bubblesortRecursive(vector<int> &nums,int end){
    if(end==0) return;
    int j=0;
    while(j<end){
        if(nums[j]>nums[j+1]) swap(nums[j],nums[j+1]);
        j++;
    }
    bubblesortRecursive(nums, end-1);
}

int main(){
    bubblesort(nums);
    bubblesortRecursive(nums,nums.size()-1);
}
