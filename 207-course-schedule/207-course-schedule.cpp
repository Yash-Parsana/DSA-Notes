class Solution {
public:
    
    bool DFS(int curr,vector<bool> &stack,vector<vector<int>>&adj,vector<bool> &vis)
    {
        vis[curr]=1;
        stack[curr]=1;
        bool b=1;
        for(int i:adj[curr])
        {
            
            if(stack[i])return 0;
            if(vis[i])continue;
            b=b&&DFS(i,stack,adj,vis);
            if(!b)break;
        }
        stack[curr]=0;
        return b;
    }
    
    bool canFinish(int n, vector<vector<int>>& c) {
        
        vector<vector<int>>adj(n);
        
        for(auto i:c)
        {
            adj[i[1]].push_back(i[0]);
        }
        
        vector<bool> vis(n,0),stack(n,0);
        for(int z=0;z<n;z++)
        {
            if(!vis[z]&&!DFS(z,stack,adj,vis))return 0;
        }
        return 1;
    } 
};