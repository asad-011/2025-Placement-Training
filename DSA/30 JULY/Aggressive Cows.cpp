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
int main(){
    vector<int> stalls={0,3,4,7,10,9};
    cout<<aggressiveCows(stalls,4);

}
