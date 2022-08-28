class Solution {
public:
    bool cycle(vector<vector<int>> &graph,int curr,vector<int> &vis)
    {
        vis[curr]=1;
        for(int i:graph[curr])
        {
            if(vis[i]==1)return 1;
            else if(vis[i]==0&&cycle(graph,i,vis))return 1;
        }
        vis[curr]=2;
        return 0;
    }
    
    void usingDFS(int curr,vector<bool>&vis,vector<int>&ans,vector<vector<int>>&graph)
    {
        vis[curr]=1;
        
        for(int i:graph[curr])
        {
            if(!vis[i])
                usingDFS(i,vis,ans,graph);
        }
        ans.push_back(curr);
    }
    
    void kahnAlgoTopLogical(int k,vector<vector<int>>&graph,vector<int>&ans)
    {
        vector<bool>vis(k,0);
        for(int i=0;i<k;i++)
        {
            if(!vis[i])
                usingDFS(i,vis,ans,graph);
        }
        reverse(ans.begin(),ans.end());
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rw, vector<vector<int>>& cl) {
        
        vector<vector<int>> graph1(k),graph2(k);
        
        for(auto i:rw)
        {
            graph1[i[0]-1].push_back(i[1]-1);
        }
        for(auto i:cl)
        {
            graph2[i[0]-1].push_back(i[1]-1);
        }
        
        vector<int>vis(k,0);
        for(int i=0;i<k;i++)
        {
            if(!vis[i]&&cycle(graph1,i,vis)) return vector<vector<int>>();
        }
   
        vis=vector<int>(k,0);
        for(int i=0;i<k;i++)
        {
            if(!vis[i]&&cycle(graph2,i,vis))return vector<vector<int>>();
        }
   
        vector<int>ans1,ans2;
        vector<vector<int>>ans(k,vector<int>(k,0));
        
        kahnAlgoTopLogical(k,graph1,ans1);
        kahnAlgoTopLogical(k,graph2,ans2);
        
        map<int,int>mp;
        for(int i=0;i<k;i++)
        {
            mp[ans1[i]+1]=i;
        }
        for(int i=0;i<k;i++)
        {
            ans[mp[ans2[i]+1]][i]=ans2[i]+1;
        }
        return ans;
        
    }
};