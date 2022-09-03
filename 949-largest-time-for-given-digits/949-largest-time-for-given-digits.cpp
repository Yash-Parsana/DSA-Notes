class Solution {
public:
    
    void solve(int i,string temp,string &ans,vector<int> &v)
    {
        if(i==5)
        {
            if(ans=="")ans=temp;
            else if(stoi(temp)>stoi(ans))
                ans=temp;
            return;
        }
        if(i==1)
        {
            for(char j='2';j>='0';j--)
            {
                if(v[j-'0'])
                {
                    v[j-'0']--;
                    solve(i+1,temp+j,ans,v);
                    v[j-'0']++;
                }
            }
        }
        else if(i==2)
        {
            char c='9';
            if(temp=="2")
            {
                c='3';
            }
            for(c;c>='0';c--)
            {
                if(v[c-'0'])
                {
                    v[c-'0']--;
                    solve(i+1,temp+c,ans,v);                    
                    v[c-'0']++;
                }
            }
        }
        else
        {
            char c='9';
            if(i==3)
                c='5';
            for(c;c>='0';c--)
            {
                if(v[c-'0'])
                {
                    
                        v[c-'0']--;
                        solve(i+1,temp+c,ans,v);
                        v[c-'0']++;
                    
                }
            }
        }
        
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        string ans="";
        vector<int>v(10,0);
        for(int i:arr)
            v[i]++;
        solve(1,"",ans,v);
        
        if(ans.size()<4)return "";
        ans=ans.substr(0,2)+":"+ans.substr(2);
        
        return ans;
    }
};