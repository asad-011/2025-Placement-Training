# include<iostream>
using namespace std;

class Solution {
  public:
    int reverseDigits(int n) {
        // Code here
        int reverse=0;
        while(n>0){
            int r=n%10;
            reverse=reverse*10+r;
            n=n/10;
        }
        return reverse;
    }
};
