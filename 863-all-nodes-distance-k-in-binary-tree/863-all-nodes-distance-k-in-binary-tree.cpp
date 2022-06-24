/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class store
{
    public:
    TreeNode* node;
    bool d; //0 left 1 right
    int dist;
    
    store(bool ddr,int dds,TreeNode* n)
    {
        node=n;
        d=ddr;
        dist=dds;
    }
    
};

class Solution {
public:
    
    int findnode(TreeNode* root,TreeNode* target,vector<store> &nodes,int &k)
    {
        if(!root)return -1;
        if(root==target)
        {
            nodes.push_back(store(0,0,root));
            return 1;
        }
        
        int left=findnode(root->left,target,nodes,k);
        
        
        
        if(left!=-1)
        {
            if(left<=k)
            {
                nodes.push_back(store(0,left,root));
            }
            return left+1;
        }
        
        int right=findnode(root->right,target,nodes,k);

        if(right!=-1)
        {
            if(right<=k)
            {
                nodes.push_back(store(1,right,root));
            }
            return right+1;
        }
        return -1;
    }
    
    void solve(TreeNode* root,int k,vector<int> &ans)
    {
        if(root==NULL)return;
        
        if(k==0)
        {
            ans.push_back(root->val);
            return;
        }
        
        solve(root->left,k-1,ans);
        solve(root->right,k-1,ans);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<store> nodes;
        vector<int>ans;
        findnode(root,target,nodes,k);
        
        for(store i:nodes)
        {
            // string s;
            // if(i.d) s="right";
            // else s="left";
            // cout<<i.node->val<<" "<<i.d<<" "<<i.dist<<endl;
            if(i.dist==0)
            {
                solve(i.node,k,ans);
            }
            else if(i.dist==k)
            {
                ans.push_back(i.node->val);
            }
            else
            {
                if(i.d)
                {
                    solve(i.node->left,k-i.dist-1,ans);
                }
                else{
                    solve(i.node->right,k-i.dist-1,ans);
                }
            }
        }
        return ans;
        
    }
};