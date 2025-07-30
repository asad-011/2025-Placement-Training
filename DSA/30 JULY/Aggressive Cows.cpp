#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool CountCows(vector<int> stalls, int dist, int k){
        int cntcows=1;
        int last=stalls[0];
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i]-last >=dist){
                cntcows++;
                last=stalls[i];
            }
            if(cntcows>=k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int limit=nums[n-1]-nums[0];
        for(int i=1; i<limit ; i++){
            if(CountCows(nums,i,k)==false){
                return i-1;
            }
        }
        return limit;
    }
    int BSaggressiveCows(vector<int> &nums, int k){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=1;
        int high=nums[n-1]-nums[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(CountCows(nums,mid,k)==true){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
int main(){
    vector<int> stalls={4,2,1,3,6};
    cout<<aggressiveCows(stalls,2);
    cout<<BSaggressiveCows(stalls,2);

}
