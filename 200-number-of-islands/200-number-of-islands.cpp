class Solution {
public:
    int numIslands(vector<vector<char>>& v) {
        
        if(v.size()==0)return 0;
        
        int n=v.size(),m=v[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int ans=0;
        for(int z=0;z<n;z++)
        {
            for(int y=0;y<m;y++)
            {
                if(v[z][y]=='1'&&!vis[z][y])
                {

                    ans++;
                    queue<pair<int,int>>q;
                    q.push({z,y});
                    vis[z][y]=1;
                    while(!q.empty())
                    {
                        
                        int i=q.front().first,j=q.front().second;
                        q.pop();
                        
                        if(i-1>=0&&!vis[i-1][j]&&v[i-1][j]=='1')
                            vis[i-1][j]=1,q.push({i-1,j});
                        if(j-1>=0&&!vis[i][j-1]&&v[i][j-1]=='1')
                            vis[i][j-1]=1,q.push({i,j-1});
                        if(i+1<n&&!vis[i+1][j]&&v[i+1][j]=='1')
                            vis[i+1][j]=1,q.push({i+1,j});
                        if(j+1<m&&!vis[i][j+1]&&(v[i][j+1]=='1'))
                            vis[i][j+1]=1,q.push({i,j+1});
                    }
                    
                }
            }
        }
        
        
        return ans;
    }
};