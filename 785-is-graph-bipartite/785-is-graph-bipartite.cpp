class Solution {
public:
    bool Bipartite(int curr,bool c,vector<vector<int>> &adj,vector<bool>&vis,vector<bool> &color)
    {
        vis[curr] = 1;
        color[curr] = c;

        for(int i:adj[curr])
        {
            if(vis[i]&&color[i]==c)
            {
                return 0;
            }
            if(!vis[i]&&!Bipartite(i, !c, adj, vis, color))
                return 0;
        }
        return 1;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        
        int n=adj.size();
        vector<bool> vis(n,0), color(n,0);

        
        for (int z = 0; z < n;z++)
        {
            if(!vis[z]&&!Bipartite(z,0,adj,vis,color))
                return 0;
        }
        return 1;
    }
};