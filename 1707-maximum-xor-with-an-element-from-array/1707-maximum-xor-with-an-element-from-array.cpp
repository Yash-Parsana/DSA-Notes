class TrieNode
{
    public:
    TrieNode*links[2];
    
    bool containLink(int bit)
    {
        return links[bit]!=NULL;
    }
    TrieNode*get(int bit)
    {
        return links[bit];
    }
    void put(int bit)
    {
        links[bit]=new TrieNode();
    }
};
class Trie{
    TrieNode*root;
    
    public:
    Trie()
    {
        root=new TrieNode();
    }
    
    void insert(int &n)
    {
        TrieNode*temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(!temp->containLink(bit))
            {
                temp->put(bit);
            }
            temp=temp->get(bit);
        }
    }
    
    int maxXor(int &n)
    {
        int ans=0;
        TrieNode*temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(bit)
            {
                if(temp->containLink(0))
                {
                    ans=ans|(1<<i);
                    temp=temp->get(0);
                }
                else{
                    temp=temp->get(1);
                }
            }
            else{
                if(temp->containLink(1))
                {
                    ans=ans|(1<<i);
                    temp=temp->get(1);
                }
                else temp=temp->get(0);
            }
        }
        return ans;
    }

};
class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        return v1[1]<v2[1];
    }
    vector<int> maximizeXor(vector<int>& v, vector<vector<int>>& q)     {
        
        
        for(int i=0;i<q.size();i++)
        {
            q[i].push_back(i);
        }
        sort(q.begin(),q.end(),cmp);

        sort(v.begin(),v.end());
        
        int j=0;
        
        Trie root;
        vector<int>ans(q.size());
        for(auto i:q)
        {
            while(j<v.size()&&v[j]<=i[1])
            {
                root.insert(v[j]);
                j++;
            }
            if(j==0)
            {
                ans[i[2]]=-1;                
            }
            else
                ans[i[2]]=root.maxXor(i[0]);
        }
        
        return ans;
    }
};