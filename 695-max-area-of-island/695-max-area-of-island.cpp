class Solution {
public:
    
    int countArea(vector<vector<int>>&v,int i,int j)
    {
        int ans=0;
        int n=v.size(),m=v[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        
        while(!q.empty())
        {
            ans++;
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            v[i][j]=-1;
            if(i-1>=0&&v[i-1][j]==1)
            {
                q.push({i-1,j});
                v[i-1][j]=-1;
            }
            if(i+1<n&&v[i+1][j]==1)
            {
                q.push({i+1,j});
                v[i+1][j]=-1;
            }
            if(j-1>=0&&v[i][j-1]==1)
            {
                q.push({i,j-1});
                v[i][j-1]=-1;
            }
            if(j+1<m&&v[i][j+1]==1)
            {
                q.push({i,j+1});
                v[i][j+1]=-1;
            }
            
        }
        
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& v) {
        
        int ans=0;
        int n=v.size(),m=v[0].size();
        for(int z=0;z<n;z++)
        {
            for(int y=0;y<m;y++)
            {
                if(v[z][y]==1)
                {
                    ans=max(ans,countArea(v,z,y));
                }
            }
        }
        return ans;
        
        
    }
};