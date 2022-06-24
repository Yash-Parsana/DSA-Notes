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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root)return ans;
        
        stack<TreeNode*> s;
        s.push(root);
        
        bool b=0;
        while(!s.empty())
        {
            int n=s.size();
            vector<int> temp;
            stack<TreeNode*>st;
            while(n--)
            {
                TreeNode* curr=s.top();
                s.pop();
                temp.push_back(curr->val);
                if(b)
                {
                    if(curr->right)st.push(curr->right);
                    if(curr->left)st.push(curr->left);
                }
                else{
                    if(curr->left)st.push(curr->left);    
                    if(curr->right)st.push(curr->right);
                }
                
            }
            ans.push_back(temp);
            b=!b;
            swap(s,st);
        }
        
        return ans;
    }
};