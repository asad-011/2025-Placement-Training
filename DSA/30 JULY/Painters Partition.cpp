#include<bits/stdc++.h>
using namespace std;

int countPainter(vector<int> nums, int time){
    int totalPainters=1;
    int work=nums[0];
    for(int i=1; i<nums.size();i++){
        if(work+nums[i]>time){
            work=nums[i];
            totalPainters++;
        }
        else work+=nums[i];
    }
    return totalPainters;
}
int PainterPartition(vector<int> nums, int UnitTime, int Painters){
    int low=INT_MIN;
    int high=0;
    for(int i=0; i<nums.size(); i++){
        low=max(low,nums[i]);
        high+=(nums[i]);
    }

    while(low<=high){
        int mid=(low+high)/2;
        int TotalPainter=countPainter(nums,mid);
        if(TotalPainter<=Painters){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low*UnitTime;
}

int main(){
    vector<int> nums={1,8,11,3};
    cout<<PainterPartition(nums,1,10);
}
