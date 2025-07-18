class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0, lmax=0, rmax=0, r=n-1,total=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(lmax>height[l]){
                    total+=lmax-height[l];
                }
                else{
                    lmax=height[l];
                }
                l++;
            }
            else{
                if(rmax>height[r]){
                    total+=rmax-height[r];
                }
                else{
                    rmax=height[r];
                }
                r--;
            }
        }
        return total;





        //Brute
        // int n=height.size();
        // // vector<int> prefix(n);
        // // prefix[0]=height[0];
        // // for(int i=1; i<n ;i++){
        // //     prefix[i]=max(prefix[i-1],height[i]);
        // // }
        // vector<int> suffix(n);
        // suffix[n-1]=height[n-1];
        // for(int i=n-2; i>=0 ; i--){
        //     suffix[i]=max(suffix[i+1],height[i]);
        // }
        // int total=0;
        // int leftmax=height[0];
        // for(int i=0; i<n ; i++){
        //     leftmax=max(leftmax,height[i]);
        //     if(height[i]<leftmax && height[i]<suffix[i]){
        //         total+=min(leftmax,suffix[i])-height[i];
        //     }
        //     // if(height[i]<prefix[i] && height[i]<suffix[i]){
        //     //     total+=min(prefix[i],suffix[i])-height[i];
        //     // }
        // }
        
        // return total;
    }
};
