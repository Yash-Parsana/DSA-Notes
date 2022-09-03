class Solution {
public:
    
    
    void solve(int &n,int &k,int pre,string s,int len,vector<int> &ans)
    {
        if(len==n)
        {
            ans.push_back(stoi(s));
            return;
        }
        
        if(pre+k<=9)
        {
            solve(n,k,pre+k,s+to_string(pre+k),len+1,ans);
        }
        if(pre-k>=0&&k!=0)
        {
            solve(n,k,pre-k,s+to_string(pre-k),len+1,ans);
        }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int>ans;
        
        for(int z=1;z<=9;z++)
        {
            solve(n,k,z,to_string(z),1,ans);
        }
        
        return ans;
    }
};