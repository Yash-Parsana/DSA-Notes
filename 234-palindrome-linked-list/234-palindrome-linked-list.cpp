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
class Solution {
public:
    
    
    bool isPalindrome(ListNode* head) {
        
        if(!head||!head->next) return true;

        ListNode* fast=head,*slow=head;
        
        while(fast->next&&fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* pre=NULL,*curr=slow->next,*nxt;
        
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nxt;
        }
        slow->next = pre;

        
        slow=slow->next;
        
        while(slow!=NULL)
        {
            if(head->val!=slow->val) return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
        
    }
};