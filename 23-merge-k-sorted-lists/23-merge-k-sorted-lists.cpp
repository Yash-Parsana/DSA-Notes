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

struct cmp
{
    bool operator()(ListNode* l1,ListNode* l2)
    {
        return l1->val>l2->val;
        
    }
};

class Solution {
public:
    
    
    ListNode* mergeKLists(vector<ListNode*>& v) {
        
        if(v.size()==0)return NULL;
        
        priority_queue<ListNode*,vector<ListNode*>,cmp> h;
        
    
        ListNode* temp=NULL;
        
        for(ListNode* l:v)
        {
            if(l!=NULL)
                h.push(l);
        }
        
        if(h.empty())return NULL;
        
        ListNode* head=h.top();
        temp=h.top();
        h.pop();
        
        if(temp->next!=NULL)
            h.push(temp->next);
        
        while(!h.empty())
        {
            temp->next=h.top();
            h.pop();
            temp=temp->next;
            if(temp->next!=NULL)h.push(temp->next);
        }
        return head;
        
    } 
};



