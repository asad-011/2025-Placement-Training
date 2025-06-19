class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0;                     //brute  
        // for(int i=0; i<n ; i++){
        //     int buy=prices[i];
        //     for(int j=i+1 ; j<n ; j++){
        //         if(buy<prices[j]){
        //             int profit=prices[j]-buy;
        //             maxProfit=max(profit,maxProfit);
        //         }
        //     }
        // }
        // return maxProfit;

        int min=prices[0];
        for(int i=1; i<n ; i++){
            if(min>prices[i]) min=prices[i];
            maxProfit=max(maxProfit,prices[i]-min);
        }
        return maxProfit;
    }
};
