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
    

    ListNode* reverse(ListNode* head,ListNode* tail)
    {
        ListNode* pre=NULL,*curr=head,*nxt=NULL;
        
        while(curr!=tail)
        {
            nxt=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nxt;
        }
        return pre;
    }
    
    ListNode* solve(ListNode* head,int l,int r)
    {
        ListNode*h=head,*t,*pre=NULL;
        
        int tt=1;
        while(tt<l)
        {
            pre=h;
            h=h->next;
            tt++;
        }
        t=h;
        while(tt<r)
        {
            t=t->next;
            tt++;
        }
        if(t)
            t=t->next;
        ListNode* nh=reverse(h,t);
        if(pre)
            pre->next=nh;
        else
            head=nh;
        h->next=t;
        return head;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left==right)return head;
        if(!(head->next->next))
        {
            ListNode* nh=head->next;
            head->next->next=head;
            head->next=NULL;
            return nh;
        }
        
        return solve(head,left,right);
    }
};