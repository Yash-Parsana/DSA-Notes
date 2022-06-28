class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> v(26,0);
        
        for(char c:s)
        {
            v[c-'a']++;
        }
        
        sort(v.begin(),v.end());
        int ans=0;
        for(int z=v.size()-1;z>0;z--)
        {
            if(v[z-1]==0)break;
            
            int temp=v[z-1];
            if(v[z-1]>=v[z])v[z-1]=max(0,v[z]-1),ans+=temp-v[z-1];
            
            
        }
        
        return ans;
    }
};