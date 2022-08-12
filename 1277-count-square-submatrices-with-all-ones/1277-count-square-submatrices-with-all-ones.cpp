class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
         
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans=0;

        for(int z=0;z<m;z++)
        {
            dp[0][z]=matrix[0][z];
        }
        for(int z=0;z<n;z++)
        {
            dp[z][0]=matrix[z][0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==1)
                    dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
            }
        }
        
        for(auto i:dp)
        {
            for(int j:i)
                ans+=j;        
        }
        
        return ans;
    }
    // 1 0 1
    // 1 1 0
    // 1 2 0
    
    
};