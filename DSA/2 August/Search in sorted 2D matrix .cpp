class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int low=0; int high=n*m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/m, col=mid%m;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) low=mid+1;
            else high=mid-1;
        }
        return false;


        // int rows=matrix.size();
        // int cols=matrix[0].size();

        // int rowslow=0, rowshigh=rows-1;
        // int ans;
        // while(rowslow<=rowshigh){
        //     int mid=(rowslow+rowshigh)/2;
        //     if(matrix[mid][0]<=target){
        //         ans=mid;
        //         rowslow=mid+1;
        //     }
        //     else rowshigh=mid-1;
        // }
        // int collow=0, colHigh=cols-1;
        // while(collow<=colHigh){
        //     int mid=(collow+colHigh)/2;
        //     if(matrix[ans][mid]==target) return true;
        //     if(matrix[ans][mid]>target) colHigh=mid-1;
        //     else collow=mid+1;
        // }
        // return false;
        
        
        
        // int rows=matrix.size();
        // int cols=matrix[0].size();
        // for(int i=0; i<rows; i++){
        //     for(int j=0; j<cols; j++){
        //         if(matrix[i][j]==target) return true;
        //     }
        // }
        // return false;
    }
};
