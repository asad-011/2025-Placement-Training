#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &nums){
    for(int i=0; i<nums.size(); i++){
        int minindex=i;
        for(int j=i+1 ; j<nums.size(); j++){
            if(nums[j]<nums[minindex]) minindex=j;
        }
        swap(nums[minindex],nums[i]);
    }
}
int findMinIndex(vector<int> nums, int start, int end){
    int minIndex=start;
    for(int i=start+1; i<end; i++){
        if(nums[start]>nums[i]) minIndex=i;
    }
    return minIndex;
    // if(start==n-1) return start;

    // int minRest=findMinIndex(nums,start+1,n);
    
    // return (nums[start]<nums[minRest]) ? start : minRest;
}
void selectionSortRecursive(vector<int> &nums,int index){
    int n=nums.size();

    if(index==nums.size()) return;
    int minIndex=findMinIndex(nums,index,n);
    swap(nums[index], nums[minIndex]);

    selectionSortRecursive(nums,index+1);
}

int main(){
    selectionSort(nums);
    selectionSortRecursive(nums,0);
}
