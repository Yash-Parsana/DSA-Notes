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
    void reorderList(ListNode* head) 
    {

        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* temp = head;
        int ListLength = 0;

        while (temp)
        {
            ListLength++;
            temp = temp->next;
            
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
    
        stack<ListNode*> s;
        while(slow->next)
        {
            ListNode* temp = new ListNode(slow->next->val);
            s.push(temp);
            slow = slow->next;
        }

        ListNode* curr;
        

        while(!s.empty())
        {
            ListNode* nxt = head->next;
            curr = s.top();
            s.pop();
            head->next = curr;
            curr->next = nxt;

            head = nxt;
        }
        

        if (ListLength % 2 == 0)
        {
            curr->next = nullptr;
        }
        else
        {
            head->next = nullptr;
        }
        head = dummy->next;

    }
};