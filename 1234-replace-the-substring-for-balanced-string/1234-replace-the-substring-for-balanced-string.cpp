class Solution {
public:
    int balancedString(string s) {
        
        unordered_map<char,int>mp;
        
        int i=0,j=0,ans=INT_MAX,k=s.size()/4;
        
        for(char c:s)
            mp[c]++;
        
        while(j<s.size())
        {
            
            mp[s[j]]--;
            while(i<s.size()&&mp['Q']<=k&&mp['W']<=k&&mp['E']<=k&&mp['R']<=k)
            {
                ans=min(ans,j-i+1);                
                mp[s[i]]++;
                i++;
            }
            j++;
        }
        return ans;
    }
};