#include<bits/stdc++.h>
using namespace std;

void substring(int index,vector<int> &temp, vector<int> nums){
    if(index>=3){
        for(auto it:temp) cout<<it<<" ";
        cout<<endl;
        return;
    }
    temp.push_back(nums[index]);
    substring(index+1,temp,nums);
    temp.pop_back();
    substring(index+1,temp,nums);
}

void printsub(int n,vector<int> test){
    vector<int> temp;
    substring(0,temp, test);
}

int main(){
    vector<int> test={1,2,3};
    printsub(3,test);
    
}