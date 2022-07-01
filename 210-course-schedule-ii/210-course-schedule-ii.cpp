class Solution {
public:
 vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int>adj[num];
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>indegree(num,0);
        for(int i=0;i<num;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        
        for(int i=0;i<num;i++){
            if(indegree[i]==0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return ans;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0;i<adj[u].size();i++){
                indegree[adj[u][i]]--;
                if(indegree[adj[u][i]]==0){
                    q.push(adj[u][i]);
                    ans.push_back(adj[u][i]);
                }
            }
        }
        if(ans.size()!=num) return {};
        return ans;
    }
};