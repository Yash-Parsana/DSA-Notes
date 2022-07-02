class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        
        int n=v.size(),m=v[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int z=1;z<n;z++)
        {
            v[z][0]+=v[z-1][0];
        }
        for(int z=1;z<m;z++)
        {
            v[0][z]+=v[0][z-1];
        }
        
        for(int z=1;z<n;z++)
        {
            for(int y=1;y<m;y++)
            {
                v[z][y]=min(v[z-1][y],v[z][y-1])+v[z][y];
            }
        }
        return v[n-1][m-1];
    }
};