class Solution {
public:
    vector<int> findOriginalArray(vector<int>& v) {
        map<int,int> mp;
        
        for(int i:v)
        {
            mp[i]++;
        }
        vector<int> ans;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            if(i->second!=0)
            {
                if(mp[2LL*(i->first)]>=i->second||i->first==0&&(i->second)%2==0)
                {
                    int nn=0;
                    if(i->first==0)
                    {
                        if(i->second%2==0)
                            nn=i->second/2;
                        else return {};
                        
                    }
                    else{
                        mp[2LL*(i->first)]-=i->second;
                        nn=i->second;             
                    }
           
                
                    while(nn--)
                    {
                        ans.push_back(i->first);
                    }
                }
                else return {};
            }
        }
        return ans;
    }
};