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
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        
        map<int,vector<int>> m;
    
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
    
        while(!q.empty())
        {
            int n=q.size();
            unordered_map<int,int> mp;
            while(n--)
            {
                TreeNode* curr=q.front().first;
                int l=q.front().second;
                q.pop();
                
                if(mp[l])
                {
                    int i=mp[l];
                    vector<int>tt;
                    while(i--)
                    {
                        if(m[l].back()>curr->val)
                        {
                            tt.push_back(m[l].back());m[l].pop_back();
                        }
                        else break;
                    }
                    m[l].push_back(curr->val);
                    while(!tt.empty())
                    {
                        m[l].push_back(tt.back());tt.pop_back();
                    }
                    mp[l]++;
                }
                else
                {
                    m[l].push_back(curr->val);
                    mp[l]++;
                }
                
                
                if(curr->left) q.push({curr->left,l-1});
                if(curr->right)q.push({curr->right,l+1});
                
            }
        }
    
        vector<vector<int>> ans;
    
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        

    
        return ans;
    }
};