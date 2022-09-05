class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mtx, int t) {
        
        int n=mtx.size(),m=mtx[0].size();
        
        int i=0,j=m-1;
        
        while(i<n&&j>=0)
        {
            if(mtx[i][j]==t)return 1;
            else if(mtx[i][j]>t)j--;
            else i++;
        }
        return 0;
    }
};