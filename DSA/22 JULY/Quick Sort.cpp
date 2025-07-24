#include<bits/stdc++.h>
using namespace std;

int partitionIndex(vector<int> &nums,int low, int high){
    int pivot=nums[low];
    int j=low;
    for(int i=low+1; i<=high ; i++){
        if(nums[i]<pivot){
            j++;
            swap(nums[j],nums[i]);
        }
    }
    swap(nums[low],nums[j]);
    return j;
}

void quicksort(vector<int> &nums, int low, int high){
    if(low>high) return;

    int q=partitionIndex(nums,low,high);
    quicksort(nums,low,q-1);
    quicksort(nums,q+1,high);
}
vector<int> qs(vector<int> &nums){
    quicksort(nums,0,nums.size()-1);
    return nums;
}
int main(){
    vector<int> arr={2,6,1,9,5,7};
    for(auto it: arr) cout<<it<<" ";
    cout<<endl;
    arr=qs(arr);
    for(auto it: arr) cout<<it<<" ";
}
