/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        
        vector<vector<int>> ans;

        if(root==NULL) return ans;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            vector<int> v;
            while(!q.empty()&&q.front()!=NULL)
            {
                TreeNode* temp=q.front();q.pop();
                v.push_back(temp->val);
                if(temp->left!=NULL)q.push(temp->left);                
                if(temp->right!=NULL)q.push(temp->right);
            }
            if(q.front()==NULL)
            {
                ans.push_back(v);
                q.pop();
                if(!q.empty())q.push(NULL);
            }
        }
        return ans;
        
    }
};