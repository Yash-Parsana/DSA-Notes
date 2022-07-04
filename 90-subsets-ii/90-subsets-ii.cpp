class Solution {
public:
    
   
    void solve(vector<int> &v,int i,int &n,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(i>=n)return;
        
        for(int z=i;z<n;z++)
        {
            if(z>i&&v[z]==v[z-1])continue;
            else{
                temp.push_back(v[z]);
                ans.push_back(temp);
                solve(v,z+1,n,ans,temp);
                temp.pop_back();
            }
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        ans.push_back({});
        vector<int> temp;
        solve(nums,0,n,ans,temp);
        
        return ans;
        
    }
};