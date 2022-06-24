/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* solve(ListNode* head,ListNode *tail)
    {
        
        if(!head||!tail)return NULL;
        if(head==tail)
        {
            TreeNode* n=new TreeNode(head->val);
            return n;
        }
        ListNode* slow=head,*pre=NULL,*fast=head;
        while(fast!=tail&&fast->next!=tail)
        {
            fast=fast->next->next;
            pre=slow;
            slow=slow->next;
        }
        
        TreeNode* n=new TreeNode(slow->val);
        
        n->left=solve(head,pre);
        n->right=solve(slow->next,tail);
    
        return n;
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(!head)return NULL;
        ListNode* tail=head;
        while(tail->next)
        {
            tail=tail->next;
        }
        
        return solve(head,tail);
        
    }
};