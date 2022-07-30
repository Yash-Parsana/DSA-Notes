class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int>fre;
        
        for(string s:words2)
        {
            map<char,int>temp;
            for(char c:s)
            {
                temp[c]++;
            }
            for(auto i:temp)
            {
                if(fre.find(i.first)!=fre.end())
                    fre[i.first]=max(i.second,fre[i.first]);
                else fre[i.first]=i.second;
            }
        }
        
//         for(auto i:fre)
//         {
//             cout<<i.first<<" -> "<<i.second<<endl;
//         }
        
        vector<string> ans;

        for(string s:words1)
        {
            map<char,int>temp;
            for(char c:s)
            {
                temp[c]++;
            }
            bool b=1;
            for(auto i:fre)
            {
                // cout<<i.first<<" -> "<<i.second<<" <-> "<<temp[i.first]<<"  "<<s<<endl;
                if(temp[i.first]<i.second)
                {b=0;break;}
            }
            // cout<<endl<<endl;
            if(b)ans.push_back(s);
        }
        return ans;
    }
};