// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool iscycle(vector<int> adj[],int curr,vector<bool> &vis,vector<bool> &stack)
{
    
    vis[curr] = 1;
    stack[curr] = 1;
    for(int i:adj[curr])
    {
        if(stack[i])
            return 1;
        if(!vis[i]&&iscycle(adj,i,vis,stack))
            return 1;
    }
    stack[curr] = 0;
    return 0;
}

    bool isCyclic(int n, vector<int> adj[]) {
        
        vector<bool> vis(n,0),stack(n,0);
        
        for(int z=0;z<n;z++)
        {
            if(!vis[z]&&iscycle(adj,z,vis,stack))return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends