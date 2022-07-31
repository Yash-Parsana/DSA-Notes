class Solution {
public:
    
    int dfs(vector<int>&v,int from,int temp,int curr,vector<pair<int,int>>&dist)
    {
        if(curr==-1)return -1;
        
        int f=dist[curr].first;
        int d=dist[curr].second;
        
        if(d==-1)
        {
            dist[curr]={from,temp};
            return dfs(v,from,temp+1,v[curr],dist);
        }
        if(from==f)return temp-d;
        
        return -1;
        
    }
    
    int longestCycle(vector<int>& v) {
        
        int ans=-1,n=v.size();
        vector<pair<int,int>>dist(n,{-1,-1});
        
        for(int z=0;z<n;z++)
        {
            ans=max(ans,dfs(v,z,0,z,dist));
        }
        return ans;
    }
};