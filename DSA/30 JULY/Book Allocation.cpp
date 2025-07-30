#include<bits/stdc++.h>
using namespace std;

int countstudents(vector<int> pages, int perpage){
    int totalstudent=1;
    int noofPages=pages[0];
    for(int i=1; i<pages.size();i++){
        if(noofPages+pages[i] > perpage){
            totalstudent++;
            noofPages=pages[i];
        }
        else noofPages+=pages[i];
    }
    return totalstudent;
}
int AllocationOfPages(vector<int> nums, int m){
    int low=INT_MIN;
    int high=0;
    for(int i=0; i<nums.size(); i++){
        low=max(low,nums[i]);
        high+=nums[i];
    }
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        int totalStudents=countstudents(nums,mid);
        if(totalStudents<=m){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> pages={25,46,28,49,24};
    cout<<AllocationOfPages(pages,5);
}
