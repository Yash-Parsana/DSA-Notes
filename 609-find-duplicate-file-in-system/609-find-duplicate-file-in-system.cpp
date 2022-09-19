class Solution {
public:
    
    string betweenTwochar(string s,char l,char r)
    {
        int i=s.find(l),j=s.find(r);
        return s.substr(i,j-i);
    }
    
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
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n=paths.size();
        vector<vector<string>> v;
        unordered_map<string,vector<pair<int,int>>> mp;
        for(string s:paths)
        {
            // cout<<s<<endl;
            v.push_back(splitBy(s,' '));
        }
        vector<vector<string>> ans;
        
        // cout<<v.size()<<endl;
        for(int i=0;i<n;i++)
        {
            // cout<<v[i][0]<<" -> ";
            for(int j=1;j<v[i].size();j++)
            {
                // cout<<v[i][j]<<" ";
                mp[betweenTwochar(v[i][j],'(',')')].push_back({i,j});
            }
            // cout<<endl;
        }
        for(auto i:mp)
        {
            vector<string> temp;
            // cout<<i.first<<" -> ";
            if(i.second.size()<2)continue;
            for(auto j:i.second)
            {
                // cout<<"{"<<j.first<<" "<<j.second<<"} ";
                string str=v[j.first][j.second];
                int k=str.find('(');
                str=str.substr(0,k);
                temp.push_back(v[j.first][0]+"/"+str);
            }
            // cout<<endl;
            ans.push_back(temp);
        }
        
        return ans;
        
        
    }
};