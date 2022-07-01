// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        int ans=0;
        
        set<pair<int,int>> s;
        s.insert({0,0});
        
        
        vector<bool> vis(n,0);
        vector<int> mst(n,INT_MAX);
        mst[0]=0;
        for(int z=0;z<n-1;z++)
        {
            int w=(*s.begin()).first;
            int curr=(*s.begin()).second;
            s.erase({w,curr});
            vis[curr]=1;
            for(auto i:adj[curr])
            {
                if(!vis[i[0]]&&mst[i[0]]>i[1])
                {
                    s.erase({mst[i[0]],i[0]});
                    mst[i[0]]=i[1];
                    s.insert({i[1],i[0]});
                }
            }
        }
        for(int i:mst)
        {
            ans+=i;
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends