class Solution {
public:
    int totalFruit(vector<int>& f) {
        
        int i=0,j=0,ans=0;
        map<int,int> mp;
        while(j<f.size())
        {
            mp[f[j]]++;
            while(mp.size()>2){
                if(--mp[f[i]]==0)mp.erase(f[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};