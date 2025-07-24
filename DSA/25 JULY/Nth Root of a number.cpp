#include<bits/stdc++.h>
using namespace std;

int findNthRoot(int n,int num){
    int ans=-1;
    int low=0, high=num;
    while(low<=high){
        int mid=(low+high)/2;
        int i=n;
        long long val=mid;
        while(i>1){
            val=val*mid;
            i--;
        }
        if(val==num) {
            return mid;
        }
        else if(val<num) low=mid+1;
        else high=mid-1;
    }
    return ans;
}
int main(){
    int n=4,m=81;
    cout<<findNthRoot(n,m);
}
