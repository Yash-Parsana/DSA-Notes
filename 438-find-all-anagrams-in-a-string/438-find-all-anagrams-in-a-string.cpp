class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
        
        int n = s.size();
        int len = p.size();
        vector<int> ans;
        if(n == 0 || len > n)  return ans;
        int i=0, j=0;
        vector<int> mp(26, 0);
        vector<int> temp(26, 0);
        while(j < len) {
            mp[p[j]-'a']++;
            temp[s[j]-'a']++;
            j++;
        }
        j--;
        while(j<n) {
            if(mp == temp) {
                ans.push_back(i);
            }
            j++;
            if(j != n) {
                temp[s[j]-'a']++;
            }
            temp[s[i]-'a']--;
            i++;
        }
        return ans;
    }
};