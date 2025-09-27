#include<bits/stdc++.h>
using namespace std;
int CountSubSeq(int index, int target, int sum, vector<int> test){
    if(index>=test.size()){
        if(sum==target) return 1;
        return 0;
    }

    int lp=CountSubSeq(index+1,target,sum+test[index],test);

    int rp=CountSubSeq(index+1, target,sum,test);
    return lp+rp;
}
int main(){
    vector<int> test={1,2,1};
    int target=4;
    cout<<CountSubSeq(0,target,0,test);

}