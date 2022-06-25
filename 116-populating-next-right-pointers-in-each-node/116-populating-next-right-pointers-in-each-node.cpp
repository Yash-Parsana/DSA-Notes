/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root)return NULL;
        
        queue<Node*> q;
        
        q.push(root);
        
        
        while(!q.empty())
        {
            Node* pre=NULL;
            int n=q.size();
            while(n--)
            {
                if(pre==NULL)
                {
                    pre=q.front();
                    q.pop();
                    if(pre->left)q.push(pre->left);
                    if(pre->right)q.push(pre->right);
                }
                else
                {
                    Node* curr=q.front();
                    q.pop();
                    
                    pre->next=curr;
                    if(curr->left)q.push(curr->left);
                    if(curr->right)q.push(curr->right);
                    pre=curr;
                }
            }
        }
        
        return root;
        
    }
};