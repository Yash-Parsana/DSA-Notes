class Solution {
public:
    
    void solve(vector<int> &v,int i,int n,vector<int>temp,vector<vector<int>> &ans)
    {
        if(i>=n)
        {
            ans.push_back(temp);
            return ;
        }
        
        solve(v,i+1,n,temp,ans);
        temp.push_back(v[i]);
        solve(v,i+1,n,temp,ans);
        
    }
    
    vector<vector<int>> subsets(vector<int>& v) {
        
        vector<vector<int>> ans;
        
        solve(v,0,v.size(),{},ans);
        return ans;
        
    }
};