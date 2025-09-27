#include<bits/stdc++.h>
using namespace std;
void printSum(int index, vector<int> &ds, int target, int sum, vector<int> test){
    if(index>=test.size()){
        if(sum==target){
            for(auto it: ds) cout<<it<<" ";
            cout<<endl;
        }
        return ;
    }
    ds.push_back(test[index]);
    sum+=test[index];
    printSum(index+1,ds,target,sum,test);

    ds.pop_back();
    sum-=test[index];
    printSum(index+1,ds, target,sum,test);
}
int main(){
    vector<int> test={1,2,1};
    int target=2;
    int sum=0;
    vector<int> temp;
    printSum(0,temp,target,sum,test);

}