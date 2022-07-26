class TrieNode{
    public:
    TrieNode*links[26];
    // bool f=0;
    
    bool containLink(char c)
    {
        return links[c-'a']!=NULL;
    }
    void put(char c)
    {
        links[c-'a']=new TrieNode();
    }
    TrieNode*get(char c)
    {
        return links[c-'a'];
    }
    // void setEnd()
    // {
    //     f=1;
    // }
    // bool isEnd()
    // {
    //     return f;
    // }
};

void allWords(TrieNode* curr,int i,int j,vector<vector<char>>&v,vector<vector<bool>>&vis,int &len)
{
    // cout<<v[i][j]<<" -> ";
    if(vis[i][j]||len<0)return;
    
    vis[i][j]=1;
    len--;
    if(!curr->containLink(v[i][j]))
    {
        curr->put(v[i][j]);
    }
    curr=curr->get(v[i][j]);
    if(i+1<v.size())
    {
        allWords(curr,i+1,j,v,vis,len);
    }
    if(j+1<v[0].size())
    {
        allWords(curr,i,j+1,v,vis,len); 
    }
    if(i-1>=0)
    {
        allWords(curr,i-1,j,v,vis,len); 
    }
    if(j-1>=0)
    {
        allWords(curr,i,j-1,v,vis,len);     
    }
    vis[i][j]=0;
    len++;
}
bool isPresent(string &s,TrieNode* &root)
{
    TrieNode*temp=root;
    for(char c:s)
    {
        if(!temp->containLink(c))
        {
            return 0;
        }
        temp=temp->get(c);
    }
    return 1;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        int n=b.size(),m=b[0].size();
        TrieNode*root=new TrieNode();
        vector<vector<bool>>vis(n,vector<bool>(m,0));

        map<char,bool>mp;
        int len=-1;
        for(string s:words)
        {
            mp[s[0]]=1;
            len=max(len,(int)s.size());
        }
        
        for(int z=0;z<n;z++)
        {
            for(int y=0;y<m;y++)
            {
                if(mp[b[z][y]])
                {
                    // cout<<b[z][y]<<endl;
                    allWords(root,z,y,b,vis,len);                     
                }
            }
        }
        vector<string>ans;
        
        for(string s:words)
        {
            if(isPresent(s,root))
            {
                ans.push_back(s);
            }
        }
        return ans;
    }
};