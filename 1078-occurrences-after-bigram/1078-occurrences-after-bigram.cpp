class Solution {
public:
    vector<string> splitBy(string s,char c)
    {
        stringstream str(s);
        string segment;
        vector<string> v;

        while(getline(str, segment, c))
        {
            v.push_back(segment);
        }
        return v;
    }
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> str=splitBy(text,' ');
        
        vector<string> ans;
        
        for(int i=0;i<str.size();i++)
        {
            if(i+2<str.size()&&str[i]==first&&str[i+1]==second)
            {
                ans.push_back(str[i+2]);
            }
        }
        return ans;
    } 
};