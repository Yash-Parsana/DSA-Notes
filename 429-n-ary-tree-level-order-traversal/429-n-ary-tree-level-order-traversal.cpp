/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        
        while(!q.empty())
        {
            int n=q.size();
            vector<int> row;
            while(n--)
            {
                Node* curr=q.front();
                q.pop();
                row.push_back(curr->val);
                int nn=(curr->children).size();
                int i=0;
                while(i<nn)
                {
                    q.push(curr->children[i]);
                    i++;
                }
                
            }
            ans.push_back(row);
        }
        return ans;
    }
};