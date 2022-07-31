class Solution {
public:
    
    void dfs(vector<int>&v,int curr,vector<int>&dist,int temp)
    {
        if(curr!=-1&&dist[curr]==-1)
        {
            dist[curr]=temp;
            dfs(v,v[curr],dist,temp+1);
        }
    }
    
    int closestMeetingNode(vector<int>& v, int n1, int n2) {
        
        int n=v.size();
        vector<int>dist1(n,-1),dist2(n,-1);
        
        dfs(v,n1,dist1,0);
        dfs(v,n2,dist2,0);
    
        int dist=INT_MAX,ans=-1;
        for(int i=0;i<n;i++)
        {
            if(min(dist1[i],dist2[i])>=0&&max(dist1[i],dist2[i])<dist)
            {
                dist=max(dist1[i],dist2[i]);
                ans=i;
            }
        }
        return ans;
    }
};