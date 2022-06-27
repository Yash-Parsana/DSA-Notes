// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool DFS(int parent,vector<int> adj[],int curr,vector<bool> &vis)
    {
        if(vis[curr])return 1;
        
        vis[curr] = 1;
        bool ans=0;
        for(int i:adj[curr])
        {
            if(i!=parent)
            {
                ans|=DFS(curr,adj,i,vis);
            }
            if(ans)break;
        }
        return ans;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        vector<bool> vis(n);
        
        
        for(int z=0;z<n;z++)
        {
            if(!vis[z]&&DFS(-1,adj,z,vis)) return 1;
        }
        
        return 0;
    }
};



// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends