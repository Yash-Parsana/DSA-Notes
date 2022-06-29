// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(int curr,bool graph[101][101],vector<int> &c,int n,int color)
{
    for(int z=0;z<n;z++)
    {
        if(z!=curr&&graph[z][curr]&&c[z]==color)return 0;
    }
    return 1;
}

bool solve(int curr,vector<int> &c,int n,int m,bool graph[101][101])
{
    if(curr==n)return 1;
    
    for(int z=1;z<=m;z++)
    {
        if(isSafe(curr,graph,c,n,z))
        {
            c[curr]=z;
            if(solve(curr+1,c,n,m,graph))return 1;
            c[curr]=-1;
        }
    }
    return 0;
}


bool graphColoring(bool graph[101][101], int m, int n) {
    
    
    vector<int> color(n,-1);
    return solve(0,color,n,m,graph);
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends