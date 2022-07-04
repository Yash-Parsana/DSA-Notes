class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        int ans=0;
        
        vector<int> cl(n,1),cr(n,1);
        
        for(int z=1;z<n;z++)
        {
            if(r[z]>r[z-1])cl[z]=cl[z-1]+1;
        }
        
        for(int z=n-2;z>=0;z--)
        {
            if(r[z]>r[z+1])cr[z]=cr[z+1]+1;
        }
        
        for(int i=0;i<n;i++)
        {
            ans+=max(cl[i],cr[i]);
        }
        return ans;
    }
};