/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* dfs(Node* n,unordered_map<int,Node*> &m)
    {
        
        Node* nn=new Node(n->val);
        m[n->val]=nn;
        int sz=(n->neighbors).size();
        nn->neighbors=vector<Node*>(sz);

        for(int z=0;z<sz;z++)
        {
            if(n->neighbors[z]==n)continue;
            
            if(!m[n->neighbors[z]->val])
            {
                nn->neighbors[z]=dfs(n->neighbors[z],m);
            }
            else
            {
                nn->neighbors[z]=m[n->neighbors[z]->val];
            }
            
        }
        return nn;
        
    }
    
    
    Node* cloneGraph(Node* node) {
        
        if(node==NULL)return NULL;
        
        unordered_map<int,Node*> m;
        return dfs(node,m);
        
    }
};





