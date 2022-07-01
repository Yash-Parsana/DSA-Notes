// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        vector<bool>vis(n,0);
        
        set<pair<int,int>> st;
        st.insert({0,s});
        vis[s]=1;
        vector<int>ans(n,INT_MAX);
        ans[s]=0;
        for(int z=0;z<n-1;z++)
        {
            
            int curr=(*st.begin()).second;
            int w=(*st.begin()).first;
            vis[curr]=1;
            st.erase({w,curr});
            for(auto i:adj[curr])
            {
                if(!vis[i[0]]&&ans[i[0]]>w+i[1])
                {
                    st.erase({ans[i[0]],i[0]});
                    ans[i[0]]=w+i[1];
                    st.insert({w+i[1],i[0]});
                }
            }
            
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends