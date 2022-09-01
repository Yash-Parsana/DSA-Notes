class Solution {
public:
    int findRadius(vector<int>& hs, vector<int>& hr) {
        
        sort(hs.begin(),hs.end());
        sort(hr.begin(),hr.end());
        
        int i=0,j=0;
        vector<int> store(hs.size(),INT_MAX);
        while(i<hs.size()&&j<hr.size())
        {
            if(hs[i]<=hr[j])
            {
                store[i]=hr[j]-hs[i];
                i++;
            }
            else j++;
        }
        i=hs.size()-1,j=hr.size()-1;
        
        while(i>=0&&j>=0)
        {
            if(hs[i]>=hr[j])
            {
                store[i]=min(store[i],hs[i]-hr[j]);
                i--;
            }
            else j--;
        }
        return *max_element(store.begin(),store.end());
    }
};