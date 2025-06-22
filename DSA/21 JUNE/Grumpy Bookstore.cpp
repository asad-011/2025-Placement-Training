class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int initialcustomer=0;
        int currentextracustomer=0;
        int extracustomer=0;
        for(int i=0; i<n ;i++){
            if(grumpy[i]==0)  initialcustomer+=customers[i];
            else if(i<minutes) currentextracustomer+=customers[i];
        }
        extracustomer=currentextracustomer;
        int r=minutes;
        int l=0;
        while(r<n){
            currentextracustomer+=customers[r]*grumpy[r];
            currentextracustomer-=customers[l]*grumpy[l];
            l++;r++;
            extracustomer=max(extracustomer,currentextracustomer);
        }
        return initialcustomer+extracustomer;
    }
};
