class Solution {
public:
    int cherryPickup(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        
        for(int z=0;z<m;z++)
        {
            for(int y=0;y<m;y++)
            {
                if(z==y)dp[z][y]=v[n-1][y];
                else dp[z][y]=v[n-1][z]+v[n-1][y];
            }
        }
        
        for(int z=n-2;z>=0;z--)
        {
            vector<vector<int>> temp(m,vector<int>(m,-1));

            for(int y=0;y<m;y++)
            {
                for(int w=0;w<m;w++)
                {
                    for(int i=-1;i<2;i++)
                    {
                        for(int j=-1;j<2;j++)
                        {
                            if(y+i<0||y+i>=m||w+j<0||w+j>=m)continue;
                            temp[y][w]=max(temp[y][w],dp[y+i][w+j]);
                        }
                    }
                    if(y==w)
                        temp[y][w]+=v[z][w];
                    else temp[y][w]+=v[z][w]+v[z][y];
                
                }
            }
            swap(dp,temp);

        }
        
        return dp[0][m-1];
    }
};