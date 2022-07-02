class Solution {
public:
    int solve(string s,int start,int end,int k){
        if(end - start < 0) return 0;
        map<int,int> mp;
        
        for(int i=start;i<end;i++)
            mp[s[i]-'a']++;
        
        for(int i=start;i<end;i++){
            if(mp[s[i]-'a'] < k){
                int j=i;
                while(j<end and mp[s[j]-'a']<k){
                    j++;
                }
                
                return max(solve(s,start,i,k),solve(s,j,end,k));
            }
        }
    return end-start;
    }
    int longestSubstring(string s, int k) {
        int n=s.size();
        return solve(s,0,n,k);
    }
};