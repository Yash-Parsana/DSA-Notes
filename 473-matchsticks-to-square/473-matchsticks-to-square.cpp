class Solution {
public:
    
    bool solve(vector<int>&m,int &side,int &n,int i,vector<int>&parts)
    {
        if(i>=n)
        {
            return 1;
        }
        bool ans=0;
        for(int z=0;z<4;z++)
        {
            if(parts[z]+m[i]<=side)
            {
                parts[z]+=m[i];
                ans=ans||solve(m,side,n,i+1,parts);
                parts[z]-=m[i];
            }
            if(ans)return 1;
        }
        return 0;
    }
    
    
    bool makesquare(vector<int>& m) {
        
        
        int n=m.size();
        int side=0;
        for(int i:m)side+=i;
        
        if(side%4)return 0;
        side/=4;
            
        vector<int> parts(4,0);
        sort(m.begin(),m.end(),greater<int>());
        return solve(m,side,n,0,parts);
        
    }
};