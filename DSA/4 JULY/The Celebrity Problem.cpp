class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int size=mat.size();
        // cout<<size;
        vector<int> celebrity(size,0);
        for(int i=0 ; i<size ; i++){
            for(int j=0; j<size ; j++){
                if(i==j) continue;
                else if(mat[i][j]==0){
                    celebrity[i]++;
                }
            }
        }
        for(int i=0 ;i<size ; i++){
            if(celebrity[i]==size-1){
                int j=0;
                while(j<size){
                    if(mat[j][i]==0) return -1;
                    j++;
                }
                return i;
            }
        }
        return -1;
    }
};
