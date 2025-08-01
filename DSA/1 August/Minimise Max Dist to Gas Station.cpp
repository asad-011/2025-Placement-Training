class Solution {
    private:
        int countGasStation(vector<int> stations, double dis, int k){
        int count=0;
        for(int i=0; i<stations.size()-1; i++){
            int numberOfStationBet=(stations[i+1]-stations[i])/dis;
            if(((stations[i+1]-stations[i]))==(numberOfStationBet*dis))
                {numberOfStationBet--;}
                
            count+=numberOfStationBet;
            
            if(count>k) return count;
        }
        return count;
        }
  public:
    
    double findSmallestMaxDist(vector<int> &stations, int k) {
        //optimal
        int n=stations.size();
        double low=0;
        double high=-1;
        for(int i=0; i<n-1; i++){
            high=max(high,(double)(stations[i+1]-stations[i]));
        }
        double diff=10e-6;
        while(high-low > diff){
            double mid=(low+high)/(2.0);
            int count=countGasStation(stations, mid, k);
            if(count>k) low=mid;
            else high=mid;
        }
        return high;
        
            
    //   int n=stations.size();
    // vector<int> placed(n-1,0);
    // priority_queue<pair<long double,int>> pq;
    // for(int i=0; i<n-1; i++){
    //     pq.push({stations[i+1]-stations[i],i});
    // }
    // for(int gas=1; gas<=k; gas++){
    //     auto tp=pq.top(); pq.pop();
    //     int secInd=tp.second;
    //     placed[secInd]++;
    //     long double iniDiff=(stations[secInd+1]-stations[secInd]);
    //     long double newSecLen= iniDiff/(long double)(placed[secInd]+1);
    //     pq.push({newSecLen, secInd});
    // }
    // return pq.top().first;
    
    
    
    // int n=stations.size();
    // vector<int> placed(n-1,0);
    // for(int gas=1 ; gas<=k ; gas++){
    //     long double maxSection=-1; int maxIndex=-1;
    //     for(int i=0; i<n-1; i++){
    //         long double inidiff=(stations[i+1]-stations[i]);
    //         long double sectionLength=inidiff/(long double)(placed[i]+1);
    //         if(maxSection<sectionLength){
    //             maxSection=sectionLength;
    //             maxIndex=i;
    //         }
    //     }
    //     placed[maxIndex]++;
    // }
    // long double ans=-1;
    // for(int i=0; i<n-1; i++){
    //     long double inidiff=(stations[i+1]-stations[i]);
    //     long double sectionLength=inidiff/(long double)(placed[i]+1);
    //     ans=max(ans,sectionLength);
    // }
    // return ans;
    }
};
