class Solution {
public:
    
    void solve(vector<int>&v,int i,int j,int &ans)
    {
        // cout<<i<<" "<<j<<endl;
        if(i==j)
        {
            ans=v[i];
            return;
        }
        if(i>j)return;
        
        int mid=(i+j)/2;
        
        if(v[mid]>v[j])
        {
            solve(v,mid+1,j,ans);
        }
        else
            solve(v,i,mid,ans);
        
    }
    
    int findMin(vector<int>& nums) {
        
        int ans=INT_MAX;
        solve(nums,0,nums.size()-1,ans);
        return ans;
        
    }
};