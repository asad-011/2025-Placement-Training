#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &nums){
    int n=nums.size();
    for(int i=0; i<n ; i++){
        int j=i;
        while(j>0 && nums[j]<nums[j-1]){
            swap(nums[j],nums[j-1]);
            j--;
        }
    }
}
void insertionSortRecursive(vector<int> &nums,int end){
    if(end==nums.size()) return;
    int j=end;
    while(j>0 && nums[j]<nums[j-1]){
        swap(nums[j],nums[j-1]);
        j--;
    }
    insertionSortRecursive(nums,end+1);
}
int main(){
    insertionSort(nums);
    insertionSortRecursive(nums,0);
}
