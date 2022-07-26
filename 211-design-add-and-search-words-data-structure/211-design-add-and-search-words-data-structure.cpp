class TrieNode
{
    public:
    TrieNode*links[26];
    bool f=0;
    
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
    void setEnd()
    {
        f=1;
    }
    bool isEnd()
    {
        return f;
    }
};


bool searchW(string &s,int i,TrieNode* curr)
{
    if(i>=s.size())
    {
        return curr->isEnd();
    }
    
    if(s[i]!='.')
    {
        if(curr->containLink(s[i]))
        {
            curr=curr->get(s[i]);
            return searchW(s,i+1,curr);  
        }
        else return 0;
    }
    bool ans=0;
    for(char c='a';c<='z';c++)
    {
        if(curr->containLink(c))
        {
            ans|=searchW(s,i+1,curr->get(c));
        }
        if(ans)return 1;
    }
    return 0;
}

class WordDictionary {
public:
    TrieNode*root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string s) {
        TrieNode*temp=root;
        for(char c:s)
        {
            if(!temp->containLink(c))
            {
                temp->put(c);
            }
            temp=temp->get(c);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        return searchW(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */