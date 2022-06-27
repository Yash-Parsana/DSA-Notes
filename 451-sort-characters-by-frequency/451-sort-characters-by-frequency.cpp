class Solution {
public:
    string frequencySort(string s) {
        
        map<char,int> frequencyMap;
        
        for(int i=0;i<s.size();i++)
        {
            frequencyMap[s[i]]++;
        }
        
        vector<pair<char,int>> vec;
        
        for(auto i=frequencyMap.begin();i!=frequencyMap.end();i++)
        {
            pair<char,int> pr{i->first,i->second};
            vec.push_back(pr);
        }
        
        sort(vec.begin(),vec.end(),[&](const pair<char,int> &a,const pair<char,int> &b)
             {
                 return b.second<a.second;
             });
        
        string res="";
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec[i].second;j++)
            {
                res.push_back(vec[i].first);
            }
        }
        return res;
    }
};