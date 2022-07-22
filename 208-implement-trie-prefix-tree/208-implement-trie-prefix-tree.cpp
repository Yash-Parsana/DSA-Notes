class TrieNode{
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
    TrieNode* get(char c)
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

class Trie {
public:
    TrieNode*root;
    
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*temp=root;
        
        for(char c:word)
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
        
        TrieNode* temp=root;
        for(char c:word)
        {
            if(!temp->containLink(c))
            {
                return 0;
            }
            temp=temp->get(c);
        }
        return temp->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode*temp=root;
        for(char c:prefix)
        {
            if(!temp->containLink(c))
                return 0;
            temp=temp->get(c);
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */