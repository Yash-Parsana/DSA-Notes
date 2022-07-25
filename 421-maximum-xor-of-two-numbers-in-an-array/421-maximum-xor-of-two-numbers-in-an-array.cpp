class TrieNode{
    public:
    TrieNode*links[2];
    
    bool containLink(int bit)
    {
        return links[bit]!=NULL;
    }
    void put(int bit)
    {
        links[bit]=new TrieNode();
    }
    TrieNode*get(int bit)
    {
        return links[bit];
    }
};
class Trie
{
    public:
    TrieNode* root;
    Trie()
    {
        root=new TrieNode();
    }
    void insert(int n)
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
    int maxXor(int n)
    {
        int tempAns=0;
        TrieNode*temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(bit)
            {
                if(temp->containLink(0))
                {
                    tempAns=tempAns|(1<<i);
                    temp=temp->get(0);
                }
                else
                {
                    // tempAns=tempAns^(1<<i);
                    temp=temp->get(1);
                }
            }
            else{
                if(temp->containLink(1))
                {
                    tempAns=tempAns|(1<<i);
                    temp=temp->get(1);
                }
                else{
                    temp=temp->get(0);
                }
            }
        }
        return tempAns;
    }
    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        Trie root;
        
        for(int i:nums)
        {
            root.insert(i);
        }
        int ans=-1;
        for(int i:nums)
        {
            ans=max(ans,root.maxXor(i));
        }
        return ans;
    }
};