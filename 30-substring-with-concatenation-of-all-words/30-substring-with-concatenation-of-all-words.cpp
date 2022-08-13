class Solution {
public:
    vector<int> findSubstring(string &s, vector<string>& words) {
        
        map<string,int> m;
        
        int sz=words[0].size(),tw=words.size();
        
        for(string str:words)
        {
            m[str]++;
        }
        vector<int>ans;
        // cout<<s<<" "<<s.size()<<" "<<sz*tw<<endl;
        for(int i=0;i<=(int)(s.size()-(sz*tw));i++)
        {
            int c=0,j=i;
            map<string,int> temp;
            while(c<tw)
            {
                string str="";
                
                if(j<s.size())
                    str=s.substr(j,sz);
                j+=sz;
                // cout<<i<<" "<<j<<" "<<str<<endl;
                if(m.find(str)!=m.end())
                {
                    temp[str]++;
                    if(m[str]<temp[str])break;
                    c++;
                }
                else break;
                if(c==tw)
                {
                    ans.push_back(i);
                }
            }
            // cout<<endl;
        }
        return ans;
    }
};