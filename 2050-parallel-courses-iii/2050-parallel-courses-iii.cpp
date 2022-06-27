class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& t)     {
        vector<vector<int>> adj(n+1);
        vector<int> deg(n+1);
        queue<int> q;
        vector<int> time(n+1,0);
        for(int z=0;z<r.size();z++)
        {
            adj[r[z][0]].push_back(r[z][1]);
            deg[r[z][1]]++;
        }
        
        for(int z=1;z<=n;z++)
        {
            if(deg[z]==0)
            {
                q.push(z);
                time[z]=t[z-1];
            }
        }
        
        while(!q.empty())
        {
            int curr=q.front();q.pop();
            
            for(int i:adj[curr])
            {
                time[i]=max(time[i],time[curr]+t[i-1]);
                if(--deg[i]==0)
                {
                    q.push(i);
                }
            }
            
        }
        int ans=0;
        for(int z=1;z<=n;z++)
        {
            ans=max(ans,time[z]);
        }
        return ans;
    }
};