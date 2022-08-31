class Solution {
public:
    
    void DFS(vector<vector<bool>> &vis,int i,int j,vector<vector<int>>&v,int &n,int &m)
    {
        
        vis[i][j]=1;
        
        if(i-1>=0&&vis[i-1][j]==0&&v[i-1][j]>=v[i][j])
            DFS(vis,i-1,j,v,n,m);
        if(j-1>=0&&vis[i][j-1]==0&&v[i][j-1]>=v[i][j])
            DFS(vis,i,j-1,v,n,m);
        if(i+1<n&&vis[i+1][j]==0&&v[i+1][j]>=v[i][j])
            DFS(vis,i+1,j,v,n,m);
        if(j+1<m&&vis[i][j+1]==0&&v[i][j+1]>=v[i][j])
            DFS(vis,i,j+1,v,n,m);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        
        int n=v.size(),m=v[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,0)),atlantic(n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++)
        {
            DFS(pacific,i,0,v,n,m);
            DFS(atlantic,i,m-1,v,n,m);
        }
        for(int i=0;i<m;i++)
        {
            DFS(pacific,0,i,v,n,m);
            DFS(atlantic,n-1,i,v,n,m);
        }
        
        
        vector<vector<int>>ans;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j]&&atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};